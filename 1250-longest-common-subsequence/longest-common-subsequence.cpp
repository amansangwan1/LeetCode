class Solution {
public:

    int solve(int index1,int index2,string text1,string text2,vector<vector<int>> &dp){
        if(index1==text1.size() || index2==text2.size()){
            return 0;
        }
        if(dp[index1][index2]!=0) return dp[index1][index2];

        int ans=0;
        if(text1[index1]==text2[index2]){
            ans=1+solve(index1+1,index2+1,text1,text2,dp);
        }else{
            ans=max(solve(index1+1,index2,text1,text2,dp),solve(index1,index2+1,text1,text2,dp));
        }

        return dp[index1][index2]=ans;
    }

    int solveTab(string text1,string text2){
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));

        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                int ans=0;
                if(text1[i]==text2[j]){
                    ans=1+dp[i+1][j+1];
                }else{
                    ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {

        return solveTab(text1,text2);

        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        return solve(0,0,text1,text2,dp);
    }
};