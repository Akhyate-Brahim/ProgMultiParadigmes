#include <iostream>
#include <string>
using namespace std;
int main(){
    bool palindrome=true;
    string word;
    cout << "print your word : " << endl;
    getline(cin,word);
    for (int i = 0;i<word.length()/2;i++){
        if (word[i]!=word[word.length()-1-i]){
            palindrome=false;
        }
    }
    cout << (palindrome ? "it is a palindrome": "its not a palindrome you buma") << endl;
    return 0;
}