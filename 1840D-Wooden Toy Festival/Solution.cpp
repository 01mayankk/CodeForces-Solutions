#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Checks whether all toy positions can be covered using
    // at most three groups if the maximum allowed distance
    // from the center of a group is 'maxDistance'.
    bool isPossible(const vector<int>& positions, int maxDistance)
    {
        // Initially, start with the first group.
        int groupsUsed = 1;

        // The first toy marks the beginning of the current group's coverage.
        int currentGroupStart = positions[0];

        // Traverse all toy positions from left to right.
        for (size_t i = 1; i < positions.size(); i++)
        {
            // A group with maximum distance 'maxDistance'
            // can cover an interval of length 2 * maxDistance.
            //
            // If the current toy lies outside this interval,
            // we must create a new group starting from this toy.
            if (positions[i] - currentGroupStart > 2 * maxDistance)
            {
                groupsUsed++;
                currentGroupStart = positions[i];
            }
        }

        // The arrangement is valid only if no more than
        // three groups are required.
        return groupsUsed <= 3;
    }

public:
    void minimumMaximumDistance(vector<int>& positions)
    {
        // Sort the toy positions so they can be processed
        // greedily from left to right.
        sort(positions.begin(), positions.end());

        // Binary search range:
        // Minimum possible answer = 0
        // Maximum possible answer = distance between
        // the leftmost and rightmost toy.
        int low = 0;
        int high = positions.back() - positions.front();

        int answer = high;

        // Binary search for the minimum feasible answer.
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Check whether 'mid' is sufficient.
            if (isPossible(positions, mid))
            {
                // Store the current answer and
                // try to find an even smaller one.
                answer = mid;
                high = mid - 1;
            }
            else
            {
                // Current distance is too small,
                // so search in the larger half.
                low = mid + 1;
            }
        }

        cout << answer << '\n';
    }
};

int main()
{
    // Enable fast input and output.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    // Process each test case independently.
    while (testCases--)
    {
        int numberOfToys;
        cin >> numberOfToys;

        vector<int> positions(numberOfToys);

        // Read the position of each toy.
        for (int& position : positions)
        {
            cin >> position;
        }

        Solution solution;
        solution.minimumMaximumDistance(positions);
    }

    return 0;
}
