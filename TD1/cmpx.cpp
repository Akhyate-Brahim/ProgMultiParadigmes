#include <iostream> 
#include <vector>

using namespace std;

void cmpx(int &i,int &j){
    if (i > j){
        int tmp;
        tmp=j;
        j=i;
        i=tmp;
    }
}

void insert(int n, vector<int> &vect){
    for (int &element : vect) {
        cmpx(element, n);
    }
    vect.push_back(n);
}

int main(){
    // lire les entiers et les trier
    vector<int> vect;
    vector<int> unsortedVect;
    int i;
    cout << "print the numbers in your list. after each number press enter, when done press Ctrl+d "<<endl;

    while (cin >> i){
        unsortedVect.push_back(i);
        insert(i,vect);
    }

    // liste non trié
        cout << "your initial list : " <<endl<<"[";
    for (int i=0;i<unsortedVect.size();i++){
        cout << unsortedVect.at(i)<<" ";
    }
    cout << "]"<<endl;

    // print la liste triée

    cout << "your sorted list : " <<endl<<"[";
    for (int i=0;i<vect.size();i++){
        cout << vect.at(i)<<" ";
    }
    cout << "]"<<endl;

    return 0;

}
