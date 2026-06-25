# 1676E - Eating Queries

## 🔗 Problem Link

https://codeforces.com/problemset/problem/1676/E

---

## 💡 Approach

To minimize the number of candies required for each query, we should always choose the candies with the highest sugar content first.

### Algorithm

1. Sort the sugar values in **descending order**.
2. Construct a **prefix sum array**, where each element represents the total sugar obtained after eating the first `i` candies.
3. For every query:

   * Use **Binary Search (`lower_bound`)** on the prefix sum array.
   * Find the first prefix sum that is greater than or equal to the required sugar.
   * The index of this prefix sum (plus one) gives the minimum number of candies.
   * If no such prefix sum exists, return `-1`.

---

## 📝 Dry Run

### Input

```text
Candies = [4, 2, 1, 10, 5]

Queries:
5
13
25
```

### Step 1: Sort in Descending Order

```text
10 5 4 2 1
```

### Step 2: Build Prefix Sum

```text
Index :      0   1   2   3   4

Candy :     10   5   4   2   1

Prefix :    10  15  19  21  22
```

### Step 3: Process Queries

#### Query = 5

```text
First prefix >= 5

10

Answer = 1
```

#### Query = 13

```text
First prefix >= 13

15

Answer = 2
```

#### Query = 25

```text
No prefix sum is greater than or equal to 25.

Answer = -1
```

---

## ✅ Correctness

* Sorting ensures that candies with the highest sugar are selected first.
* The prefix sum array stores the maximum sugar obtainable after consuming the first `k` candies.
* Since the prefix sums are sorted in non-decreasing order, Binary Search efficiently finds the minimum number of candies required for every query.
* Therefore, the algorithm always produces the optimal answer.

---

## ⏱️ Complexity Analysis

| Operation               | Complexity               |
| ----------------------- | ------------------------ |
| Sorting                 | **O(n log n)**           |
| Prefix Sum Construction | **O(n)**                 |
| Each Query              | **O(log n)**             |
| Total                   | **O(n log n + q log n)** |

### Space Complexity

```text
O(n)
```

for the prefix sum array.

---

## 🛠️ Concepts Used

* Sorting
* Prefix Sum
* Binary Search
* STL (`sort`, `lower_bound`)
* Greedy Strategy
