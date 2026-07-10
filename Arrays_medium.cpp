#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>

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

//Stock buy and sell
int stock(vector<int>& nums){
    int today_price = 0;
    int min_price_sofar = INT_MAX;
    int max_profit = 0;

    for(int i=0;i<nums.size();i++){
        today_price = nums[i];
        min_price_sofar = min(today_price,min_price_sofar);
        
        int profit = today_price - min_price_sofar ;
        if(profit >= 0){
            max_profit = max(profit,max_profit);
        }
    }
    return max_profit;
}

//Rearrange array element by sign
vector<int> rearrange(vector<int>& nums){
    vector<int> pattern(nums.size());
    int pos_index = 0;
    int neg_index = 1;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > 0){
            pattern[pos_index] = nums[i];
            pos_index += 2;
            }
        else{
            pattern[neg_index] = nums[i];
            neg_index += 2;
        }
    }
    return pattern;
}

//Next permutation : find next lexicographically greater permutation
vector<int> permutation(vector<int>& nums){
    int n = nums.size();
    int dip_index = -1;
    for(int i=n-2;i>-1;i--){
        if(nums[i] < nums[i+1]){
            dip_index = i;
            break;
        }
    }
    if(dip_index == -1){
        reverse(nums.begin(),nums.end());
        return;
    }
    for(int j=n-1;j>dip_index;j--){
        if(nums[j] > nums[dip_index]){
            swap(nums[j],nums[dip_index]);
            break;
        }
    }
    reverse(nums.begin()+dip_index+1,nums.end());
}

//Leaders in an array
vector<int> leader_in_arr(vector<int>& nums){
    vector<int> temp;
    int n = nums.size();
    int leader = INT_MIN;
    for(int i=n-1;i>-1;i--){
        if(nums[i] > leader){
            leader = nums[i];
            temp.emplace_back(leader);
        }
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

//Longest Consecutive sequence in an array 
int sequence(vector<int>& nums){
    unordered_set<int> st;
    for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
    }

    int longest = 0;
    for(int j=0;j<nums.size();j++){
        int num = nums[j];
        if(st.count(num - 1) == 0){
            int start = num;
            int streak = 1;
            while(st.count(num+1) == 1){
                streak++;
                num++;
            }
            longest = max(longest,streak);
        }
    }
    return longest;
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