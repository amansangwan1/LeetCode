class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output = strs[0];
        for(string i:strs){
            int cnt=0;
            int j=0,flag=0;
            while(j<=i.length() && j<=output.length() && flag==0){
                if(i[j]==output[j]){
                    cnt++;
                }else{
                    flag=1;
                }
                j++;
            }
            output=output.substr(0,cnt);
        }
        return output;
    }
};