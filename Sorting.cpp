#include <iostream>
using namespace std;

//Selection sort
/*
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
*/

//Bubble sort (Optimised version)
/*
void bubble_sort(int arr[],int n){
    for(int i=n-1;i>=1;i--){
    //Optimisation is the didswap part
        int didswap = 0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didswap = 1;
            }
            if(didswap == 0){
                break;
            }
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
    bubble_sort(arr,n);
    //printing the sorted array
    cout << "The sorted array is : ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}
*/

//Insertion sort
/*
void insertion_sort(int arr[],int n){
    int i,j;
    for(i=0;i<=n-1;i++){
        j=i;
        while(j>0 && arr[j-1] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--; 
        }
    }
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

    insertion_sort(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}
*/

//Merge sort
#include <vector>
//merge condition : combines the two sorted halves back together.
void merge(int arr[],int low,int mid,int high){
    vector<int> temp;       //temporary array to hold the sorted elements
    int left = low;         //pointer for the left half
    int right = mid+1;      //pointer for the right half

    //compare the elements of the two halves and pushes the smaller one into temp
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    //if any elements are left in the left half, pushes it into temp
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    //if any elements are left in the right half, pushes it into temp
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    //transfers all the elements form 'temp' back to the orignal array 'arr'
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

//divides the given array in half recursively
void mergesort(int arr[],int low,int high){
    //return condition or base condition
    if(low >= high){
        return;
    }

    int mid = (low + high)/2;

    //divide recursively the left half
    mergesort(arr,low,mid);
    //divide recursively the right half
    mergesort(arr,mid+1,high);
    //merge the 2 sorted half
    merge(arr,low,mid,high);
}

int main(){
    int n;
    cout << "Enter the number of elements of the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    mergesort(arr,0,n-1);

    cout << "The sorted array is : ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}