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