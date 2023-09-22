#include <iostream>
#include <sstream>
using namespace std;
class Rat
{
public:
    Rat() : num(0), denum(1){}
    Rat(int n) : num(n), denum(1){}
    Rat(int n, unsigned int d){
        if (d <= 0) {
            throw runtime_error("Denominator cannot be equal or inferior to zero!");
        }
        int pgcd = gcd(d,n);
        num=n/pgcd;
        denum=d/pgcd;
    }
    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int getNum(){
        return num;
    }
    unsigned int getDenum(){
        return denum;
    }
    Rat operator +(Rat r){
        int p = num*r.denum + r.num*denum;
        int q = r.denum * denum;
        Rat r9(p,q);
        return r9;
    }
    Rat operator -() {
        return Rat(-num, denum);
    }
    Rat operator -(Rat r){
        Rat negated = -r;
        return *this + negated;
    }
    Rat operator ++(){
        Rat one(1,1);
        return *this + one;
    }
    Rat operator ++(int){
        Rat original = *this;
        Rat one(1,1);
        *this = *this + one;
        return original;
    }
    Rat operator *(Rat r){
        int p = num*r.num;
        int q = denum*r.denum;
        Rat r1(p,q);
        return r1;
    }
    Rat invert(){
        if (num == 0) {
            throw runtime_error("0 cannot be inverted !");
        }
        if (num > 0) {
            return Rat(denum, num);
        } else {
            return Rat(-denum, -num);
        }
    }
    Rat operator /(Rat r){
        if (r.num==0){
            throw runtime_error("you cannot divide by 0 !");
        }
        return *this*r.invert();
    }
    bool operator ==(Rat r){
        return (num==r.num && denum==r.denum);
    }
    bool operator !=(Rat r){
        return (num!=r.num || denum!=r.denum);
    }
    bool operator >(Rat r){
        return (num>r.num);
    }
    bool operator <(Rat r){
        return (num<r.num);
    }
    bool operator <=(Rat r){
        return (num<=r.num);
    }
    bool operator >=(Rat r){
        return (num>=r.num);
    }
private: 
    int num;
    unsigned int denum;
    /*
    to overload the << and >> operators we need to access the private attributes of the class.
    either use getters or setters, or in our case, friend functions
    */
   friend ostream& operator<< (ostream&o, Rat& r);
   friend istream& operator>> (istream&i, Rat& r);
};

ostream& operator<< (ostream&o, Rat& r){
    if (r.denum==1){
        o<<r.num<<endl;
    }else{
        o << r.num << "/" << r.denum << endl;
    }
    return o;
}

istream& operator>> (istream& i, Rat& r){
    // version where you can input a single number alone
    // on va prendre tout le input sous forme d'un string puis le traiter
    string inputLine;
    getline(i,inputLine);
    char dummyChar;
    int possibleNum,possibleDenum=1;
    stringstream ss(inputLine);
    ss >> possibleNum;
    if (ss >> dummyChar){
        if (dummyChar == '\n'){

        }
        else if (dummyChar=='/'){
            ss >> possibleDenum;
        } else {
            throw runtime_error("Invalid input format!");
        }
    }
    r= Rat(possibleNum,possibleDenum);
    return i;

}

int main(){
    // using default constructor
    Rat r1,r2;
    cout << "print your first fraction or number r1 ,if fraction, your numerator followed by your denominator seperated by a / : " << endl;
    cin >> r1;
    cout << "print r2: ";
    cin >> r2;
    cout << "note that if 0 is in one your fractions the division and inverse will not work. " << endl;
    Rat r=r1+r2;
    cout << "the sum : " << r << endl;
    r=r1-r2;
    cout << "the substraction : " << r << endl;
    r = r1*r2;
    cout << "multiplication : "<< r <<endl;
    r=r1/r2;
    cout << "division : "<< r <<endl;
    r = -r ;
    cout << "opposite of the result : "<< r <<endl;
    Rat r8 = r.invert();
    cout << "inverse of the result : "<< r8 << endl;
    cout << "are your fractions equal : " << (r1==r2) << endl;
    cout << "are your fractions different : " << (r1!=r2) << endl;
    cout << "is r1 > r2 :" << (r1 > r2) <<endl;
    cout << "is r1 >= r2 :" << (r1 >= r2) <<endl;
    cout << "is r1 < r2 :" << (r1 < r2) <<endl;
    cout << "is r1 <= r2 :" << (r1 <= r2) <<endl;
    return 0;
}