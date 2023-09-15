#include <iostream> 
#include <vector>

using namespace std;
template<typename T>
void cmpx(T &i,T &j){
    if (i > j){
        T tmp;
        tmp=j;
        j=i;
        i=tmp;
    }
}
template<typename T>
void insert(T n, vector<T> &vect){
    for (T &element : vect) {
        cmpx(element, n);
    }
    vect.push_back(n);
}

int main(){
    // lire les entiers et les trier
    vector<string> vect;
    vector<string> unsortedVect;
    string i;
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
