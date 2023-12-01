# TD9 - Conversion et héritage

## Conversion par troncation d'objet

```cpp
class B : public A
{
...
}

main()
{
B unB; // type statique
A unA = unB; // conversion de B ---> A 
// A unA (type statique)
}
```

- `unA = unB` **conversion par troncation** en effet, A recopie tout les membres dont il partage avec B et les membres restants dans B sont supprimés.
## Conversion en utilisant des pointeurs
exemple 2:

```cpp
    main(){
        B unB;
        A *ptr = &unA; // type statique A* pointeur vers un objet de type A
        ptr = &unB;
    }
```
- type statique de ptr : pointeur vers A = A*
- type dynamique de ptr : au début c'est A*, puis B *. en effet **le type dynamique dépend du type de l'objet dont l'addresse est stockée.**

## Fonctions virtuelles

```cpp
class Figure()
{
    ...
    public:
    void draw(){
        // dessin par défaut
    }
}
class Triangle : public Figure
{
    public:
    void draw(){
        // dessin d'un triangle
    }
}
class Rectangle : public Figure
{
    public:
    void draw()
    {
        // dessin rectangle
    }
}
```
**and then in the main**

```cpp
int main()
{
    vector<Figure*> v;
    v.push_back(new Triangle(...));
    v.push_back(new Rectangle(...));
    ...
    for (int i = 0; i < v.size(); i++)
    {
        v[i]->draw(); 
        /* 
        * type statique est Figure*
        * type dynamique correspond au type de figure (Triangle* , Rectangle* ...)
        */
    }
}
```
- **AMBIGUITÉ**, ici le compilateur peut choisir soit le type dynamique ou le type statique.
- **Par défaut** le compilateur utilise le type **statique**
- Le mot clé **virtual** engendre le compilateur à utiliser le type dynamique du pointeur

```cpp
class Figure
{
    ...
    public:
    virtual void draw(){
        // dessing;
    } // type dynamique
}
class Triangle : public Figure
{
    public:
    virtual void draw(){
        // dessin Triangle
    }
}
```
- Mettre virtual dans les classes filles est une question de présentation. **Tout les implémentations de draw() dans les classes filles sont automatiquement virtual.**

- On peut avoir une fonction **purement virtuelle** (la fonction n'a pas une implémentation dans la classe Figure)
- ****Une classe en C++ est **abstraite** quand elle a **au moins** une fonction purement virtuelle.****

```cpp
class Figure
{
    public:
    virtual void draw() = 0; // purement virtuelle
    // autre fonctions..
}
```

- Figure ici est abstraite.
```cpp
Figure f; // KO, Figure abstraite
Figure *f = new Triangle(...); // OK
```
## Héritage private et protected
```cpp
class Tab : public vector<int>
{
    protected: // instead of private
    int nbacc;
    public:
    Tab(int n) : vector<int>(n), nbacc(0){}
    int &operator[](int i)
    {
        nbacc++;
        return (*this)[i];
    }
    int getnbacc() const
    {
        return nbacc;
    }
}

class Pile : private Tab
{
    int nbelem;
    public:
    Pile(int n) : Tab(n), nbelem(0){}
    void push(int v)
    {
        (*this)[nbelem] = v;
        nbelem++;
    }
    int pop(){
        nbelem--;
        return (*this)[-nbelem];
    }
    bool is_empty()
    {
        nbacc++;
        return nbelem == 0;
    }
}
```

- le mot clé protected nous permet d'accéder à la donnée membre `nbacc` qui devient **private** dans le classe Pile.

**Remarque**:

Héritage Public :

Les membres public de la classe de base restent public dans la classe dérivée.
Les membres protected de la classe de base restent protected.
Les membres private de la classe de base ne sont pas accessibles directement par la classe dérivée, mais ils sont toujours hérités en tant que partie intégrante de l'objet.
Héritage Protected :

Les membres public et protected de la classe de base deviennent protected dans la classe dérivée. Cela permet à la classe dérivée et à ses sous-classes d'y accéder, mais pas aux autres parties du programme.
Les membres private de la classe de base ne sont pas accessibles dans la classe dérivée, tout comme dans l'héritage public.
Héritage Private :

Tous les membres hérités (qu'ils soient public ou protected) deviennent private dans la classe dérivée, ce qui signifie qu'ils ne sont accessibles que dans le contexte de cette classe dérivée spécifique.
Les membres private de la classe de base restent inaccessibles à la classe dérivée, comme pour les autres types d'héritage.