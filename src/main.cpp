#include <iostream>
#include "DataBase.h"
#include "entities/Book.h"
#include "mappers/BookMapper.h"
#include "mappers/ThemeMapper.h"
#include "mappers/ThemeBookMapper.h"
#include "mappers/PublisherMapper.h"
#include "mappers/CopyMapper.h"
#include "mappers/ReaderMapper.h"
#include "entities/Date.h"
#include "entities/Reader.h"
#include "entities/Theme.h"
#include "entities/ThemeBook.h"
#include <string>
#include <cctype>
using namespace std;

void printMenu() {
    cout << "Choose option: \n";
    cout << "**Books**\n";
    cout << "[1] List of books\n";
    cout << "[2] Add book\n";
    cout << "[3] Update book\n";
    cout << "[4] Delete book\n";
    cout << "[5] Get all free copies of book. \n";
    cout << "**Publishers**\n";
    cout << "[6] List of publishers\n";
    cout << "[7] Add publisher\n";
    cout << "[8] Update publisher\n";
    cout << "[9] Delete publisher\n";
    cout << "**Readers**\n";
    cout << "[10] List of readers\n";
    cout << "[11] Add new reader\n";
    cout << "[12] Update reader\n";
    cout << "[13] Delete reader\n";
    cout << "[14] Get all books borrowed by the reader.\n";
    cout << "**Themes** \n";
    cout << "[15] List of themes\n";
    cout << "[16] Add theme\n";
    cout << "[17] Update theme\n";
    cout << "[18] Delete theme\n";
    cout << "**Copies** \n";
    cout << "[19] List of copies\n";
    cout << "[20] Add copy\n";
    cout << "[21] Delete copy\n";
    cout << "**Theme catalog**\n";
    cout << "[22] Add book to theme \n";
    cout << "[23] Get all books of theme\n";
    cout << "[24] Remove book-theme \n";
    cout << "[25] Get full list of theme-books \n";
    cout << "**Return-Borrow books**\n";
    cout << "[26] Borrow book\n";
    cout << "[27] Return book \n";
    cout << "[0] Exit \n";
}


void printBook(vector<Book> books) {
    std::cout << std::left << std::setw(5) << "¹" << std::setw(20) << "isbn" << std::setw(40)
        << "Book name" << std::setw(20) << "Author" << std::setw(20) << "Publisher" << std::setw(20) << "Publ_place" << std::setw(10) << "Publ_year" << std::setw(10) << "price" << std::setw(10) << "N of copies" << std::endl;
    for (int i = 0; i < books.size(); i++) {
        books[i].print(i);
    }
}

void printPublisher(vector<Publisher> publishers) {
    std::cout << std::left << std::setw(10) << "¹" << std::setw(20) << "Name"<< std::setw(20) << "Place" << std::endl;
    for (int i = 0; i < publishers.size(); i++) {
        publishers[i].print(i);
    }
}

void printReader(vector<Reader> readers) {
    std::cout << std::left << std::setw(10) << "¹" << std::setw(20) << "cardNum" << std::setw(20) << "lastName" << std::setw(20) << "firstName" << std::setw(20) << "middleName" << std::setw(20) << "birthDate" << std::setw(20) << "phoneNumber" << std::endl;
    for (int i = 0; i < readers.size(); i++)
        readers[i].print(i);
}

void printTheme(vector<Theme> themes) {
    std::cout << std::left << std::setw(10) << "¹" << std::setw(20) << "Theme" << std::endl;
    for (int i = 0; i < themes.size(); i++)
        themes[i].print(i);

}

void printCopy(vector<Copy> copies) {
    std::cout << std::left << std::setw(10) <<"¹" << std::setw(20) << "inventoryNum" << std::setw(20)
        << "isbn" << std::setw(20) << "reader card num" << std::setw(20) << "borrow date" << std::setw(20) << "return date" << std::endl;
    for (int i = 0; i < copies.size(); i++)
        copies[i].print(i);
}

void printThemeBook(vector<ThemeBook> themeBooks) {
    std::cout << std::left << std::setw(10) << "¹" << std::setw(20) << "Theme name" << std::setw(20) << "BookName" << std::setw(20) << "Book ISBN" << std::endl;
    for (int i = 0; i < themeBooks.size(); i++)
        themeBooks[i].print(i);
}
bool isNumeric(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

string cinDigit() {
    string s;
    while (true) {
        cin >> s;
        if (isNumeric(s)) {
            break;
        }
        else {
            cout << "Incorrect input, try again \n";
        }
    }
    return s;

}

void menu() {
    string choice;
    DataBase dataBase("libDSN", "kodya", "123");
    PublisherMapper publisherMapper(dataBase);
    ThemeMapper themeMapper(dataBase);
    ReaderMapper readerMapper(dataBase);
    BookMapper bookMapper(dataBase, publisherMapper);
    CopyMapper copyMapper(dataBase, bookMapper, readerMapper);
    ThemeBookMapper themeBookMapper(dataBase, themeMapper, bookMapper);
    
    while (true) {
        vector<Publisher> publishers;
        vector<Reader> readers;
        vector<Book> books;
        vector<Theme> themes;
        vector<Copy> copies;
        vector<Copy> freeCopies;
        vector<ThemeBook> themeBooks, books_of_theme;
        Copy copy;
        Theme theme;
        Book book;
        Publisher publisher;
        ThemeBook themeBook;
        Reader reader;
        Date date;
        string publisherName, publisherPlace;
        string firstName, lastName, middleName, phoneNumber;
        string theme_name;
        string isbn, book_name, author,Choice;
        string day, month, year, cardNum, inventory_num, pages, price;
        bool flag = false;
        printMenu();
        choice = cinDigit();
        switch (stoi(choice)) {
        case 1: 
            cout << "List of books: \n";
            books = bookMapper.getAll();
            if (!books.empty()) {
                printBook(books);
            }
            else {
                cout << "List of books is empty. \n";
            }           
			break;
        case 2:
            cout << "Add book \n";
            publishers = publisherMapper.getAll();
            while (true) {
                cout << "Enter isbn \n";
                isbn = cinDigit();
                book = bookMapper.getByIsbn(isbn);
                if (book.getIsbn() != " ") {
                    cout << "A book with this isbn already exists, try again \n";
                }
                else {
                    break;
                }
            }
            cout << "Enter book name \n";
            cin.ignore(cin.rdbuf()->in_avail());
            getline(cin, book_name);
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Enter author \n";
            getline(cin, author);
            cin.clear();
            cout << endl;
            printPublisher(publishers);
            cout << "Choose publisher from 1 to  " << publishers.size() << "\n";
            while (true) {
                Choice = cinDigit();
                if (stoi(Choice) >= 1 && stoi(Choice) <= publishers.size()) {
                    break;
                }
                else {
                    cout << "There is no publisher with this number, try again \n";
                }
            }
            publisher = publishers[stoi(Choice) - 1];
            cout << "Enter publish year \n";
            year = cinDigit();
            cout << "Enter pages \n";
            pages = cinDigit();
            cout << "Enter price \n";
            price = cinDigit();
            book.setIsbn(isbn);
            book.setAuthor(author);
            book.setBookName(book_name);
            book.setPublisher(publisher);
            book.setPublishYear(stoi(year));
            book.setPrice(stoi(price));
            book.setPages(stoi(pages));
            book.setCopyAmount(0);
            bookMapper.save(book);
            cout << "Book was successfully added \n";
            break;
        case 3:
            cout << "Update book \n";
            publishers = publisherMapper.getAll();
            while (true) {
                cout << "Enter isbn \n";
                cin >> isbn;
                book = bookMapper.getByIsbn(isbn);
                if (book.getIsbn() == " ") {
                    cout << "A book with this isbn doesn't exists, try again \n";
                }
                else {
                    break;
                }
            }
            cout << "Enter book name \n";
            cin.ignore(cin.rdbuf()->in_avail());
            getline(cin, book_name);
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Enter author \n";
            getline(cin, author);
            cin.clear();
            cout << endl;
            printPublisher(publishers);
            cout << "Choose publisher from 1 to  \n" << publishers.size();
            while (true) {
                Choice = cinDigit();
                if (stoi(Choice) >= 1 && stoi(Choice) <= publishers.size()) {
                    break;
                }
                else {
                    cout << "There is no publisher with this number, try again \n";
                }
            }
            publisher = publishers[stoi(Choice) - 1];
            cout << "Enter publish year \n";
            year = cinDigit();
            cout << "Enter pages \n";
            pages = cinDigit();
            cout << "Enter price \n";
            price = cinDigit();
            book.setIsbn(isbn);
            book.setAuthor(author);
            book.setBookName(book_name);
            book.setPublisher(publisher);
            book.setPublishYear(stoi(year));
            book.setPrice(stoi(price));
            book.setPages(stoi(pages));
            book.setCopyAmount(0);
            bookMapper.update(book);
            break;
        case 4:
            cout << "Delete book \n";   
            themeBooks = themeBookMapper.getAll();
            while (true) {
                cout << "Enter isbn \n";
                cin >> isbn;
                book = bookMapper.getByIsbn(isbn);
                if (book.getIsbn() == " ") {
                    cout << "A book with this isbn doesn't exists, try again \n";
                }
                else {
                    break;
                }
            }
            book = bookMapper.getByIsbn(isbn);
            if (book.getCopyAmount() != 0) {
                cout << "There are copies of this book. It can't be deleted\n";
                break;
            }
            
            for (int i = 0; i < themeBooks.size(); i++) {
                if (themeBooks[i].getBook()->getIsbn() == book.getIsbn()) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << "This book is in theme catalog. It can't be deleted\n";
                break;
            }
            bookMapper.remove(book);
            break;
        case 5:
            cout << "Get all free copies of book. \n";
            while (true) {
                cout << "Enter isbn \n";
                isbn = cinDigit();
                book = bookMapper.getByIsbn(isbn);
                if (book.getIsbn() == " ") {
                    cout << "A book with this isbn doesn't exists, try again \n";
                }
                else {
                    break;
                }
            }
            copies = copyMapper.getAll();
            for (int i = 0; i < copies.size(); i++) {
                if (book.getIsbn() == copies[i].getBook()->getIsbn() && ((copies[i].getBorrowDate().getStringTime() == " " && copies[i].getReturnDate().getStringTime() == " ") || copies[i].getReturnDate().getStringTime() != " "))
                    freeCopies.push_back(copies[i]);
            }
            if (!freeCopies.empty()) {
                cout << "Number of free copies: " << freeCopies.size() << "\n";
                printCopy(freeCopies);
                break;
            }
            cout << "There is no free copies of this book. \n";

            break;
        case 6:
            cout << "List of publishers:\n";
            publishers = publisherMapper.getAll();
            if (!publishers.empty()) {
                printPublisher(publishers);
            }
            else {
                cout << "List of publishers is empty \n";
            }         
            break;
        case 7:
            publishers = publisherMapper.getAll();
            cout << "Add publisher: \n";
            cout << "Enter a name of publisher\n";
            cin.ignore(cin.rdbuf()->in_avail());
            getline(cin, publisherName);
            cin.clear();
            publisher.setPublisherName(publisherName);
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Enter a place of publisher\n";
            getline(cin, publisherPlace);
            cin.clear();
            publisher.setPlace(publisherPlace);
            for (int i = 0; i < publishers.size(); i++) {
                if (publisherPlace == publishers[i].getPlace() && publisherName == publishers[i].getPublisherName()) {
                    cout << "This publisher already exists. \n";
                    flag = true;
                    break;
                }

            }
            if (flag)
                break;
            publisherMapper.save(publisher);
            cout << "Publisher was successfully added \n";
            break;
        case 8:
            cout << "Update publisher: \n";
            publishers = publisherMapper.getAll();
            if (!publishers.empty()) {
                printPublisher(publishers);
                while (true) {
                    cout << "Choose publisher: " << "from 1 to " << publishers.size() << "\n";
                    Choice = cinDigit();
                    if (stoi(Choice) >= 1 && stoi(Choice) <= publishers.size()) {
                        break;
                    }
                    else {
                        break;
                    }
                }
                cout << "Enter a name of publisher\n";
                cin.ignore(cin.rdbuf()->in_avail());
                getline(cin, publisherName);
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
                cout << "Enter a place of publisher\n";
                getline(cin, publisherPlace);
                cin.clear();
                publisher.setPlace(publisherPlace);
                publisher.setPublisherName(publisherName);
                publisher.setID(publishers[stoi(Choice) - 1].getID());
                publisherMapper.update(publisher);
                cout << "Publisher was successfully updated \n";
            }
            else {
                cout << "List of publishers is empty, nothing to update. \n";
            }
            break;
        case 9:
            cout << "Delete publisher \n";
            books = bookMapper.getAll();
            publishers = publisherMapper.getAll();
            printPublisher(publishers);
            if (!publishers.empty()) {
                while (true) {
                    cout << "Choose publisher: " << "from 1 to " << publishers.size() << "\n";
                    Choice = cinDigit();
                    if (stoi(Choice) >= 1 && stoi(Choice) <= publishers.size()) {
                        break;
                    }
                    else {
                        break;
                    }
                }
                for (int i = 0; i < books.size(); i++) {
                    if (books[i].getPublisher()->getID() == publishers[stoi(Choice) - 1].getID()) {
                        cout << "There is book with this publisher. It can't be deleted. \n";
                        flag = true;
                        break;
                    }

                }
                if (flag)
                    break;
                publisherMapper.remove(publishers[stoi(Choice) - 1]);
                cout << "Publisher was successfully deleted. \n";
            }
            else {
                cout << "List of publishers is empty, nothing to delete. \n";
            }
            break;
        case 10:
            cout << "List of Readers: \n";
            readers = readerMapper.getAll();
            if (!readers.empty()) {
                printReader(readers);
            }
            else {
                cout << "List of readers is empty. \n";
            }
            break;
        case 11:
            cout << "Add new reader: \n";
            cout << "Enter lastname \n";
            cin >> lastName;
            cout << "Enter firstname: \n";
            cin >> firstName;
            cout << "Enter middlename \n";
            cin >> middleName;
            while(true){
                cout << "Enter day of birth \n";
                day = cinDigit();
                cout << "Enter month of birth \n";
                month = cinDigit();
                cout << "Enter year of birth \n";
                year = cinDigit();
                if (date.isDateValid(stoi(day), stoi(month), stoi(year))) {
                    break;
                }
                cout << "Date is invalid, try again. \n";
            }            
            cout << "Enter mobile phone \n";
            phoneNumber = cinDigit();
            date =  Date(stoi(year), stoi(day), stoi(month));
            reader.setFirstName(firstName);
            reader.setLastName(lastName);
            reader.setMiddleName(middleName);
            reader.setBirthDate(date);
            reader.setPhoneNumber(phoneNumber);
            readerMapper.save(reader);
            cout << "Reader was successfully added \n";
            break;
        case 12:
            cout << "Update reader \n";
            readers = readerMapper.getAll();
            printReader(readers);
            while (true) {
                cout <<  "Enter reader card number: \n";
                cardNum = cinDigit();
                reader = readerMapper.getByCardNum(stoi(cardNum));
                if (reader.getCardNum() == -1) {
                    cout << "There is no reader with this card number, try again. \n";
                }
                else
                    break;
            }          
            cout << "Enter firstname: \n";
            cin >> firstName;
            cout << "Enter lastname \n";
            cin >> lastName;
            cout << "Enter middlename \n";
            cin >> middleName;
            while (true) {
                cout << "Enter day of birth \n";
                day = cinDigit();
                cout << "Enter month of birth \n";
                month = cinDigit();
                cout << "Enter year of birth \n";
                year = cinDigit();
                if (date.isDateValid(stoi(day), stoi(month), stoi(year))) {
                    break;
                }
                cout << "Date is invalid, try again. \n";
            }
            cout << "Enter mobile phone \n";
            phoneNumber = cinDigit();
            date = Date(stoi(year), stoi(day), stoi(month));
            reader.setFirstName(firstName);
            reader.setLastName(lastName);
            reader.setMiddleName(middleName);
            reader.setBirthDate(date);
            reader.setPhoneNumber(phoneNumber);
            readerMapper.update(reader);
            cout << "Reader was successfully updated \n";
            break;
        case 13:
            cout << "Remove reader: \n";
            cout << "Choose reader: " << "Enter reader card number: \n";
            while (true) {
                cout << "Enter reader card number: \n";
                cardNum = cinDigit();
                reader = readerMapper.getByCardNum(stoi(cardNum));
                if (reader.getCardNum() == -1) {
                    cout << "There is no reader with this card number, try again. \n";
                }
                else
                    break;
            }
            reader = readerMapper.getByCardNum(stoi(cardNum));        
            copies = copyMapper.getAll();
            for (int i = 0; i < copies.size(); i++) {
                if (copies[i].getReader()->getCardNum() == reader.getCardNum()) {
                    flag = true;
                    cout << "This reader borrowed book and can't be deleted. \n";
                    break;
                }                    
            }
            if (flag) {
                break;
            }
            readerMapper.remove(reader);
            cout << "Reader was successfully removed\n";
            break;
        case 14:
            cout << "Get all books borrowed by the reader \n";
            cout << "Choose reader. ";
            while (true) {
                cout << "Enter reader card number: \n";
                cardNum = cinDigit();
                reader = readerMapper.getByCardNum(stoi(cardNum));
                if (reader.getCardNum() == -1) {
                    cout << "There is no reader with this card number, try again. \n";
                }
                else
                    break;
            }
            copies = copyMapper.getAll();
            for (int i = 0; i < copies.size(); i++) {
                if (copies[i].getReader() != nullptr && copies[i].getReader()->getCardNum() == reader.getCardNum() && copies[i].getReturnDate().getStringTime() == " ") {
                    freeCopies.push_back(copies[i]);
                }
            }
            if (!freeCopies.empty()) {
                cout << "Number of books borrowed by this reader = " << freeCopies.size() << "\n";
                printCopy(freeCopies);
                break;
            }
            cout << "there is no copies borrowed by this resder \n";
            break;
        case 15:
            cout << "List of Themes: \n";
            themes = themeMapper.getAll();
            if (!themes.empty()) {
                printTheme(themes);
            }
            else {
                cout << "List of themes is empty \n";
            }
            break;
        case 16:
            cout << "Add theme: \n";
            cout << "Enter theme name: \n";
            cin.ignore(cin.rdbuf()->in_avail());
            getline(cin, theme_name);
            themes = themeMapper.getAll();
            for (int i = 0; i < themes.size(); i++) {
                if (themes[i].getThemeName() == theme_name) {
                    cout << "Theme with this name already exists. \n";
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            theme.setThemeName(theme_name);
            cin.clear();
            themeMapper.save(theme);
            cout << "Theme was succsessfully added\n";
            break;
        case 17:
            cout << "Update theme: \n";
            themes = themeMapper.getAll();
            printTheme(themes);
            if (!themes.empty()) {                
                while (true) {
                    cout << "Choose theme: " << "from 1 to " << themes.size() << "\n";
                    Choice = cinDigit();
                    if (stoi(Choice) >= 1 && stoi(Choice) <= themes.size()) {
                        break;
                    }
                    else {
                        cout << "There is no theme with this number, try again.\n";
                    }
               }
                cout << "Enter theme name\n";
                cin.ignore(cin.rdbuf()->in_avail());
                getline(cin, theme_name);
                themes[stoi(Choice) - 1].setThemeName(theme_name);
                cin.clear();
                themeMapper.update(themes[stoi(Choice) - 1]);
            }
            else {
                cout << "List of themes is empty, nothing to update. \n";
            }
            break;
        case 18:
            cout << "Delete theme: \n";
            themes = themeMapper.getAll();
            themeBooks = themeBookMapper.getAll();
            if (!themes.empty()) {
                printTheme(themes);
                while (true) {
                    cout << "Choose theme: " << "from 1 to " << themes.size() << "\n";
                    Choice = cinDigit();
                    if (stoi(Choice) >= 1 && stoi(Choice) <= themes.size()) {
                        break;
                    }
                    else {
                        cout << "There is no theme with this number, try again.\n";
                    }
                }

                for (int i = 0; i < themeBooks.size(); i++) {
                    if (themeBooks[i].getTheme()->getID() == themes[stoi(Choice) - 1].getID()) {
                        flag = true;
                        cout << "This theme is in theme catalog. It can't be deleted. \n";
                        break;
                    }
                }
                if (flag)
                    break;
                themeMapper.remove(themes[stoi(Choice) - 1]);
                cout << "Theme was successfully removed. \n";
            }
            else {
                cout << "List of themes is empty, nothing to delete. \n";
            }
            break;
        case 19:
            cout << "List of copies: \n";
            copies = copyMapper.getAll();
            if (!copies.empty()) {
                printCopy(copies);
            }
            else {
                cout << "List of themes is empty \n";
            }
            break;
        case 20:
            cout << "Add copy: \n";
            while (true) {
                cout << "Enter inventory_num \n";
                inventory_num = cinDigit();
                copy = copyMapper.getByInvNum(stoi(inventory_num));
                if(copy.getInventoryNum() != -1) {
                    cout << "A copy this inventory number already exists. Try again. \n";
                }
                else {
                    break;
                }
            }
           
            while (true) {
                cout << "Enter book isbn \n";
                isbn = cinDigit();
                    book = bookMapper.getByIsbn(isbn);
                    if (book.getIsbn() == " ") {
                        cout << "There is no book with this isbn. Try again. \n";
                    }
                    else {
                        break;
                    }

               

            }            
            copy.setBook(&book);
            copy.setReader(nullptr);
            copy.setInventoryNum(stoi(inventory_num));
            copyMapper.save(copy);
            book.setCopyAmount(book.getCopyAmount() + 1);
            bookMapper.update(book);
            cout << "Copy was succsessfully added \n";
            break;
        case 21:
            cout << "Delete copy: \n";
            copies = copyMapper.getAll();
            printCopy(copies);
            while (true) {
                cout << "Enter inventory num \n";
                inventory_num = cinDigit();
                copy = copyMapper.getByInvNum(stoi(inventory_num));
                if (copy.getInventoryNum() == -1) {
                    cout << "There is no copy with this inventory num. Try again.";
                }
                else {
                    break;
                }
            }
            book = bookMapper.getByIsbn(copy.getBook()->getIsbn());
            book.setCopyAmount(book.getCopyAmount() - 1);
            bookMapper.update(book);
            copyMapper.remove(copy);
            cout << "Copy was succsessfully removed. \n";
            break;
        case 22:
            themes = themeMapper.getAll();
            cout << "Add book to theme \n";
            printTheme(themes);
            while (true) {
                cout << "Choose theme from 1 to " << themes.size() << endl;
                Choice = cinDigit();
                if (stoi(Choice) >= 1 && stoi(Choice) <= themes.size()) {
                    break;
                }
                else {
                    cout << "There is no theme with this number. Try again. \n";
                }
            }
                
            
            theme = themes[stoi(Choice) - 1];
            books = bookMapper.getAll();
            printBook(books);
            while (true) {
                cout << "Enter book isbn \n";
                isbn = cinDigit();
                book = bookMapper.getByIsbn(isbn);
                if (book.getIsbn() != " ")
                    break;
                else
                    cout << "There is no book with this isbn. Try again\n";
            }
            themeBooks = themeBookMapper.getAll();
            for (int i = 0; i < themeBooks.size(); i++) {
                if (themeBooks[i].getTheme()->getID() == theme.getID() && themeBooks[i].getBook()->getIsbn() == book.getIsbn()) {
                    cout << "This book has already been added to this theme.\n";
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            themeBook.setBook(&book);
            themeBook.setTheme(&theme);
            themeBookMapper.save(themeBook);
            cout << "Book was successfully added to theme. \n";
            break;
        case 23:
            themes = themeMapper.getAll();
            cout << "Get all books of theme\n";
            printTheme(themes);
            while (true) {
                cout << "Choose theme from 1 to " << themes.size() <<"\n";
                Choice = cinDigit();
                if (stoi(Choice) >= 1 && stoi(Choice) <= themes.size())
                    break;
                else {
                    cout << "There is no theme with this number. Try again. \n";
                }
            }
            theme = themes[stoi(Choice) - 1];
            themeBooks = themeBookMapper.getAll();
            cout << endl;
            for (int i = 0; i < themeBooks.size(); i++) {
                if (themeBooks[i].getTheme()->getID() == theme.getID()) {
                    books_of_theme.push_back(themeBooks[i]);
                }                    
            }
            if (books_of_theme.empty()) {
                cout << "There are no books in this theme yet. \n";
            }
            else {
                printThemeBook(books_of_theme);
            }
            break;
        case 24:
            themes = themeMapper.getAll();
            cout << "Remove book from theme \n";
            printTheme(themes);
            while (true) {
                cout << "Choose theme from 1 to " << themes.size() <<endl;
                Choice = cinDigit();
                if (stoi(Choice) >= 1 && stoi(Choice) <= themes.size())
                    break;
                else {
                    cout << "There is no theme with this number. Try again. \n";
                }
            }
            theme = themes[stoi(Choice) - 1];
            themeBooks = themeBookMapper.getAll();
            cout << endl;
            for (int i = 0; i < themeBooks.size(); i++) {
                if (themeBooks[i].getTheme()->getID() == theme.getID()) {
                    books_of_theme.push_back(themeBooks[i]);
                }
            }
            if (books_of_theme.empty()) {
                cout << "There are no books in this theme yet. Nothing to delete. \n";
                break;
            }
            printThemeBook(books_of_theme);
            cout << "Enter isbn of book you want to delete \n";
            isbn = cinDigit();
            for (int i = 0; i < books_of_theme.size(); i++) {
                if (isbn == books_of_theme[i].getBook()->getIsbn()) {
                    themeBook = themeBookMapper.getByID(isbn, stoi(Choice));
                    themeBookMapper.remove(themeBook);
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            cout << "There is no book with this isbn in this theme.\n";
            break;
        case 25:
            cout << "Get full list of themes-books \n";
            themeBooks = themeBookMapper.getAll();
            if (!themeBooks.empty()) {
                cout << endl;
                printThemeBook(themeBooks);
            }
            else {
               cout << "List of themes-books is empty \n";
            }

            break;
        case 26:
            cout << "Borrow book: \n";
            books = bookMapper.getAll();
            printBook(books);
            while (true) {
                cout << "Enter book isbn: \n";
                isbn = cinDigit();
                book = bookMapper.getByIsbn(isbn);
                if (book.getIsbn() != " ") {
                    break;
                }
                else {
                    cout << "There are no books with this isbn. Try again. \n";
                }
            }
            if (book.getCopyAmount() == 0) {
                cout << "There are no copies of this book. \n";
                break;
            }
           
            readers = readerMapper.getAll();
            printReader(readers);
            while (true) {
                cout << "Enter reader card number: \n";
                cardNum = cinDigit();
                reader = readerMapper.getByCardNum(stoi(cardNum));
                if (reader.getCardNum() == -1) {
                    cout << "There is no reader with this card num. Try again. \n";
                }
                else {
                    break;
                }
            }
            copies = copyMapper.getAll();
            for (int i = 0; i < copies.size(); i++) {
               if (copies[i].getBook()->getIsbn() == isbn && ( (copies[i].getReturnDate().getStringTime() == " " && copies[i].getBorrowDate().getStringTime() == " ") || !(copies[i].getReturnDate().getStringTime() == " "))) {
                        copy = copies[i];
                        Date date;
                        copy.setBorrowDate(date);
                        copy.setReader(&reader);
                        flag = true;
                        copyMapper.update(copy, true);
                        break;

                }
            }
            if (flag) {
                cout << "Succsessfull\n";
                break;
            }
            cout << "There is no free copies of this book. Try later. \n";
            break;
        case 27:
            cout << "Return book: \n";
            copies = copyMapper.getAll();
            printCopy(copies);
            while (true) {
                cout << "Enter copy inventory_num: \n";
                inventory_num = cinDigit();
                copy = copyMapper.getByInvNum(stoi(inventory_num));
                if (copy.getInventoryNum() == -1)
                    cout << "There is no copy with this inventory num \n";
                else {
                    break;
                }

            }
            date = Date();
            if (copy.getReturnDate().getStringTime() == " " && copy.getBorrowDate().getStringTime() != " ") {
                copy.setReturnDate(date);
                copyMapper.update(copy, false);
            }
            else {
                cout << "This copy has already been returned. \n";
                break;
            }
            cout << "Succsessfull\n";
            break;
        case 0: 
            return;
        default:
            cout << "Incorrect input, try again \n";
            break;
        }
        

    }

}

int main() {
    setlocale(LC_ALL, "Russian");    
    menu();

}