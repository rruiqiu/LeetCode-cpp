class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mapSymbol{
           { 'I' , 1 },
           { 'V' , 5 },
           { 'X' , 10 },
           { 'L' , 50 },
           { 'C' , 100 },
           { 'D' , 500 },
           { 'M' , 1000 }
        };
        int sum =mapSymbol[s.back()]; //make the reference point to the end of the string
        for(int i= s.length()-2;i>=0;i--){ //in the reverse order of the string
            if(mapSymbol[s[i]] < mapSymbol[s[i+1]]){
                sum-= mapSymbol[s[i]];
            }else{
                sum+= mapSymbol[s[i]];
            }
        }       
        return sum;
    }
};
