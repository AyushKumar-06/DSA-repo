#include <iostream>
using namespace std;

//Binary search
int binary_search(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while(low <= high){
        mid = low + (high - low)/2;

        if(target == nums[mid]){
            return mid;
        }
        else if(target > nums[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    return -1;
}

//implement lower bound
int lower_bound(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    int ans = nums.size();
    while(low <= high){
        mid = low + (high - low)/2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

//implement upper bound
int upper_bound(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int mid;
    int ans;

    while(left <= right){
        mid = low + (high - low)/2;

        if(target < nums[mid]){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}




int main(){

}