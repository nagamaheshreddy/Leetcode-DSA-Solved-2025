/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s;
        for(int &num:nums)s.insert(num);

        ListNode* prev=new ListNode(-1);
        ListNode* dummy=prev;

        prev->next=head;
        ListNode* curr=head;

        while(curr){
            if(s.find(curr->val)!=s.end()){
                prev->next=curr->next;
            }else{
                prev=curr;
            }
            curr=curr->next;
        }

        return dummy->next;

    }
};