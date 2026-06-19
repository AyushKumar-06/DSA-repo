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
/*
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
*/

//Remove duplicated from sorted array
/*
#include <vector>

int removeduplicates(vector<int>& sort){
    int i = 0;
    int j;
    
    for(j=1;j<sort.size();j++){
        if(sort[j] != sort[i]){
            sort[i+1] = sort[j];
            i++;
        }
    }

    return i+1;
}
int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> sort(n);
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
         cin >> sort[i];
    }

    int unique_count = removeduplicates(sort);

    cout << "The array after removing duplicates is : ";
    for (int i = 0; i < unique_count; i++) {
        cout << sort[i] << " ";
    }

    return 0;
}
*/

//Left rotate the array by one
/*
#include <vector>
int rotate_left(vector<int>& nums){
    int temp = nums[0];
    for(int i=1;i<nums.size();i++){
        nums[i-1] = nums[i];
    }
    nums[nums.size()-1] = temp;
}

int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    rotate_left(nums);

    cout << "The left rotated array be one place is : ";
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
}
*/

//Rotate array by K elements
/*
#include <vector>
#include <string>
#include <utility>

void reversearray(vector<int>& nums,int start,int end){
    while(start < end){
        swap(nums[start],nums[end]);
        start++;
        end--;
    }
}

vector<int> rotate(vector<int>& nums,int k,string dir){
    int n = nums.size();

    k = k % n;

    if(dir == "right"){
        //reverse the whole array 
        reversearray(nums,0,n-1);
        //reverse the first k elements
        reversearray(nums,0,k-1);
        //reverse rest of the elements
        reversearray(nums,k,n-1);
    }

    else if(dir == "left"){
        //reverse the first k elements
        reversearray(nums,0,k-1);
        //reverse rest of the elements
        reversearray(nums,k,n-1);
        //reverse the whole array
        reversearray(nums,0,n-1);
    }

    return nums;

}
int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    int k;
    cout << "Enter the number by which you want to rotate the array : ";
    cin >> k;

    string direction;
    cout << "Enter the direction in which you want to rotate the array (left/right) : ";
    getline(cin >> ws, direction);

    rotate(nums,k,direction);

    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
}
*/

//Move zeroes to the end
/*
#include <vector>
#include <utility>

vector<int> zeroes(vector<int>& arr,int n){

    //  Self thought answer (worse than brute)
    //     reason - TC = O(N^2) and SC = O(1)
    //     brute had TC = O(N) and SC = O(N)

    // for(int i=n-1;i>-1;i--){
    //     if(arr[i] == 0){
    //         for(int j=i;j<(n-1);j++){
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }
    // }

    // Optimal solution
    int j = -1;

    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1){
        return arr;
    }

    for(int i = j+1;j<n;j++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    for(int i=n-1;i>-1;i--){
        if(arr[i] == 0){
            int temp = i;

        }
    }

    return arr;
}
int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    zeroes(nums,n);

    cout << "The final version is : ";
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
}
*/

//linear search
int search(vector<int>& arr,int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i] == k){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    int k;
    cout << "Enter the number you want the indexing for : ";
    cin >> k;

    int index = search(nums,n,k);
    if(index == -1){
        cout << "The number was not within the given elements.";
    }
    else{
    cout << "The indexing for " << k << " is : " << index;
    }
}