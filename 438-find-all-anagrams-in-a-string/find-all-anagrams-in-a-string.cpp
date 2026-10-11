class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=s.size();
        int m=p.size();
        if(m>n) return ans;
        vector<int> freqs(26,0);
        vector<int> freqp(26,0);
        for(int i=0;i<m;i++){
            freqp[p[i]-'a']++;
            freqs[s[i]-'a']++;
        }
        if(freqs==freqp) ans.push_back(0);
        for(int i=m;i<n;i++){
            freqs[s[i-m]-'a']--;
            freqs[s[i]-'a']++;
            if(freqs==freqp){
                ans.push_back(i-m+1);
            }
        }
        return ans;
    }
};