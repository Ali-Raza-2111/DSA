# 🐍 DSA in Python — Beginner Practice Questions

> Solve each question below in Python. Paste your solution in the provided code block.
> These questions progressively build core DSA concepts needed for LeetCode & Codeforces.

---

## Q1. Two Sum (Arrays + Hash Map)

**Difficulty:** Easy | **Topic:** Arrays, Hash Maps

Given an array of integers `nums` and an integer `target`, return the **indices** of the two numbers that add up to `target`. You may assume each input has exactly one solution, and you may not use the same element twice.

**Example:**
```
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]   # because nums[0] + nums[1] == 9
```

**Hint:** A brute-force approach uses two loops (O(n²)). Can you do it in O(n) using a dictionary?

### Your Solution:
```python




```

---

## Q2. Reverse a String (Two Pointers)

**Difficulty:** Easy | **Topic:** Strings, Two Pointers

Write a function that reverses a string **in-place** (given as a list of characters).

**Example:**
```
Input:  ['h', 'e', 'l', 'l', 'o']
Output: ['o', 'l', 'l', 'e', 'h']
```

**Hint:** Use two pointers — one at the start, one at the end — and swap them.

### Your Solution:
```python




```

---

## Q3. Find the Maximum Element (Arrays)

**Difficulty:** Easy | **Topic:** Arrays, Iteration

Given a list of integers, find the **maximum** element **without** using the built-in `max()` function.

**Example:**
```
Input:  [3, 1, 4, 1, 5, 9, 2, 6]
Output: 9
```

**Hint:** Keep a variable to track the largest value seen so far while looping through the list.

### Your Solution:
```python




```

---

## Q4. Check if Array is Sorted (Arrays)

**Difficulty:** Easy | **Topic:** Arrays, Iteration

Write a function that returns `True` if the given list is sorted in **non-decreasing** order, and `False` otherwise.

**Example:**
```
Input:  [1, 2, 2, 3, 4]  →  True
Input:  [1, 3, 2, 4]     →  False
```

**Hint:** Compare each element with the next one.

### Your Solution:
```python




```

---

## Q5. Linear Search (Searching)

**Difficulty:** Easy | **Topic:** Arrays, Searching

Given a list and a target value, return the **index** of the target if found, otherwise return `-1`. Do **not** use Python's `.index()` method.

**Example:**
```
Input:  nums = [10, 20, 30, 40, 50], target = 30
Output: 2
```

**Hint:** Loop through the array and compare each element with the target.

### Your Solution:
```python




```

---

## Q6. Binary Search (Searching)

**Difficulty:** Easy | **Topic:** Arrays, Searching, Divide & Conquer

Given a **sorted** list and a target value, implement **Binary Search** to return the index of the target. Return `-1` if not found.

**Example:**
```
Input:  nums = [1, 3, 5, 7, 9, 11], target = 7
Output: 3
```

**Hint:** Maintain `low` and `high` pointers. Check the middle element — if it's the target, return; if it's smaller, search right half; if larger, search left half.

### Your Solution:
```python




```

---

## Q7. Bubble Sort (Sorting)

**Difficulty:** Easy | **Topic:** Sorting

Implement **Bubble Sort** to sort a list of integers in ascending order.

**Example:**
```
Input:  [64, 34, 25, 12, 22, 11, 90]
Output: [11, 12, 22, 25, 34, 64, 90]
```

**Hint:** Repeatedly step through the list, compare adjacent elements, and swap them if they are in the wrong order. Repeat until no swaps are needed.

### Your Solution:
```python




```

---

## Q8. Valid Parentheses (Stack)

**Difficulty:** Easy | **Topic:** Stack, Strings

Given a string `s` containing only `(`, `)`, `{`, `}`, `[`, `]`, determine if the input string has **valid** (properly matched and nested) brackets.

**Example:**
```
Input:  "({[]})"  →  True
Input:  "({[})"   →  False
Input:  ""        →  True
```

**Hint:** Use a stack (Python list). Push opening brackets, and for every closing bracket check if it matches the top of the stack.

### Your Solution:
```python




```

---

## Q9. Reverse a Linked List (Linked List)

**Difficulty:** Easy | **Topic:** Linked List, Pointers

Given the head of a singly linked list, reverse it and return the new head.

```
Input:  1 → 2 → 3 → 4 → 5
Output: 5 → 4 → 3 → 2 → 1
```

**Hint:** Use three pointers — `prev`, `curr`, and `next`. In each step, reverse `curr.next` to point to `prev`, then move all pointers one step forward.

**Starter Code:**
```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseList(head):
    # Your code here
    pass
```

### Your Solution:
```python




```

---

## Q10. Climbing Stairs (Recursion / Dynamic Programming)

**Difficulty:** Easy | **Topic:** Recursion, DP

You are climbing a staircase with `n` steps. Each time you can climb **1 or 2** steps. In how many **distinct ways** can you reach the top?

**Example:**
```
Input:  n = 2  →  Output: 2   (1+1 or 2)
Input:  n = 3  →  Output: 3   (1+1+1, 1+2, 2+1)
Input:  n = 5  →  Output: 8
```

**Hint:** This is basically the Fibonacci sequence! `ways(n) = ways(n-1) + ways(n-2)`. Try a recursive solution first, then optimize with memoization or a simple loop.

### Your Solution:
```python




```

---

## 📚 What You'll Learn From These Questions

| # | Question | Key Concept |
|---|----------|-------------|
| 1 | Two Sum | Hash Map lookups in O(1) |
| 2 | Reverse String | Two-pointer technique |
| 3 | Find Maximum | Array traversal |
| 4 | Is Sorted | Array comparison |
| 5 | Linear Search | Sequential search O(n) |
| 6 | Binary Search | Divide & conquer O(log n) |
| 7 | Bubble Sort | Basic sorting algorithm |
| 8 | Valid Parentheses | Stack data structure |
| 9 | Reverse Linked List | Pointer manipulation |
| 10 | Climbing Stairs | Recursion & Dynamic Programming |

> **Next Steps:** Once you solve all 10, try these on [LeetCode](https://leetcode.com):
> - Two Sum (#1), Valid Parentheses (#20), Reverse Linked List (#206), Climbing Stairs (#70), Binary Search (#704)

Good luck! 🚀
