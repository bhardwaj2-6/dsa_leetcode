class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int left=0,right=m-1,up=0,down=n-1;
        while(left<=right && up<=down){
            for(int j=left;j<=right;j++){
                ans.push_back(matrix[up][j]);
            }
            up++;
            for(int i=up;i<=down;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(up<=down){
                for(int j=right;j>=left;j--){
                    ans.push_back(matrix[down][j]);
                }
                down--;
            }
            
            if(left<=right){
                for(int i=down;i>=up;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            
        }
        return ans;
    }
};