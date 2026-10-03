class Solution {
public:
    int row[4]={1,-1,0,0};
    int col[4]={0,0,-1,1};
    bool valid(int a, int b, int n, int m){
        if(a>=0 && b>=0 && a<n && b<m){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int& i, int& j, int n, int m, int &per){
        visit[i][j]=1;
        for(int k=0;k<4;k++){
            int newi=i+row[k];
            int newj=j+col[k];
            if(valid(newi,newj,n,m)==0){
                per++;
            }else if(valid(newi,newj,n,m)==1 && grid[newi][newj]==0){
                per++;
            }else if(valid(newi,newj,n,m) && grid[newi][newj]==1 && visit[newi][newj]==0){
                dfs(grid,visit,newi,newj,n,m,per);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int per=0;
        vector<vector<bool>> visit(n, vector<bool> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(grid,visit,i,j,n,m,per);
                    return per;
                }
            }
        }
        return 0;
    }
};