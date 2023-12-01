#include "menu.h"

void Menu::activate(){
    int choice;
    cout << menuTitle << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << i << "- " << v[i]->getDescription() << endl;
    }

    cout << "Your choice? ";
    cin >> choice;

    if (choice >= 0 && choice < v.size()) {
            v[choice]->execute();
    } else {
            cout << "Invalid choice" << endl;
    }
}