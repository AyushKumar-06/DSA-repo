#include <iostream>
using namespace std;

//Largest element of an array 
/*
int Largest_elem(int arr[],int n){
    //assuming the 1st element as smallest just makes it a matter of comparision with rest of the elements
    int largest = arr[0];
    
    //this loop iterates form the 2nd element to the nth element
    for(int i=1;i<n;i++){
        //if condition to compare the rest of the elements with the 1st element
        if(arr[i]>largest){
            //changing largest if the value is larger than 1st element
            largest = arr[i];
        }
    }
    //returning the largest value in the array
    return largest;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    //Took the input into the array
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "The largest element is : " << Largest_elem(arr,n);
}
*/

//