# Problem H - Mega Inversions

### Problem statement

https://open.kattis.com/contests/q7qhgd/problems/megainversions

### Solution

There are two exceptionally hard problems on NP-Compete this year: Megainversions (this problem) and Feistel Fun.
This is the second hardest problem because of the relatively obscure data structures required to solve it.

The question is asking for triplets of decreasing integers on a given array.
In order to count this number, we also keep track of decreasing "singlets" of numbers
and decreasing doubles of numbers with the least number being n.

We then go through the array one by one:
Each integer always ends off one singlet (itself) and ends off
many pairs (x,y) where y is our number and x was a singlet greater than y seen before.
Each number also ends off many triplets (x,y,z) where (x,y) was a pair ended off by y seen before.
Note that to count triplets we don't ever need to know x, just how many pairs that ended in y.

To simplify even further, we essentially have 3 arrays of size N, where, whenever we see a new number x:
array 1 is incremented by 1 @ x
array 2 @ x is incremented by the sum of all values greater than x in array 1
array 3 @ x is incremented by the sum of all values greater than x in array 2

However, we cannot simply sum over these arrays, because that takes O(N) time for a O(N^2) solution, which will TLE.
Instead, we use segment trees to use O(log N) time per sum, giving O(N log N) time.

This problem somewhat resembles a DP problem from summer training, but the O(N^2) solution from that problem
can't be applied here, since N = 10^5.

The segment trees we use are not the implementation used in Competitive Programming 3 (Chapter 2.4.3), but rather the one described here:
https://codeforces.com/blog/entry/18051

### Note

Fenwick Tree - Binary Indexed Tree (BIT) can also be used to solve this problem. You can read more about it in Competitive Programming 3 (Chapter 2.4.4)

### Complexity

`O(nlog(n))`
