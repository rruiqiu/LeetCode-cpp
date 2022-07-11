class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate = nums[i];
            }
            count += ((nums[i]==candidate) ? 1:-1);
        }
        return candidate;
    }
};

//Same way to do but figure out for loop can directly itrate num
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, majority;
        for (int num : nums) {
            if (!counter) {
                majority = num;
            }
            counter += num == majority ? 1 : -1;
        }
        return majority;
    }
};
