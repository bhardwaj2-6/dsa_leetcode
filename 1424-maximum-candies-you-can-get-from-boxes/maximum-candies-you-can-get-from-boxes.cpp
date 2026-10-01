class Solution {
public:
    int maxCandies(vector<int>& status,
                   vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int n = status.size();

        int ans = 0;

        vector<bool> visited(n, false);
        vector<bool> haveKey(n, false);
        vector<bool> haveBox(n, false);

        queue<int> q;

        // Initial boxes
        for(int box : initialBoxes) {
            haveBox[box] = true;

            if(status[box] == 1) {
                q.push(box);
            }
        }

        while(!q.empty()) {

            int box = q.front();
            q.pop();

            if(visited[box])
                continue;

            visited[box] = true;

            // Collect candies
            ans += candies[box];

            // Get keys
            for(int key : keys[box]) {

                haveKey[key] = true;

                // If we already possess this box,
                // now it can be opened
                if(haveBox[key] && !visited[key]) {
                    q.push(key);
                }
            }

            // Get contained boxes
            for(int newBox : containedBoxes[box]) {

                haveBox[newBox] = true;

                // Can open immediately?
                if(!visited[newBox] &&
                   (status[newBox] == 1 || haveKey[newBox])) {

                    q.push(newBox);
                }
            }
        }

        return ans;
    }
};