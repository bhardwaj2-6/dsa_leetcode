class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        int j=0;
        int n=s.size();
        unordered_map<string,string> mp;
        for(auto it:knowledge){
            mp[it[0]]=it[1];
        }
        int flag=0;
        string temp="";
        while(j<n){
            if(flag==0 && s[j]!='('){
                ans+=s[j];
            }else if(flag==0 && s[j]=='('){
                flag=1;
            }else if(flag==1 && s[j]!=')'){
                temp+=s[j];
            }else if(flag==1 && s[j]==')'){
                if(mp.find(temp)!=mp.end()){
                    ans+=mp[temp];
                }else{
                    ans+='?';
                }
                temp="";
                flag=0;
            }
            j++;
        }
        return ans;
    }
};