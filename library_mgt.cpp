#include <iostream>
#include <fstream>
#include <limits>
#include <cstring>
using namespace std;

struct Book
{
    char title[100];
    char author[100];
    char ISBN[100];
    int quantity;
};

struct Borrower
{
    char name[100];
    char ID[100];
    char contactInfo[100];
};

struct Transaction
{
    char borrowerID[100];
    char bookISBN[100];
    char dateBorrowed[100];

};

void addBook(Book books[],int bookCount, ofstream& bookFile){
    cout<<"\n===> Add Book <==="<<endl;
    cout<<"Enter amount of Book to Input:";
    cin>> bookCount;
    bookFile.open("Books.bin",ios::app|ios::binary);
    Book book;

    if(!bookFile.is_open()){
        cerr<<"Failed to open file!"<<endl;
        return;
    }

    for(int i = 0;i<bookCount;i++){
        cout<<"Enter Book Title: ";cin.ignore();cin.getline(books[i].title,100);
        cout<<"Enter book Author: ";cin.getline(books[i].author,100);
        cout<<"Enter book ISBN: ";cin.getline(books[i].ISBN,100);
        cout<<"Enter book Quantity: ";cin>>books[i].quantity;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bookFile.write(reinterpret_cast<char*>(&books[i]), sizeof(book));
    }
    cout<<"\n===> The End <==="<<endl<<endl;
    bookFile.close();
}

void displayBook(){
    cout<<"\n===> Display Book <==="<<endl<<endl;
    ifstream bookFile;
    Book book;
    bookFile.open("Books.bin",ios::in|ios::binary);
    if(!bookFile.is_open()){
        cout<<"File cannot open!"<<endl;
        return;
    }

    while (bookFile.read(reinterpret_cast<char*>(&book), sizeof(book))){
        cout<<"Title: "<<book.title<<" ,Author: "<<book.author<<" ,ISBN: "<<book.ISBN<<" ,Qty: "<<book.quantity<<endl;
    }
    if(bookFile.eof()){
        cout<<"\n===> The End <==="<<endl<<endl;
    }
    bookFile.close();
}

void searchBook(){
    cout<<"\n===> Search Book by Title <==="<<endl;
    char searchBook[100];
    bool findbook = false;
    ifstream bookFile;
    Book book;

    bookFile.open("Books.bin",ios::in|ios::binary);
    if(!bookFile.is_open()){
        cout<<"File cannot open!"<<endl;
        return;
    }

    cout<<"Enter Book Title to search: ";cin.ignore();cin.getline(searchBook,100);

    while (bookFile.read(reinterpret_cast<char*>(&book), sizeof(book))){
        if(strcmp(searchBook,book.title)==0){
            cout<<"Title: "<<book.title<<" ,Author: "<<book.author<<" ,ISBN: "<<book.ISBN<<" ,Qty: "<<book.quantity<<endl;
            findbook = true;
            break;
        }
    }
    if(findbook == false){
        cout<<"Book not found"<<endl;
    }
    cout<<"\n===> The End <==="<<endl<<endl;
    bookFile.close();
}



int main(){
    ofstream bookFile;
    Book books[1000],book;
    int choice,bookCount=0;
    cout<<"[1].Add Book"<<endl;
    cout<<"[2].Display Books"<<endl;
    cout<<"[3].Search Book by Title"<<endl;
    cout<<"[4].Add Borrower"<<endl;
    cout<<"[5].Display Borrowers"<<endl;
    cout<<"[6].Borrow Book"<<endl;
    cout<<"[7].Return Book"<<endl;
    cout<<"[8].Save Data"<<endl;
    cout<<"[9].Exit"<<endl;

    while (true)
    {
        cout<<"Enter Choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            addBook(books,bookCount,bookFile);
            break;

        case 2:
            displayBook();
            break;
        case 3:
            searchBook();
            break;
        case 9:
            cout<<"\n===> Program Ended, Thank you! <==="<<endl<<endl;
            exit(1);
        
        default:
        cout<<"\n===> Choice is not avaliable! Try again! <==="<<endl<<endl;
            break;
        }
    }
    
}