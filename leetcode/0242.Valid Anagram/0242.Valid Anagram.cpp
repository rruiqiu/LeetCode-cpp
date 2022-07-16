class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> H;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            H[s[i]] = H[s[i]]+1;// H[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            H[t[i]] = H[t[i]]-1;//H[s[i]]--;
            if(H[t[i]] < 0){
                return false;
            }
        }
        return true;
    }
};
//Sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s==t;            
    }
};
