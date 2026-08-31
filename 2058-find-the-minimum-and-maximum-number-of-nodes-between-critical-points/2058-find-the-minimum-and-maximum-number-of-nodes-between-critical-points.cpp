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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head,*curr=head->next,*future=head->next->next;
        vector<int> ans={INT_MAX,-1};
        int fcount=0,pcount=0,count=1;
        while(future!=nullptr){
            if((prev->val > curr->val && future->val > curr->val) || (prev->val < curr->val && future->val < curr->val)){
                if(fcount==0){
                    fcount=count;
                    pcount=count;
                }
                else{
                    ans[0]=min(ans[0],count-pcount);
                    pcount=count;
                }
            }
            prev=curr;
            curr=future;
            future=future->next;
            count++;
        }
        if(fcount!=0 && pcount!=fcount) ans[1]=pcount-fcount;
        else ans[0]=-1;
        return ans;
    }
};