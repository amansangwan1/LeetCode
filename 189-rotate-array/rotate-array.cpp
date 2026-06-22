class Solution {
public:

    void reverse(vector<int>& nums,int st,int end){
        while(st<end){
            swap(nums[st],nums[end]);
            st++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {

        if(k==0) return;

        int n=nums.size();
        k=k%n;
        
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};