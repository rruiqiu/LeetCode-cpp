#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int,int> A;
        for(int i=0;i<nums.size();i++){
            auto it = A.find(nums[i]);
            if(it!=A.end() && (abs(i-(it->second)) <= k)){
                cout << i << ";"<< nums[i]<<"\n"; //correct
               for (auto& x: A) {
                std::cout << x.first << ": " << x.second << std::endl;
               }               
                cout<<it->first<<";"<<it->second<<"\n";
                
                cout<<abs(i-(it->first));
                return true;
            }
            A[nums[i]] = i;
        }
          for (auto& x: A) {
            std::cout << x.first << ": " << x.second << std::endl;
          }
        return false;
    }
};
int main()
{
    Solution nihao;
    vector<int> nums{1,0,1,1};
    int k=2;
    cout<<nihao.containsNearbyDuplicate(nums,k);
    return 0;
}
