#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
     * Solves a single test case.
     *
     * Idea:
     * - Compute the number of distinct characters in every prefix.
     * - Compute the number of distinct characters in every suffix.
     * - Try every possible split and maximize:
     *
     *      distinct(prefix) + distinct(suffix)
     */
    void solve()
    {
        int length;
        cin >> length;

        string str;
        cin >> str;

        // prefixDistinct[i] stores the number of distinct
        // characters in the substring str[0...i].
        vector<int> prefixDistinct(length);

        // suffixDistinct[i] stores the number of distinct
        // characters in the substring str[i...length-1].
        vector<int> suffixDistinct(length);

        unordered_set<char> leftCharacters;

        // Build the prefix distinct count array.
        for (int index = 0; index < length; index++)
        {
            leftCharacters.insert(str[index]);
            prefixDistinct[index] = leftCharacters.size();
        }

        unordered_set<char> rightCharacters;

        // Build the suffix distinct count array.
        for (int index = length - 1; index >= 0; index--)
        {
            rightCharacters.insert(str[index]);
            suffixDistinct[index] = rightCharacters.size();
        }

        int maximumDistinct = 0;

        // Try every valid split.
        // Left part  : [0 ... index]
        // Right part : [index + 1 ... length - 1]
        for (int index = 0; index < length - 1; index++)
        {
            int currentDistinct =
                prefixDistinct[index] + suffixDistinct[index + 1];

            maximumDistinct = max(maximumDistinct, currentDistinct);
        }

        cout << maximumDistinct << '\n';
    }
};

int main()
{
    // Enable fast input and output.
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