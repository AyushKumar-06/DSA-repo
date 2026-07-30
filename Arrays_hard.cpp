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

//4 sum
vector<vector<int>> four_sum(vector<int>& nums){
    int k;
    cout<<"Enter the target number : ";
    cin >> k;

    vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        int left,right;
        int num1,num2,num3,num4;

        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            num1 = nums[i];
            for(int j = i + 1;j<nums.size();j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                num2 = nums[j];

                left = j + 1;
                right = nums.size() - 1;
                while(left < right){
                    num3 = nums[left];
                    num4 = nums[right];
                    long long sum = (long long)num1 + num2 + num3 + num4;
                    if(sum == k){
                        ans.push_back({num1,num2,num3,num4});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left - 1]){
                            left++;
                        }
                        while(left < right && nums[right] == nums[right + 1]){
                            right--;
                        }
                    }
                    else if(sum > k){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        return ans;
}

//Largest subarray with sum 0
int largest_subarray(vector<int>& nums){
    unordered_map<int,int> mpp;

    int running_sum = 0;
    int length = 0;
    int max_length = 0;
    for(int i=0;i<nums.size();i++){
        running_sum += nums[i];
        if(running_sum == 0){
            length = i + 1;
            max_length = max(length,max_length);
        }
        else if(mpp.find(running_sum) != mpp.end()){
            length = i - mpp[running_sum];
            max_length = max(max_length,length);
        }
        else{
            mpp[running_sum] = i;
        }
    }
    return max_length;
}

//Count the number of subarrays with given xor K
int subarray_xor(vector<int>& nums){
    int target;
    cout<<"Enter the target number : ";
    cin >> target;

    unordered_map<int,int> mpp;
    mpp[0] = 1; 

    int running_xor = 0;
    int count = 0;

    for(int i=0;i<nums.size();i++){
        running_xor = running_xor ^ nums[i];

        int required_xor = running_xor ^ target;

        if(mpp.find(required_xor) != mpp.end()){
            count = count + mpp[required_xor];
        }
        mpp[running_xor]++;
    }
    return count;
}

//Merge overlapping Sub-intervals
vector<vector<int>> overlapping_sub_intervals(vector<vector<int>>& matrix){
    sort(matrix.begin(),matrix.end());
    vector<vector<int>> ans;

    for(int i=0;i<matrix.size();i++){
    
        if(ans.empty() || matrix[i][0] > ans.back()[1]){
            ans.push_back(matrix[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1],matrix[i][1]);
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