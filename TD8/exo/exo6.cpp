#include <iostream>
using namespace std;

string do_something(string &s)
{
	s = s+'!';
	return s;
}
// do_something prend une référence, donc opere sur la meme string sur ça meme case memoire passée en para
int main()
{
	string s = "toto";
	cout << s << endl;

	do_something(s);
	cout << s << endl; // "toto!"

	string s2 = do_something(s);
	cout << s2 << endl; // "toto!!"

	cout << &s << endl;
	cout << &s2 << endl;
	// &s et &s2 sont differentes, en effet s2 est un string different
	return 0;
}
