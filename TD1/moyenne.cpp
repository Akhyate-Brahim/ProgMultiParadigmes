#include <iostream>
#include <fstream>
using namespace std;
int main(){
   ifstream inputFile("moyenne.txt");
   int i=0;
   int s=0;
   int n;
   cout <<"the numbers are in the moyenne.txt file"<<endl;
   while (inputFile >> n && i<10){
    s+=n;
    i++;
   }
   cout << "the sum of these numbers is : " <<s<<"\nthe mean of these numbers is : "<<(double)s/i<<endl;
}