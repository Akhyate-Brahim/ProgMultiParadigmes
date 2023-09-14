#include <iostream>
using namespace std;
int main(){
    int num1,num2,num3,num4,num5,num6,num7,num8,num9,num10;
    cout << "enter 10 numbers seperated by spaces" << endl;
    cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9 >> num10;
    int sum=num1+num2+num3+num4+num5+num6+num7+num8+num9+num10;
    double moyenne=sum/10;
    cout << "the sum : " <<sum<<"\nthe mean : "<<moyenne<<endl;
    return 0;
}