class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        //insert each num into the hashtable(key), if found, let the hashvalue corresponding +1, after that, compare the largest value corresponding to each key in the hashmap and extract out the largest value and return to its position
        unordered_map<int,int> T;
        
        for(int i=0;i < nums.size();i++){
            auto it = T.find(nums[i]);
            if(it ==T.end()){
                T[nums[i]] = 1; 
            }else{
                T[nums[i]] ++;
            }    
        }
        // for (auto& x: T) {
        // std::cout << x.first << ": " << x.second << std::endl;
        // }
        // return 0;
        auto pr = std::max_element(T.begin(), T.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;
        });
        return pr->first;
    }
};

//Sample principle but more elegant
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> a;
        for(int i:nums)
            a[i]++;  				//if find, it will increment to the cooresponding value else create a new key
        int maxval=nums[0];
        for(auto x:a)
        {
            if(x.second>a[maxval])
                maxval=x.first;
        }
        return maxval;
    }
};
