# LeetCode in cpp

# Intro

Hi, below is my studying notes for the leetcode question.

# Content

[0001.Two Sum - hashmap](#0001.Two Sum)

[0013.Roman to Integer - hashmap](#0013.Roman to Integer)

[0141.Linked List Cycle - hashset/Two Pointer Algorithm](#0141.Linked List Cycle)

[0169.Majority Element - hashset/Moore Voting Algorithm](#0169.Majority Element)

[0202.Happy Number - hashset/extract integerd digits ](#0202.Happy Number)

[0217.Contains Duplicate - hashset](#0217.Contains Duplicate)

[0219.Contains Duplicate II - hashmap](#0219.Contains Duplicate II)

[0242.Valid Anagram - hashmap/[]operator](#0242.Valid Anagram)

[0349.Intersection of Two Arrays - hashset](#0349.Intersection of Two Arrays)

[0392. Is Subsequence](#0392. Is Subsequence)

[0268.Missing Number - sorting/bit manipulation](#0268.Missing Number)

[0746.Min Cost Climbing Stairs - dynamic programming](#0746.Min Cost Climbing Stairs)







# [0001.Two Sum](https://leetcode.com/problems/two-sum/)

## Question

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly\* one solution**, and you may not use the *same* element twice.

You can return the answer in any order. 

**Example 1:**

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]. 
```



## Solving Ideas

theta(n^2): Iterate the first list, iterate the second list with the first list index+1 without repition. The first index with the second index of any numbers from the input and determine if meet the target.

theta(n): Space for time, create a HashMap to store the target value required in each list, and search whether the target value exists in HashMap every iteration

## Answer

theta(n^2):

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool ans=false;
        vector<int>index;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((i!=j) && (nums[i]+nums[j]==target)){
                    index.push_back(i);
                    index.push_back(j);
                    ans = true;
                    break;
                }
            }
        if(ans==true)break;
        }
        return index;
    }
};
```

theta(n):

```c++
class Solution {
public:
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}
};
```



# [0013.Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

## Question

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

**Example 1:**

```
Input: s = "III"
Output: 3
Explanation: III = 3.
```



## Solving Ideas

This problem is simple to solve by using the hash map, construct a hashap and compare the real value of the symbol from back to front by adding or subtract the key corresponding value into the symbol and return the final output.

Notes on i-- and --i difference: https://stackoverflow.com/questions/24853/what-is-the-difference-between-i-and-i.

## Answer

```cpp
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
```

# [**21. Merge Two Sorted Lists**](https://leetcode.com/problems/merge-two-sorted-lists/)

## Question


You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists in a one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

**Example 2:**

```
Input: list1 = [], list2 = []
Output: []
```

**Example 3:**

```
Input: list1 = [], list2 = [0]
Output: [0]
```

## Solving Ideas

Two ways, recursive or create a new linked list to track one linked list and compare there values, since they are sorted itis easy to implement.

## Answer

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy, *temp;
        dummy = new ListNode();
        temp = dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
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
```

Recursive:

```c++
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	
```





# [0141.Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

## Question

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that `pos` is not passed as a parameter**.

Return `true` *if there is a cycle in the linked list*. Otherwise, return `false`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

## Solving Ideas

int won't work in this part because it will pass the address of each node in the list instead of the integer, each address is unique and it can be put in the hashset instead of the integer./ it won't work if the integer is repeated in the linked list for the first cycle but it can find the same address if it is repeated.

(Two pointer method)

Making two pointers point to the head, let the first pointer move one step at a time and the second pointer move two steps. If it is not a cycled list, they will reach the end and return false, else they will eventually meet.

## Answer

Hashset method;

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> L; //int won't work in this part because it will pass the address of each node in the list instead of the integer, each address is unique and it can be put in the hashset instead of the integer./ it won't work if the integer is repeated in the linked list for the first cycle but it can find the same address if it is repeated.
        while(head!=NULL){
            if(L.find(head) == L.end()){
                L.insert(head);
            }else{
                return true;
            }
            head = head->next;
        }

        return false;
    }
};
```

(Two pointer method)

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
```



# [0160.Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)

## Question

Given the heads of two singly linked-lists `headA` and `headB`, return *the node at which the two lists intersect*. If the two linked lists have no intersection at all, return `null`.

For example, the following two linked lists begin to intersect at node `c1`:

![img](https://assets.leetcode.com/uploads/2021/03/05/160_statement.png)

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

**Note** that the linked lists must **retain their original structure** after the function returns.

**Custom Judge:**

The inputs to the **judge** are given as follows (your program is **not** given these inputs):

- `intersectVal` - The value of the node where the intersection occurs. This is `0` if there is no intersected node.
- `listA` - The first linked list.
- `listB` - The second linked list.
- `skipA` - The number of nodes to skip ahead in `listA` (starting from the head) to get to the intersected node.
- `skipB` - The number of nodes to skip ahead in `listB` (starting from the head) to get to the intersected node.

The judge will then create the linked structure based on these inputs and pass the two heads, `headA` and `headB` to your program. If you correctly return the intersected node, then your solution will be **accepted**.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/05/160_example_1_1.png)

```
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
```

## Solving Ideas

Hash method: Because these two linked lists will me met if there has common node, we can create a hash set to store the first one location, and use find to find if the second list will repeat the first one location. else return NULL, not find.

Two pointer differnce method(less space): We can first to count the length of each list, and find the difference of each list. If they are not equal, let the longer one go first until they reached out the same length, while traverse both lists and compare their node for each traverse, if they are the same, return the meeting node else return NULL.

## Answer

Hashset

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> L;
        while(headA!=NULL){
            L.insert(headA);
            headA = headA -> next;
        }
        while(headB!=NULL){
            if(L.find(headB)!=L.end()){
                return headB;
            }
            headB = headB ->next;
        }
        return NULL;
    }
};
```

Using Two pointer difference

```cpp
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int n = 0;
		int m = 0;
		ListNode* ptr1 = headA;
		ListNode* ptr2 = headB;
		while(ptr1 != NULL){
			n++;
			ptr1 = ptr1 -> next;
		}
		while(ptr2 != NULL){
			m++;
			ptr2 = ptr2 -> next;
		}
		int t = abs(n - m);
		if(n > m){
			while(t){
				headA = headA -> next;
				t--;
			}
		}
		else{
			while(t){
				headB = headB -> next;
				t--;
			}
		}
		while(headA != NULL and headB != NULL){
			if(headA == headB){
				return headA;
			}
            headA = headA -> next;
            headB = headB -> next;
		}
		return NULL;
	}
};
```



# [0169.Majority Element](https://leetcode.com/problems/majority-element/)

## Question

Given an array `nums` of size `n`, return *the majority element*.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

**Example 1:**

```
Input: nums = [3,2,3]
Output: 3
```

**Example 2:**

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```



## Solving Ideas

Insert each num into the hashtable(key), if found, let the hashvalue corresponding +1, after that, compare the largest value corresponding to each key in the hashmap and extract out the largest value and return to its position

## Answer

Hashmap solution: O(n) in both time and space complexity.

```cpp
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
```

Boyer-Moore Voting Algorithm method: O(n) in Time and O(1) in Space complexity.

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate = nums[i];
            }
            count += ((nums[i]==candidate) ? 1:-1);
        }
        return candidate;
    }
};

//Same way to do but figure out for loop can directly itrate num
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, majority;
        for (int num : nums) {
            if (!counter) {
                majority = num;
            }
            counter += num == majority ? 1 : -1;
        }
        return majority;
    }
};
```



# [0202.Happy Number](https://leetcode.com/problems/happy-number/)

## Question

Write an algorithm to determine if a number `n` is happy.

A **happy number** is a number defined by the following process:

- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.
- Those numbers for which this process **ends in 1** are happy.

Return `true` *if* `n` *is a happy number, and* `false` *if not*.

**Example 1:**

```
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

**Example 2:**

```
Input: n = 2
Output: false
```



## Solving Ideas

by using the modulus to extract each digit and add the square of them one by one to the sum. divide them by 10 until they are equal to zero in a while loop, determine if this sum is equal to 1, if not iterate the loop again;

Because the question metion it will loop in an endless cycle if it can't have 1, so it is used the hash_set to implement, insert the key of each value if it is new key, or it is repeating the cycle then return false, unhappy :<

## Answer

```cpp
class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> set;
        while(n != 1){
            if(set.find(n) == set.end()){
                set.insert(n);
            }else{
                return false;
                break;
            }
            
            int sum =0;
            while(n != 0){
                sum += pow(n%10,2);
                n = n/10;
            }
            n = sum;
        }
        return true;
    }      
};
```

# [0205.Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)

## Question

Given two strings `s` and `t`, *determine if they are isomorphic*.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

**Example 1:**

```
Input: s = "egg", t = "add"
Output: true
```

**Example 2:**

```
Input: s = "foo", t = "bar"
Output: false
```

**Example 3:**

```
Input: s = "paper", t = "title"
Output: true
```

## Solving Ideas

Assign a hashmap which the key coorepsonding to the char of string x and value to the char of string Y, also assign a hashset which store the char of string y, for each iteration, it will check first if the char find in s is already mapped in the string t, if they appear before, the corresponded key value should be equal to the current index char of string t, if not, return false; And if it is not found in the string s, then it will check if y can be found, if y can be found, that means it has been inserted before which will return false; and if not found, it will insert the key of char s and the value of char t, and also inserting the set value of y to find.

## Answer

```cpp
class Solution {
public:
bool isIsomorphic(string X, string Y)
{
    // if 'X' and 'Y' have different lengths, they cannot be isomorphic
    if (X.length() != Y.length()) {
        return false;
    }
 
    // use a map to store a mapping from characters of string 'X' to string 'Y'
    unordered_map<char, char> map;
 
    // use set to store a pool of already mapped characters
    unordered_set<char> set;
 
    for (int i = 0; i < X.length(); i++)
    {
        char x = X[i], y = Y[i];
 
        // if 'x' is seen before
        if (map.find(x) != map.end())
        {
            // return false if the first occurrence of `x` is mapped to a
            // different character
            if (map[x] != y) {
                return false;
            }
        }
 
        // if 'x' is seen for the first time (i.e., it isn't mapped yet)
        else {
            // return false if 'y' is already mapped to some other char in 'X'
            if (set.find(y) != set.end()) {
                return false;
            }
 
            // map 'y' to 'x' and mark it as mapped
            map[x] = y;
            set.insert(y);
        }
    }
 
    return true;
}
 
};
```

# [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

## Question

Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```
Input: head = [1,2]
Output: [2,1]
```

**Example 3:**

```
Input: head = []
Output: []
```

## Solving Ideas

To reverse a linked list, simply added a prev node to reverser the arrow of the linked list and set the head to last one.



## Answer

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head;
        ListNode *prev = NULL, *next = NULL;
        while(current!=NULL){
            next = current -> next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
};
```



# [0217.Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

## Question

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

 **Example 1:**

```
Input: nums = [1,2,3,1]
Output: true
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: false
```

**Example 3:**

```
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
```

## Answer

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> A;
        for(int i=0;i<nums.size();i++){
            if(A.find(nums[i])!=A.end()){
                return true;
            }
            A.insert(nums[i]);
        }
        return false;
    }
};

//sorting method:
bool containsDuplicate1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i=0; i<int(nums.size())-1; i++) {
        if (nums[i]==nums[i+1])
            return true;
    }
    return false;    
}
```

# [0219.Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)

## Question

Given an integer array `nums` and an integer `k`, return `true` if there are two **distinct indices** `i` and `j` in the array such that `nums[i] == nums[j]` and `abs(i - j) <= k`.

 **Example 1:**

```
Input: nums = [1,2,3,1], k = 3
Output: true
```

**Example 2:**

```
Input: nums = [1,0,1,1], k = 1
Output: true
```

**Example 3:**

```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

## Solving Ideas

//That's the place really got confused, because it will occur more than twice, the value appear agian should be replaced its orginal index since it will always compare to the closet to find which value is smaller.

This can be done by using the hashmap, notice that find method in hashmap is used to find the key value, so in this question the array nums cannont be stored as value instead of should be stored as keys. And because the appeared number will always follow larger than the previous one, so the question is asked to compare smaller, so we can always replace the newest appeared number with new indice and  by calling the key value cooresponding value to minus the current index to compare with k.

## Answer

```cpp
// find the location of same number
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;
        for(int i=0;i<nums.size();i++){
            if(myMap.find(nums[i])!=myMap.end() && abs(i-myMap[nums[i]])<=k){
                return true;
            }
        myMap[nums[i]] = i; //That's the place really got confused, because it will occur more than twice, the value appear agian should be replaced its orginal index since it will always compare to the closet to find which value is smaller.
        }
        return false;
    }
};
```



# [0242.Valid Anagram](https://leetcode.com/problems/valid-anagram/)

## Question

Given two strings `s` and `t`, return `true` *if* `t` *is an anagram of* `s`*, and* `false` *otherwise*.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 **Example 1:**

```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```
Input: s = "rat", t = "car"
Output: false
```

## Solving Ideas

In this question, because change the letter order will not affect anything, so we can simply by using hashmap to count the appearnce of each character and make comparsion of the the second string. If they have the same character overall, return true elese false;

Sorting method is to sort their letter from the beginning to the end and compare if they are equal.

## Answer

```cpp
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
```

# [0268.Missing Number](https://leetcode.com/problems/missing-number/)

## Question

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array.*

**Example 1:**

```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 2:**

```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 3:**

```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

## Solving Ideas

Sorting Idea: We can sort from the begin to end, because there will be a missing number so if the current index is not equal to i, then it will return the missing value-i. else it will return the last missing number which is the nums.size();

Bitting manipulation: Retrived From: (https://leetcode.com/problems/missing-number/discuss/69777/C%2B%2B-solution-using-bit-manipulation) For people who don't understand this solution: what he's doing is he's using the bitwise XOR operator to single out the missing number. How? First, we need to understand the properties of XOR: firstly, XOR'ing a number by itself results in 0. So if we have 1 ^ 1, this will equal 0. Secondly, XOR is commutative and associative - what this means is we can re-order our XOR operations in any way we want and it will result in the same value we would have if we didn't. Finally, a number XOR'd by 0 will result in the same number unchanged. So, essentially, by XOR'ing all the numbers from 0 to n, and all the numbers in the array, we will end up XOR'ing 2 of every number except for the missing one. As we know, it doesn't matter which order we XOR these numbers in - as long as we XOR 2 of the same number, it will result in 0. So eventually we will get 0 ^ the missing number, which, due to the third property I mentioned, will simply equal the missing number. If you're not convinced as to how these properties work, I would recommend taking a quick look as to how they work.

Simply that means by using the bit operator xor we can exculde all the number exist and by xor the index to return the missing value.

## Answer

Sorting:

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return nums.size();
    }
};
```

Bit manipulation:

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        return result;
    }
};
```

# [0290.Word Pattern](https://leetcode.com/problems/word-pattern/)

## Question

Given a `pattern` and a string `s`, find if `s` follows the same pattern.

Here **follow** means a full match, such that there is a bijection between a letter in `pattern` and a **non-empty** word in `s`.

 **Example 1:**

```
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
```

**Example 2:**

```
Input: pattern = "abba", s = "dog cat cat fish"
Output: false
```

**Example 3:**

```
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
```

## Solving Ideas

For this question there are several steps need to take. 

First, in order to reference the string in s, we can use stringstream to conver the string type with empty space into a vector being able to call index.

Second, we need to create a set, and hashmap, with each time iterate the pattern.size(), we will determine if the first number they corresponded to is equal to the previous one they stored before, if not, return false;

For the empty we can put the char for the key and value for the string specific index, since same letter correspond to one string, we can use this characteristics to make if else loop.

## Answer

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> v;
        // word variable to store word in the string s
        string word;
        // making a string stream
        stringstream iss(s);
       // Push each word in vector
        while (iss >> word)
            v.push_back(word);
      
        set<string> S; // To check if the same word is not mappped with another character
      // If vector and pattern are of different sizes there can be no mapping
        if (pattern.size() != v.size())
            return false;
        unordered_map<char, string> m;
        for (int i = 0; i < pattern.size(); i++) {
            // Take current character in pattern
            char ch = pattern[i];
            // If current character is present in the map
            if (m.find(ch) != m.end()) {
            //Check if the string mapped to that character is different or not if yes
			//return false
                if (m[ch] != v[i])
                    return false;
            }
            // If not present in the map
            else {
                // Check if the string is previously in set
                // If it is in set it means it is already mapped return false
                if (S.count(v[i]) > 0)
                    return false;
                // Other wise insert into map and set
                m[ch] = v[i];
                S.insert(v[i]);
            }
        }
        return true;
    }
};
```



# [0349.Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)

## Question

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must be **unique** and you may return the result in **any order**.

 

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

**Example 2:**

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```

## Solving Ideas

Use the hashset to store the first array and use count to find out if the number exist, if exist, use erase to erase the number that appeared in the origin hashset and continue return the final array.

## Answer

```cpp
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
```

```cpp
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
```

# [0350.Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

## Question

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must appear as many times as it shows in both arrays and you may return the result in **any order**.

 

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
```

**Example 2:**

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
```

## Solving Ideas

By using calling the Index of Hashmap to count the appearance of the number in nums1, each appear will let the key plus one, iterate the nums2 and minus their value if they have cooresponded key will give a minus value on that originoal one thus it must be greater or equal to zero.

## Answer

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> H;
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            H[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            H[nums2[i]]--;
            if(H[nums2[i]]>=0){
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};
```

# [0392. Is Subsequence](https://leetcode.com/problems/is-subsequence/)

## Question

Given two strings `s` and `t`, return `true` *if* `s` *is a **subsequence** of* `t`*, or* `false` *otherwise*.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).


**Example 1:**

```
Input: s = "abc", t = "ahbgdc"
Output: true
```

**Example 2:**

```
Input: s = "axc", t = "ahbgdc"
Output: false
```

## Solving Ideas

Some concepts, string in cpp is iteratable. Put the t into a hashmap with each value corresponds to the index. Find s string and compare the found one value before. The previous one should be smaller than the next one and if not found return false.

Problem countered: repetitive t = "baab".

Another Idea: loop the first string with the first character, inside that loop. loop the string t until find the mathced t[i] = s[j], record i and j value, j important, loop the second string, the second loop will start from the found index of j, 

## Answer

```cpp
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
```



# [0724.Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)

## Question

Given an array of integers `nums`, calculate the **pivot index** of this array.

The **pivot index** is the index where the sum of all the numbers **strictly** to the left of the index is equal to the sum of all the numbers **strictly** to the index's right.

If the index is on the left edge of the array, then the left sum is `0` because there are no elements to the left. This also applies to the right edge of the array.

Return *the **leftmost pivot index***. If no such index exists, return -1.

 

**Example 1:**

```
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
```

**Example 2:**

```
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
```

## Solving Ideas

Because we want to find out the rightsum and leftsum with an index. It can be implemented by adding their total sum, and for each incremenation recording the rightsum, the rightsum can be simply equal to the total sum minus left sum plus the next pivot index value.

## Answer

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0, leftsum=0;
        for(int x: nums) sum+=x;
        for(int i=0;i<nums.size();i++){
            if (leftsum == sum - leftsum - nums[i]) return i;
            leftsum += nums[i];
        }
        return -1;
    }
};
```



# [0746.Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)

## Question

You are given an integer array `cost` where `cost[i]` is the cost of `ith` step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

Return *the minimum cost to reach the top of the floor*.

**Example 1:**

```
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
```

**Example 2:**

```
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
```



## Solving Ideas

This question is kind of tricky, main idea is to compare the smallest and add them during the movement of array and find the smallest cost. Notice it can either climb one or two steps. A diagram can better represent the algorithm below.

![image-20220710221114831](/Users/richardqiu/Library/Application Support/typora-user-images/image-20220710221114831.png)

## Answer

```cpp
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    for(int i=2;i<n;i++){
        cost[i]+= min(cost[i-1],cost[i-2]); //Take either 1 or 2 step
    }
    return min(cost[n-1],cost[n-2]);
}
};
```



# [1480.Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)

## Question

Given an array `nums`. We define a running sum of an array as `runningSum[i] = sum(nums[0]…nums[i])`.

Return the running sum of `nums`.

 

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```

**Example 2:**

```
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```

**Example 3:**

```
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
```



## Solving Ideas

Following the question said that each index inrementation add their previous sum, it can be used by using the accumulate function.

Anothe method is using the partial sum or prefix method which all can return the result.

## Answer

Time complexitity n using accumulate

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSum;
        int sum=0;
        for(int i=1;i<=nums.size();i++){
            runningSum.push_back(accumulate(nums.begin(),nums.begin()+i,sum));
        }
        return runningSum;
    }
};
```

Another way is to use partial_sum function directly find the value.

```cpp
class Solution {
public:
vector<int> runningSum(vector<int>& nums) {
    partial_sum(nums.begin(), nums.end(), nums.begin());
    return nums;
}
};
```

Prefix Sum

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int> nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};
```

