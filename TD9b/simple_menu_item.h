#ifndef _SIMPLE_MENU_ITEM_H_
#define _SIMPLE_MENU_ITEM_H_


#include <iostream>

class Simple_Menu_Item : public Menu_Item
{
    public:
    Simple_Menu_Item(string s, foncPtr ptr) : Menu_Item(s, ptr){}
    void execute(){
        (*myFunc)();
    }
};


#endif