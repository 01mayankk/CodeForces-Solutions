# 1840D - Wooden Toy Festival

## 🔗 Problem Link

https://codeforces.com/problemset/problem/1840/D

---

## 💡 Approach

We need to divide all toy positions into **at most three groups** such that the maximum distance from any toy to its assigned center is minimized.

Instead of directly searching for the answer, we **binary search** on the maximum allowed distance `x`.

For a fixed value of `x`:

* Each group can cover an interval of length `2 × x`.
* After sorting the positions, greedily cover as many consecutive toys as possible with the current group.
* Whenever a toy lies outside the current interval, start a new group.
* If all toys can be covered using **three or fewer groups**, then `x` is feasible.

Since feasibility is monotonic (if a value works, every larger value also works), binary search finds the minimum possible answer.

---

## 📝 Algorithm

1. Sort the toy positions.
2. Binary search the answer from `0` to `max_position - min_position`.
3. For each middle value:

   * Start the first group from the leftmost uncovered toy.
   * Extend the current group while the distance remains within `2 × mid`.
   * If a toy cannot be covered, start a new group.
4. If no more than **three groups** are required:

   * Try a smaller answer.
5. Otherwise:

   * Increase the search range.
6. Output the minimum feasible value.

---

## 📝 Dry Run

### Input

```text
Positions = [1, 2, 4, 8, 10]
```

### Step 1: Sort

```text
1 2 4 8 10
```

### Step 2: Binary Search

Suppose we check

```text
mid = 2
```

Each group can cover an interval of length

```text
2 × 2 = 4
```

### Greedy Coverage

Group 1 starts at

```text
1
```

It covers

```text
1 2 4
```

Next uncovered toy

```text
8
```

Group 2 starts at

```text
8
```

It covers

```text
8 10
```

Only **2 groups** are used.

Since this is within the limit of **3 groups**, the value `2` is feasible.

Binary search continues to check whether an even smaller answer exists.

---

## ✅ Correctness

### Greedy Choice

For a fixed maximum distance `x`, beginning each group at the leftmost uncovered toy and extending it as far as possible always covers the maximum number of toys with that group.

### Feasibility Check

The greedy process computes the minimum number of groups required for the chosen `x`.

* If it needs at most **3 groups**, then `x` is achievable.
* Otherwise, `x` is too small.

### Binary Search

If a value `x` is feasible, every larger value is also feasible.

Therefore, the search space is monotonic, allowing binary search to correctly determine the minimum feasible answer.

---

## ⏱️ Complexity Analysis

| Operation         | Complexity     |
| ----------------- | -------------- |
| Sorting           | **O(n log n)** |
| Feasibility Check | **O(n)**       |
| Binary Search     | **O(log M)**   |

where

* `n` = number of toy positions
* `M` = maximum coordinate difference

### Overall Complexity

```text
O(n log n + n log M)
```

---

## 💾 Space Complexity

```text
O(1)
```

Ignoring the input array (the algorithm uses only a few additional variables).

---

## 🛠️ Concepts Used

* Binary Search on Answer
* Greedy Algorithm
* Sorting
* Monotonic Predicate
* Two-Pointer / Interval Coverage
* STL (`sort`)
