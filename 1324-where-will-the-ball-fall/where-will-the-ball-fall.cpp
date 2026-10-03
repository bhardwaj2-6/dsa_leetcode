class Solution {
public:
    int n,m;
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i==n){
            return j;
        }
        if(grid[i][j]==1){
            if(j+1>=m){
                return -1;
            }
            if(grid[i][j+1]==-1){
                return -1;
            }else{
                return dfs(grid,i+1,j+1);
            }
        }else{
            if(j-1<0){
                return -1;
            }
            if(grid[i][j-1]==1){
                return -1;
            }else{
                return dfs(grid,i+1,j-1);
            }
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<int> ans(m);
        for(int j=0;j<m;j++){
            ans[j]=dfs(grid,0,j);
        }
        return ans;
    }
};