class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int des=n/2;
        if(n%2!=0){
            des++;
        }
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>=des){
                return nums[i];
            }
        }
        return 0;
    }
};