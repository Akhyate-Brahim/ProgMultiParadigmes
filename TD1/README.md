# TD0 - INTRODUCTION
## Review
- ```cpp
    #include <iostream> and #include <string>
    ```
    These are preprocessor directives that include the necessary C++ standard libraries for input and output (iostream), Data Types, Algorithms, iterators, etc.
- `using namespace std;` : This line brings the std namespace into the current scope, allowing you to use objects and functions from the standard library without the std:: prefix. (*the "current scope" refers to the region of your code where a particular variable, function, or symbol is visible and can be accessed without any qualification. It defines the context in which a particular identifier (like a variable or function name) is valid and can be used.*)
- In order to print anything in the std output you do :
    ```cpp
    cout << "anything" << endl;
    ```
cout = character output
endl = end line

- in order, to receive input:
    ```cpp 
    cin >> var;
    ```
- to compile and execute
```bash
g++ -W -Wall palindrome.cpp -o palindrome
./palindrome
```
## Exercise 1 - palindromes

- Dynamic Sizing: std::string can grow or shrink dynamically, eliminating the need for manual memory management.
- Character Access: You can access individual characters using indexing, e.g., str[0].
- String Concatenation: Easily concatenate strings using + operator or append() method.
- String Comparison: Supports various comparison operators like ==, !=, <, >, etc.
- Substring Extraction: Extract substrings using substr() method.
- Length Retrieval: Get the length of a string with length() or size() methods.

## Exercise 2 - moyenne
**ifstream (Input File Stream):**
- Open a File: `ifstream input("file.txt");`
- Check if Opened: `if (input.is_open()) { /* file is open */ }`
- Read Data: `int data; input >> data;`
- Close File: `input.close();`

**ofstream (Output File Stream):**
- Open a File: `ofstream output("file.txt");`
- Check if Opened: `if (output.is_open()) { /* file is open */ }`
- Write Data: `int data = 42; output << data;`
- Close File: `output.close();`

## Exercise 3 - automate
- the `rand()`from the `<cstdlib>` library is a function that generates a random integer.

## Exercise 4 - cmpx
- in both methods, in the arguments we use references, that's because these functions need to use existing variables and manipulate them.
- we had to use the insert function each time whilst creating the list, each time we add an element, we compare it to the elements we have already added, thus the `insert(T x,vect<T> vect)`function is used in the while loop
- **C++ Templates :** in order to be able to use functions with any type, we can precise a template before the function like this in [cmpx.cpp](cmpx.cpp) :
    ```cpp
    template<typename T>
    void insert(T n, vector<T> &vect){
        for (T &element : vect) {
            cmpx(element, n);
        }
        vect.push_back(n);
    }
    ```
    we later precise the type in the main.

# Exercise 5 - bookrecord

- a struct in cpp is similar to the ones in c with the following syntax:
    ```cpp
    struct Bookrecord{
       string nom;
       double somme;
    };
    ```
    and then we can initialize and take any of the fields using:
    ```cpp
    Bookrecord b;
    b.nom="John";
    b.somme=-85.2;
    ```
- We can create a file with structs with each line representing a struct and spaces seperating their fields : [transactions](transactions.txt)

We can go through the elements then by doing the following loop:
```cpp
while (cin >> transactions.nom >> transactions.somme){
    ...
}
```
- input and output operators for a struct allow us to read or print the fields we want of the struct by simply calling the struct itself.

    it allows us to go from this code:
    ```cpp
    cout << b.name << b.somme <<endl;
    ```
    to this:
    ```cpp
    cout << b << endl;
    ```
- the hardest part is the signature of these functions:
    ```cpp
    ostream& operator<< (ostream&o,const Bookrecord &b)
    ```
    - **ostream:** Represents an output stream. Streams are a way to handle sequences of bytes, whether they are characters displayed on the screen (cout) or written to a file.

    *Example: The commonly used cout for console output is an object of the ostream class.*

    - **operator<<:** This is how we indicate that we're overloading the << operator. By doing so, we're giving it a new behavior specifically for our Bookrecord struct.

    - **Overloading:** We're essentially teaching the << operator how to handle a new data type, in this case, our Bookrecord struct. Instead of the compiler throwing an error because it doesn't know how to display a Bookrecord, our overloaded function tells it what to do.
- likewise for The Input Operator (`>>`):

    When dealing with input from streams, we use the `>>` operator. By overloading it, we define how to interpret incoming data for our custom structures.

    **Signature**:
    ```cpp
    stream& operator>> (istream& i, Bookrecord &b)
    ```
    - **istream**:
        - Represents an input stream, like `cin`.
        - **Example**: The `cin` object reads console input and is an instance of the `istream` class.

    - **operator>>**:
        - We're overloading this operator for our `Bookrecord` struct, guiding the compiler on how to read data into a `Bookrecord` object.







