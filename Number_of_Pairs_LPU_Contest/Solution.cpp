#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
     * Solves a single test case.
     *
     * Idea:
     * 1. Sort the array.
     * 2. For every element a[i], determine the valid range
     *    of the second element such that:
     *
     *        l <= a[i] + a[j] <= r
     *
     *    Rearranging,
     *
     *        l - a[i] <= a[j] <= r - a[i]
     *
     * 3. Use binary search to count all elements satisfying
     *    the above condition in the remaining part of the array.
     */
    void solve()
    {
        int arraySize;
        long long minimumSum, maximumSum;

        cin >> arraySize >> minimumSum >> maximumSum;

        vector<long long> numbers(arraySize);

        for (int index = 0; index < arraySize; index++)
        {
            cin >> numbers[index];
        }

        // Sorting enables binary searching for valid partners.
        sort(numbers.begin(), numbers.end());

        long long validPairs = 0;

        for (int firstIndex = 0; firstIndex < arraySize; firstIndex++)
        {
            // Compute the valid range for the second element.
            long long lowerValue = minimumSum - numbers[firstIndex];
            long long upperValue = maximumSum - numbers[firstIndex];

            /*
             * Find the first element >= lowerValue
             * among indices greater than firstIndex.
             */
            auto lower =
                lower_bound(numbers.begin() + firstIndex + 1,
                            numbers.end(),
                            lowerValue);

            /*
             * Find the first element > upperValue.
             */
            auto upper =
                upper_bound(numbers.begin() + firstIndex + 1,
                            numbers.end(),
                            upperValue);

            // Number of valid partners for numbers[firstIndex].
            validPairs += (upper - lower);
        }

        cout << validPairs << '\n';
    }
};

int main()
{
    // Enable fast input/output.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    Solution solver;

    while (testCases--)
    {
        solver.solve();
    }

    return 0;
}