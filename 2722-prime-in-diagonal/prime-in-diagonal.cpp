class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        vector<int> arr;
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j || j==n-i-1){
                    arr.push_back(nums[i][j]);
                }
            }
        }
        sort(arr.begin(),arr.end());
        int p=arr.size();
        for(int i=p-1;i>=0;i--){
            int flag=0;
            for(int k=2;k<=arr[i]/2;k++){
                if(arr[i]%k==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                if(arr[i]==1){
                    return 0;
                }
                return arr[i];
            }
        }
        
        return 0;
    }
};