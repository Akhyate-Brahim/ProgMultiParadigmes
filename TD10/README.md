# TD10 - cpp

## Héritage et droits d'acces:

- for a public attribute x in class A:
    - if i have a class B has public inheritance from A, x stays public
    - if i have a class B has protected inheritance from A, x stays protected
    - if i have a class B has private inheritance from A, x stays private

- une fois une donnée membre est private elle devient inaccessible qlq soit le type d'héritage.

- l'héritage peut réduire les droits d'acces mais jamais les augmenter.

## Conversion et pointeur

```cpp
class Figure{};
class Cercle : public Figure{
    public:
    int rayon;
};
```
```cpp
main(){
    Figure* ptr;
    ptr = new Cercle(..); // new REND une POINTEUR (dans ce cas sur un cercle)
    cout << ptr->rayon; // KO, le compilateur prend le type statique par défaut
    cout << dynamic_cast<Cercle*>(ptr)->rayon;
}
```
`dynamic_cast` assure que le type du pointeur est son type dynamique, dans ce cas `Cercle`.

- `static_cast`: Cannot be used to downcast `Figure*` to `Cercle*` in your code because it does not check type compatibility at runtime.

- `dynamic_cast`: Safely downcasts `Figure*` to `Cercle*`, allowing access to `Cercle` specific members like `rayon`. Checks type at runtime; returns `nullptr` if the cast is invalid.


```cpp
main(){
    Figure f;
    f.dessiner(); // Figure's func
    Cercle c;
    Figure& f = c; // init d'une référence
    f.dessiner(); // cercle
}
```

***L'opérateur typeid***
```cpp
class type_info
{
    public:
    const char* name() const;
};
Figure *ptr = new Rectangle(..);
cout << typeid(*ptr).name(); // -> Rectangle
```

## Virtual functions - abstract, interface and polymorphic classes
if Figure is abstract : **it has at least one purely virtual member function**
```cpp
class Figure{
    virtual void dessiner() = 0;
    ...
}
```
Donc on a:

```cpp
main(){
    Figure f; // KO , Figure est abstraite
}
```

**Classe interface** : cette classe ne contient que des fonctions purement virtuelles


**Classe polymorphe** :  cette classe contient au moins une fonction virtuelle (not necessarily purely)


## Les modeles (de fonctions ou de classes) - templates

**template of a function**
```cpp
template<typename T>
T min(T p, T q){
    return p > q ? q : p;
}


main(){
    cout << min<int>(10,20); // -> 10
    cout << min<string>("brahim", "cpp"); // -> brahim

    // on peut meme ecrire avec la plupart des compilateurs:
    cout << min(10,20);
}
```

**template of a class**
```cpp
// in .h
template<typename T>
class Paire{
    T a;
    T b;
    public:
    T proj1() const;
};
#include "fichier.cpp" // Pas de compilation séparée
```
```cpp
//impl dans le cpp
template<typename T>
T Paire::proj1() const{
    return a;
}

main(){
    Paire<int> p(..);
}
```



























