class Solution {
public:
    void solve(string &str,int open,int closed, vector<string>&ans){
        if(open==0 && closed==0){
            ans.push_back(str);
            return;
        }
        
        if(open>0){
            str.push_back('(');
            solve(str,open-1,closed,ans);
            str.pop_back();
        }

        if(closed>open){
            str.push_back(')');
            solve(str,open,closed-1,ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=n;
        int closed=n;
        string str;
        solve(str,open,closed,ans);
        return ans;
    }
};