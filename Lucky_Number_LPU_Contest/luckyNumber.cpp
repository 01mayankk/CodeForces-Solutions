#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
     * Computes the luckiness of a number.
     *
     * Luckiness = (Largest Digit) - (Smallest Digit)
     *
     * Example:
     *  5072 -> Largest = 7, Smallest = 0
     *  Luckiness = 7
     */
    int calculateLuckiness(int number)
    {
        int maximumDigit = 0;
        int minimumDigit = 9;

        // Traverse every digit of the number.
        while (number > 0)
        {
            int digit = number % 10;

            maximumDigit = max(maximumDigit, digit);
            minimumDigit = min(minimumDigit, digit);

            number /= 10;
        }

        return maximumDigit - minimumDigit;
    }

    /*
     * Finds the number with the maximum luckiness
     * in the range [left, right].
     *
     * Observation:
     * The maximum possible luckiness is 9 (digits 9 and 0).
     * Such a number, if it exists, appears very quickly.
     * Therefore, checking only the first 101 numbers
     * of the range is sufficient.
     */
    void findLuckiestNumber(int left, int right)
    {
        int bestNumber = left;
        int maximumLuckiness = -1;

        // Check only the first 101 numbers of the range.
        for (int current = left; current <= min(right, left + 100); current++)
        {
            int currentLuckiness = calculateLuckiness(current);

            // Update the answer if a better luckiness is found.
            if (currentLuckiness > maximumLuckiness)
            {
                maximumLuckiness = currentLuckiness;
                bestNumber = current;
            }

            // Maximum luckiness cannot exceed 9,
            // so no further search is required.
            if (maximumLuckiness == 9)
            {
                break;
            }
        }

        cout << bestNumber << '\n';
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

    // Process each test case independently.
    while (testCases--)
    {
        int left, right;
        cin >> left >> right;

        solver.findLuckiestNumber(left, right);
    }

    return 0;
}