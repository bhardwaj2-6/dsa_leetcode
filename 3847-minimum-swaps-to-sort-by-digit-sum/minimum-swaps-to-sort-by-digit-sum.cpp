class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int x : nums) {
            int temp = x;
            int sum = 0;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            arr.push_back({sum, x});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        vector<int> target(n);

        for (int i = 0; i < n; i++) {
            target[i] = pos[arr[i].second];
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || target[i] == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = target[j];
                cycle++;
            }

            ans += cycle - 1;
        }

        return ans;
    }
};