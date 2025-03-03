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

void addBook(Book books[],int& count){
    int bookCount;
    cout<<"\n===> Add Book <==="<<endl;
    cout<<"Enter amount of Book to Input: ";
    cin>> bookCount;
    bookCount = count + bookCount;

    for(count;count<bookCount;count++){
        cout<<"Enter Book Title: ";cin.ignore();cin.getline(books[count].title,100);
        cout<<"Enter book Author: ";cin.getline(books[count].author,100);
        cout<<"Enter book ISBN: ";cin.getline(books[count].ISBN,100);
        cout<<"Enter book Quantity: ";cin>>books[count].quantity;
    }
    cout<<"Count: "<<count<<endl;
    cout<<"\nBooks Added Successfully "<<endl;
    cout<<"===> The End <==="<<endl<<endl;
}

void displayBook(Book book[],int& count){
    cout<<"\n===> Display Book <==="<<endl<<endl;
    for(int i = 0;i<count;i++){
        cout<<"Title: "<<book[i].title<<" ,Author: "<<book[i].author<<" ,ISBN: "<<book[i].ISBN<<" ,Qty: "<<book[i].quantity<<endl;
    }

    cout<<"\n===> The End <==="<<endl<<endl;
}

void searchBook(Book book[],int& count){
    cout<<"\n===> Search Book by Title <==="<<endl;
    char searchBook[100];
    bool findbook = false;

    cout<<"Enter Book Title to search: ";cin.ignore();cin.getline(searchBook,100);

    for(int i=0;i<count;i++){
        if(strcmp(searchBook,book[i].title)==0){
            cout<<"Title: "<<book[i].title<<" ,Author: "<<book[i].author<<" ,ISBN: "<<book[i].ISBN<<" ,Qty: "<<book[i].quantity<<endl;
            findbook = true;
            cout<<"Book find Successfully!"<<endl;
            break;
        }
    }
    if(findbook == false){
        cout<<"Book not found"<<endl;
    }
    cout<<"\n===> The End <==="<<endl<<endl;
}

void addBorrower(Borrower borrower[],int& borrowerCount){
    int addborrower;
    addborrower = borrowerCount + 1;
    cout<<"\n===> Add Borrower <==="<<endl<<endl;

    for(borrowerCount;borrowerCount<addborrower;borrowerCount++){
        cout<<"Enter Borrower Name: ";cin.ignore();cin.getline(borrower[borrowerCount].name,100);
        cout<<"Enter Borrower ID: ";cin.getline(borrower[borrowerCount].ID,100);
        cout<<"Enter Borrower Contact Info: ";cin.getline(borrower[borrowerCount].contactInfo,100);
    }

    cout<<"Borrower Count: "<<borrowerCount<<endl;
    cout<<"\nBorrower Added Successfully "<<endl;
    cout<<"===> The End <==="<<endl<<endl;

}

void displayBorrower(Borrower borrower[],int& borrowerCount){
    cout<<"\n===> Display Borrowers <==="<<endl<<endl;
    for(int i = 0;i<borrowerCount;i++){
        cout<<"Name: "<<borrower[i].name<<" ,ID: "<<borrower[i].ID<<" ,Contact Info: "<<borrower[i].contactInfo<<endl;
    }

    cout<<"\n===> The End <==="<<endl<<endl;
}

void saveData(Book books[],int& count,Borrower borrowers[],int& borrowerCount,Transaction transactions[],int& transcationCount){
    ofstream bookFile,borrowerFile,transcationFile;
    bookFile.open("Books.bin");
    borrowerFile.open("Borrowers.bin");
    transcationFile.open("transactions.bin");
    Book book;
    Borrower borrower;
    Transaction transaction;

    if(!bookFile.is_open()){
        cerr<<"Failed to open file!"<<endl;
        return;
    }

    if(!borrowerFile.is_open()){
        cerr<<"Failed to open Borrower file!"<<endl;
        return;
    }

    if(!transcationFile.is_open()){
        cerr<<"Failed to open transcation file!"<<endl;
        return;
    }

    for(int i = 0;i<count;i++){
        bookFile.write(reinterpret_cast<char*>(&books[i]), sizeof(book));
    }
    for(int i = 0;i<borrowerCount;i++){
        borrowerFile.write(reinterpret_cast<char*>(&borrowers[i]), sizeof(borrower));
    }
    for(int i = 0;i<transcationCount;i++){
        transcationFile.write(reinterpret_cast<char*>(&transactions[i]), sizeof(transaction));
    }
    cout<<"\n Data Saved Successfully"<<endl<<endl;
    cout<<"===> The End <==="<<endl<<endl;
    bookFile.close();
    borrowerFile.close();
}

void borrowerBook(Book books[],int& count,Borrower borrowers[],int& borrowerCount,Transaction transactions[],int& transcationCount){
    cout<<"\n===> Borrow Book <==="<<endl;
    char bookISBN[100],borrowerID[100],date[100];
    bool findbookISBN = false,findBorrowerId = false;
    int addTranscation;
    addTranscation = transcationCount + 1;

    cout<<"Enter Book ISBN to borrow: ";cin.ignore();cin.getline(bookISBN,100);
    cout<<"Enter BorrowerID to borrow: ";cin.getline(borrowerID,100);
    cout<<"Enter Date to borrow: ";cin.getline(date,100);

    for(int i = 0;i<count;i++){
        if(strcmp(bookISBN,books[i].ISBN)==0){
            findbookISBN = true;
            books[i].quantity--;
            cout<<"Book ISBN is corrected"<<endl;
            break;
        }
    }

    for(int i = 0;i<borrowerCount;i++){
        if(strcmp(borrowerID,borrowers[i].ID)==0){
            findBorrowerId = true;
            cout<<"Borrower ID is corrected"<<endl;
            break;
        }
    }

    if(findbookISBN && findBorrowerId){
        strcpy(transactions[transcationCount].bookISBN,bookISBN);
        strcpy(transactions[transcationCount].borrowerID,borrowerID);
        strcpy(transactions[transcationCount].dateBorrowed,date);
        transcationCount++;
        cout << "Transaction added successfully!" << endl;
    }else{
        cout << "Invalid ISBN or Borrower ID. Transaction failed." << endl;
    }
}

void returnBook(Book books[],int& count,Borrower borrowers[],int& borrowerCount,Transaction transactions[],int& transcationCount){
    cout<<"\n===> Return Book <==="<<endl;
    char bookISBN[100],borrowerID[100];
    bool findbookISBN = false,findBorrowerId = false;
    int addTranscation;
    addTranscation = transcationCount + 1;

    cout<<"Enter Book ISBN to Return: ";cin.ignore();cin.getline(bookISBN,100);
    cout<<"Enter BorrowerID to Return: ";cin.getline(borrowerID,100);

    for(int i = 0;i<count;i++){
        if(strcmp(bookISBN,books[i].ISBN)==0){
            findbookISBN = true;
            books[i].quantity++;
            cout<<"Book ISBN is corrected"<<endl;
            break;
        }
    }

    for(int i = 0;i<borrowerCount;i++){
        if(strcmp(borrowerID,borrowers[i].ID)==0){
            findBorrowerId = true;
            cout<<"Borrower ID is corrected"<<endl;
            break;
        }
    }

    if(findbookISBN && findBorrowerId){
        bool found = false;
        for(int i =0 ;i<transcationCount;i++){
            if(strcmp(bookISBN,transactions[i].bookISBN)==0 && strcmp(borrowerID,transactions[i].borrowerID)==0){
                for(int j=i;j<transcationCount-1;j++){
                    transactions[j] = transactions[j+1];
                }
                transcationCount--;
                cout << "Book Return successfully!" << endl;
                found = true;
            }
        }
        if(!found){
            cout<<"Transcation not found!"<<endl;
        }
    }else{
        cout << "Invalid ISBN or Borrower ID. Transaction failed." << endl;
    }
}

void displayTranscation(Transaction transactions[],int& transcationCount){
    cout<<"\n===> Display Transaction <==="<<endl<<endl;
    for(int i = 0;i<transcationCount;i++){
        cout<<"Book ISBN: "<<transactions[i].bookISBN<<" ,Borrower Id: "<<transactions[i].borrowerID<<" ,Date of Transcation: "<<transactions[i].dateBorrowed<<endl;
    }

    cout<<"\n===> The End <==="<<endl<<endl;
}

void sortBook(Book books[],int& n){
    Book temp;
	cout<<"===> Sort Selected <==="<<endl;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(books[i].quantity<books[j].quantity){
				temp=books[i];
				books[i]=books[j];
				books[j]=temp;
			}
		}
	}
	cout<<"\n===> Display Book After sort <==="<<endl<<endl;
    for(int i = 0;i<n;i++){
        cout<<"Title: "<<books[i].title<<" ,Author: "<<books[i].author<<" ,ISBN: "<<books[i].ISBN<<" ,Qty: "<<books[i].quantity<<endl;
    }
	cout<<"===> The End <==="<<endl;
}


int main(){
    Book books[1000];
    Borrower borrowers[1000];
    Transaction transactions[1000];
    int choice;
    ifstream bookFiles,borrowerFiles,transactionFiles;
    Book book;
    Borrower borrower;
    Transaction transaction;
    int count = 0,borrowerCount = 0,transactionCount = 0;

    bookFiles.open("Books.bin");
    if(!bookFiles.is_open()){
        cout<<"File cannot open!"<<endl;
    }else{
        while (bookFiles.read(reinterpret_cast<char*>(&book), sizeof(book))){
            cout<<"Book added successfully"<<endl;
            books[count] = book;
            count++;
        }
    }
    bookFiles.close();
    cout<<"Count: "<<count<<endl;

    borrowerFiles.open("Borrowers.bin");
    if(!borrowerFiles.is_open()){
        cout<<"Borrowers File cannot open!"<<endl;
    }else{
        while (borrowerFiles.read(reinterpret_cast<char*>(&borrower), sizeof(borrower))){
            cout<<"Borrowers added successfully"<<endl;
            borrowers[borrowerCount] = borrower;
            borrowerCount++;
        }
    }
    borrowerFiles.close();
    cout<<"Borrower Count: "<<borrowerCount<<endl;

    transactionFiles.open("transactions.bin");
    if(!transactionFiles.is_open()){
        cout<<"Transaction File cannot open!"<<endl;
    }else{
        while (transactionFiles.read(reinterpret_cast<char*>(&transaction), sizeof(transaction))){
            cout<<"Transcation added successfully"<<endl;
            transactions[transactionCount] = transaction;
            transactionCount++;
        }
    }
    transactionFiles.close();
    cout<<"Borrower Count: "<<transactionCount<<endl;


    cout<<"[1].Add Book"<<endl;
    cout<<"[2].Display Books"<<endl;
    cout<<"[3].Search Book by Title"<<endl;
    cout<<"[4].Add Borrower"<<endl;
    cout<<"[5].Display Borrowers"<<endl;
    cout<<"[6].Borrow Book"<<endl;
    cout<<"[7].Return Book"<<endl;
    cout<<"[8].Display Transcation"<<endl;
    cout<<"[9].Save Data"<<endl;
    cout<<"[10].Sort Book by Qty"<<endl;
    cout<<"[11].Exit"<<endl;

    while (true)
    {
        cout<<"Enter Choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            addBook(books,count);
            break;
        case 2:
            displayBook(books,count);
            break;
        case 3:
            searchBook(books,count);
            break;
        case 4:
            addBorrower(borrowers,borrowerCount);
            break;
        case 5:
            displayBorrower(borrowers,borrowerCount);
            break;
        case 6:
            borrowerBook(books,count,borrowers,borrowerCount,transactions,transactionCount);
            break;
        case 7:
            returnBook(books,count,borrowers,borrowerCount,transactions,transactionCount);
            break;
        case 8:
            displayTranscation(transactions,transactionCount);
            break;
        case 9:
            saveData(books,count,borrowers,borrowerCount,transactions,transactionCount);
            break;
        case 10:
            sortBook(books,count);
            break;
        case 11:
            cout<<"\n===> Program Ended, Thank you! <==="<<endl<<endl;
            exit(1);
        
        default:
            cout<<"\n===> Choice is not avaliable! Try again! <==="<<endl<<endl;
            break;
        }
    }
    
}