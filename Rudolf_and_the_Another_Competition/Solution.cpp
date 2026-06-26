#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
     * Computes the number of solved problems and the total penalty
     * for a participant assuming they solve the problems in the
     * optimal order (shortest solving times first).
     *
     * Returns:
     * {pointsScored, totalPenalty}
     */
    pair<int, long long> calculateScore(vector<int> &problemTimes,
                                        int contestDuration)
    {
        // Solve problems requiring the least amount of time first.
        sort(problemTimes.begin(), problemTimes.end());

        int solvedProblems = 0;
        long long totalPenalty = 0;
        long long elapsedTime = 0;

        for (int timeRequired : problemTimes)
        {
            // Skip remaining problems if the contest time is exceeded.
            if (elapsedTime + timeRequired > contestDuration)
            {
                break;
            }

            elapsedTime += timeRequired;
            totalPenalty += elapsedTime;
            solvedProblems++;
        }

        return {solvedProblems, totalPenalty};
    }

    /*
     * Processes a single test case and determines
     * Rudolf's final rank.
     */
    void solve()
    {
        int participants, problems, contestDuration;
        cin >> participants >> problems >> contestDuration;

        int rudolfSolved = 0;
        long long rudolfPenalty = 0;

        // Rudolf starts at rank 1.
        int rudolfRank = 1;

        for (int participant = 0; participant < participants; participant++)
        {
            vector<int> problemTimes(problems);

            for (int index = 0; index < problems; index++)
            {
                cin >> problemTimes[index];
            }

            auto [solvedProblems, totalPenalty] =
                calculateScore(problemTimes, contestDuration);

            // Store Rudolf's result.
            if (participant == 0)
            {
                rudolfSolved = solvedProblems;
                rudolfPenalty = totalPenalty;
            }
            else
            {
                /*
                 * A participant ranks ahead of Rudolf if:
                 * 1. They solve more problems.
                 * 2. They solve the same number of problems
                 *    but have a smaller penalty.
                 */
                if (solvedProblems > rudolfSolved ||
                    (solvedProblems == rudolfSolved &&
                     totalPenalty < rudolfPenalty))
                {
                    rudolfRank++;
                }
            }
        }

        cout << rudolfRank << '\n';
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