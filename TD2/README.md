# Reminder

```cpp
void swap(int &p, int &q){
    int tmp=p;
    p=q;
    q=tmp;
}
main(){
    int a=1,b=2;
    swap(a,b);
}
```
- the '&' character indicates that we pass the variables in the function with references and not actual values

- dans une classe, les fonctions membres prennent un argument de plus qui est implicite, c'est l'objet courant.

# HEADER FILES IN CPP

## The structure

- rat.h (declarations)
- rat.cpp (implementations)
for instance our class Rat with the **header file rat.h:**
```cpp
#ifndef RAT_H
#define RAT_H
class Rat{
// par defaut les membres sont private
    int num;
    int denum;
public:
    Rat(int p,int q);
    Rat operator-();
    friend ostream& operator<<(ostream&o,Rat r);
}
#endif
```
**then in rat.cpp:**
```cpp
#include "rat.h"

Rat::Rat(int p, int q){//your code}

Rat Rat::operator-(){// your code}

ostream& operator<<(ostream&o,Rat r) {// your code}

```
- the include statement is necessary
- You need to indicate with Rat:: that you are defining the member functions of the Rat class, *friend functions are not member functions.*

## Compilation

```shell
g++ -c rat.cpp --> rat.o
g++ -c main_rat.cpp --> main_rat.o
g++ rat.o main_rat.o -o main_rat.exec --> main_rat.exec
```

## Makefile

```makefile
FLAG = -W -Wall
CXX = g++

main_rat.exec : rat.o main_rat.o
    $(CXX) rat.o main_rat.o

rat.o : rat.h rat.cpp
    $(CXX) -c $(FLAG) rat.cpp

main_rat.o : main_rat.cpp rat.h
    $(CXX) -c $(FLAG) main_rat.cpp

```
then 
```shell
make main_rat.exe
ou bien
make
```
    
