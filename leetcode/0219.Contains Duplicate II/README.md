# [0219.Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)

## Question

Given an integer array `nums` and an integer `k`, return `true` if there are two **distinct indices** `i` and `j` in the array such that `nums[i] == nums[j]` and `abs(i - j) <= k`.

 **Example 1:**

```
Input: nums = [1,2,3,1], k = 3
Output: true
```

**Example 2:**

```
Input: nums = [1,0,1,1], k = 1
Output: true
```

**Example 3:**

```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

## Solving Ideas

//That's the place really got confused, because it will occur more than twice, the value appear agian should be replaced its orginal index since it will always compare to the closet to find which value is smaller.

This can be done by using the hashmap, notice that find method in hashmap is used to find the key value, so in this question the array nums cannont be stored as value instead of should be stored as keys. And because the appeared number will always follow larger than the previous one, so the question is asked to compare smaller, so we can always replace the newest appeared number with new indice and  by calling the key value cooresponding value to minus the current index to compare with k.

## Answer

```cpp
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
```


