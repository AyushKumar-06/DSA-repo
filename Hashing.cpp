#include <iostream>
using namespace std;

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