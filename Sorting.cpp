#include <iostream>
using namespace std;

//Selection sort

#include <utility>
int main(){
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    //comparing and swapping
    for(int i=0;i<=n-2;i++){
        int mini;
        mini = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }

    //printing the swapped array
    cout << "The sorted array is : " << endl; 
    for(int i=0;i<n;i++){
        cout << arr[i] << "  ";
    }
    
    return 0;
}