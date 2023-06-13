#include <iostream>   // Predefined functions and classes
#include <cmath>
#include <fstream>    // File I/O operations
#include <memory>
using namespace std;  // Namespace for avoiding naming conflicts between libraries

// Global variables
double x;
double result;
const double constantValue = 10.3; //cannot change is always constant
bool condition = false;
int numbers[] = {1, 2, 3, 4, 5}; // Declaration and initialization of array
int arraySize = sizeof(numbers) / sizeof(numbers[0]); // Get array size

// Structures
// Structures allow you to grop together multiple variables under same name
struct Person {
    string name;
    int age;
};

// Classes
class Rectangle {
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int calculateArea() {
        return width * height;
    }
};

// Function prototypes
void solve(); //function prototypes before they are used and call this before int main()
void print();
int add(int a, int b);
template <typename T>
T maximum(T a, T b);
void exceptionHandling();
void fileIO();
void pointersAndDynamicMemory();

int main() {   //main intialize
    solve();
    print();
    fileIO();
    pointersAndDynamicMemory();

    cout << "Press any key to exit..."; //display output
    cin.ignore();
    cin.get(); //any key pressed returned

    return 0;
}

// Function to demonstrate various concepts
void solve() {
    cout << "Your last name: "; //display output
    string lastName;
    cin >> lastName;  //read input

    cout << "Enter a number: "; //display output
    cin >> x; //read input
    cout << "You entered: " << x << endl; //display output

    // Calculate the sine of x
    result = sin(x);

    // Conditional statement
    if (condition) {
        /* if condition is true */
    } else {
        /* if condition is false */
    }

    // For loop example
    for (int i = 0; i < arraySize; i++) {
        cout << "Element at index " << i << ": " << numbers[i] << endl;
    }

    // While loop example
    while (condition) {
        // Execute something while condition is true
    }

    // Do-while loop example
    do {
        // Execute something at least once, then repeat while condition is true
    } while (condition);

    // Call the exception handling function
    exceptionHandling();
}

// Function to print the result
void print() {
    cout << "The sine of " << x << " is " << result << endl;
    cout << "The end!" << endl;
}

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function template to find the maximum of two values
// Template can be used for multiple data types
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Function to demonstrate exception handling
void exceptionHandling() {
    try {
        // Code that might throw an exception
        throw std::runtime_error("An error occurred.");
    } catch (const std::runtime_error& e) {
        // Code to handle the exception
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

// Function to demonstrate file I/O operations
void fileIO() {
    ofstream outputFile("output.txt"); //make file then read whats putted and in there

    if (outputFile.is_open()) {
        outputFile << "This is some sample text." << endl;
        outputFile.close();
    } else {
        cout << "Unable to open the file." << endl;
    }

    ifstream inputFile("input.txt");  //find file then read it

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "Unable to open the file." << endl;
    }
}

// Function to demonstrate pointers and dynamic memory allocation
void pointersAndDynamicMemory() {
    // Pointer example
    int* ptr = nullptr;  // Declare a pointer and initialize it to nullptr (pointer with no explicit address)
    int value = 5;  // Declare an integer variable
    ptr = &value;  // Assign the address of 'value' to the pointer

    cout << "Value: " << value << endl;
    cout << "Pointer: " << ptr << endl;
    cout << "Dereferenced Pointer: " << *ptr << endl;  // Dereference the pointer to access the value

    // Dynamic memory allocation example
    int* dynamicPtr = new int;  // Allocate memory for an integer on the heap
    *dynamicPtr = 10;  // Store a value in the dynamically allocated memory
    cout << "Dynamic Pointer: " << dynamicPtr << endl;
    cout << "Dereferenced Dynamic Pointer: " << *dynamicPtr << endl;

    // Unique pointer example (unique pointer automatically deletes when out of scope)
    unique_ptr<int> uniquePtr(new int);  // Create a unique pointer and allocate memory for an integer
    *uniquePtr = 20;  // Store a value in the dynamically allocated memory
    cout << "Unique Pointer: " << uniquePtr.get() << endl;
    cout << "Dereferenced Unique Pointer: " << *uniquePtr << endl;

    // Shared pointer example (shared pointer automatically deletes when out of scope)
    shared_ptr<int> sharedPtr = make_shared<int>(30);  // Create a shared pointer and allocate memory for an integer
    cout << "Shared Pointer: " << sharedPtr.get() << endl;
    cout << "Dereferenced Shared Pointer: " << *sharedPtr << endl;

    // Weak pointer example
    weak_ptr<int> weakPtr = sharedPtr;  // Create a weak pointer from the shared pointer
    cout << "Weak Pointer Expired: " << weakPtr.expired() << endl;  // Check if the weak pointer is expired

    // Deallocate the dynamically allocated memory to avoid memory leaks
    delete dynamicPtr;  // Remove this line when using smart pointers
}

