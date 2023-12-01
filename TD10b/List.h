#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class List {
private:
    struct Cell {
        T val;
        Cell *next;
        Cell(T v, Cell *n = nullptr) : val(v), next(n) {}
    };

    Cell *head;
    Cell *tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    ~List() {
        Cell *current = head;
        while (current != nullptr) {
            Cell *next = current->next;
            delete current;
            current = next;
        }
    }

    List(const List& l) : head(nullptr), tail(nullptr) {
        Cell *current = l.head;
        while (current != nullptr) {
            append(current->val);
            current = current->next;
        }
    }

    List& operator=(const List& l) {
        if (this != &l) {
            Cell *current = l.head;
            while (current != nullptr) {
                append(current->val);
                current = current->next;
            }
        }
        return *this;
    }

    void append(T v) {
        Cell *p = new Cell(v);
        if (head == nullptr) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    void prepend(T v) {
        Cell *p = new Cell(v);
        if (head == nullptr) {
            head = tail = p;
        } else {
            p->next = head;
            head = p;
        }
    }

    void insert(T e) {
        Cell *p = head, *prev = nullptr;
        while (p != nullptr && p->val < e) {
            prev = p;
            p = p->next;
        }
        Cell *newCell = new Cell(e, p);
        if (prev == nullptr) {
            head = newCell;
        } else {
            prev->next = newCell;
        }
        if (p == nullptr) {
            tail = newCell;
        }
    }

    T get_first() {
        if (head == nullptr) throw std::runtime_error("List is empty");
        T val = head->val;
        Cell *temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return val;
    }

    bool is_empty() const {
        return head == nullptr;
    }

    T get_middle_value() const {
        if (is_empty()) throw std::runtime_error("List is empty");
        Cell *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->val;
    }

    friend ostream& operator<<(ostream& os, const List<T>& list) {
        for (Cell *p = list.head; p != nullptr; p = p->next) {
            os << p->val << ' ';
        }
        return os;
    }
};
#endif
