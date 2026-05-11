class Solution {
public:

    int solve(vector<int>& coins,int amount,vector<int>& dp){
        if(amount==0){
            return 0;
        }
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){

            int ans=solve(coins,amount-coins[i],dp);

            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }

        }
        dp[amount]=mini;
        return mini;
        
    }

    int solveTab(vector<int>& coins,int amount){
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                int ans=INT_MAX;
                if(i-coins[j]>=0){
                    ans=dp[i-coins[j]];
                }
                if(ans!=INT_MAX){
                    dp[i]=min(dp[i],1+ans);
                }
            }
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {

        return (solveTab(coins,amount)==INT_MAX)? -1:solveTab(coins,amount);
        
        
        vector<int> dp(amount+1,-1);
        int ans=solve(coins,amount,dp);
        return (ans==INT_MAX)? -1:ans;
        
    }
};