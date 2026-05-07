class Solution {
public:

    int longest(vector<int>&nums,int index,int n,int prevIndex,vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }
        if(dp[index][prevIndex]!=-1) return dp[index][prevIndex];

        int include=0;
        if(nums[index]>nums[prevIndex]){
            include=1+longest(nums,index+1,n,index,dp);
        }
        int exclude=longest(nums,index+1,n,prevIndex,dp);

        int maxx=max(include,exclude);
        dp[index][prevIndex]=maxx;
        return maxx;
    }

    int binaryDP(vector<int>&nums , int n){
        if(n==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans[ans.size()-1]){
                ans.push_back(nums[i]);
            }else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {

        // if(nums.size()==0) return 0;

        // int maxx=1;
        // for(int i=0;i<nums.size();i++){
        //     vector<vector<int>> dp (nums.size()+1,vector<int>(nums.size()+1,-1));
        //     int temp=1+longest(nums,i+1,nums.size(),i,dp);
        //     maxx=max(temp,maxx);
        // }

        // return maxx;

        int maxx=binaryDP(nums,nums.size());
        return maxx;
    }
};