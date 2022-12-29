//
// Created by jenny zhang on 12/28/22.
//
/*Fall2022 - PA #2*/

#include <iostream>
#include <string>
#include <vector>
// FIXME include vector library

using namespace std;

//Function should display menu options
void DisplayMenu()
{
    cout << "Menu options:" << endl ;
    cout << "1. Display All Seats Status:" << endl ;
    cout << "2. Total Number of Available Seats:" << endl ;
    cout << "3. Display Available Seats: " << endl ;
    cout << "4. Book Seat:" << endl ;
    cout << "5. Cancel Seat:" << endl ;
    cout << "6. Change Seat:" << endl ;
    cout << "7. Quit:" << endl ;
    cout << endl ;
    cout << "Please select an option: " << endl ;
    cout << endl ;
}

///* //Function should show all seats and seat status where a 0 marks the seat status as available and an
//1 marks the seat status as occupied.
void DisplayAllSeatsStatus ( const vector <string> &seatNumbers , const vector <bool> &seatAvail )
{
    unsigned int i ;

    cout << "Seat" << "\t" << "Status" << endl ;

    for ( i = 0 ; i < seatNumbers.size() ; i ++ )
    {
        cout << seatNumbers.at ( i ) ;
        cout << "\t";
        cout << seatAvail.at ( i ) ;
        cout << endl ;
    }
}

//Function display which seats are currently available
void DisplayAvailableSeats( const vector <string> &seatNumbers , const vector <bool> &seatAvail )
{
    unsigned int i ;

    for ( i = 0 ; i < seatNumbers.size() ; i ++ )
    {
        if ( seatAvail.at ( i ) == false )
        {
            cout << seatNumbers.at ( i ) << endl ;
        }
    }
}


//Function should show the number of seats not currently booked
int TotalNumberOfAvailableSeats( const vector <bool> &seatAvail )
{
    unsigned int i = 0 ;
    int count = 0 ;
    while ( i < seatAvail.size() )
    {
        if ( seatAvail.at ( i ) == false )
        {
            count ++ ;
            i ++ ;
        }
        else
        {
            i ++ ;
        }
    }
    cout << count ;
    return count ;
}

bool BookSeatHelper ( const string &userSeat , const vector <string> &seatNumbers , vector <bool> &seatAvail )
{
    unsigned int i ;

    for ( i = 0 ; i < seatNumbers.size() ; i ++ )
    {
        if ( seatNumbers.at ( i ) == userSeat )
        {
            if ( seatAvail.at ( i ) == false )
            {
                seatAvail.at ( i ) = true ;
                return true ;
            }

        }
    }
    return false ;
}

//Function should take in a seat from user and mark that seat as unavailable
void BookSeat( const string &userSeat , const vector <string> &seatNumbers , vector <bool> &seatAvail )
{
    unsigned int i ;

    string newUser = userSeat ;

    while ( BookSeatHelper  ( newUser , seatNumbers , seatAvail ) == false )
    {
        cout << "That seat is already taken.";
        cout << endl ;
        cout << "Enter seat to book: " ;
        cin >> newUser ;
    }

    cout << "Seat" << "\t" << "Status" << endl ;

    for ( i = 0 ; i < seatNumbers.size() ; i ++ )
    {
        cout << seatNumbers.at ( i ) ;
        cout << "\t";
        cout << seatAvail.at ( i ) ;
        cout << endl ;
    }
}


//Function should take in a seat from user and mark that seat as available
void CancelSeat ( const string &userSeat , const vector <string> &seatNumbers , vector <bool> &seatAvail )
{
    unsigned int i ;

    for ( i = 0 ; i < seatNumbers.size() ; i ++ )
    {
        if ( seatNumbers.at ( i ) == userSeat )
        {
            seatAvail.at ( i ) = false ;
        }
    }
    cout << "Seat" << "\t" << "Status" << endl ;

    for ( i = 0 ; i < seatNumbers.size() ; i ++ )
    {
        cout << seatNumbers.at ( i ) ;
        cout << "\t";
        cout << seatAvail.at ( i ) ;
        cout << endl ;
    }
}

//Function should take in two seats from the user.  It should mark the first seat as available and
//the second seat as unavailable // iNPUT ANOTHER IN FUCNTION
void ChangeSeat( const string &userSeat , const string &replaceSeat , const vector <string> &seatNumbers, vector <bool> &seatAvail )
{
    unsigned int i ;

    for ( i = 0 ; i < seatNumbers.size() ; i ++ )
    {
        if ( seatNumbers.at ( i ) == userSeat )
        {
            seatAvail.at ( i ) = false ;
        }
    }

    for ( i = 0 ; i < seatNumbers.size() ; i ++ )
    {
        if ( seatNumbers.at ( i ) == replaceSeat )
        {
            seatAvail.at ( i ) = true ;
        }
    }
    cout << "Seat" << "\t" << "Status" << endl ;

    for ( i = 0 ; i < seatNumbers.size() ; i ++ )
    {
        cout << seatNumbers.at ( i ) ;
        cout << "\t";
        cout << seatAvail.at ( i ) ;
        cout << endl ;
    }
}

//add other functions you might need here // */

int main() {

    int userInput ;
    string userSeat ;
    string replaceSeat ;

    vector < string > seatNumbers ;
    vector < bool > seatAvail ( 25 , 0 ) ;

    seatNumbers.push_back ( "1A" ) ;
    seatNumbers.push_back ( "1B" ) ;
    seatNumbers.push_back ( "1C" ) ;
    seatNumbers.push_back ( "1D" ) ;
    seatNumbers.push_back ( "1E" ) ;
    seatNumbers.push_back ( "2A" ) ;
    seatNumbers.push_back ( "2B" ) ;
    seatNumbers.push_back ( "2C" ) ;
    seatNumbers.push_back ( "2D" ) ;
    seatNumbers.push_back ( "2E" ) ;
    seatNumbers.push_back ( "3A" ) ;
    seatNumbers.push_back ( "3B" ) ;
    seatNumbers.push_back ( "3C" ) ;
    seatNumbers.push_back ( "3D" ) ;
    seatNumbers.push_back ( "3E" ) ;
    seatNumbers.push_back ( "4A" ) ;
    seatNumbers.push_back ( "4B" ) ;
    seatNumbers.push_back ( "4C" ) ;
    seatNumbers.push_back ( "4D" ) ;
    seatNumbers.push_back ( "4E" ) ;
    seatNumbers.push_back ( "5A" ) ;
    seatNumbers.push_back ( "5B" ) ;
    seatNumbers.push_back ( "5C" ) ;
    seatNumbers.push_back ( "5D" ) ;
    seatNumbers.push_back ( "5E" ) ;

    DisplayMenu() ;

    cin >> userInput ;

    while ( userInput != 7 ) {

        if ( userInput == 1 )
        {
            DisplayAllSeatsStatus ( seatNumbers , seatAvail ) ;
            cout << endl ;
            DisplayMenu() ;
            cout << endl ;
            cin >> userInput ;
        }


        else if ( userInput == 2 )
        {
            cout << "Number of available seats: " ;
            TotalNumberOfAvailableSeats ( seatAvail ) ;
            cout << endl ;
            cout << endl ;
            DisplayMenu() ;
            cout << endl ;
            cin >> userInput ;
        }

        else if ( userInput == 3 )
        {
            cout << "Available seats:" << endl ;
            DisplayAvailableSeats ( seatNumbers , seatAvail ) ;
            cout << endl ;
            DisplayMenu() ;
            cin >> userInput ;
        }

        else if  ( userInput == 4 )
        {
            cout << "Enter seat to book: " ;
            cout << endl ;
            cout << endl ;
            cin >> userSeat ;
            BookSeat ( userSeat , seatNumbers , seatAvail );
            cout << endl ;
            DisplayMenu() ;
            cin >> userInput ;
        }

        else if ( userInput == 5 )
        {
            cout << "Enter seat to cancel:" ;
            cout << endl ;
            cout << endl ;
            cin >> userSeat ;
            CancelSeat ( userSeat , seatNumbers , seatAvail ) ;
            cout << endl ;
            DisplayMenu() ;
            cin >> userInput ;
        }

        else if ( userInput == 6 )
        {
            cout << "Enter seat to cancel:" << endl ;
            cout << endl ;
            cin >> userSeat ;
            cout << "Enter seat to book: " << endl ;
            cout << endl ;
            cin >> replaceSeat ;
            ChangeSeat ( userSeat , replaceSeat , seatNumbers , seatAvail ) ;
            cout << endl ;
            DisplayMenu() ;
            cin >> userInput ;
        }
    }
    return 0;
}


