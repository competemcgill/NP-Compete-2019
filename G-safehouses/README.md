# Problem G - Safe Houses

### Problem statement

https://open.kattis.com/contests/q7qhgd/problems/safehouses

### Solution

- For each spy, we can simply find manually their distance from a safe house.
- Inserting all the spies into a grid, we run BFS for every spy and find the nearest safe house.
- Alternatively, we can iterate over all pairs of spy/safe house and calculate their Manhattan distance in `O(1)` to find the answer.
- BONUS: There is an O(n^2) solution. Can you find it?

### Complexity

`O(n^4)` but `O(n^3)` in practice
