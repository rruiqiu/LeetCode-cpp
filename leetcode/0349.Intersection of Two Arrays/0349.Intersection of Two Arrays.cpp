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

class Solution {
public:
    bool contains(vector<int> vec, const int & elem)
    {
        bool result = false;
        if(find(vec.begin(), vec.end(), elem) != vec.end() )
        {
            result = true;
        }
        return result;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> H;
        vector<int> index;
        for(int i=0;i<nums1.size();i++){
            H.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(H.find(nums2[i])!= H.end()){
                if(!contains(index,nums2[i])){
                    index.push_back(nums2[i]);
                }
            }
        }
        return index;
    }
};
