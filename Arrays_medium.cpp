#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include <algorithm>

//Two sum
vector<int> two_sum(vector<int>& nums){
    int k;
    cout << "Enter the target number : ";
    cin >> k;

    map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        int target = k - nums[i];
        if(mpp.find(target) != mpp.end()){
            return {i,mpp[target]};
        }
        else{
            mpp[nums[i]] = i;
        }
    }
    return {};
}

//Counting the number of 0s, 1s and 2s
vector<int> count(vector<int>& nums){
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(nums[mid] == 0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
    return nums;
}

int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> temp(n);
    cout << "Enter the elements : ";
    for(int i=0;i<n;i++){
        cin >> temp[i];
    }

    //Two sum
    // vector<int> result = two_sum(temp);
    // cout << "The index of the two numbers equaling to " << k << " is " ;
    // for(int i=0;i<result.size();i++){
    //     cout << result[i] << " ";
    // }

    vector<int> result = count(temp);
    cout << "The sorted array is : " ;
    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }

}