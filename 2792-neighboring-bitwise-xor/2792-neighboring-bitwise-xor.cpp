class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
       int res=0;
       for(int &der:derived){
        res=res^der;
       } 
       return res==0;
    }
};