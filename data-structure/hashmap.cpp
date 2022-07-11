#include <iostream>
#include <unordered_map>

std:map<int,string> mapStudent;  //创建了一个key是int，value是string

using namespace std;
//插入元素：
//三种方法

//第一种，用insert函数插入pair
mapStudent.insert(pair<int,string>(000,"student_zero"));

// 第二种 用insert函数插入value_type数据
mapStudent.insert(map<int, string>::value_type(001, "student_one"));

// 第三种 用"array"方式插入
mapStudent[123] = "student_first";
mapStudent[456] = "student_second";


//How to Find with Hash Map
//There’s two methods to find an element in a std::unordered_map: the find() method and the square bracket operator([]). The find() method returns an iterator to a key-value pair, meaning an iterator to std::pair<Key, Value>. Because it’s an iterator to a pair, you can access the key with it->first and the value with it->second. If nothing was found, the end() iterator is returned from the unordered_map.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
  std::unordered_map<int,string> mymap; //creat a mymap with key is string and value is string.
  //we can insert the element into the hashmap or directly assign the hashmap
  
  mymap = {
    {200,"zenuo"},
    {100,"qiuqiu"},
    {50,"shouzi"},
  }
  
  //print all elements in the hashmap
  for (auto& x: mymap) {
    std::cout << x.first << ": " << x.second << std::endl;
  }
  
  //This will assign the handsome_guy the mymap[key] value, if not found in the mymap, it will create a new mymap key with mymap[100] but withoud the element.
  string handsome_guy = mymap[100];
  cout << handsome_guy;
  //create a new node
  string ugly_guy = mymap[101];
  cout << mymap[101] << "\n";
  
  mymap[101] = "John";
  cout << mymap[101] << "\n"';
  
  string ugly_girl = "zenoo";
  mymap[102] = ugly_girl;
  cout << mymap[102] << "\n";
  
  //The other way to find an element in the hashmap
  auto it = mymap.find(200);
  if(it != mymap.end()){
    cout << it->first << ":" << it->second << "\n";
  }else{
    cout << "Don't find. \n";
  }
  
  it = mymap.find(50);
  if(it!=mymap.end()){
    cout<<it->first<<": "<<it->second<<"\n";
  }else{
    cout<<"Don't find. \n";
  }
  
  //find the maximum value(int type) in the hashmap.
  // retrived from (https://www.techiedelight.com/find-element-with-the-maximum-value-in-a-map-in-cpp/ )
  auto pr = std::max_element(map.begin(), map.end(), [](const auto &x, const auto &y) {return x.second < y.second;});
  std::cout << pr->first << std::endl;   //will return the largest map key, pr->second will return the value
  
  
}


