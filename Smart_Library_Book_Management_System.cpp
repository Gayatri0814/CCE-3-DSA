#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;

    Book()
    {
        id = 0;
        title = "";
        author = "";
    }

    Book(int bookId, string bookTitle, string bookAuthor)
    {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
    }
};

class Node
{
public:
    Book data;
    Node *left;
    Node *right;

    Node(Book b)
    {
        data = b;
        left = nullptr;
        right = nullptr;
    }
};

class Library
{
private:
    Node *root;

    Node *insert(Node *current, Book b)
    {
        if (current == nullptr)
            return new Node(b);

        if (b.id < current->data.id)
            current->left = insert(current->left, b);
        else if (b.id > current->data.id)
            current->right = insert(current->right, b);
        else
            cout << "Book ID already exists.\n";

        return current;
    }

    Node *search(Node *current, int id)
    {
        if (current == nullptr || current->data.id == id)
            return current;

        if (id < current->data.id)
            return search(current->left, id);

        return search(current->right, id);
    }

    Node *findMin(Node *current)
    {
        while (current != nullptr && current->left != nullptr)
            current = current->left;

        return current;
    }

    Node *remove(Node *current, int id)
    {
        if (current == nullptr)
            return nullptr;

        if (id < current->data.id)
        {
            current->left = remove(current->left, id);
        }
        else if (id > current->data.id)
        {
            current->right = remove(current->right, id);
        }
        else
        {
            if (current->left == nullptr)
            {
                Node *temp = current->right;
                delete current;
                return temp;
            }

            if (current->right == nullptr)
            {
                Node *temp = current->left;
                delete current;
                return temp;
            }

            Node *successor = findMin(current->right);
            current->data = successor->data;
            current->right = remove(
                current->right, successor->data.id);
        }

        return current;
    }

    void inorder(Node *current)
    {
        if (current == nullptr)
            return;

        inorder(current->left);

        cout << "ID: " << current->data.id
             << " | Title: " << current->data.title
             << " | Author: " << current->data.author
             << '\n';

        inorder(current->right);
    }

    void destroy(Node *current)
    {
        if (current == nullptr)
            return;

        destroy(current->left);
        destroy(current->right);
        delete current;
    }

public:
    Library()
    {
        root = nullptr;
    }

    ~Library()
    {
        destroy(root);
    }

    void addBook()
    {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;

        if (search(root, id) != nullptr)
        {
            cout << "Book ID already exists.\n";
            return;
        }

        cout << "Enter Book Title: ";
        getline(cin >> ws, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        Book b(id, title, author);
        root = insert(root, b);

        cout << "Book added successfully.\n";
    }

    void searchBook()
    {
        int id;

        cout << "Enter Book ID to search: ";
        cin >> id;

        Node *result = search(root, id);

        if (result == nullptr)
        {
            cout << "Book not found.\n";
        }
        else
        {
            cout << "Book Found!\n";
            cout << "ID: " << result->data.id << '\n';
            cout << "Title: " << result->data.title << '\n';
            cout << "Author: " << result->data.author << '\n';
        }
    }

    void deleteBook()
    {
        int id;

        cout << "Enter Book ID to delete: ";
        cin >> id;

        if (search(root, id) == nullptr)
        {
            cout << "Book not found.\n";
            return;
        }

        root = remove(root, id);
        cout << "Book deleted successfully.\n";
    }

    void displayBooks()
    {
        cout << "\nBooks in Ascending Order:\n";
        inorder(root);
    }

    void run()
    {
        int choice;

        do
        {
            cout << "\n===== LIBRARY MANAGEMENT =====\n";
            cout << "1. Add Book\n";
            cout << "2. Search Book\n";
            cout << "3. Delete Book\n";
            cout << "4. Display All Books\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addBook();
                break;

            case 2:
                searchBook();
                break;

            case 3:
                deleteBook();
                break;

            case 4:
                displayBooks();
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
            }

        } while (choice != 0);
    }
};

int main()
{
    Library library;
    library.run();

    return 0;
}
