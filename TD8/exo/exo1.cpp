#include <iostream>
using namespace std;

int main()
{
	string s = "toto";
	cout << s << endl;

	string *pt_s; 
	// ça compile
	cout << (*pt_s) << endl; // le pointeur est non initialisé !!
	cout << pt_s << endl; // affiche n'importe quelle addresse (si deja affecté, elle donne l'addresse auquel le pointeur pointe)
	cout << &pt_s << endl; // affiche l'addresse du pointeur, donc pas de probleme

	pt_s = &s;
	cout << pt_s << endl; // affiche l'addresse du string s
	cout << &pt_s << endl; // affiche l'addresse du pointeur

	return 0;
}
