# Pointers in Cpp 2

## Pointer vs Reference
- **Pointers**:
  - Can be initialized to `nullptr`.
  - Can be reassigned to point to another object.
  - Need to be dereferenced (`*ptr`) to access the value they point to.
  - Can point to an array and use pointer arithmetic.
  - More complex, with potential for pointer arithmetic and manual memory management.

- **References**:
  - Cannot be null; must be initialized to a valid object.
  - Cannot be reassigned; always refer to the initially assigned object.
  - Directly access the value they refer to, no dereferencing needed.
  - Cannot be used for array indexing or pointer arithmetic.
  - Typically safer and easier to use, avoiding many pointer-related errors.
## Loss of memory
```cpp
class List{
    Cell *d;
    public:
    // supprime le premier element et le renvoie;
    int get_first(){
        Cell *p = d;
        int r = d->val;
        d = d->next;
        delete p; //déallocation mémoire
        return r;
    }
}
```

## Member functions added by default

```cpp
class A{
    // constructeur par défaut
    // destructeur
    // affectation (chaanger la val d'un objet de type A)
    // constructeur de copie (initialiser un objet de type A avec un autre objet de type A)
}
```

## Copy constructor

```cpp
class A{
    public:
    A(){cout << "constr par défaut";} //constr par défaut

    A(const A& a){cout << "constr de copie";} // constr de copie

    ~A(){cout << "destructeur";} // destructeur

    A &operateur=(const A&a){
        cout << "affectation";
        return *this;
    } // affectation, well there are other operations in these functions, the point here is that they exist by default
}
```

**exemples**:
```cpp
main(){
    A x; // constr par défaut
    A x(); // FAUX
    A y = x; // constr de copie
    A y(x); // meme chose, constructeur de copie
    

    A z; // constr par défaut
    z = y; // operator =
    z.operator=(y); // meme chose, operator =
}
``` 

**Au cours de l'affectation le compilateur, recopie les données membres un par un de l'objet y vers l'objet z.**

### Affectation et pointeur 
l1 et l2 des List avec des attributs de début et fin qui pointe vers des Cell
```cpp
List l2;
l2 = l1;
l1.get_first(); // avec une désallocation
// !! l2.debut PLUS VALIDE
// en effet, les deux listes pointent vers le memes cellules, puisque les deux pointeurs qui sont recopié par l'opérateur = par défaut pointent aux memes emplacements mémoires
```
***solution***:
- redéfinir l'opérateur d'affectation '=' pour qu'on puisse effectivement crée des nouvelles cellules. 

## Héritage public vs private

- public : on garde l'interface de la classe de base. public -> public

- private : on perd l'interface de la classe de base. En effet, les membres public de la classe de base deviennent private. public -> private

**L'héritage private** traduit le faite que la classe de base est une implémentation possible de la classe dérivée.

**Exemple**: Pile LiFo bornée
```cpp
class Pile : private vector<int>
{
    int nbelem;
    public:
    Pile(int taille) : vector<int>(taille), nbelem(0){}
    void push(int n){
        (*this)[nbelem++] = n;
        // vérifier qu'on dépasse pas la taille de la pile
    }
    void pop(){
        return (*this).[--nbelem];
    }
    bool is_empty(){
        return nbelem==0;
    }
}

int main(){
    Pile p(10);
    p.push(100);
    cout << p.pop();
    cout << p[2]; // KO
}
```
**l'héritage private dans ce cas assure la préservation des proprietés de la classe dérivée dans leur cadre et capacité**
