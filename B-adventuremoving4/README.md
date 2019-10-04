# Problem B - Adventures in Moving -- Part IV

### Problem statement

https://open.kattis.com/contests/q7qhgd/problems/adventuremoving4

### Solution

#### First approach

This one is a funky dynamic programming problem

The key to a DP problem is figuring out what the states are, what the transitions are, and whether that's fast enough
The states are:
Pairs of (number of station reached, fuel left in car)
The transitions are:
Amount you fill up the gas tank at each station (up to full)

Then, there are `100*200` states and at each state we fill up to 200 literes (only whole numbers) for a time of
`100*200*200 = 4*10^6` operations, which is fast enough

Thus, we can use this DP formulation

#### Second approach

Another DP approach that can be used to solve this problem is go iterate over all kilometer from km 0 to the destination. We can set up a lookup table of size Total kilometers * Tank capacity. Initially when we're at km 0, the cost of reaching km 0 with tank capacity = 100 is 0 (since we are just starting). Let's then move our car km by km. At km `i` and tank capacity `j`, `cost(i,j) = cost(i-1, j+1)`, because we lose 1 liter of gas for every km we travel.

That can almost get us to the solution. If there is a gas station at kilometer i, we can decide whether it's better to fill up the gas tank to a certain amount by a simple calculation that takes at most 200 iterations (max tank capacity). Finally, we check if it's possible for us to reach the destination with a half full gas tank, i.e `cost(destination, 100) < INFINITY`, then we can simply return the cost.

### Complexity

- First approach: `O(n*m^2)` where n = number of stations, m = tank capacity
- Second approach `O(k*c)` where k = road length, c = tank capacity
