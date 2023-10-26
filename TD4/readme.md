# TD4

## Constructeurs de conversion

- example from the last lab:
```cpp
cout << (d1 == d2); // OK, operator==
cout << (d1 == 212697); // OK
cout << (2126697 == d1); // KO conversions automatiquement seulement sur les argc explicites
``` 
the second Boolean operation works as expected due to the existence of a conversion constructor in the Date class. A ***conversion constructor*** is a special type of constructor in C++ that can be called with a single argument. It enables implicit conversion of the argument type into the object type of the class.
in order for this implicit conversion to not happen, we add the keyword ***explicit*** to the constructor that will get evoked:
```cpp
explicit Date(int n);
// in this case, the correct bool expression is:
cout << (Date(545428) == d1);
```

*  ways to use friend functions:
    -  syntaxic reasons (<< and >> operations)
    -  overriding certain operators to allow interchangibility, as using member functions allows only in one sense.

- common error : **ambiguous call**
```cpp
Class A{
    public:
    A(int n){...}
}
class B{
    public:
    B(int n){...}
}
int fonc(A a);
int fonc(B b);
main(){
    cout << fonc(123); // KO appel Ambigue
}
```
here the compiler cannot tell which conversion to use, A or B as they both convert the int.
solution:
 - mark the function you don't want to use as **explicit**
 - call the constructor needed explicitly:
 ```cpp
 cout << fonc(A(123)); // OK appel explicite
 ```   
 ## initialization operator

 - in order to initialize members properly and not assign using the '=' operator we should use the ':' initialization operator in the constructor using the following syntax:

 ```cpp
 class Segment{
    Point depart;
    Point arrivee;
    public:
    Segment(Point p, Point q) : depart(p), arrivee(q) {}
 }
 ```
 - **error case 1**
 ```cpp
 Class Point{
    int x,y;
    public:
    Point(int a, int b) : x(a), y(b){}
    // NO DEFAULT CONSTRUCTOR (without arguments)
 }
 class Segment{
    Point depart;
    Point arrivee;
    public:
    Segment(Point p, Point q)
    {
        depart = p;
        arrivee = q; 
    }
    // WRONG
 }
 ```
 depart and arrivee are actually initialized before the affectation, and by default they need to be initialized using the default constructor Point() which we dont have --> ***ERROR***

**the intialization constructor is the most efficient tool of initializing, because the usual java syntax actually intializes our data before, then it affects it to the parameters.**

- **error case 2 : const member**
```cpp
 class Segment{
    const Point depart;
    Point arrivee;
    public:
    Segment(Point p, Point q)
    {
        depart = p;
        arrivee = q; 
    }
    // WRONG
 }
```
You cannot modify a const member after initializing it, depart is implicitly initialized using the default constructor before the affectation.

- **error case 3**
```cpp
class Segment{
    Point depart, arrivee;

    public:
    Segment(Point p, Point q){
        Point depart(p);
        Point arrivee(q);
    }
}
```
incorrect, inside the constructor we actually create new Point local objects, therefore our members are not even initialized.
