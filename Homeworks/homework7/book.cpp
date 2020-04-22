#include "Book.h"
using namespace std;

Book::Book() {
    title = "";
    author = "";
}
Book::Book(string inputTitle, string inputAuthor) {
    title = inputTitle;
    author = inputAuthor;
}
string Book::getTitle() {
    return title;
}
void Book::setTitle(string inputTitle) {
    title = inputTitle;
}
string Book::getAuthor() {
    return author;
}
void Book::setAuthor(string inputAuthor) {
    author = inputAuthor;
}
