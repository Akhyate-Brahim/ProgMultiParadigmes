#include <iostream>
using namespace std;

string * do_something(string s) 
{
	string *pt_s=&s; 
	s = s+'!';
	return pt_s;
}
/* s passé par valeur, 
un nouveau string locale est créé.
puis un pointeur qui pointe vers ce nouveau string est retourné.
Donc le pointeur rendu n'est pas valide, puisqu'il pointe vers un objet local.
*/
int main()
{
	string s = "toto";
	cout << s << endl; // "toto"

	do_something(s); 
	cout << s << endl; // "toto"

	string *pt_s = do_something(s);
	cout << pt_s << endl; // KO, addresse vers une variable local
	cout << (*pt_s) << endl; // KO, déréference vers un objet qui n'existe plus

	return 0;
}
