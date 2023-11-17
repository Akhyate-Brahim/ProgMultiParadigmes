#include <iostream>
using namespace std;

int do_something(string s)
{
	int i=06;
	s = s+'!';
	return i;
}


int main()
{
	string s = "toto";
	cout << s << endl;

	int i=33;
	do_something(s);
	cout << s << endl; // affiche "toto" car do_somethign(string s) passe par valeur, donc un nouveau string de meme valeur que s est crée lors de l'appel de do_something avec un autre emplacement mémoire
	cout << i << endl; // affiche 33, en effet do_something crée un nouveau objet int et le retourne

	int  j=29;
	j=do_something(s);
	cout << s << endl; // affiche "toto" car do_somethign(string s) passe par valeur
	cout << j << endl; // affiche 6 car on affecte la valeur de retour de do_something à j

	return 0;
}
