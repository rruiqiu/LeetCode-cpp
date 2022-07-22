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
