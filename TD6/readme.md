# TD6 - Inheritance

## Inheritance rules
4 common rules for all types of inheritance.

0. We inherit from all members
1. Private members of the base class become non accessible.
    ```cpp
    class A {
        private: 
        int n; 
        public:
        int getn(){
            return n;
        }
        ...
        }
    class B : public A {
        fonc(){
            cout<< n; // KO
            cout << getn(); // OK
            }
    }
    ```
2. Access rights stay the same or get more strict.
3. Usually, he default constructor of the base class is called.
    ```cpp
    class A{
        public:
        A() {...}
        A(int n){...}
    }
    class B : public A {
        public : 
        B() {...} // A() is called
        B(int n) : A(n); // A(int n) called
    }
    ```

### types of inheritance
- public
    ```cpp
    class Point{
        int x,y;

    }
    class Pixel : public Point{
        string color;
        ...
    }
    ```
    un pixel est un point **particulier**, conversion pixel en point par troncation
- private

