# Problem A - Suspension Bridges

### Problem statement

https://open.kattis.com/contests/q7qhgd/problems/suspensionbridges

### Solution

If you play around with the equation to solve, you might realize that it has only one solution (you can play around in python to verify this). Lucky for us, sinh and cosh are both built in (but wouldn't be difficult to recreate with exp). This means that the difference between the functions `a+s` and `a*cosh(d/(2a))` will be positive on one side of the root and negative on the other. Thus, it can be binary searched.

Note that althouh d and s are bounded in the problem, these both guarantee nothing about the value of a. Thus, we should be careful about the bounds of the binary search (or be clever about how to set them).

The lower bound is clearly at least 0, since `a*cosh(d/(2a))` approaches infinity as a approaches 0. On the other hand, the upper bound is nonobvious.

Here, we set the upper bound to be `10^8` to be super safe, since it makes us more sure of the answer while sacrificing next to no time at all. We could also test exponentially higher values of a until we reach a sign change and then set the lower bound there

We set an "acceptable error" to stop the binary search when we know the true value within `10^-10`

Then, the absolute error is almost certainly within `10^-4` of the true answer

### Complexity

`O(log(d))`
