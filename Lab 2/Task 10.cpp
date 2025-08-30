#include <iostream>
#include <cstring>

using namespace std;

class Library {
private:
    int num_categories;
    char** category_names;
    int* book_count;
    int** book_IDs;

public:
    Library(int n) : num_categories(n) {
        category_names = new char*[num_categories];
        book_count = new int[num_categories];
        book_IDs = new int*[num_categories];     
        for (int i = 0; i < num_categories; i++) {
            char temp_name[100];
            cout << "Enter name of category " << (i + 1) << ": ";
            cin >> temp_name;
            category_names[i] = new char[strlen(temp_name) + 1];
            strcpy(category_names[i], temp_name);          
            cout << "Enter number of books in " << category_names[i] << ": ";
            cin >> book_count[i];  
            book_IDs[i] = new int[book_count[i]];
            cout << "Enter book IDs for " << category_names[i] << ":" << endl;
            for (int j = 0; j < book_count[i]; j++) {
                cout << "Book " << (j + 1) << " ID: ";
                cin >> book_IDs[i][j]; } } }

    ~Library() {
        for (int i = 0; i < num_categories; i++) {
            delete[] category_names[i];
            delete[] book_IDs[i]; }
        delete[] category_names;
        delete[] book_count;
        delete[] book_IDs;
    }

    void searchBook(int search_ID) const {
        bool found = false;
        for (int i = 0; i < num_categories; i++) {
            for (int j = 0; j < book_count[i]; j++) {
                if (book_IDs[i][j] == search_ID) {
                    cout << "Book ID " << search_ID << " is available in category " << category_names[i] << endl;
                    found = true;
                    return; } } }
        if (!found) {
            cout << "Book ID " << search_ID << " is not available." << endl; }
    }
};

int main() {
    int num_categories;
    cout << "Enter number of book categories: ";
    cin >> num_categories;
    Library lib(num_categories);
    int search_ID;
    char continue_search = 'y';
	while (continue_search == 'y' || continue_search == 'Y') {
    	cout << "\nEnter book ID to search: ";
    	cin >> search_ID;
    	lib.searchBook(search_ID);
    	cout << "Do you want to search another book? (y/n): ";
    	cin >> continue_search; }
    return 0;
}
