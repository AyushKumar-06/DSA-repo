#include <iostream>
using namespace std;

//basic hashing
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
/*
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
    return 0;
}
*/
//hashing with map
/*
#include <map>

int main(){
    int n;
    cout << "Enter the number of integers in array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    //precompute
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    int q;
    cout << "Enter the number of queries you want to ask : ";
    cin >> q;
    while(q--){
        int num;
        cout << "The number you want to ask about is : ";
        cin >> num;
        //fetch
        cout <<"The frequency of " <<  num << " is : " << mpp[num] << endl;
    }
    return 0;
}
*/
//highest/lowest frequency element
/*
#include <map>
#include <algorithm>
int main(){
    int n;
    cout << "Enter the number of element in the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    //precompute
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    int highfreq = -1;
    int highelement = 0;

    int lowfreq = n+1;
    int lowelement = 0;

    for(int i=0;i<n;i++){
        if(mpp[arr[i]]>highfreq){
            highfreq = mpp[arr[i]];
            highelement = arr[i];
        }
    }

    for(int i=0;i<n;i++){
        if(mpp[arr[i]]<lowfreq){
            lowfreq = mpp[arr[i]];
            lowelement = arr[i];
        }
    }
    cout << "The highest frequency is : " << highfreq << " of the element : " << highelement << endl;
    cout << "The lowest frequency is : " << lowfreq << " of the element : " << lowelement << endl;

    return 0;
}
*/
//highest/lowest frequency element (optimised)
/*
#include <map>
#include <algorithm>
int main(){
    int n;
    cout << "Enter the number of element in the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    //precompute
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    int maxFreq = 0;     
    int maxElement = -1; 
    
    int minFreq = n + 1; 
    int minElement = -1; 

    for (auto it : mpp) {
        int element = it.first;  
        int count = it.second;  

        if (count > maxFreq) {
            maxFreq = count;
            maxElement = element;
        }

        if (count < minFreq) {
            minFreq = count;
            minElement = element;
        }
    }

    cout << "The highest frequency element is " << maxElement << " (Appears " << maxFreq << " times)" << endl;
    cout << "The lowest frequency element is " << minElement << " (Appears " << minFreq << " times)" << endl;
    
    return 0;
}
*/