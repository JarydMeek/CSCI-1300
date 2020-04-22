#include <iostream>
#include <string>
#include <fstream>
#include "../User.cpp"
#include "../Book.cpp"
#include "../Library.cpp"
using namespace std;

void displayMenu(){
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Read ratings" << endl;
    cout << "3. Print all books" << endl;
    cout << "4. Print books by author" << endl;
    cout << "5. Get rating" << endl;
    cout << "6. Find number of books user rated" << endl;
    cout << "7. View ratings" << endl;
    cout << "8. Get average rating" << endl;
    cout << "9. Get average rating by author" << endl;
    cout << "10. Add a user" << endl;
    cout << "11. Checkout a book" << endl;
    cout << "12. Get recommendations" << endl;
    cout << "13. Quit" << endl;
}

int main() {
    Library library;
    bool restart = true; //track whether to show the menu again
    bool booksRead = false;
    bool usersRead = false;
    
    while (restart == true) {//checks whether to show the menu again
        int selection = 0; //initializes the selection variable
        displayMenu(); //show the menu given on moodle
        cin >> selection; // save the given input to the selection variable
  
        if (selection == 1) { //if 1 is selected
            booksRead = true;
            int returned = 0;
            string fileName = "";
            cout << "Enter a book file name:" << endl;
            cin >> fileName;
            returned = library.readBooks(fileName);
            if (returned == -1) {
               cout << "No books saved to the database." << endl;
            } else if (returned == -2) {
               cout << "Database is already full. No books were added." << endl;
            } else if (returned >= 50) {
               cout << "Database is full. Some books may have not been added." << endl;
            }else {
                cout << "Total books in the database: " << returned << endl;
            }
        } else if (selection == 2) { //2 is selected
            usersRead = true;
            int returned = 0;
            string fileName = "";
            cout << "Enter a user file name:" << endl;
            cin >> fileName;
            returned = library.readRatings(fileName);
            if (returned == -1) {
               cout << "No users saved to the database." << endl;
            } else if (returned == -2) {
               cout << "Database is already full. No users were added." << endl;
            } else if (returned >= 100) {
               cout << "Database is full. Some users may have not been added." << endl;
            } else {
                cout << "Total users in the database: " << returned << endl;
            }
        }else if (selection == 3) {//3 is selected
           if (usersRead == true && booksRead == true) {
               library.printAllBooks();
           } else {
               cout << "Database has not been fully initialized." << endl;
           }
        }else if (selection == 4) { //4 is selected
            if (usersRead == true && booksRead == true) {
                string author;
                cout << "Enter an author name:" << endl;
                cin.ignore();
                getline(cin, author); //save book title
                library.printBooksByAuthor(author);
           } else {
                cout << "Database has not been fully initialized." << endl;
           }
        }else if (selection == 5) {
            if (usersRead == true && booksRead == true) {
                string username = "";
                cout << "Enter a user name:" << endl;
                cin >> username;
                string title;
                cout << "Enter a book title:" << endl;
                cin.ignore();
                getline(cin, title); //save book title
                int rating = library.getRating(username, title);
                if (rating == 0) {
                    cout << username << " has not rated " << title << endl; //if the rating is 0, the user has not rated the title
                } else if (rating == -3) {
                    cout << username << " or " << title << " does not exist." << endl; //if the rating is -3, the title or username could not be found in the array
                } else {
                    cout << username <<  " rated " << title << " with " << rating << endl; //otherwise, give the rating
                }
           } else {
                cout << "Database has not been fully initialized." << endl;
           }
        }else if (selection == 6) {
            if (usersRead == true && booksRead == true) {
                string username = "";
                cout << "Enter a user name:" << endl;
                cin >> username;
                int numBooksRead = library.getCountReadBooks(username);
                if (numBooksRead == 0) {
                    cout << username << " has not rated any books."<< endl; //if the rating is 0, the user has not rated the title
                } else if (numBooksRead == -3) {
                    cout << username << " does not exist." << endl; //if the rating is -3, the title or username could not be found in the array
                } else {
                    cout << username <<  " rated " << numBooksRead << " books." << endl; //otherwise, give the rating
                }
           } else {
                cout << "Database has not been fully initialized." << endl;
           }
        }else if (selection == 7) {
            if (usersRead == true && booksRead == true) {
                string username = "";
                cout << "Enter a user name:" << endl;
                cin >> username;
                int minRating;
                cout << "Enter a minimum rating:" << endl;
                cin >> minRating;
                library.viewRatings(username, minRating);
           } else {
                cout << "Database has not been fully initialized." << endl;
           }
        }else if (selection == 8) {
              if (usersRead == true && booksRead == true) {
                string title;
                cout << "Enter a book title:" << endl;
                cin.ignore();
                getline(cin, title); //save book title
                double rating = library.calcAvgRating(title);
                if (rating == -3) {
                    cout <<  title << " does not exist." << endl; //if the rating is -3, the title or username could not be found in the array
                } else {
                    cout << "The average rating for " << title << " is " << rating << endl; //otherwise, give the rating
                }
           } else {
                cout << "Database has not been fully initialized." << endl;
           }
        }else if (selection == 9) {
            if (usersRead == true && booksRead == true) {
                string author;
                cout << "Enter an author name:" << endl;
                cin.ignore();
                getline(cin, author); //save book title
                double rating = library.calcAvgRatingByAuthor(author);
                if (rating == -3) {
                    cout <<  author << " does not exist." << endl; //if the rating is -3, the title or username could not be found in the array
                } else {
                    cout << "The average rating for " << author << " is " << rating << endl; //otherwise, give the rating
                }
           } else {
                cout << "Database has not been fully initialized." << endl;
           }
        }else if (selection == 10) {
            usersRead = true;
            string username;
            cout << "Enter a user name:" << endl;
            cin >> username;
            int response = library.addUser(username);
            if (response == 1) {
                cout << "Welcome to the library " << username << endl; //if the rating is -3, the title or username could not be found in the array
            } else if (response == 0)  {
                cout << username <<" already exists in the database."<< endl; //otherwise, give the rating
            } else {
                cout << "Database is already full. "<< username <<" was not added." << endl;
            }
        }else if (selection == 11) {
            if (usersRead == true && booksRead == true) {
                string username;
                cout << "Enter a user name:" << endl;
                cin >> username;
                string title;
                cout << "Enter a book title:" << endl;
                cin.ignore();
                getline(cin, title); //save book title
                int newRating;
                cout << "Enter a new rating:" << endl;
                cin >> newRating;
                int response = library.checkOutBook(username, title, newRating);
                if (response == 1) {
                    cout << "We hope you enjoyed your book. The rating has been updated." << endl; //if the rating is -3, the title or username could not be found in the array
                } else if (response == -4) {
                    cout << newRating << " is not valid." << endl; //otherwise, give the rating
                } else {
                    cout << username << " or " << title << " does not exist." << endl;
                }
           } else {
                cout << "Database has not been fully initialized." << endl;
           }
        }else if (selection == 12) {
            if (usersRead == true && booksRead == true) {
                string username;
                cout << "Enter a user name:" << endl;
                cin >> username;
                library.getRecommendations(username);
           } else {
                cout << "Database has not been fully initialized." << endl;
           }
        }else if (selection == 13) { //6 is selected
            cout << "Good bye!" << endl;
            restart = false;//don't show menu again
        } else { 
            cout << "Invalid input." <<endl; //user entered something wrong. this user is a dummy.
        }
        cout << endl;
    }
}