#include <fstream>
#include <iostream>
#include <cstdlib>
//#include <string>
#include <vector>
#include <sstream>
using namespace std ;

vector<int> split(const string &str);

int main(int argc, char* argv[]) {

    ifstream input ;
    ofstream output ;

    // OPEN INPUT FILE
    input.open ( argv [ 1 ] ) ;

    vector < int > numbers ;

    if (!input.is_open()) {
        cout << "Error opening " << argv[1] << endl;
        exit(1);
    }

    // read file into line
    string fileLine;
    while ( getline ( input , fileLine ) )
    {
        // splint line into vector
        numbers = split(fileLine);
    }

    int total = 0 ;

    // find total of numbers added

    for (unsigned int i = 0; i < numbers.size(); i++) {
        //cout << numbers.at(i) << ' ';
        total = total + numbers.at ( i ) ;
    }

    int average = total / ( numbers.size ( ) ) ;

    //cout << average ;

    for (unsigned int p = 0; p < numbers.size(); p++) {
        numbers.at (p) = numbers.at ( p ) - average ;
    }

    output.open (argv [ 2 ] ) ;

    for ( unsigned int p = 0 ; p < numbers.size ( ) ; p ++ ) {
        if (p == numbers.size() - 1) {
            output << numbers.at(p);
        } else {
            output << numbers.at ( p ) << "," ;
        }
    }


//    for (int x = 0; x < numbers.size(); x++) {
//        cout << numbers.at(x) << ' ';
//    }



    //istringstream inSS(userInfo);


//    string str = "1,2,3,4,5";
//    char sep = ',';
//
//    vector<int> tokens = split(str, sep);
//    for (auto &i: tokens) {
//        cout << i << ' ';
//    }
//
//    string fileLine ;
//
//    while ( getline ( input , fileLine ) )
//    {
//
//    }

//
//
//
//
//
//    // Prints argc and argv values
//    cout << "argc: " << argc << endl;
//    for (i = 0; i < argc; ++i) {
//        cout << "argv[" << i << "]: " << argv[i] << endl;
//    }
//
//    cout << "Hello " << argv[1] << endl;
//
//    cout << "I'm " << argv[2] << endl;

    return 0;
}


vector<int> split(const string &str)
{
    vector<int> tokens;

    int i;
    stringstream ss(str);
    while (ss >> i) {
        tokens.push_back(i);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }

    return tokens;
}