#include <iostream>
#include <string>
#include <fstream>
#include "../Library.cpp"
#include "../Book.cpp"
#include "../User.cpp"

using namespace std;

//Driver file for Library class to test different functions
int main() {
   Library libraryTest;
    cout << libraryTest.getSizeBook() << endl; //50
    cout << libraryTest.getSizeUser() << endl; //100
    cout << libraryTest.getNumBooks() << endl; //0
    cout << libraryTest.readBooks("books.txt") << endl; //50
    //libraryTest.printAllBooks();
    //libraryTest.printBooksByAuthor("Douglas Adams");
    cout << libraryTest.readRatings("ratings.txt") << endl; //86
    cout << libraryTest.getRating("brittany", "The Hitchhiker's Guide To The Galaxy") << endl; //2
    cout << libraryTest.getCountReadBooks("brittany") << endl; //41
    cout << libraryTest.calcAvgRating("Lord of the Flies") << endl; //2.05479 
    cout << libraryTest.calcAvgRatingByAuthor("William Golding") << endl; //2.71233
    libraryTest.getRecommendations("pamela"); //list of stuff
}