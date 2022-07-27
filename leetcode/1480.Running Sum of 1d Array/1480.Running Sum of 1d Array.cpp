class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSum;
        int sum=0;
        for(int i=1;i<=nums.size();i++){
            runningSum.push_back(accumulate(nums.begin(),nums.begin()+i,sum));
        }
        return runningSum;
    }
};

class Solution {
public:
vector<int> runningSum(vector<int>& nums) {
    partial_sum(nums.begin(), nums.end(), nums.begin());
    return nums;
}
};

class Solution {
public:
    vector<int> runningSum(vector<int> nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};
