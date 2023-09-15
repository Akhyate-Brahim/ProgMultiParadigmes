#include <iostream> 
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>
using namespace std;
int main(){
    // code qui génére une liste de booléen random
    srand(std::time(nullptr));
    const int numBooleans = 10;
    vector<bool> randomBooleans;
    cout << "random list of bools"<<endl<<"[";
    for (int i = 0; i < numBooleans; ++i) {
        bool randomBoolean = rand() % 2 == 1;
        randomBooleans.push_back(randomBoolean);
        cout << randomBoolean << " ";
    }
    cout<<"]"<<endl;
    vector<bool> newList;

    // my code
    for (int i = 0;i<numBooleans;i++){
        if (i==0){
            newList.push_back(randomBooleans.at(i+1));
        }else if (i==numBooleans-1){
            newList.push_back(randomBooleans.at(i-1));
        } else{
            newList.push_back((randomBooleans.at(i-1) && randomBooleans.at(i+1)));
        }
    }
    cout << "here is the transformed automate " <<endl<<"[";
    // print all values
    for (int i = 0;i<numBooleans;i++){
        cout << newList.at(i)<<" ";
    }
    cout << "]"<<endl;

    return 0;
}