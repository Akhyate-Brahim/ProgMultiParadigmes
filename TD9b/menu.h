#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include "menu_item.h"
#include <vector>
using namespace std;

typedef void (*foncPtr)();

class Menu{
    string menuTitle;
    vector<Menu_Item*> v;
    public:

    Menu(string s, vector<Menu_Item*> vec) : menuTitle(s), v(vec){}
    
    
    void activate();
};

#endif