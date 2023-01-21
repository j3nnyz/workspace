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

    for (int number : numbers) {
        total = total + number ;
    }

    int average = total / ( numbers.size ( ) ) ;

    for (int number : numbers) {
        number = number - average ;
    }

    output.open (argv [ 2 ] ) ;

    for ( unsigned int p = 0 ; p < numbers.size ( ) ; p ++ ) {
        if (p == numbers.size() - 1) {
            output << numbers.at(p);
        } else {
            output << numbers.at ( p ) << "," ;
        }
    }

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