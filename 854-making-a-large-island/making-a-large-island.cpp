class Solution {
public:
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};
    bool valid(int a, int b, int n){
        if(a>=0 && b>=0 && a<n && b<n){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int i, int j, int temp, int n, unordered_map<int,int>& mp){
        
        grid[i][j]=temp;
        visit[i][j]=1;
        mp[temp]++;
        for(int k=0;k<4;k++){
            int newi=i+row[k];
            int newj=j+col[k];
            if(valid(newi,newj,n) && visit[newi][newj]==0 && grid[newi][newj]==1){
                dfs(grid,visit,newi,newj,temp,n,mp);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> visit(n,vector<bool>(n,0));
        unordered_map<int,int> mp;
        int temp=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visit[i][j]==0 && grid[i][j]!=0){
                    mp[temp]=0;
                    dfs(grid,visit,i,j,temp,n,mp);
                    temp++;
                }
            }
        }
        int ans=0;
        for(auto it: mp){
            ans=max(ans,it.second);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int temp1=1;
                    unordered_map<int,int> mp2;
                    for(int k=0;k<4;k++){
                        int newi=i+row[k];
                        int newj=j+col[k];
                        if(valid(newi,newj,n) && grid[newi][newj]!=0){
                            if(mp2.find(grid[newi][newj])==mp2.end()){
                                temp1+=mp[grid[newi][newj]];
                                mp2[grid[newi][newj]]=0;
                            }
                        }
                    }
                    ans=max(ans,temp1);
                }
            }
        }
        return ans;
    }
};