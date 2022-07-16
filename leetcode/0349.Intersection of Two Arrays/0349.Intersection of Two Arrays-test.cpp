/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        // for(auto x:m){
        //     cout << x;
        // }
        vector<int> res;
        for (auto a : nums2)
            if (m.find(a) != m.end()) { //or use m.count(a) //both will work
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};


int main()
{
    Solution nihao;
    vector<int> nums1 {1,2,2,1};
    vector<int> nums2 {2,2};
    vector<int> nums3 = nihao.intersection(nums1,nums2);
    for(vector<int>::iterator it = nums3.begin();it!=nums3.end();++it){
        cout<<""<< *it <<'\n';
    }
    return 0;
}
