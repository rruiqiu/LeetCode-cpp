/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string word;
        stringstream iss(s);
        while(iss>>word){
            v.push_back(word);
        }
        // for(auto i: v){
        //     cout<<i <<'\n';
        // }
        // cout << v.size();
        set<string> S;
        // if(pattern.size()!=v.size()){
        //     return false;
        // }
        unordered_map<char,string> m;
        for(int i=0;i<pattern.size();i++){
            char ch = pattern[i];
            cout<<ch<<"\n";
            //cout << "vi" << v[i] << " ";
            if(m.find(ch)!=m.end()){
                //cout << "vi" << v[i] << " ";
                if(m[ch] != v[i]){
                    return false;
                }
            }else{
                if(S.count(v[i]) >0){
                    return false;
                }
                m[ch] = v[i];
                S.insert(v[i]);
            }
        }
        return true;
        
    }
};

int main()
{
    Solution nihao;
    string a = "abba";
    string b = "dog cat cat dog";
    cout << nihao.wordPattern(a,b);
    return 0;
}
