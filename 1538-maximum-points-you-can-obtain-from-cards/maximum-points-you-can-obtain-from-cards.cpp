class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int windowsize=n-k;
        int i=0,j=0;
        int temp=INT_MAX;
        int sum=0;
        int min_sum=0;
        while(j<n){
            sum+=cardPoints[j];
            min_sum+=cardPoints[j];
            if(j-i+1==windowsize){
                temp=min(temp,min_sum);
                min_sum-=cardPoints[i];
                i++;
            }
            j++;
        }
        if(k==n){
            return sum;
        }
        return sum-temp;
        
    }
};