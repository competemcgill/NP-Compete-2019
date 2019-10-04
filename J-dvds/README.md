# Problem J - DVDs

### Problem statement

https://open.kattis.com/contests/q7qhgd/problems/dvds

### Solution

One thing to note is that the constraint of this problem is huge (array of at most 1 milliion integers). This suggests using a greedy algorithm with a complexity of O(n) or O(nlogn).

Let `i` and `j` be arbitrary indices in the array and `i < j`. Note that if `x_i > x_j`, then `x_i` must be popped and moved to the end of the array.

We need to find the increasing sequence 1,2,3 that starts from 1 and call those elements "in order". The results is the number of integers in the sequence that are not in order. This can be done in O(n) time, and we don't need to store the integers in any array.

### Complexity

`O(n)`
