#include "list-copy.h"

ostream &operator<<(ostream &o, const List &list) 
{
    for (Element* current = list.start; current != nullptr; current = current->next) {
        o << current->data << " ";
    }
    return o;
}



void List::append(int i)
{
    Element* element = new Element(i);
    if (is_empty()) {
        start = end = element;
    } else {
        end->next = element;
        end = element;
    }
}


void List::prepend(int i) 
{
    start = new Element(i, start);
    if (end == nullptr) {
        end = start;
    }
}


bool List::is_empty()
{
    return start == nullptr;
}


int List::get_first()
{
    if (is_empty()) {
        throw new EmptyListException();
    }
    int firstElement = start->data;
    Element* toDelete = start;
    start = start->next;
    if (start == nullptr) {
        end = nullptr;
    }
    delete toDelete;
    return firstElement;
}


int List::get_last() 
{
    if (is_empty()) {
        throw new EmptyListException();
    }
    if (start == end) {
        int lastElement = start->data;
        delete end;
        start = end = 0;
        return lastElement;
    }
    Element* current = start;
    while (current->next != end) {
        current = current->next;
    }
    int lastElement = end->data;
    delete end;
    end = current;
    end->next = nullptr;
    return lastElement;
}


void List::insert(int i) 
{
    if (is_empty() || i <= start->data) {
        prepend(i);
        return;
    }
    if (i >= end->data) {
        append(i);
        return;
    }
    Element* element = new Element(i);
    Element* current = start;
    while (current->next != nullptr && current->next->data < i) {
        current = current->next;
    }
    element->next = current->next;
    current->next = element;
}


void List::sort() 
{
    List sortedList;
    while (!is_empty()){
        int i = get_first();
        sortedList.insert(i);
    }
    *this = sortedList;
}


int List::get_middle_value()
{
    if (is_empty()){
        throw new EmptyListException();
    }
    Element* slow = start;
    Element* fast = start;
    while(fast->next != 0 && fast->next != 0){
        slow = slow->next;
        fast= fast->next->next;
    }
    return slow->data;
}


int &List::max() 
{
    if (is_empty()) {
        throw new EmptyListException();
    }
    int* max = &(start->data);

    for (Element* current = start->next; current != nullptr; current = current->next) {
        if (current->data > *max) {
            max = &(current->data);
        }
    }
    return *max;
}


void List::mirror() 
{
    if (is_empty() || start == end) {
        return;
    }
    Element *prev = nullptr, *next = nullptr;
    for (Element* current = start; current != nullptr; current = next) {
        next = current->next;
        current->next = prev;
        prev = current;
    }

    end = start;
    start = prev;
}


List::List(const List &list) : start(nullptr), end(nullptr) {
    Element* ptr = list.start;
    while (ptr != nullptr) {
        append(ptr->data);
        ptr = ptr->next;
    }
}

List& List::operator=(const List &list) {
    this->~List();
    new (this) List(list);
}

List::~List() {
    Element* current = start;
    while (current != nullptr) {
        Element* next = current->next;
        delete current;
        current = next;
    }
    start = end = nullptr;
}

List List::operator+(const List &list) {
    List result(*this);

    for (Element* ptr = list.start; ptr != nullptr; ptr = ptr->next) {
        result.append(ptr->data);
    }

    return result;
}

List List::operator*(const List &other) {
    List result;
    Element* ptr1 = this->start;
    Element* ptr2 = other.start;

    while (ptr1 != nullptr && ptr2 != nullptr) {
        result.append(ptr1->data);
        result.append(ptr2->data);

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return result;
}

