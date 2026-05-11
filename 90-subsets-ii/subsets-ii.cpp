class Solution {
public:

    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &output,int index,map<vector<int>,int> &count){
        if(index>=nums.size()){
            if(!count[output]){
                count[output]++;
                ans.push_back(output);
            }
            return;
        }


        solve(nums,ans,output,index+1,count);

        output.push_back(nums[index]);
        solve(nums,ans,output,index+1,count);

        output.pop_back();

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<vector<int>,int> count;
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(nums,ans,output,index,count);
        return ans;
    }
};