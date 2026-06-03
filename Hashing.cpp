#include <iostream>
using namespace std;

/*
int main(){
    int n;
    cout << "Enter the number of elements of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    // precompute 
    int hash[13] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]] += 1;
    }

    int q;
    cout << "Enter the number of queries you want to ask : ";
    cin >> q;
    while(q--){
        int number;
        cout << "The number you want to ask about : ";
        cin >> number;
        // fetch
        cout << "The number of times " << number << " is repeated is : ";
        cout << hash[number] << endl;
    }
}
*/

//charecter hashing
int main(){
    string s;
    cout << "Enter a word : ";
    cin >> s;

    //precompute
    int hash[26] = {0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    int q;
    cout << "Enter the number of alphabets you want the frequency of : ";
    cin >> q;
    while(q--){
        char c;
        cout << "Enter the alphabet you want to ask for : ";
        cin >> c;
        cout << "The frequency of the word " << c << " is : ";
        cout << hash[c - 'a'] << endl;
    }
}