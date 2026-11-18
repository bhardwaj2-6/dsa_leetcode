class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int inc=1;
        int dec=1;
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int temp=nums[i];
            while(j<n){
                if(temp<nums[j]){
                    inc=max(inc,j-i+1);
                    temp=nums[j];
                    j++;
                }else{
                    break;
                }
            }
        }
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int temp=nums[i];
            while(j<n){
                if(temp>nums[j]){
                    dec=max(dec,j-i+1);
                    temp=nums[j];
                    j++;
                }else{
                    break;
                }
            }
        }
        return max(inc,dec);
    }
};