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
    char bookISBN[100];
    int bookCount;
    cout<<"\n===> Add Book <==="<<endl;
    cout<<"Enter amount of Book to Input: ";
    if(!(cin>>bookCount)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "=> Invalid input. Please enter a number Values. Try again! <=" << endl<<endl;
        return;
    }
    bookCount = count + bookCount;

    for(count;count<bookCount;count++){
        bool sameISBN = false;
        cout<<"Enter Book Title: ";cin.ignore();cin.getline(books[count].title,100);
        cout<<"Enter book Author: ";cin.getline(books[count].author,100);
        cout<<"Enter book ISBN: ";cin.getline(bookISBN,100);
        cout<<"Enter book Quantity: ";cin>>books[count].quantity;

        if(books[count].quantity < 0){
            cout << "\n=> Invalid quantity! Quantity cannot be less than 0. Please re-enter details for this book. <=\n\n";
            count--;
            continue;
        }

        for(int i=0;i<count;i++){
            if(strcmp(bookISBN,books[i].ISBN)==0){
                cout << "\n=> Invalid ISBN! ISBN cannot be the same. <=\n\n";
                count--;
                sameISBN = true;
                continue;
            }
        }
        if(!sameISBN){
            strcpy(books[count].ISBN,bookISBN);
            cout<<"\nBooks Added Successfully "<<endl;
        }
    }
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
    cout<<"\n===> Search Book <==="<<endl;
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
    bool bookfound = false;
    cout<<"\n===> Update Book <==="<<endl;
    cout<<"Enter Book ISBN to Update: ";cin.ignore();cin.getline(bookISBN,100);

    for(int i=0;i<count;i++){
        if(strcmp(bookISBN,book[i].ISBN)==0){
            bookfound = true;
        }
    }

    if(!bookfound){
        cout<<"=> Book does not Exist. Try again! <="<<endl<<endl;
        return;
    }

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
    bool borrowerFound = false;
    cout<<"\n===> Update Borrower <==="<<endl;
    cout<<"Enter Borrower ID to Update: ";cin.ignore();cin.getline(ID,100);

    for(int i=0;i<count;i++){
        if(strcmp(ID,borrower[i].ID)==0){
            borrowerFound = true;
        }
    }

    if(!borrowerFound){
        cout<<"=> Borrower does not Exist. Try again! <="<<endl<<endl;
        return;
    }

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
    cout<<"\n===> Delete Borrower <==="<<endl;
    cout<<"Enter Borrower ID to Delete: ";cin.ignore();cin.getline(ID,100);
    for(int i =0 ;i<count;i++){
        if(strcmp(ID, borrower[i].ID)==0){
            for(int j=i;j<count-1;j++){
                borrower[j] = borrower[j+1];
            }
            count--;
            cout<<"\n=> Borrower Deleted Successfully <= \n"<<endl;
        }
    }
}

void deleteBook(Book books[],int& count){
    char bookISBN[100];
    cout<<"\n===> Delete Book <==="<<endl;
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
    char id[100];
    addborrower = borrowerCount + 1;
    cout<<"\n===> Add Borrower <==="<<endl<<endl;

    for(borrowerCount;borrowerCount<addborrower;borrowerCount++){
        bool sameId = false;
        cout<<"Enter Borrower Name: ";cin.ignore();cin.getline(borrower[borrowerCount].name,100);
        cout<<"Enter Borrower ID: ";cin.getline(id,100);
        cout<<"Enter Borrower Contact Info: ";cin.getline(borrower[borrowerCount].contactInfo,100);

        for(int i=0 ;i<borrowerCount;i++){
            if(strcmp(id,borrower[i].ID)==0){
                cout<<"Invild Id, The id cannot be the same. Try again!!"<<endl;
                borrowerCount--;
                sameId = true;
                continue;
            }
        }
        if(!sameId){
            strcpy(borrower[borrowerCount].ID,id);
            cout<<"\nBorrower Added Successfully "<<endl;
            cout<<"===> The End <==="<<endl<<endl;
        }
    }

}

void displayBorrower(Borrower borrower[],int& borrowerCount){
    cout<<"\n===> Display Borrowers <==="<<endl<<endl;
    for(int i = 0;i<borrowerCount;i++){
        cout<<"Name: "<<borrower[i].name<<" ,ID: "<<borrower[i].ID<<" ,Contact Info: "<<borrower[i].contactInfo<<endl;
    }

    cout<<"\n===> The End <==="<<endl<<endl;
}

void binarySerachBorrower(Borrower borrower[],int& count){
    char ID[100];
    int left = 0;
    int right = count - 1;
    int index;
    cout<<"\n===> Search Borrower <==="<<endl;
    cout<<"Enter Borrower ID to search: ";cin.ignore();cin.getline(ID,100);

    while (left <= right)
    {
        int mid = left + (right - left)/2;
        int cmp = strcmp(borrower[mid].ID, ID);

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
        cout << "Borrower found at index " << index << endl;
        cout << "Name: " << borrower[index].name << endl;
        cout << "ID: " << borrower[index].ID << endl;
        cout << "Contact Info: " << borrower[index].contactInfo << endl;
    } else {
        cout << "Book with ISBN " << ID << " not found." << endl;
    }
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
        cout << "\n=> Transaction added successfully! <=" << endl;
    }else{
        cout << "\n=> Invalid ISBN or Borrower ID. Transaction failed. <=" << endl;
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

void sortBook(Book book[],int& count){
	cout<<"===> Sort Selected <==="<<endl;
	for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(book[j].ISBN, book[j+1].ISBN) > 0) {
                // Swap books
                Book temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }
	cout<<"\n===> Display Book After sort <==="<<endl<<endl;
    for(int i = 0;i<count;i++){
        cout<<"Title: "<<book[i].title<<" ,Author: "<<book[i].author<<" ,ISBN: "<<book[i].ISBN<<" ,Qty: "<<book[i].quantity<<endl;
    }
	cout<<"===> The End <==="<<endl;
}

void sortBorrower(Borrower borrowers[],int& borrowerCount){
	cout<<"===> Sort Selected <==="<<endl;
	for (int i = 0; i < borrowerCount - 1; i++) {
        for (int j = 0; j < borrowerCount - i - 1; j++) {
            if (strcmp(borrowers[j].ID, borrowers[j+1].ID) > 0) {
                Borrower temp = borrowers[j];
                borrowers[j] = borrowers[j+1];
                borrowers[j+1] = temp;
            }
        }
    }
	cout<<"\n===> Display Borrower After sort <==="<<endl<<endl;
    for(int i = 0;i<borrowerCount;i++){
        cout<<"Name: "<<borrowers[i].name<<" ,ID: "<<borrowers[i].ID<<" ,Contact Info: "<<borrowers[i].contactInfo<<endl;
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
            books[count] = book;
            count++;
        }
    }
    bookFiles.close();
}

void loadBorrowerFiles(Borrower borrowers[],int& borrowerCount){
    ifstream borrowerFiles;
    Borrower borrower;

    borrowerFiles.open("Borrowers.bin");
    if(!borrowerFiles.is_open()){
        cout<<"Borrowers File cannot open!"<<endl;
    }else{
        while (borrowerFiles.read(reinterpret_cast<char*>(&borrower), sizeof(borrower))){
            borrowers[borrowerCount] = borrower;
            borrowerCount++;
        }
    }
    borrowerFiles.close();
};

void loadTranscationFiles(Transaction transactions[],int& transactionCount){
    ifstream transactionFiles;
    Transaction transaction;

    transactionFiles.open("transactions.bin");
    if(!transactionFiles.is_open()){
        cout<<"Transaction File cannot open!"<<endl;
    }else{
        while (transactionFiles.read(reinterpret_cast<char*>(&transaction), sizeof(transaction))){
            transactions[transactionCount] = transaction;
            transactionCount++;
        }
    }
    transactionFiles.close();
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

    cout<<"===> Welcome to Library Mgt System! <==="<<endl<<endl;

    while (true)
    {
        cout<<"[1].Add ,Update & Delete Book"<<endl;
        cout<<"[2].Display Books"<<endl;
        cout<<"[3].Search Book by ISBN"<<endl;
        cout<<"[4].Add, Udpate & Delete  Borrower"<<endl;
        cout<<"[5].Display Borrowers"<<endl;
        cout<<"[6].Search Borrowers"<<endl;
        cout<<"[7].Borrow Book"<<endl;
        cout<<"[8].Return Book"<<endl;
        cout<<"[9].Display Transcation"<<endl;
        cout<<"[10].Save Data"<<endl;
        cout<<"[11].Sort Book by ISBN"<<endl;
        cout<<"[12].Sort Borrower by ID"<<endl;
        cout<<"[13].Exit"<<endl<<endl;
        cout<<"Enter Choice: ";

        if(!(cin>>choice)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input. Please enter a number between 1 and 11. Try again!" << endl<<endl;

            continue;
        }

        if(choice < 1 || choice > 13){
            cout << "Invalid choice. Please enter a number between 1 and 11." << endl<<endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            cout<<"\n===> Enter Book Choice to Add, Update or Delete <==="<<endl;
            cout<<"[1].Add book"<<endl; 
            cout<<"[2].Update Book"<<endl;
            cout<<"[3].Delete Book"<<endl;
            cout<<"[4].Exit"<<endl;
            cout<<"Enter choice number: ";
            if(!(cin>>bookChoice)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid input. Please enter a number between 1 and 4. Try again!" << endl<<endl;
    
                continue;
            }
    
            if(bookChoice < 1 || bookChoice > 4){
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl<<endl;
                continue;
            }
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
            case 4:
                cout<<"Exit Successfully"<<endl;
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
        cout<<"\n===> Enter Borrower Choice to Add, Update or Delete <==="<<endl;
            cout<<"[1].Add Borrower"<<endl; 
            cout<<"[2].Update Borrower"<<endl;
            cout<<"[3].Delete Borrower"<<endl;
            cout<<"[4].Exit"<<endl;
            cout<<"Enter choice number: ";
            if(!(cin>>borrowerChoice)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Invalid input. Please enter a number between 1 and 4. Try again!" << endl<<endl;
    
                continue;
            }
    
            if(borrowerChoice < 1 || borrowerChoice > 4){
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl<<endl;
                continue;
            }
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
            case 4:
                cout<<"Exit Successfully"<<endl;
                break;
            default:
                break;
            }
            break;
        case 5:
            displayBorrower(borrowers,borrowerCount);
            break;
        case 6:
            binarySerachBorrower(borrowers,borrowerCount);
            break;
        case 7:
            borrowerBook(books,count,borrowers,borrowerCount,transactions,transactionCount);
            break;
        case 8:
            returnBook(books,count,borrowers,borrowerCount,transactions,transactionCount);
            break;
        case 9:
            displayTranscation(transactions,transactionCount);
            break;
        case 10:
            saveData(books,count,borrowers,borrowerCount,transactions,transactionCount);
            break;
        case 11:
            sortBook(books,count);
            break;
        case 12:
            sortBorrower(borrowers,borrowerCount);
            break;
        case 13:
            cout<<"\n===> Program Ended, Thank you! <==="<<endl<<endl;
            exit(1);
        
        default:
            cout<<"\n===> Choice is not avaliable! Try again! <==="<<endl<<endl;
            break;
        }
    }
    
}