#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Bookrecord{
    string nom;
    double somme;
};
ostream& operator<< (ostream&o,const Bookrecord &b){
    o<<"nom : " << b.nom <<"\nsomme : " <<b.somme<<endl;;
    return o;
}
istream& operator>> (istream& i,Bookrecord &b){
    i >> b.nom >> b.somme;
    return i;
}

int main(){
    ifstream inputFile("transactions.txt");
    vector<Bookrecord> transactions;
    Bookrecord transaction;
    while (inputFile >> transaction){
        transactions.push_back(transaction);
    }
    // print transactions
    for (const Bookrecord &record : transactions) {
        cout << record << endl;
    }
    cout << "print name of a client when done press Ctrl d" << endl;
    string nomClient;
    while (cin >> nomClient){
        for (Bookrecord transact : transactions){
            if (transact.nom==nomClient){
                cout << "la somme correspondant à ce client :" <<transact.somme<<endl;
            }
        }
    }
    return 0;
}


