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
