class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int> ans;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(int a: arr){
            pq.push({abs(x-a),a});
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};