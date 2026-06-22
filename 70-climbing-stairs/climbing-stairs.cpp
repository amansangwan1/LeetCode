class Solution {
public:

    int climbing(int n,vector<int>dp){
        if (n == 0 || n == 1)
            return 1;
        if(dp[n]!=-1) return dp[n];

        dp[n]=climbStairs(n - 1) + climbStairs(n - 2);
        return dp[n];
    }

    int climbing_dp(int n){
        vector<int> dp(n,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int prev1=1;
        int prev2=2;
        int curr;
        for(int i=3;i<=n;i++){
            curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return curr;
    }
};