#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void requiredCandies(vector<long>& sugarValues,
                         const vector<long>& queries)
    {
        // Sort candies in descending order so that candies with the
        // highest sugar content are consumed first.
        sort(sugarValues.begin(), sugarValues.end(), greater<long>());

        // Prefix sum array where prefixSum[i] represents the total sugar
        // obtained after eating the first (i + 1) candies.
        vector<long> prefixSum(sugarValues.size());

        prefixSum[0] = sugarValues[0];

        // Build the prefix sum array.
        for (size_t i = 1; i < sugarValues.size(); i++)
        {
            prefixSum[i] = prefixSum[i - 1] + sugarValues[i];
        }

        // Process each query independently.
        for (long requiredSugar : queries)
        {
            // Find the first prefix sum that is greater than or equal
            // to the required amount of sugar.
            auto position = lower_bound(
                prefixSum.begin(),
                prefixSum.end(),
                requiredSugar
            );

            // If no such prefix sum exists, it is impossible to
            // collect the required amount of sugar.
            if (position == prefixSum.end())
            {
                cout << -1 << '\n';
            }
            else
            {
                // Convert the iterator position to the number of candies.
                cout << (position - prefixSum.begin() + 1) << '\n';
            }
        }
    }
};

int main()
{
    // Enable fast input and output.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long testCases;
    cin >> testCases;

    // Process each test case.
    while (testCases--)
    {
        long numberOfCandies, numberOfQueries;
        cin >> numberOfCandies >> numberOfQueries;

        // Read sugar values of all candies.
        vector<long> sugarValues(numberOfCandies);

        for (long& sugar : sugarValues)
        {
            cin >> sugar;
        }

        // Read all query values.
        vector<long> queries(numberOfQueries);

        for (long& query : queries)
        {
            cin >> query;
        }

        Solution solution;
        solution.requiredCandies(sugarValues, queries);
    }

    return 0;
}