#include "list_simple.h"

ostream &operator<<(ostream &o, List list)
{
    for (Element* current = list.base; current != nullptr ; current = current->next){
        o << current->data << " ";
    }
    return o;
}

void List::append(int i)
{
    Element* element = new Element(i);
    if (is_empty()){
        base = element;
        return;
    }
    Element* current = base;
    while(current -> next != nullptr){
        current = current->next;
    }
    current->next = element;

}

void List::prepend(int i)
{
    Element* newBase = new Element(i);
    newBase->next = base;
    base = newBase;
}

bool List::is_empty()
{
    return base == nullptr;
}

int List::get_first() {
    if (base == nullptr) {
        throw new EmptyListException();
    }
    int firstElement = base->data;
    Element* toDelete = base;
    base = base->next;
    delete toDelete;
    return firstElement;
}

void List::insert(int i)
{
    Element* element = new Element(i);
    if (is_empty()){
        base = element;
        return;
    } 
    Element* current = base;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = element;

}
