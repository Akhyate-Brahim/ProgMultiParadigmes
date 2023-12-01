#ifndef _MENU_ITEM_H_
#define _MENU_ITEM_H_

#include <iostream>
#include <string>
typedef void (*foncPtr)();
using namespace std;

class Menu_Item
{
    string desc;
public:
    foncPtr myFunc;
    Menu_Item(string description, foncPtr ptr) : desc(description), myFunc(ptr) {}
    Menu_Item() {}
    virtual void execute() = 0;
    string getDescription() { return desc; }
};

#endif
