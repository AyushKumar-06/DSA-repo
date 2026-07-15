#include <iostream>
using namespace std;
#include <vector>

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