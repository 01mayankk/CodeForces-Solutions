#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void countValidTrips()
    {
        long long numberOfDays;
        long long minimumTripLength;
        long long maximumTemperature;

        cin >> numberOfDays >> minimumTripLength >> maximumTemperature;

        long long totalWays = 0;
        long long consecutiveValidDays = 0;

        // Traverse each day's temperature.
        for (int day = 0; day < numberOfDays; day++)
        {
            long long currentTemperature;
            cin >> currentTemperature;

            // If the temperature is within the allowed limit,
            // extend the current valid segment.
            if (currentTemperature <= maximumTemperature)
            {
                consecutiveValidDays++;
            }
            else
            {
                // The current valid segment ends here.
                // If its length is at least the required trip length,
                // count all possible contiguous trips within this segment.
                if (consecutiveValidDays >= minimumTripLength)
                {
                    // Number of possible starting positions for a trip.
                    long long possibleStarts =
                        consecutiveValidDays - minimumTripLength + 1;

                    // Total valid subarrays of length at least minimumTripLength.
                    totalWays +=
                        (possibleStarts * (possibleStarts + 1)) / 2;
                }

                // Start counting a new valid segment.
                consecutiveValidDays = 0;
            }
        }

        // Process the final valid segment, if the array ends
        // while still inside a valid sequence.
        if (consecutiveValidDays >= minimumTripLength)
        {
            long long possibleStarts =
                consecutiveValidDays - minimumTripLength + 1;

            totalWays +=
                (possibleStarts * (possibleStarts + 1)) / 2;
        }

        cout << totalWays << '\n';
    }
};

int main()
{
    // Enable fast input and output.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    Solution solution;

    // Process each test case independently.
    while (testCases--)
    {
        solution.countValidTrips();
    }

    return 0;
}
