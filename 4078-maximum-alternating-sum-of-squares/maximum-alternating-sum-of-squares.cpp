class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long score=0;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        if(n%2!=0){
            score+=(nums[n-1]);
            nums.pop_back();
        }
        int m=nums.size();
        int i=0,j=m-1;
        while(i<j){
            score+=nums[j]-nums[i];
            i++;
            j--;
        }
        return score;
    }
};