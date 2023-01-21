#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std ;

int charCnt ( string fileName , char letter ) ;

int main ( ) {

    string fileName ;
    cout << "Enter the name of the input file: " ;
    cout << endl ;

    char letter ;

    cin >> fileName ;
    cin.ignore();
    cout << "Enter a character: " ;
    cout << endl ;
    cin.get ( letter ) ;



    charCnt ( fileName , letter ) ;

    return 0 ;

}

int charCnt ( string fileName , char letter )
{

    // OPEN FILE
    ifstream input ;
    input.open ( fileName ) ;

    if (!input.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit ( 1 ) ; // 1 indicates error
    }
    int counter = 0 ;
    char look ;

    while ( input.get( look ) )
    {
        if ( look == letter )
        {
            counter ++ ;
        }
    }

    cout << "# of " << letter << "'s: " << counter ;

    cout << endl ;

    return counter ;

}




