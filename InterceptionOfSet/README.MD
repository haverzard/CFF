# Interception Of Set
## Description
Find the intercept elements between 2 sets (A and B).

## Problem 1
Interception between 2 sorted sets.
### The Idea
This is like merge sort where we iterate both sets at the same time. There are 3 cases:
- If A[i] < B[j], we go to the next i.
- If A[i] > B[j], we go to the next j.
- If A[i] == B[j], we add this element to our solution.
### Time Complexity
O(n+m) where n is set A's size and m is set B's size.
### Solution
```solution1.cpp```

## Problem 2
Interception between 2 random sets.
### The Idea
We just sort both sets using quick sort and do the same thing just like problem 1.
### Time Complexity
O(n log n + m log m)
### Solution
```solution2.cpp```

## Problem 3
Interception between 1 small set and 1 very big set.
### The Idea
We just sort both sets using quick sort and use binary search instead for each elements in the small set. The time complexity is the same, but it's better than using the same idea at problem 1.
### Time Complexity
O((n+m) log m)
### Solution
```solution3.cpp```