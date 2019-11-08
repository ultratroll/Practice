#include <ctime>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <map>
class markov {
public:
    void create( std::string& file, unsigned int keyLen, unsigned int words ) {
        
        std::ifstream f( file.c_str(), std::ios_base::in );
        fileBuffer = std::string( ( std::istreambuf_iterator<char>( f ) ), std::istreambuf_iterator<char>() );
        f.close();
        
        if( fileBuffer.length() < 1 ) 
            return;

        std::cout << std::endl;

        std::cout << "Creating dictionary .." << std::endl;

		CreateDictionary( "Odisea.txt", keyLen);
	    
        std::cout << "Finished dictionary .." << dictionary.size() << std::endl;

        std::cout<< std::endl;
        createText( words - keyLen );
    }
private:

    /** To handle the file. */
    std::string fileBuffer;

    /** Our dictionary. */
    std::map<std::string, std::vector<std::string> > dictionary;

    void createText( int w ) {
        std::string key, first, second;
        size_t next;
        std::map<std::string, std::vector<std::string> >::iterator it = dictionary.begin();
        std::advance( it, rand() % dictionary.size() );
        key = ( *it ).first;
        std::cout << key;
        while( true ) {
            std::vector<std::string> d = dictionary[key];
            if( d.size() < 1 ) break;
            second = d[rand() % d.size()];
            if( second.length() < 1 ) break;
            std::cout << " " << second;
            if( --w < 0 ) break;
            next = key.find_first_of( 32, 0 );
            first = key.substr( next + 1 );
            key = first + " " + second;
        }
        std::cout << "\n";
    }

    /** 
     *
     *  Creates the dictionary, improved version.
     *  Order of the refixes to create.
     */
    void CreateDictionary(char filename[], unsigned int Order) 
    { 
        // Open a file stream 
        std::fstream fs(filename); 

        std::string SingleWord, Key, Suffix;
    
        int KeyCountWord = 0;
        long int pos = 0;
        // Keep reading words while there are words to read 
        
        // Lets create the keys
        while (fs >> SingleWord) 
        { 
            if (KeyCountWord == 0) 
                pos = fs.tellp();

            KeyCountWord++;
			Key += SingleWord;
			if (KeyCountWord<2) Key += " ";

            if (KeyCountWord >= Order)
            {
                fs >> SingleWord;
                fs.seekp(pos);

				if( std::find( dictionary[Key].begin(), dictionary[Key].end(), SingleWord ) == dictionary[Key].end() )
                	dictionary[Key].push_back( SingleWord );

				KeyCountWord = 0;
                Key.clear();
            }
        }
    
        fs.close(); 
    } 

    void PrintDictionary()
    {
        std::string key, first, second;
        size_t next;
        std::map<std::string, std::vector<std::string> >::iterator it = dictionary.begin();

        std::cout << std::endl << std::endl;

        for(auto it = dictionary.cbegin(); it != dictionary.cend(); ++it)
        {
            key = ( *it ).first;
            std::cout << std::endl << "(Key: " << key << ")";
            
            std::vector<std::string> d = dictionary[key];
            if( d.size() < 1 ) break;
            second = d[rand() % d.size()];
            if( second.length() < 1 ) break;
            
            std::cout<<"[";

            for (int i = 0; i < d.size(); i++)
            {
                std::cout << d[i];

                if (i<d.size()-1)
                    std::cout<< "|";
            }

            std::cout<<"]";
        }

        std::cout << "\n";
    }
    
};

int main( int argc, char* argv[] ) {
    srand( unsigned( time( 0 ) ) );
    markov m;
    m.create( std::string( "Odisea.txt" ), 2, 200 );
    
    return 0;
}