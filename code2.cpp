//
// Created by jenny zhang on 12/28/22.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int GetFrequencyOfWord(const vector<string> &wordsList, string currWord)
{
    unsigned int p = 0 ;
    int count = 0  ;

    while ( p < wordsList.size() )
    {
        if ( currWord == wordsList.at ( p ) )
        {
            count ++ ;
            p ++ ;
        }
        else { p ++ ; }
    }
    return count ;
}

int main() {

    int numWords ;
    int i ;
    unsigned int x ;
    int y = 0 ;
    string userWord ;
    string word ;
    vector < string > listWords ( 0 ) ;
    vector < int > frequencyWords ( 0 ) ;

    // 1. get number of words

    cin >> numWords ;

    // 2. input words and put into vector

    for ( i = 0 ; i < numWords ; i ++ )
    {
        cin >> userWord ;
        listWords.push_back ( userWord ) ;
    }

    // 2.5 call function

    for ( x = 0 ; x < listWords.size () ; x ++ )
    {
        word = listWords.at ( x ) ;
        frequencyWords.push_back ( GetFrequencyOfWord ( listWords , word ) ) ;
    }

    while ( y < frequencyWords.size () )
    {
        cout << listWords.at ( y ) << " " << frequencyWords.at ( y ) ;
        cout << endl ;
        y ++ ;
    }

    return 0;
}
