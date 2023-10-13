# Cpp - TD5

## Exceptions

- in cpp, an exception does not have its own type, you can define it as an int, string, another class, etc.

    example:
    ```cpp
    class MVector{
        vector<double> data;
        ...
        public:
        class Bad_Index{}; // at least a default constructor
        double operator[](int i) const{
            if (i<0 || i>= data.size())
                throw Bad_Index();
        }
        ...
    };
    ```
    then in the main 
    ```cpp
    main(){
        ...
        try{
            // use the function that can throw the exception
        } catch(MVector::Bad_Index bi){
            ...
        }
    }
    ```

## Usage of the reference operator

- only use `&` on an argument when you have to modify the object passed as argument.

**error case :**

```cpp
friend ostream& operator<<(ostream& o,MVector &mv); // WRONG

main(){
    MVector mv1(...);
    MVector mv2(...);
    cout << mv1; // OK
    cout << (mv1 + mv2); // ERROR: (mv1 + mv2) NOT A REFERENCE
}
```
**solution** : 
```cpp
ostream& operator<<(ostream& o, const MVector &mv); // for efficiency reasons
ostream& operator<<(ostream& o, MVector mv); 
```
- `const &`: Allows binding of temporary objects, suitable for expressions like `cout << mv1 + mv2`.
- `&`: Non-const lvalue references cannot bind to temporaries, causing compile errors for such expressions.

passing the MVector object by value implies copying the whole object again because you use a constructor.

### modifying objects through references

- we can return reference of objects that can eventually be modified
```cpp
int &max(vector<int> v){
    ...
    return v[m];
}

main(){
    vector<int> w;
    ...
    cout << max(w);
    max(w) = 200; // max returns a reference
}
```


- In the following code, `int &r = n;` creates a reference `r` that acts as an alias for the integer variable `n`, meaning both `r` and `n` point to the same memory location; thus, modifying `r` also changes the value of `n`.

```cpp
main(){
    int n=3;
    int &r = n; // init
    cout << r; // 3
    r = 5;
    cout << n; // 5 
}
```

- `const` here makes the implicit argument `*this` constant. 
```cpp
double operator[](int i) const {...}
```
## Conversion constructors

- `Date(int n)` **converts int --> Date**

     `Rat(int n)` **converts int --> Rat**

- how can we convert from Rat to double? We use the conversion operator :
```cpp
// conversion operatos from double to Rat
class Rat{
    ...
    operator double(){
        return (double) num / denom;
    }

}

main(){
    Rat r(2,3);
    cout << double(r);
}
```

- Of course, once again, to prevent automatic conversion using a conversion operator, you can mark them as **`explicit`**