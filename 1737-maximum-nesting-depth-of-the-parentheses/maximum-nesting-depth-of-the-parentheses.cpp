class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int cnt=0;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
                cnt++;
                if(cnt>ans){
                    ans=cnt;
                }
            }else if(s[i]==')'){
                st.pop();
                cnt--;
            }
        }
        return ans;
    }
};