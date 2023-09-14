# TD1 - INTRODUCTION
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
g++ -o palindrome palindrome.cpp
./palindrome
```
