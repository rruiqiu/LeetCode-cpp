//
//  392.cpp
//  xcode c++
//
//  Created by Richard Qiu on 2022-11-13.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0){
            return true;
        }
        if(t.length()==0){
            return false;
        }
        auto temp = t.length();
        int count = 0;
        bool res=true;
        for(int i=0;i<s.length();i++){
            if(res==false){return res;}
            char A = s[i];
            if(count==temp){return false;}
            for(int j=count;j<temp;j++){
                count --;
                char B = t[j];
                if(A==B && j > count){
                    count = j+1;
                    res = true;
                    break;
                }else{
                    res = false;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution A;
    string s="acb", t="ahbgdc";
    
    cout << A.isSubsequence(s,t);
//    A.printmap(t);
}
