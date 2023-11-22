#include "ThemeBook.h"

ThemeBook::ThemeBook() {
    ThemeBook::book = nullptr;
    ThemeBook::theme = nullptr;
}

void ThemeBook::setBook(Book* book) {
    this->book = new Book();
    this->book->setIsbn(book->getIsbn());
    this->book->setAuthor(book->getAuthor());
    this->book->setBookName(book->getBookName());
    this->book->setCopyAmount(book->getCopyAmount());
    this->book->setPages(book->getPages());
    this->book->setPrice(book->getPrice());
    this->book->setPublishYear(book->getPublishYear());
    this->book->setPublisher(*book->getPublisher());
}

void ThemeBook::setTheme(Theme* theme) {
    this->theme = new Theme();
    this->theme->setID(theme->getID());
    this->theme->setThemeName(theme->getThemeName());
}

ThemeBook::~ThemeBook() = default;

Book* ThemeBook::getBook() const {
    return book;
}

Theme* ThemeBook::getTheme() const {
    return theme;
}

void ThemeBook::print(int i) {
    std::cout << std::left << std::setw(10) << i + 1 << std::setw(20) << theme->getThemeName() << std::setw(20) << book->getBookName() << std::setw(20) << book->getIsbn() << std::endl;
}
