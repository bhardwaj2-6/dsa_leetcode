class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long ans=0;
        if(k==0) return ans;
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int o=limits[i];
            vector<int> temp;
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
            sort(temp.begin(),temp.end());
            int l=temp.size()-1;
            while(o--){
                pq.push(temp[l]);
                l--;
            }
        }
        
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
            k--;
            if(k==0){
                break;
            }
        }
        return ans;
    }
};