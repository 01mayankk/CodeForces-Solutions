# E. Number of Pairs

## 🔗 Problem Summary

You are given an array of **n** integers along with two values **l** and **r**.

Your task is to count the number of index pairs **(i, j)** such that:

* `i < j`
* The sum of the selected elements lies within the inclusive range:

```text
l ≤ a[i] + a[j] ≤ r
```

Return the total number of valid pairs for each test case.

---

## 💡 Approach

A brute-force solution checks every possible pair, resulting in **O(n²)** time complexity, which is too slow for the given constraints.

Instead, we optimize the solution using **sorting** and **binary search**.

### Step 1: Sort the Array

Sorting allows us to efficiently search for valid partner elements for every index.

### Step 2: Fix the First Element

For every element `a[i]`, determine the range of values that the second element must satisfy.

From:

```text
l ≤ a[i] + a[j] ≤ r
```

Subtract `a[i]` from every part:

```text
l - a[i] ≤ a[j] ≤ r - a[i]
```

Now the problem reduces to finding how many elements after index `i` lie within this range.

### Step 3: Binary Search

For every index:

* Use **lower_bound()** to find the first value greater than or equal to `l - a[i]`.
* Use **upper_bound()** to find the first value greater than `r - a[i]`.

The difference between the two iterators gives the number of valid partners for the current element.

Repeat this for every index and accumulate the answer.

---

## 🚀 Algorithm

1. Read the array.
2. Sort the array in non-decreasing order.
3. Initialize the answer as `0`.
4. For every element:

   * Compute:

     * `lowerValue = l - a[i]`
     * `upperValue = r - a[i]`
   * Use binary search to find the valid range.
   * Add the number of valid elements to the answer.
5. Print the final count.

---

## 📌 Dry Run

### Input

```text
n = 5
l = 5
r = 8

Array = [5, 1, 2, 4, 3]
```

### Step 1: Sort

```text
[1, 2, 3, 4, 5]
```

---

### Iteration

| Current Element | Required Partner Range | Valid Partners | Count |
| --------------: | :--------------------: | :------------: | ----: |
|               1 |          [4,7]         |       4,5      |     2 |
|               2 |          [3,6]         |      3,4,5     |     3 |
|               3 |          [2,5]         |       4,5      |     2 |
|               4 |          [1,4]         |        —       |     0 |
|               5 |          [0,3]         |        —       |     0 |

Total pairs:

```text
2 + 3 + 2 = 7
```

Output:

```text
7
```

---

## 🎯 Key Observation

For every fixed element, the required value of the second element forms a **continuous interval**.

Since the array is sorted, this interval can be located efficiently using binary search instead of scanning every remaining element.

This reduces the complexity from quadratic to nearly linear.

---

## ⏱️ Complexity Analysis

Let **n** be the size of the array.

### Time Complexity

* Sorting:

```text
O(n log n)
```

* Binary search for every element:

```text
n × O(log n)
```

Overall:

```text
O(n log n)
```

---

### Space Complexity

Only the input array and a few variables are used.

```text
O(n)
```

---

## ✅ Correctness

* Sorting guarantees that binary search can be applied.
* For every index `i`, binary search correctly identifies all elements satisfying:

```text
l - a[i] ≤ a[j] ≤ r - a[i]
```

* Only indices greater than `i` are considered, ensuring each pair is counted exactly once.
* Summing the counts for every index gives the total number of valid pairs.

Therefore, the algorithm always returns the correct answer.

---

## 📚 Concepts Used

* Sorting
* Binary Search
* `lower_bound()`
* `upper_bound()`
* Two-Element Pair Counting
* Implementation
