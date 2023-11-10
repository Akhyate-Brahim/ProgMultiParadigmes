# TD7

## function declaration

```cpp
int fonc(string s="hello", int n=2, char c='A'); // 4 fonctions "fonc" (3,2,1 et 0 args)
int fonc(string s, int n); // KO, already declared
int fonc(string s="hello", int n, char c); // KO, compiler refuses, all arguments need to be given a default value, or none
```
## output stream and references

```cpp
ostream& operator<<(ostream&os, const Matrix& m);// &os pour modifier l'arg, const Matrix& pour efficacité
```
Why does this function return an `ostream&`?

-> `(cout << mat) << mat2;`

- en effet, l'opérateur `<<` est un opérateur avec effet de bord (change l'état de la mémoire);
- autre opérateur, ++, =.

## Les Pointeurs en C++

### Rappel

**!!** l'opérateur **`*`** sert à deux distinctes opérations:

- Déclarer un pointeur : `int* ptr;` **POINTEUR VERS UN INT**
- Déréferencer un pointeur : `(*ptr);`

Question sur l'ordre des opérateurs en exam final.

- Ex canonique "swap"

    ```cpp
    void swap(int* p, int* q){
        int tmp = *p;
        *p = *q;
        *q = tmp;
    }

    main(){
        int a = 1;
        int b = 2;
        swap(&a, &b);
    }
    ```
    faire un diagramme d'objet en exam (petit diagramme avec des cases)

### Allocation dynamique

```cpp
class A{
    ...
};

main(){
    A* ptr; // pointe vers rien, car A non initialisé
    ptr = new A; // Allocation MEM + constructeur par défaut
    ptr = new A(2,3); // Allocation MEM + constr A(int, int) + durée de vie  jusqu'appel de l'opérateur delete

    A a; // durée de vie limitée au bloc - variable locale
}
```
### More on syntax
```cpp
struct cell{
    int val;
    cell* next;
    Cell(int n=0, Cell *ptr=0) : val(n), next(ptr){}
}
main(){
    cell* debut;
    debut = new Cell(12);
    debut = new Cell(24, debut); // prepend(24) debut devient 24, le deuxieme élément est 12, et le troisieme est 0.
    
    cout << (*debut).val; // syntaxe de C, valide avec C++
    cout << debut->val; // syntaxe C++, meilleur
    cout << (debut->next)->val; // valeur du prochain élément
}
```

### Contre exemple classique
```cpp
class List{
    Cell* debut;
    public:
    bool is_empty(){return debut==0;}
}
void prepend(int i){
    debut = new Cell(i, debut);
}
```