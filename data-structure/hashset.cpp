#include <iostream>
#include <string>
#include <unordered_set>

// kind of similar format as the hashmap exclude it only contains the key without having values
using namespace std;
int main ()
{
  unordered_set<int> hashset; // create a hashset with the key
	if(hashset.find(100)==hashset.end()){
    hashset.insert(50);
  }else{
    cout<< "found!" << "\n";
  }
  //also, use to find the key;
  std::unordered_set<std::string>::const_iterator got = myset.find (input);
  if ( got == myset.end() )
    std::cout << "not found in myset";
  else
    std::cout << *got << " is in myset"; //kind of silly because it won't have the corresponding value, so if found the key is the key.

  
}

