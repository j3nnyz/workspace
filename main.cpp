#include <iostream>
using namespace std;

class Rectangle {
public:
    Rectangle(double length = 0.0, double width = 0.0);
    void Print() const;
    Rectangle operator+(double rhs);
    Rectangle operator+(Rectangle rhs);
private:
    double numLength;
    double numWidth;
};

Rectangle::Rectangle(double length, double width) {
    numLength = length;
    numWidth = width;
}

// No need to accommodate for overflow or negative values

/* Your code goes here */
Rectangle Rectangle :: operator+( double rhslength )
{
    Rectangle newObj ;
    newObj.numLength = numLength + rhslength ;
    newObj.numWidth = numWidth ;

    return newObj ;
}
Rectangle Rectangle :: operator+(Rectangle rhs)
{
    Rectangle newObj ;
    newObj.numLength = numLength + rhs.numLength ;
    newObj.numWidth = numWidth + rhs.numWidth;
    return newObj ;
}

void Rectangle::Print() const {
    cout << "Length: " << numLength << " units, width: " << numWidth << " units";
}

int main() {
    double length1;
    double width1;
    double length2;
    double width2;

    cin >> length1;
    cin >> width1;
    cin >> length2;
    cin >> width2;

    Rectangle rectangle1(length1, width1);
    Rectangle rectangle2(length2, width2);

    Rectangle sum1 = rectangle1 + length2;
    Rectangle sum2 = rectangle1 + rectangle2;

    rectangle1.Print();
    cout << endl;
    cout << "Length: " << length2 << " units" << endl;
    cout << "Sum: ";
    sum1.Print();
    cout << endl;

    cout << endl;

    rectangle1.Print();
    cout << endl;
    rectangle2.Print();
    cout << endl;
    cout << "Sum: ";
    sum2.Print();
    cout << endl;

    return 0;
}