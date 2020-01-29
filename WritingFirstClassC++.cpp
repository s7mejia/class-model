// WritingFirstClassC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>

class Date {   
public:
    //The constructor, copy constructor, operator, and destructor are the 4 requiered METHODS
    Date(int aMonth = 1, int aDay = 1, int aYear = 2020) //contructor, has to have 0 arguments or arguments must have a default value (in case value is not given)
    :month(aMonth), day(aDay),year(aYear) { // need to intialize values with the values in protected with the arguments given :day gets its value from "aDay"
    
    }
    Date(const Date& aCopy) {  //Copy constructer: &aCopy is reference to aCopy   
    //:month(aCopy.month), day(aCopy.day), year(aCopy.year)   //allows you to clone a Date type object
        * this = aCopy; //We can call operator = when in the copy constructor - short hand when making class 

    }
    
    Date(const std::string &aString) {  //Conversion constructor    
        // string is character data, so need to parse(breaks it apart at the dashes) the string to integers
        std::istringstream theInput(aString);  //input string stream that initializes from the string provided
         // need to skip the dash and only parse the date characters
        char theDash;
        theInput >> year >> theDash >> month >> theDash >> day; 
    }

    ~Date() {} //use to free memory when pointers and other stuff

    Date& operator=(const Date &aCopy) { //(Date&):returns a reference to an object that you call it on, and the pass a Date refence 
        //Assignment operator: takes an object that already exists and assign it to another object that already exists
        month=aCopy.month; 
        day=aCopy.day; 
        year=aCopy.year;
        return *this;  //wahtever object I want to assign to (Date&) is going to be returning a reference back to itself to the caller
    }

    //conversion operator: converts to a standard string
    operator std::string() {
        //open up a new stream of type string and write our data from the date class into the string and return that string to the caller
        std::ostringstream theOutput;//output stream
        theOutput << year << "-" << month << "-" << day; //writing into the string: converts internal Date fields into a string
        return theOutput.str(); //gives me the string that I just wrote too
    }

    friend std::ostream& operator << (std::ostream& output, const Date& aDate) { //this is a string conversion operator & insertion operator (<<)
        //accepts an arugment of type output stream and the second argument is the same as the object we are working with
        output << aDate.year << "-" << aDate.month << "-" << aDate.day; //need to specify object where the value comes from
        return output; //expects that you return stream (return is the same method as the first argument passed)
    }
protected:
     int month, day, year;       // Constructs DATA MEMEBERS
};

int main()
{
    Date theDate1(11, 22, 1997);    //object "Date" type created on the stack
    Date theDate2(theDate1); //creates an object and references the object in () to copy its properties
    theDate2 = theDate1; //expects that theDate2 is going to be identical to theDate1 - it calls our assignment operator
    std::cout << (std::string)theDate2<<"\n";  //conversion operator is called and theDate data is converted into a string for it to read and output
    std::cout << theDate2; //calls friend method directly instead of the conversion operator - 

    Date theDate("3-3-3"); //intialize the date class from a string - a conversion constructor is need (construct this object using this other data type)
   
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
