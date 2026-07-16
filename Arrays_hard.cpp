#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <math.h>

//Majority element - 2
vector<int> majority_2(vector<int>& nums){
    vector<int> ans;
    int num1 = INT_MIN;
    int num2 = INT_MIN;
    int cnt1 = 1;
    int cnt2 = 0;
    for(int i=1;i<nums.size();i++){
        if(nums[i] == num1){
            cnt1++;
        }
        else if(nums[i] == num2){
            cnt2++;
        }
        else if(cnt1 == 0){
            num1 = nums[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0){
            num2 = nums[i];
            cnt2 = 1;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    int cnt1_actual = 0;
    int cnt2_actual = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == num1){
            cnt1_actual++;
        }
        else if(nums[i] == num2){
            cnt2_actual++;
        }
    }
    int n = nums.size() / 3;
    if(cnt1_actual > n){
        ans.push_back(num1);
    }
    if(cnt2_actual > n){
        ans.push_back(num2);
    }
    return ans;
}

//3 sum
vector<vector<int>> three_sum(vector<int>& nums){

    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    int left;
    int right;

    int num1,num2,num3;
    for(int i=0;i<nums.size();i++){
        num1 = nums[i];
        left = i + 1;
        right = nums.size() - 1;
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        else{
            while(left < right){
                num2 = nums[left];
                num3 = nums[right];
                int sum = num1 + num2 + num3;
                if(sum == 0){
                    ans.push_back({num1,num2,num3});
                    left++;
                    right--;
                    
                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    }
    return ans;
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
}