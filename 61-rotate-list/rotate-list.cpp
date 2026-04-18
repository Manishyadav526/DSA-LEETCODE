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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL ;
        }
        vector<int>ans;
        ListNode*temp=head;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
        k=k%n;
        int i=ans.size()-k;
        temp=head;
        while(k--){
            temp->val=ans[i];
            i++;
            temp=temp->next;
        }
        int j=0;
        while(temp){
            temp->val=ans[j];
            temp=temp->next;
            j++;
        }
        return head;
    }
};