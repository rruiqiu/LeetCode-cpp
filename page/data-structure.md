# Array

Accumulate/Partial_Sum

```cpp
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    int sum = std::accumulate(v.begin(), v.end(), 0);
    
    int sum = accumulate(v.begin,v.begin()+3,10); //find the sum of the first three elements in the vector and add their sum to 10;

		partial_sum(v.begin(),v.end(),v.begin());//do the same thing as
/*
y0 = x0
y1 = x0 + x1
y2 = x0 + x1 + x2
y3 = x0 + x1 + x2 + x3
y4 = x0 + x1 + x2 + x3 + x4
*/
}


```



# Vector

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
   // 创建一个向量存储 int
   vector<int> vec; 
   int i;
 
   // 显示 vec 的原始大小
   cout << "vector size = " << vec.size() << endl;
 
   // 推入 5 个值到向量中
   for(i = 0; i < 5; i++){
      vec.push_back(i);
   }
 
   // 显示 vec 扩展后的大小
   cout << "extended vector size = " << vec.size() << endl;
 
   // 访问向量中的 5 个值
   for(i = 0; i < 5; i++){
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }
 
   // 使用迭代器 iterator 访问值
   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }
	 //print out the content of vector
   for(vector<int>::iterator it = nums.begin();it!=nums.end();++it){
    cout<<""<< *it <<'\n';
   }

   return 0;
}
```



# Hashmap

```cpp
#include <iostream>
#include <unordered_map>

std:map<int,string> mapStudent;  //创建了一个key是int，value是string

using namespace std;
//插入元素：
//三种方法

//第一种，用insert函数插入pair
mapStudent.insert(pair<int,string>(000,"student_zero"));  

//Notice that the insert method will not cover the raw value if there are two same keys appeared, if want to cover should be used [] method.

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
  std::unordered_map<int,string> mymap; //creat a mymap with key is int and value is string.
  //we can insert the element into the hashmap or directly assign the hashmap
  
  mymap = {
    {200,"zenuo"},
    {100,"qiuqiu"},
    {50,"shouzi"},
  };
  
  //For two int types in hashmap, it can be also used to count the number appeared by directly using the ++ operator to assign the value by using []operator.
  
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
  auto it = mymap.find(200); //notice this is used to find the key 
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


```

# Hashset

```cpp
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

```

# Sorting

```cpp
// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

int main(){
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33
	
}
```

# Special String

```c++
// istringstream constructors.
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string

int main () {

  std::string stringvalues = "125 320 512 750 333";
  std::istringstream iss (stringvalues);

  for (int n=0; n<5; n++)
  {
    int val;
    iss >> val;
    std::cout << val*2 << '\n';
  }

  return 0;
}

```

Output:

```
250 
640 
1024 
1500 
666
```

```cpp
//stringstream  //leetcode word pattern 290
// swapping ostringstream objects
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream

int main () {

  std::stringstream ss;

  ss << 100 << ' ' << 200;

  int foo,bar;
  ss >> foo >> bar;

  std::cout << "foo: " << foo << '\n';
  std::cout << "bar: " << bar << '\n';

  return 0;
}
```

Output:

```
foo: 100 
bar: 200 
```