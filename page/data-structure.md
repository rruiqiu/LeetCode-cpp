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

	//for matrix
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix[i].size(); j++){
		}
	    cout << matrix[i][j];
		
	}//print the matrix
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

# Linked List

```cpp
// C++ program for the above approach
#include <iostream>
using namespace std;

// Node class to represent
// a node of the linked list.
class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Linked list class to
// implement a linked list.
class Linkedlist {
    Node* head;

public:
    // Default constructor
    Linkedlist() { head = NULL; }
    Node *getHead(){
        return head;
    }// to get the head of the current linked list
    void setHead(Node *ptr){
        head = ptr;
    }// to set the new head a linked list
  
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position
    void deleteNode(int);
};


// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be
    // deleted is less than the length
    // of the linked list.
    if (ListLen < nodeOffset) {
        cout << "Index out of range"
            << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Deleting the head.
    if (nodeOffset == 1) {

        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1) {

        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}

// Function to insert a new node.
void Linkedlist::insertNode(int data)
{
    // Create the new Node.
    Node* newNode = new Node(data);0
      
    }

    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {

        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
}

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node* temp = head;

    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node *dummy, *temp;
        dummy = new Node();
        temp = dummy;
        while(list1 && list2){
            if(list1->data < list2->data){
                temp->next = list1;
                list1 = list1 ->next;
            }else{
                temp->next = list2;
                list2 = list2 ->next;
            }
            temp=temp->next;

        }
        if(list1){
            temp->next = list1;
        }else{
            temp->next = list2;
        }
        return dummy->next;
    }
};


// Driver Code
int main()
{
    Solution res;
    Linkedlist list;
    Linkedlist ans;
    Linkedlist result;
    // Inserting nodes
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    Linkedlist list2;

    // Inserting nodes
    list2.insertNode(1);
    list2.insertNode(3);
    list2.insertNode(4);
    list2.insertNode(5);
    Node* ptr1 = list.getHead();
    Node* ptr2 = list2.getHead();
    
    cout << "Elements of the list are: ";

    result.setHead(res.mergeTwoLists(ptr1, ptr2));//ans linked to the head of the

    // Print the list
    result.printList();
    cout << endl;

    // Delete node at position 2.
    list.deleteNode(2);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    return 0;
}

//find MiddleNode and return the rest
    ListNode* middleNode(ListNode *head) {
        // write your code here.
        int length=0;
        ListNode *temp =head;
        while(temp!=NULL){
            length ++;
            temp = temp->next;
        }
        temp = head;
        int halfLength = length/2;
        for(int i=0;i<halfLength;i++){
            temp = temp ->next;
        }
        return temp;
    }
//swap two listNodes
    ListNode* swapNodes(ListNode *head, int x, int y) {
        // write your code here
        // swap two nodes given two values
        // find the two values first
        // temp ListNode to store the net of v1
        // the net of v1 = the net of v2
        // the prevX of v1 = the prevX of v2
        if(x==y){
            return head;
        }

        ListNode *prevX = NULL, *currX = head;
        while(currX && currX->val !=x){
            prevX = currX;
            currX = currX->next;
        }
        ListNode *prevY = NULL, *currY = head;
        while(currY && currY->val !=y){
            prevY = currY;
            currY = currY->next;
        }
        if(currX == NULL || currY == NULL){
            return head;
        }
        if (prevX != NULL)
            prevX->next = currY;
        else // Else make y as new head
            head = currY;
    
        // If y is not head of linked list
        if (prevY != NULL){prevY->next = currX;}
        else{head = currX;} // Else make  as new head
            
    
        // Swap net pointers
        ListNode* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
        return head;
    }
```





![image-20221205105519332](../../../Library/Application Support/typora-user-images/image-20221205105519332.png)



# Bit manipulation

```cpp
Bitwise Operators:

Not ~;
And &;
or |;
XOR ^;  // 1^1 = 0;
Left Shift <<;
Right Shift >>;

Left Shift:  0b001 left shift one -> 0b010
1 << 1 = 2 = 2^1
1 << 2 = 4 = 2^2 ,1 << 3 = 8 = 2^3
1 << 4 = 16 = 2^4
…
eg: lets take N=22; which is 00010110 in Binary Form.
      Now, if “N is left-shifted by 2” i.e N=N<<2 then N will become N=N*(2^2). Thus, N=22*(2^2)=88 which can be written as 01011000.
        
Right Shift: 0b010 right shift one -> 0b001
eg: lets take N=32; which is 100000 in Binary Form.
     Now, if “N is right-shifted by 2” i.e N=N>>2 then N will become N=N/(2^2). Thus, N=32/(2^2)=8 which can be written as 1000.

//// Bitwise XOR based method 
x = x ^ x; // x becomes 0 
x = x ^ x; // x remains 0 
x = x ^ x; // x remains 0
// XOR can be used to find the extra number;
		void swap(int a, int b){
      a = a^b;
      b = a^b;
      a = a^b;
      cout << a << b;
    }
// fidn the non-repeated num in an arrary
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        
        return result;
    }
// find the missing number of an arry
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;
        for (int i = 0; i < n; i++) {
            result ^= i ^ nums[i];
        }
        return result;
    }
//reverse bits
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= n & 1;
            n >>= 1;
        }
        
        return result;
    }
//Counting bits;
/*
    Given int, return array: for each i, ans[i] is # of 1's
    Ex. n = 2 -> [0,1,1], 0 = 0 has 0, 1 = 1 has 1, 2 = 10 has 1

    x = 1001011101 = 605
    x'= 0100101110 = 302
    Differ by 1 bit, by removing LSB: f(x) = f(x / 2) + (x mod 2)

    Time: O(n)
    Space: O(n)
*/
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            //                 i / 2      i % 2
            result[i] = result[i >> 1] + (i & 1);
        }
        
        return result;
    }
//add two string a and b in binary format
/* Example 1:

Input: a = "11", b = "1"
Output: "100" */
		string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        string ans;
        int carry = 0;w
        
        while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry += a[i] - '0';//convert char to int to allow integer operation
                i--;
            }
            if(j>=0){
                carry += b[j] - '0';
                j--;
            }
            
            ans += (carry%2 + '0');//convert int back to char and + is adding the number to 		the end
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


Just like the & and && operator, the double Operator is a "short-circuit" operator.

For example:

if(condition1 || condition2 || condition3)
If condition1 is true, condition 2 and 3 will NOT be checked.

if(condition1 | condition2 | condition3)
  
  
```



![Screenshot 2022-12-01 at 7.50.55 PM](../../Screenshot 2022-12-01 at 7.50.55 PM.png)

# Data structure alignment

```cpp
using x86 32bits -> 4bytes;
struct X
{
    short s; /* 2 bytes */
             /* 2 padding bytes */
    int   i; /* 4 bytes */
    char  c; /* 1 byte */
             /* 3 padding bytes */
};

struct Y
{
    int   i; /* 4 bytes */
    char  c; /* 1 byte */
             /* 1 padding byte */
    short s; /* 2 bytes */
};

struct Z
{
    int   i; /* 4 bytes */
    short s; /* 2 bytes */
    char  c; /* 1 byte */
             /* 1 padding byte */
};

const int sizeX = sizeof(struct X); /* = 12 */
const int sizeY = sizeof(struct Y); /* = 8 */
const int sizeZ = sizeof(struct Z); /* = 8 */
```

