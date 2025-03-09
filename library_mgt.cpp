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
    if(!(cin>>bookCount)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input. Please enter a number Values. Try again!" << endl<<endl;
        return;
    }
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

void binarySerachBook(Book book[],int& count){
    char bookISBN[100];
    int left = 0;
    int right = count - 1;
    int index;
    cout<<"Enter Book ISBN to search: ";cin.ignore();cin.getline(bookISBN,100);

    while (left <= right)
    {
        int mid = left + (right - left)/2;
        int cmp = strcmp(book[mid].ISBN, bookISBN);

        if(cmp == 0){
            index = mid;
            break;
        }else if(cmp < 0){
            left = mid + 1;
            index = -1;
        }else{
            right = mid - 1;
            index = -1;
        }
    }
    
    if (index != -1) {
        cout << "Book found at index " << index << endl;
        cout << "Title: " << book[index].title << endl;
        cout << "Author: " << book[index].author << endl;
        cout << "Quantity: " << book[index].quantity << endl;
    } else {
        cout << "Book with ISBN " << bookISBN << " not found." << endl;
    }
}

void updateBook(Book book[],int& count){
    int updateChoice;
    char bookISBN[100];
    bool running = true;
    cout<<"Enter Book ISBN to Update: ";cin.ignore();cin.getline(bookISBN,100);

    while (running)
    {
        cout<<"Enter Book Choice to Update Information"<<endl;
        cout<<"[1].Update title"<<endl;
        cout<<"[2].Update author"<<endl;
        cout<<"[3].Update ISBN"<<endl;
        cout<<"[4].Updat book Quanity"<<endl;
        cout<<"[5].Exit"<<endl;
        cout<<"Enter number Choie to Update: ";cin>>updateChoice;
        switch (updateChoice)
        {
        case 1:
            for(int i = 0;i<count;i++){
                if(strcmp(bookISBN,book[i].ISBN)==0){
                    cout<<"Enter new Title: ";
                    cin.ignore();cin.getline(book[i].title,100);
                    cout<<"New Title: "<<book[i].title<<" ,Author: "<<book[i].author<<" ,ISBN: "<<book[i].ISBN<<" ,Qty: "<<book[i].quantity<<endl;
                }
            }
            break;
        case 2:
            for(int i = 0;i<count;i++){
                if(strcmp(bookISBN,book[i].ISBN)==0){
                    cout<<"Enter new Author: ";
                    cin.ignore();cin.getline(book[i].author,100);
                    cout<<"\n===> Update Successfully! <==="<<endl;
                    cout<<"New Title: "<<book[i].title<<" ,Author: "<<book[i].author<<" ,ISBN: "<<book[i].ISBN<<" ,Qty: "<<book[i].quantity<<endl;
                }
            }
            break;
        case 3:
            for(int i = 0;i<count;i++){
                if(strcmp(bookISBN,book[i].ISBN)==0){
                    cout<<"Enter new ISBN: ";
                    cin.ignore();cin.getline(book[i].ISBN,100);
                    cout<<"\n===> Update Successfully! <==="<<endl;
                    cout<<"New Title: "<<book[i].title<<" ,Author: "<<book[i].author<<" ,ISBN: "<<book[i].ISBN<<" ,Qty: "<<book[i].quantity<<endl;
                    strcpy(bookISBN,book[i].ISBN);
                }
            }
            break;
        case 4:
            for(int i = 0;i<count;i++){
                if(strcmp(bookISBN,book[i].ISBN)==0){
                    cout<<"Enter new Qunatity: ";
                    cin>>book[i].quantity;
                    cout<<"New Title: "<<book[i].title<<" ,Author: "<<book[i].author<<" ,ISBN: "<<book[i].ISBN<<" ,Qty: "<<book[i].quantity<<endl;
                }
            }
            break;
        case 5:
            running = false;
            break;
        default:
            break;
        }
    }


}

void updateBorrower(Borrower borrower[],int& count){
    int updateChoice;
    char ID[100];
    bool running = true;
    cout<<"Enter Borrower ID to Update: ";cin.ignore();cin.getline(ID,100);

    while (running)
    {
        cout<<"Enter Book Choice to Update Information"<<endl;
        cout<<"[1].Update Name"<<endl;
        cout<<"[2].Update ID"<<endl;
        cout<<"[3].Update ContactInfo"<<endl;
        cout<<"[4].Exit"<<endl;
        cout<<"Enter number Choie to Update: ";cin>>updateChoice;
        switch (updateChoice)
        {
        case 1:
            for(int i = 0;i<count;i++){
                if(strcmp(ID,borrower[i].ID)==0){
                    cout<<"Enter new Name: ";
                    cin.ignore();cin.getline(borrower[i].name,100);
                    cout<<"\n===> Update Successfully! <==="<<endl;
                    cout<<"New Name: "<<borrower[i].name<<" ,Id: "<<borrower[i].ID<<" ,Contact Info: "<<borrower[i].contactInfo<<endl;
                }
            }
            break;
        case 2:
            for(int i = 0;i<count;i++){
                if(strcmp(ID,borrower[i].ID)==0){
                    cout<<"Enter new ID: ";
                    cin.ignore();cin.getline(borrower[i].ID,100);
                    cout<<"\n===> Update Successfully! <==="<<endl;
                    cout<<"New Name: "<<borrower[i].name<<" ,Id: "<<borrower[i].ID<<" ,Contact Info: "<<borrower[i].contactInfo<<endl;
                    strcpy(ID,borrower[i].ID);
                }
            }
            break;
        case 3:
            for(int i = 0;i<count;i++){
                if(strcmp(ID,borrower[i].ID)==0){
                    cout<<"Enter new Contact Info: ";
                    cin.ignore();cin.getline(borrower[i].contactInfo,100);
                    cout<<"\n===> Update Successfully! <==="<<endl;
                    cout<<"New Name: "<<borrower[i].name<<" ,Id: "<<borrower[i].ID<<" ,Contact Info: "<<borrower[i].contactInfo<<endl;
                }
            }
            break;
        case 4:
            running = false;
            break;
        default:
            break;
        }
    }


}


void deleteBorrower(Borrower borrower[],int& count){
    char ID[100];
    cout<<"Enter Borrower ID to Delete: ";cin.ignore();cin.getline(ID,100);
    for(int i =0 ;i<count;i++){
        if(strcmp(ID, borrower[i].ID)==0){
            for(int j=i;j<count-1;j++){
                borrower[j] = borrower[j+1];
            }
            count--;
            cout<<"Borrower Deleted Successfully"<<endl;
        }
    }
}

void deleteBook(Book books[],int& count){
    char bookISBN[100];
    cout<<"Enter Book ISBN to Delete: ";cin.ignore();cin.getline(bookISBN,100);
    for(int i =0 ;i<count;i++){
        if(strcmp(bookISBN, books[i].ISBN)==0){
            for(int j=i;j<count-1;j++){
                books[j] = books[j+1];
            }
            count--;
            cout<<"Book Deleted Successfully"<<endl;
        }
    }
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
			if(books[i].ISBN<books[j].ISBN){
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

void loadBookFiles(Book books[],int& count){
    ifstream bookFiles;
    Book book;
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
}

void loadBorrowerFiles(Borrower borrowers[],int& borrowerCount){
    ifstream borrowerFiles;
    Borrower borrower;

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
};

void loadTranscationFiles(Transaction transactions[],int& transactionCount){
    ifstream transactionFiles;
    Transaction transaction;

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
};

int main(){
    Book books[1000];
    Borrower borrowers[1000];
    Transaction transactions[1000];
    int choice,bookChoice,borrowerChoice;
    int count = 0,borrowerCount = 0,transactionCount = 0;

    //load all the Files into Array
    loadBookFiles(books,count);
    loadBorrowerFiles(borrowers,borrowerCount);
    loadTranscationFiles(transactions,transactionCount);

    while (true)
    {
        cout<<"[1].Add ,Update & Delete Book"<<endl;
        cout<<"[2].Display Books"<<endl;
        cout<<"[3].Search Book by Title"<<endl;
        cout<<"[4].Add, Udpate & Delete  Borrower"<<endl;
        cout<<"[5].Display Borrowers"<<endl;
        cout<<"[6].Borrow Book"<<endl;
        cout<<"[7].Return Book"<<endl;
        cout<<"[8].Display Transcation"<<endl;
        cout<<"[9].Save Data"<<endl;
        cout<<"[10].Sort Book by Qty"<<endl;
        cout<<"[11].Exit"<<endl<<endl;
        cout<<"Enter Choice: ";

        if(!(cin>>choice)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input. Please enter a number between 1 and 11. Try again!" << endl<<endl;

            continue;
        }

        if(choice < 1 || choice > 11){
            cout << "Invalid choice. Please enter a number between 1 and 11." << endl<<endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            cout<<"Enter Book Choice"<<endl;
            cout<<"[1].Add book"<<endl; 
            cout<<"[2].Update Book"<<endl;
            cout<<"[3].Delete Book"<<endl;
            cout<<"Enter choice number: ";cin>>bookChoice;
            switch (bookChoice)
            {
            case 1:
                cout<<"Choice 1 Selected: Add book"<<endl;
                addBook(books,count);
                break;
            case 2:
                cout<<"Choice 2 Selected: Update book"<<endl;
                updateBook(books,count);
                break;
            case 3:
                cout<<"Choice 3 Selected: Delete book"<<endl;
                deleteBook(books,count);
                break;
            default:
                break;
            }
            break;
        case 2:
            displayBook(books,count);
            break;
        case 3:
            binarySerachBook(books,count);
            break;
        case 4:
            cout<<"Enter Borrower Choice"<<endl;
            cout<<"[1].Add Borrower"<<endl; 
            cout<<"[2].Update Borrower"<<endl;
            cout<<"[3].Delete Borrower"<<endl;
            cout<<"Enter choice number: ";cin>>borrowerChoice;
            switch (borrowerChoice)
            {
            case 1:
                cout<<"Choice 1 Selected: Add Borrower"<<endl;
                addBorrower(borrowers,borrowerCount);
                break;
            case 2:
                cout<<"Choice 2 Selected: Update Borrower"<<endl;
                updateBorrower(borrowers,borrowerCount);
                break;
            case 3:
                cout<<"Choice 3 Selected: Delete Borrower"<<endl;
                deleteBorrower(borrowers,borrowerCount);
                break;
            default:
                break;
            }
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