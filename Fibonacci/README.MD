# Fibonacci
## Description
Find the n-th fibonacci number

### The Idea
Because f(n) = f(n-1) + f(n-2) and f(n-1) = f(n-2) + f(n-3), we can see that this is recursive and dynamic programming can be applied with each step using 2 variables to store the last 2 fibonacci numbers.
### Space Complexity
O(1)
### Time Complexity
O(n)
### Solution
```solution.cpp```