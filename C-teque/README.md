# Problem C - Teque

### Problem statement

https://open.kattis.com/contests/q7qhgd/problems/teque

### Solution

- Pushing to the back and front are the easiest operations since we basically just need to keep track of the first and last index of the teque.
- We cannot use the same push middle algorithm like array list because shifting elements takes too much time in a linear data structure.
- Index access should be fast enough (faster than `O(n)`) since the sequence can contain up to 10^6 for this problem.
- Idea: Use 2 deques and keep them balanced, i.e keep the size difference between the deques at most 1. If the size of the whole teque is odd, then the first deque has 1 more element than the second deque. Otherwise they have the same number of elements. This way we can perform push middle in constant time by just pushing to the back of the first array, or push to the front of the second array.
- Be careful: Using linked lists work for the push operations, but your solution will TLE on get(i) operation.

### Complexity

`O(n)`
