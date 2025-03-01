#include <iostream>
using namespace std;

struct Book
{
    string title;
    string author;
    string ISBN;
    int quantity;
};


int main(){
    Book books = {"Harry Potter","vathanak","1111",10};
    cout<<"Title: "<<books.title<<endl;
    cout<<"Author: "<<books.author<<endl;
    cout<<"ISBN: "<<books.ISBN<<endl;
    cout<<"Author: "<<books.quantity<<endl;
}