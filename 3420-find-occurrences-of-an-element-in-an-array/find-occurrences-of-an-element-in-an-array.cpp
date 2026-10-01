class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n=nums.size();
        vector<int> ans;
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                arr.push_back(i);
            }
        }
        int m=arr.size();
        for(int x: queries){
            if(x<=m){
                ans.push_back(arr[x-1]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};