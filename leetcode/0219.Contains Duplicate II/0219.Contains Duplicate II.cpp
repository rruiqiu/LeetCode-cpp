// find the location of same number
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;
        for(int i=0;i<nums.size();i++){
            if(myMap.find(nums[i])!=myMap.end() && abs(i-myMap[nums[i]])<=k){
                return true;
            }
        myMap[nums[i]] = i; //That's the place really got confused, because it will occur more than twice, the value appear agian should be replaced its orginal index since it will always compare to the closet to find which value is smaller.
        }
        return false;
    }
};
