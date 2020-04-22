#include "User.h"
using namespace std;

/*
* Algorithm: sets up a new user with wiped everything (username, number of ratings, and storage array)
* Input parameters: none
* Output (prints to screen): nothing
* Returns: nothing
*/
User::User() {
    username = ""; //wipes username
    numRatings = 0; //sets the user to 0 items stored
    size = 50;
    for (int i = 0; i < 49; i++) { //wipes array of ratings for new user
        ratings[i] = 0;
    }
}

/*
* Algorithm: Takes the inputusername and an import array of ratings and stores that to the user in the class. Checks to make sure there is enough rome in the class for all the input information, 
            then wipes the storage array for the user, then fills the given information
* Input parameters: string of username, an array of ratings, and the number of ratings.
* Output (prints to screen): nothing
* Returns: nothing
*/
User::User(string inputUsername, int inputRatings[], int inputNumRatings) {
    username = inputUsername;
    if (inputNumRatings > 50) { //make sure the array has room
        numRatings = 50; //if it doesn't force the maximum number saved to be within the storage of the array
    } else if (inputNumRatings >= 0) { //if it is less, save the number passed to the function as the number stored.
        numRatings = inputNumRatings;
    }
    for (int i = 0; i < 49; i++) { //wipe the entire array
        ratings[i] = 0;
    }
    for (int i = 0; i < inputNumRatings; i++) { //fill the array with the given information
        ratings[i] = inputRatings[i];   
    }
}

//getter for username
string User::getUsername() {
    return username;
}
 //setter for username
void User::setUsername(string inputUsername) {
    username = inputUsername;
}

/*
* Algorithm: Takes the position, and returns the value of the rating at that position if the position is within the array size
* Input parameters: position to read rating of.
* Output (prints to screen): nothing
* Returns: the rating, or -1 if an invalid position is entered.
*/
int User::getRatingAt(int position) {
    if (position > 49 || position < 0) { //makes sure the position to return is in the array
        return -1; //if it isn't return -1
    } else {
        return ratings[position]; //if it is, return the rating
    }
}

/*
* Algorithm: make sure the position is in the array, and the rating is a valid rating (0-5) if it is, store that rating at the position given
* Input parameters: position to save the value at, and the value to save
* Output (prints to screen): nothing
* Returns: true if saved successfully, false if not returned successfully.
*/
bool User::setRatingAt(int position, int value) {
    if (position >= 0 && position < size && value >=0 && value <= 5) { //make sure the position given is within the array (0-50), and the rating given is valid (0-5)
        ratings[position] = value; //if it is, save the new value at the given position
        return true; //return true as it was saved successfully
    } else {
        return false; //something invalid was entered, and value wasn't saved successfully.
    }
}

//getter for the number of ratings
int User::getNumRatings() {
    return numRatings;
}

//setter for number of ratings
void User::setNumRatings (int inputNumRatings) {
    numRatings = inputNumRatings;
}

//getter for size of array (50 as given on moodle)
int User::getSize() {
    return size;
}