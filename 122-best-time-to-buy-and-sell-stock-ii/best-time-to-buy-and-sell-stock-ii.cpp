class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_high=INT_MAX;
        int ans=0;
        int i=0;
        int buy=prices[0],sell=prices[0];
        while(i<prices.size()){
            if(prices[i]<buy){
                ans=ans+sell-buy;
                buy=prices[i];
                sell=prices[i];                
            }else if(prices[i]>sell){
                sell=prices[i];
            }else if(prices[i]<sell){
                ans=ans+sell-buy;
                buy=prices[i];
                sell=prices[i]; 
            }
            i++;
        }
        if(sell!=buy){
            ans+=sell-buy;
        }
        return ans;
    }
};