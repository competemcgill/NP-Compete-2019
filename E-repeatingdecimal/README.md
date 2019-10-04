# Problem E - Repeating Decimal

### Problem statement

https://open.kattis.com/contests/q7qhgd/problems/repeatingdecimal

### Solution

Repeat the following operation `c` times to extract each digit:

```
a = a * 10
d = a / b   # note that this is an integer division
print(d)
a = a - b*d
```
