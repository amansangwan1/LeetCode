class Solution {
public:

    bool isSafe(int n,
            int row,
            int col,
            vector<vector<bool>>& visited) {

    int r = row;
    int c = col;

    while(r >= 0) {

        if(visited[r][c])
            return false;

        r--;
    }
    r = row;
    c = col;

    while(r >= 0 && c >= 0) {

        if(visited[r][c])
            return false;

        r--;
        c--;
    }
    r = row;
    c = col;

    while(r >= 0 && c < n) {

        if(visited[r][c])
            return false;

        r--;
        c++;
    }

    return true;
}

    void solve(int n,int index,vector<string>& path,vector<vector<string>>&ans,vector<vector<bool>>&visited){
        if(index>=n){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(n,index,i,visited)){
                visited[index][i]=1;
                path[index][i]='Q';
                solve(n,index+1,path,ans,visited);
                visited[index][i]=0;
                path[index][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> path(n,string(n,'.'));
        int index=0;
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        solve(n,index,path,ans,visited);
        return ans;
    }
};