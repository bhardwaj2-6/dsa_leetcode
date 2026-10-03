class Solution {
public:
    int dp(vector<int>& nums, int l, int r){
        int prev1=0;
        int prev2=0;
        for(int i=l;i<=r;i++){
            int take=prev2+nums[i];
            int skip=prev1;
            int curr=max(take,skip);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int case1=dp(nums,0,n-2);
        int case2=dp(nums,1,n-1);
        return max(case1,case2);
    }
};