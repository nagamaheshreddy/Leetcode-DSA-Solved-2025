class Solution {
public:
    string clearDigits(string s) {
       stack<char>st;

       for(char &ch:s){
            if(isdigit(ch) && !st.empty()){
                st.pop();
            }else{
                st.push(ch);
            }
       }

       string ans;
       while(!st.empty()){
        ans+=st.top();
        st.pop();
       } 
       reverse(ans.begin(),ans.end());
       return ans;
    }
};