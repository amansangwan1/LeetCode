class Solution {
public:
    bool solve(vector<int> &nums,int n,int target,int index,vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        bool include=0;
        if(target-nums[index]>=0){
            include=solve(nums,n,target-nums[index],index+1,dp);
        }
        bool exclude=solve(nums,n,target,index+1,dp);
        
        dp[index][target]=include or exclude;

        return include or exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum%2!=0) return false;
        int n=nums.size();
        int target=sum/2;
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

        return solve(nums,n,target,0,dp);
    }
};