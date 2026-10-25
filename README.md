# SmartLibraryBookManagement

A menu-driven Smart Library Book Management System developed in C++ using a Binary Search Tree (BST). Supports adding and deleting book records, searching books by ID, displaying books in ascending order, counting book records, issuing books, and returning books.

# Smart Library Book Management System Using Binary Search Tree in C++

## 1. Project Overview

The **Smart Library Book Management System** is a menu-driven C++ application developed using a Binary Search Tree (BST). It allows users to manage library book records by adding new books, searching for books using their unique IDs, deleting book records, displaying all books in sorted order, counting the total number of books, issuing books, and returning books.

This project demonstrates the practical implementation of fundamental Data Structures and Algorithms concepts, including binary search trees, dynamic memory allocation, node insertion and deletion, searching, inorder traversal, pointer manipulation, and memory management.

**Academic Details**

* **College:** Amrutvahini College of Engineering, Sangamner
* **Course:** S.Y. B.Tech, Electronics and Computer Engineering
* **Subject:** Data Structures and Algorithms
* **Course Code:** R25-EC-PCC-202
* **Semester:** III
* **Academic Year:** 2026–2027
* **Project Title:** Smart Library Book Management System
* **Programming Language:** C++

## 2. Objectives

* To understand the structure and operation of a Binary Search Tree.
* To implement insertion and deletion of book records using a BST.
* To search for books using their unique book IDs.
* To display book records in ascending order using inorder traversal.
* To count the total number of book records in the system.
* To implement basic book issue and return operations.
* To apply object-oriented programming concepts using classes, constructors, and member functions.
* To understand the practical application of data structures in library management.
* To test the application and maintain the source code in a GitHub repository.

## 3. Technologies Used

| Technology         | Purpose                                       |
| ------------------ | --------------------------------------------- |
| C++                | Implementation of the application             |
| Binary Search Tree | Storage and management of book records        |
| Visual Studio Code | Writing, compiling, and testing the program   |
| GCC / MinGW-w64    | Compilation of the C++ source code            |
| Git                | Version control and tracking project progress |
| GitHub             | Hosting the source code and documentation     |

## 4. Data Structure Used

A **Binary Search Tree (BST)** is a non-linear data structure in which each node contains data and has at most two children. The left subtree contains keys smaller than the current node's key, while the right subtree contains keys greater than the current node's key.

In this project, each node represents a book and stores its ID, title, author name, and availability status.

### Node Structure

Conceptually, each book node contains:

* `id`: Unique identifier of the book.
* `title`: Name of the book.
* `author`: Name of the book's author.
* `available`: Boolean value indicating whether the book is available.
* `left`: Pointer to the left child node.
* `right`: Pointer to the right child node.

### Important Variables and Pointers

| Variable / Pointer | Purpose                                                             |
| ------------------ | ------------------------------------------------------------------- |
| `root`             | Points to the root node of the BST                                  |
| `current`          | Refers to the node currently being processed during tree operations |
| `left`             | Points to the left child of a node                                  |
| `right`            | Points to the right child of a node                                 |
| `successor`        | Points to the inorder successor during deletion                     |
| `data`             | Stores the book record in a node                                    |

### Example Binary Search Tree

Suppose books with IDs 102, 101, and 103 are inserted into the BST.

```text
          102
         /   \
       101   103
```

In this example, book 102 is the root node, book 101 is its left child, and book 103 is its right child.

Inorder traversal visits the left subtree, the root, and then the right subtree. Therefore, the books are displayed in ascending order of their IDs.

## 5. Features and Menu Options

The application provides the following operations:

| Option | Operation         | Description                                            |
| ------ | ----------------- | ------------------------------------------------------ |
| 1      | Add Book          | Adds a new book record using its ID, title, and author |
| 2      | Search Book by ID | Searches for a book using its unique ID                |
| 3      | Delete Book       | Deletes an existing book record                        |
| 4      | Display All Books | Displays books in ascending order of their IDs         |
| 5      | Count Books       | Displays the total number of book records              |
| 6      | Issue Book        | Marks an available book as issued                      |
| 7      | Return Book       | Marks an issued book as available                      |
| 0      | Exit              | Terminates the application                             |

**Note:** Book issue and return operations update the availability status in memory. The application simulates library record management and does not connect to an external library database.

## 6. Implementation Details

### Insertion

A new book record is created using its ID, title, and author name. The program compares the book ID with the current node's ID.

If the tree is empty, the new node becomes the root. Otherwise, the program moves to the left subtree if the new ID is smaller or to the right subtree if it is greater. This process continues until an empty position is found.

Duplicate book IDs are rejected to maintain unique keys in the BST.

### Searching

The program searches for a book by comparing the requested ID with the ID stored in the current node.

If the IDs match, the book is found. If the requested ID is smaller, the search continues in the left subtree; otherwise, it continues in the right subtree.

If the search reaches a null pointer, the book does not exist in the system.

### Deletion

The program handles the three standard cases of BST deletion:

1. **Node with no children:** The node is deleted directly.
2. **Node with one child:** The node is deleted, and its child takes its place.
3. **Node with two children:** The inorder successor, which is the smallest node in the right subtree, replaces the deleted node's data. The successor is then deleted from its original position.

These operations preserve the Binary Search Tree property.

### Inorder Traversal

The program uses inorder traversal to display book records in ascending order of book IDs.

The traversal follows three steps:

1. Visit the left subtree.
2. Display the current book record.
3. Visit the right subtree.

### Counting Books

The program recursively counts the nodes in the left and right subtrees and adds one for the current node.

The total number of books is calculated as:

`Total = 1 + Left Subtree Count + Right Subtree Count`

If the current node is null, the count is zero.

### Book Issue and Return

When a book is issued, the program searches for its ID and changes its availability status to `Issued`.

When a book is returned, the program searches for its ID and changes the status to `Available`.

The application checks whether a book exists and whether its current status allows the requested operation.

### Memory Management

The program dynamically allocates tree nodes using `new`. When a book is deleted, its node is released using `delete`.

A destructor traverses the remaining tree and releases all dynamically allocated nodes when the library object is destroyed.

## 7. Algorithms and Time Complexity

Let `n` be the number of book records and `h` be the height of the BST.

| Operation         | Average case for a reasonably balanced BST | Worst case |
| ----------------- | ------------------------------------------ | ---------- |
| Add Book          | O(log n)                                   | O(n)       |
| Search Book       | O(log n)                                   | O(n)       |
| Delete Book       | O(log n)                                   | O(n)       |
| Display All Books | O(n)                                       | O(n)       |
| Count Books       | O(n)                                       | O(n)       |
| Issue Book        | O(log n)                                   | O(n)       |
| Return Book       | O(log n)                                   | O(n)       |

The BST requires **O(n) space** to store `n` book records. Recursive tree operations also use stack space proportional to the tree height, O(h).

The project uses an ordinary BST, not a self-balancing BST. Therefore, insertion, searching, deletion, issue, and return operations may take O(n) time in the worst case when the tree becomes skewed.

## 8. Software Setup and Execution

### Prerequisites

* Visual Studio Code or another C++ IDE
* A compatible C++ compiler, such as GCC through MinGW-w64
* The Microsoft C/C++ extension for VS Code (recommended)

### Source Code

Save the program in a file named `main.cpp`.

### Compilation

Open the project folder in VS Code and create a terminal using **Terminal → New Terminal**.

Compile the program using:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o library.exe
```

Run the application in Windows PowerShell using:

```powershell
.\library.exe
```

On Linux or macOS, run the compiled executable using:

```bash
./library
```

If the source file has a different name, replace `main.cpp` with the actual filename.

## 9. Testing and Validation

The following test cases should be executed to verify the application.

| No. | Test Case                            | Expected Result                              |
| --- | ------------------------------------ | -------------------------------------------- |
| 1   | Display books when the tree is empty | An appropriate empty-library message appears |
| 2   | Add a new book                       | The book is inserted successfully            |
| 3   | Add multiple books                   | All unique book records are stored           |
| 4   | Add a duplicate book ID              | The program rejects the duplicate            |
| 5   | Search for an existing book          | The correct book details are displayed       |
| 6   | Search for a nonexistent book        | A book-not-found message appears             |
| 7   | Display all books                    | Books appear in ascending order of IDs       |
| 8   | Count books                          | The correct total is displayed               |
| 9   | Delete a leaf node                   | The selected book is removed                 |
| 10  | Delete a node with one child         | The child is correctly reconnected           |
| 11  | Delete a node with two children      | BST ordering is preserved                    |
| 12  | Issue an available book              | The status changes to Issued                 |
| 13  | Issue an already-issued book         | The program prevents issuing it again        |
| 14  | Return an issued book                | The status changes to Available              |
| 15  | Return an already-available book     | An appropriate message is displayed          |
| 16  | Delete a nonexistent book            | A book-not-found message appears             |
| 17  | Exit the menu                        | The application terminates properly          |

**Testing record:** Execute each test case in your chosen C++ environment, record the actual output, mark the result as Pass or Fail, and capture relevant screenshots. Do not mark a test as passed until it has been executed.

## 10. Binary Search Tree Diagrams

The following diagrams can be included in the `diagrams/` directory to explain the main operations.

1. **Initial BST:** Show a root node with left and right children.
2. **Insertion:** Show the tree before and after inserting a new book ID.
3. **Searching:** Show the path followed when searching for a book ID.
4. **Deletion of a Leaf Node:** Show a leaf being removed.
5. **Deletion of a Node with One Child:** Show how the child replaces the deleted node.
6. **Deletion of a Node with Two Children:** Show the inorder successor replacing the deleted node.
7. **Inorder Traversal:** Show the order in which the nodes are visited to display books in sorted order.

Use clearly labelled nodes and directional arrows. Each diagram should match the algorithms implemented in the source code.

## 11. Repository Structure

The repository can be organized as follows:

```text
SmartLibraryBookManagement/
├── main.cpp
├── README.md
├── .gitignore
├── test_cases.md
├── screenshots/
│   ├── add_book.png
│   ├── search_book.png
│   ├── display_books.png
│   ├── issue_return_book.png
│   └── delete_book.png
└── diagrams/
    ├── 01_initial_bst.png
    ├── 02_insertion.png
    ├── 03_searching.png
    ├── 04_delete_leaf.png
    ├── 05_delete_one_child.png
    ├── 06_delete_two_children.png
    └── 07_inorder_traversal.png
```

The diagram and screenshot filenames are examples. Add these files as you complete the project. The `.gitignore` file should exclude compiled executable files, such as `*.exe`.

## 12. Git and GitHub

Git is used to track changes during development, while GitHub hosts the project repository.

Common commands used to update the repository are:

* `git status` — checks working-tree changes.
* `git add .` — stages changes.
* `git commit -m "Describe the change"` — records a commit.
* `git push` — uploads commits to GitHub.

Example:

```bash
git init
git add .
git commit -m "Initial Smart Library Book Management System"
```

To upload the project to GitHub, create a repository and follow its instructions for connecting the local repository and pushing the code.

**Repository URL:** Add your GitHub repository URL here after creating it.

## 13. Team Contributions

Add the actual details of your project group below.

| No. | Student Name   | Roll Number | Contribution               |
| --- | -------------- | ----------- | -------------------------- |
| 1   | Darade Gayatri |   6016      | BST implementation         |
| 2   | Patil Tejas    |   229       | Testing and validation     |
| 3   | Sarve Anshuman |   242       | Documentation and diagrams |

Each group member should understand the project implementation and be prepared to explain the data structure, algorithms, code, and test cases during the demonstration and viva.

## 14. Conclusion

The Smart Library Book Management System demonstrates the use of a Binary Search Tree to organize and manage library book records. It implements insertion, searching, deletion, inorder traversal, counting, and basic book issue and return operations in a menu-driven C++ application.

The project reinforces important Data Structures and Algorithms concepts, including tree traversal, pointer manipulation, recursive algorithms, dynamic memory allocation, and memory management. Testing different cases helps verify the implementation and prepares students to explain how a BST can be used in a practical library management application.

## 15. Future Scope

The project can be improved in the following ways:

* Add file handling to save book records permanently.
* Store student information and borrower details.
* Add issue dates and return dates.
* Implement overdue-book tracking and fine calculation.
* Add searching by title and author.
* Use an AVL tree to maintain balance and improve worst-case search performance.
* Develop a graphical user interface.
* Add authentication for librarians and administrators.
