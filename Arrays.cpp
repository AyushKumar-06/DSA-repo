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

//Second largest element in an array without Sorting (Self thought) (Better solution)
/*
int sec_largest(int arr[],int n){
    int largest = arr[0];
    int sec_large = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>sec_large && arr[i] != largest){
            sec_large = arr[i];
        }
    }

    return sec_large;
}

int main(){
    int n;
    cout << "Enter the number of elements in array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "The second largest element in array is : " << sec_largest(arr,n);
}
*/

//Second largest element in an array (Optimal Solution)
/*
void sec_largest(int arr[],int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }

        else if(arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
}

int main(){
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sec_largest(arr,n);

    return 0;
}
*/

//Check if the array is sorted 
#include <utility>
void sorted(int arr[],int n){
    //Using the optimised version of bubble sort
    int compare = 1;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            compare = 0;
            break;
        }
    }
    if(compare == 1){
        cout << "The array is sorted ";
    }
    else{
        cout << "The array is not sorted ";
    }
}

int main(){
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sorted(arr,n);
}
