# 1840C - Ski Resort

## 🔗 Problem Link

https://codeforces.com/problemset/problem/1840/C

---

## 💡 Approach

A valid ski trip consists of **at least `k` consecutive days** where the temperature on every day is **less than or equal to `q`**.

Instead of checking every possible subarray, we observe that:

* Consecutive days satisfying the temperature condition form **valid segments**.
* Any day with temperature greater than `q` breaks the current segment.
* For every valid segment of length `L`:

  * If `L < k`, it contributes **0** trips.
  * Otherwise, the number of valid trips is

```text
(L - k + 1) × (L - k + 2) / 2
```

This formula counts all contiguous subarrays whose length is at least `k`.

We process the array once, identify every valid segment, calculate its contribution, and add it to the final answer.

---

## 📝 Algorithm

1. Initialize:

   * `consecutiveValidDays = 0`
   * `totalWays = 0`
2. Traverse the temperature array.
3. If the current temperature is at most `q`:

   * Extend the current valid segment.
4. Otherwise:

   * If the current segment length is at least `k`, calculate its contribution.
   * Reset the segment length.
5. After traversal, process the final valid segment (if any).
6. Output the total number of valid trips.

---

## 📝 Dry Run

### Input

```text
n = 7
k = 2
q = 5

Temperatures:

4 3 6 2 5 1 4
```

### Step 1

The valid segments are

```text
[4, 3]

[2, 5, 1, 4]
```

### Step 2

For the first segment

```text
Length = 2

Possible Trips = 1
```

### Step 3

For the second segment

```text
Length = 4

Possible Starts = 4 - 2 + 1 = 3

Trips = 3 × 4 / 2 = 6
```

### Final Answer

```text
1 + 6 = 7
```

---

## ✅ Correctness

For every maximal valid segment:

* Every contiguous subarray inside the segment automatically satisfies the temperature constraint.
* Any subarray crossing an invalid day is impossible.
* Therefore, every valid trip belongs entirely to exactly one maximal valid segment.

For a segment of length `L`:

* The number of subarrays of length at least `k` is

```text
(L - k + 1) × (L - k + 2) / 2
```

Summing the contribution of every valid segment counts each valid trip exactly once.

Hence, the algorithm always produces the correct answer.

---

## ⏱️ Complexity Analysis

| Operation       | Complexity |
| --------------- | ---------- |
| Array Traversal | **O(n)**   |

### Overall Time Complexity

```text
O(n)
```

---

## 💾 Space Complexity

```text
O(1)
```

The algorithm uses only a few variables regardless of the input size.

---

## 🛠️ Concepts Used

* Array Traversal
* Sliding Consecutive Segment
* Mathematics (Counting Subarrays)
* Greedy Observation
* Implementation
