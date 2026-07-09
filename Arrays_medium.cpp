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

//Majority element - 1
//better approach
int majority(vector<int>& nums){
    int n = nums.size();
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
        if(mpp[nums[i]] > n/2){
            return nums[i];
        }
    }
    return -1;
}
//Optimal approach - A bit of deviation from Moore's voting algoritm
int majority_optimal(vector<int>& nums){
    int n = nums.size();
    int cnt = 0;
    int number = nums[0];
    for(int i=0;i<n;i++){
        if(nums[i] == number){
            cnt++;
        }
        else{
            cnt--;
            if(cnt == 0){
                number = nums[i];
                cnt = 1;
            }
        }
    }

    return number;
}
//Optimal arrpoach - Moore's voting algorithm
int majority_optimal_moore(vector<int>& nums){
    int cnt = 0;
    int candidate = 0;
    for(int i=0;i<nums.size();i++){
        if(cnt == 0){
            candidate = nums[i];
        }
        else if(nums[i] == candidate){
            cnt++;
        }
        else{
            cnt--;
        }
    }
}

//Kadane's algorithm
int kadane(vector<int>& nums){
    int sum = 0;
    int max_sum = INT_MIN;
    for(int i=0;i<nums.size();i++){
        sum = sum + nums[i];
        max_sum = max(max_sum,sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return max_sum;
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

    //Counting the number of 0s, 1s and 2s
    // vector<int> result = count(temp);
    // cout << "The sorted array is : " ;
    // for(int i=0;i<result.size();i++){
    //     cout << result[i] << " ";
    // }

    //Majority element - 1
    // majority(temp);
    // majority_optimal(temp);
    // majority_optimal_moore(temp);

    //Kadane's algorithm
    cout << kadane(temp);

}