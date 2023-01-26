//
//  main.cpp
//  xcode c++
//
//  Created by Richard Qiu on 2022-11-13.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
vector<int> runningSum(vector<int>& nums) {
    partial_sum(nums.begin(), nums.end(), nums.begin());
    return nums;
}
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution test1;
    vector<int>input {1,2,3,4};
    for(vector<int>::iterator it = input.begin();it!=input.end();++it){
     cout<<""<< *it <<'\n';
    }
    vector<int> nums = test1.runningSum(input);
    for(vector<int>::iterator it = nums.begin();it!=nums.end();++it){
     cout<<""<< *it <<'\n';
    }
    return 0;
}
