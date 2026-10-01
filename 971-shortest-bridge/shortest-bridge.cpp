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
    void dfs(vector<vector<int>>& grid, int n, int m, queue<pair<int,int>>& q, int i, int j, vector<vector<bool>>& visit){
        visit[i][j]=1;
        q.push({i,j});
        grid[i][j]=2;
        for(int k=0;k<4;k++){
            int newi=i+row[k];
            int newj=j+col[k];
            if(valid(newi,newj,n,m) && visit[newi][newj]==0 && grid[newi][newj]==1){
                dfs(grid,n,m,q,newi,newj,visit);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visit(n,vector<bool> (m,0));
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(grid,n,m,q,i,j,visit);
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        int ans=0;
        while(!q.empty()){
            int p=q.size();
            while(p--){
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newa=a+row[k];
                    int newb=b+col[k];
                    if(valid(newa,newb,n,m)){
                        if(grid[newa][newb]==0){
                            q.push({newa,newb});
                            grid[newa][newb]=2;
                        }
                        if(grid[newa][newb]==1){
                            return ans;
                        }
                    }
                }
            }
            ans++;
            
        }
        return ans;
    }
};