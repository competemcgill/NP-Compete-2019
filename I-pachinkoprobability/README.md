# Problem I - Pachinko Probability

### Problem statement

https://open.kattis.com/contests/q7qhgd/problems/pachinkoprobability

### Solution

#### Dynamic programming approach

- States: the nodes
- Transitions: the pointers to the next nodes
For every node we sum the number of paths to reach it from its parents, and summing over both good gates and all gates this way.

#### DFS approach

The idea is similar to the DP approach presented above, but now we start our DAG traversal from nodes with indegree = 0 instead.

Let the total number of paths to all leaf nodes in a DAG starting from a node u be `P(u)`. One observation is that if the graph has only 1 node, i.e u is both the root and leaf, then `P(u) = 1`. We can show that for every u, `P(u) = sum of P(v)` where v is a child of node u. Our answer is the sum of all `P(u)` where `indegree(u) = 0`

### Note

A concern that the keen-eyed observer might see is that the answer can explode outside the range of a 64-bit integer with a cleverly made graph. This does not occur in the test cases, but one shouldbe aware of weird edge cases when solving the problem.

### Complexity

`O(n+m)`
