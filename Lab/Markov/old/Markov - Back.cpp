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

        printUniquedWords( "Odisea.txt");

        return;

        InitDictionary(keyLen);

        std::cout << "Finished dictionary .." << std::endl;

        //PrintDictionary();
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
     *  Creates the dictionary.
     *  Order of the refixes to create.
     */
    void InitDictionary(unsigned int Order)
    {
        std::string SingleWord, Key;
        size_t WordCountKey = 0, Pos, Next;

        Next = fileBuffer.find_first_not_of( 32, 0 );
        
        // No separator character found, so we leave. npos is the bigger possible value for size_t
        if( Next == std::string::npos ) 
            return;

        while( WordCountKey < Order ) {
            Pos = fileBuffer.find_first_of( ' ', Next );
            SingleWord = fileBuffer.substr( Next, Pos - Next );
            Key += SingleWord + " ";
            Next = fileBuffer.find_first_not_of( 32, Pos + 1 );
            
            if( Next == std::string::npos ) 
                return;
            
            WordCountKey++;
        }

        // Remove the extra space
        Key = Key.substr( 0, Key.size() - 1 );
        //std::cout<< "Debug K " << Key;

        if (Key.find_first_of(EOF))
        {
            std::cout << "Ends here " << Key << std::endl;
        }

        // Lets save the suffix
        while( true ) {
            Next = fileBuffer.find_first_not_of( 32, Pos + 1 );

            if( Next == std::string::npos) 
                return;
            
            Pos = fileBuffer.find_first_of( 32, Next );
            SingleWord = fileBuffer.substr( Next, Pos - Next );
            
            
            
            if( std::find( dictionary[Key].begin(), dictionary[Key].end(), SingleWord ) == dictionary[Key].end() ) 
                dictionary[Key].push_back( SingleWord );
            
            Key = Key.substr( Key.find_first_of( 32 ) + 1 ) + " " + SingleWord;

            //std::cout<< "Debug Suffix " << SingleWord << std::endl;
        }
    } 

    void printUniquedWords(char filename[]) 
    { 
        // Open a file stream 
        std::fstream fs(filename); 
    
        // Keep reading words while there are words to read 
        std::string word; 
        while (fs >> word) 
        { 
            std::cout << "--" << word; 
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
    m.create( std::string( "Odisea.txt" ), 3, 200 );
    return 0;
}