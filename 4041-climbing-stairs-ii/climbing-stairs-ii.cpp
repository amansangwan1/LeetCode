// class Solution {
// public:

//     int minCostClimbing(int n, vector<int>& costs, int curr, vector<int>& dp) {
//         if (curr == n) return 0;

//         if (dp[curr] != -1) return dp[curr];

//         int ans = INT_MAX;

//         int st = curr;

//         int end = curr + 1;
//         if (end <= n) {
//             int cost = costs[end - 1] + (end - st) * (end - st);
//             ans = min(ans, cost + minCostClimbing(n, costs, end, dp));
//         }

//         end = curr + 2;
//         if (end <= n) {
//             int cost = costs[end - 1] + (end - st) * (end - st);
//             ans = min(ans, cost + minCostClimbing(n, costs, end, dp));
//         }

//         end = curr + 3;
//         if (end <= n) {
//             int cost = costs[end - 1] + (end - st) * (end - st);
//             ans = min(ans, cost + minCostClimbing(n, costs, end, dp));
//         }

//         return dp[curr] = ans;
//     }

//     int climbStairs(int n, vector<int>& costs) {
//         vector<int> dp(n + 1, -1);
//         return minCostClimbing(n, costs, 0, dp);
//     }
// };




//  THE ABOVE ONE IS MEMOIZATION AND THE BELOW ONE IS TABULATIONS





class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, INT_MAX);

        dp[n] = 0;

        for (int curr = n - 1; curr >= 0; curr--) {

            for (int jump = 1; jump <= 3; jump++) {

                int end = curr + jump;

                if (end <= n) {

                    int cost =
                        costs[end - 1] + jump * jump;

                    dp[curr] = min(
                        dp[curr],
                        cost + dp[end]
                    );
                }
            }
        }

        return dp[0];
    }
};