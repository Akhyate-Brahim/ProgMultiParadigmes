#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Bookrecord{
    string nom;
    double somme;
};

int main(){
    ifstream inputFile("transactions.txt");
    vector<Bookrecord> transactions;
    Bookrecord transaction;
    while (inputFile >> transaction.nom >> transaction.somme){
        transactions.push_back(transaction);
    }
    // print transactions
    for (const Bookrecord &record : transactions) {
        cout << "Nom: " << record.nom << ", Somme: " << record.somme << endl;
    }
    // print name of a client when done press Ctrl d
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


