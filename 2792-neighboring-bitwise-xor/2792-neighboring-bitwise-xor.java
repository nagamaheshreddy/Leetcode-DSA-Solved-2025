class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        
        Integer ans=0;

        for(int num:derived){
            ans=ans^num;
        }
        return ans==0;
    }
}