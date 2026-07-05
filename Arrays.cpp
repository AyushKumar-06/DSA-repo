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
/*
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
*/

//union of 2 sorted arrays
/*
#include <vector>

// My solution (Better)
//  TC = O(N+M)
// vector<int> removeduplicate(vector<int>& temp){
//     int i;
//     int j = 0;
//     //Removing duplicates;
//     for(i=1;i<temp.size();i++){
//         if(temp[i] != temp[j]){
//             temp[j+1] = temp[i];
//             j++;
//         }
//     }
//     temp.resize(j + 1);
//     return temp;
// }

// vector<int> sortedunion(vector<int>& arr1,vector<int>& arr2,int n,int m){
//     vector<int> temp;
//     int left = 0;
//     int right = 0;
//     //Merging the 2 arrays
//     while(left < n && right < m){
//         if(arr1[left]<=arr2[right]){
//             temp.emplace_back(arr1[left]);
//             left++;
//         }
//         else{
//             temp.emplace_back(arr2[right]);
//             right++;
//         }
//     }

//     while(left<n){
//         temp.emplace_back(arr1[left]);
//         left++;
//     }

//     while(right<m){
//         temp.emplace_back(arr2[right]);
//         right++;
//     }

//     removeduplicate(temp);

//     return temp;
// }

// Optimised solution
vector<int> sortedunion(vector<int>& arr1,vector<int>& arr2,int n,int m){
    int left = 0;
    int right = 0;
    vector<int> temp;
    while(left<n && right<m){
        if(arr1[left]<=arr2[right]){
            if(temp.size() ==0 || temp.back() != arr1[left]){
                temp.emplace_back(arr1[left]);
            }
            left++;
        }
        else{
            if(temp.size() == 0 || temp.back() != arr2[right]){
                temp.emplace_back(arr2[right]);
            }
            right++;
        }
    }

        while(left < n){
            if(temp.size() == 0 || temp.back() != arr1[left]){
                temp.emplace_back(arr1[left]);
            }
            left++;
        }

        while(right < m){
            if(temp.size() == 0 || temp.back() != arr2[right]){
                temp.emplace_back(arr2[right]);
            }
            right++;
        }
    return temp;
}

int main(){
    int n;
    cout << "Enter the number of elements  of 1st array : ";
    cin >> n;
    
    vector<int> nums1(n);
    cout << "Enter the elements of 1st array : ";
    for(int i=0;i<n;i++){
        cin >> nums1[i];
    }

    int m;
    cout << "Enter the number of elements in the 2nd array : ";
    cin >> m;

    vector<int> nums2(m);
    cout << "Enter the elements of the 2nd array : ";
    for(int i=0;i<m;i++){
        cin >> nums2[i];
    }

    vector<int> arr = sortedunion(nums1,nums2,n,m);

    cout << "The union of the two arrays is : ";
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
}
*/

//Find the missing number
/*
#include <vector>

int missing_num(vector<int>& num,int n){

    long long expected_sum = (long long) (n+1) * (n+2) / 2;

    long long actual_sum = 0;
    for(int i=0;i<num.size();i++){
        actual_sum += num[i];
    }
    return expected_sum - actual_sum;
}
int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "The missing number is : ";
    cout << missing_num(arr,n) << endl;
}
*/

//Maximum consecutive ones
/*
#include <vector>
#include <algorithm>

int consecutive_ones(vector<int>& nums){
    int cnt = 0;
    int cnt_max = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == 1){
            cnt++;
            cnt_max = max(cnt,cnt_max);
        }
        else{
            cnt = 0;
        }
    }
    return cnt_max;
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

    cout << consecutive_ones(nums);
}
*/

//Find the number that appers only once, and the other numbers twice
/*
#include<vector>

int single(vector<int>& nums){
    int single = nums[0];
    for(int i=1;i<nums.size();i++){
        single = single ^ nums[i];
    }

    return single;
}
int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }

    cout << "The number that appears only once is : " << single(arr) << endl; 
}
*/

//Longest subarray with given sum K(positive)
/*
#include <vector>
#include <algorithm>

int subarray(vector<int>& nums,int k){
    int left = 0;
    int right = 0;
    int len = 0;
    int max_len = 0;
    long long sum = nums[0];
    int n = nums.size();
    while(right < n){    
        while(left <= right && sum > k){
            sum = sum - nums[left];
            left++;
        }

        if(sum == k){
            len = right - left + 1;
            max_len = max(len,max_len);
        }

        right++;
        if(right < n){
            sum = sum + nums[right];
        }
    }
    return max_len;

}
int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter the number you want to add up to : ";
    cin >> k;

    cout << "The number of elements that add upto " << k << " is : " << subarray(arr,k);
}
*/

//Length of the longest subarray with zero Sum
/*
#include <map>
#include <algorithm>
int longest_subarray(vector<int>& nums){
    int sum = 0;
    int maxi = 0;
    unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        sum = sum + nums[i];

        if(sum == 0){
            maxi = i+1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i - mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}
int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    longest_subarray(arr);
}
*/