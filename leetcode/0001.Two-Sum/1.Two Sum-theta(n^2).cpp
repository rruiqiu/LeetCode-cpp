class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool ans=false;
        vector<int>index;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((i!=j) && (nums[i]+nums[j]==target)){
                    index.push_back(i);
                    index.push_back(j);
                    ans = true;
                    break;
                }
            }
        if(ans==true)break;
        }
        return index;
    }
};
