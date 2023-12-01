#ifndef _WALKING_ITEM_
#define _WALKING_ITEM_

#include "menu.h"
#include "menu_item.h"

class Walking_Menu : public Menu_Item , public Menu{
    public:
    Walking_Menu(string s, vector<Menu_Item*> v) : Menu(s, v){}
    void execute(){activate();}
};

#endif