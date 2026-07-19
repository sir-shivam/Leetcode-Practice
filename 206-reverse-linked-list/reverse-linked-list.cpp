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

    pair<ListNode*, ListNode*> help( ListNode * temp  ){
        
        if( temp && temp -> next == NULL ) return {temp , temp };


        pair<ListNode* , ListNode*>  ret  = help(temp -> next );

        temp -> next = NULL;
        ret.second -> next = temp;

        return {ret.first , temp};
    }
public:
    ListNode* reverseList(ListNode* head) {
        // trying recursive way 

        if( head == NULL ) return NULL;
        
        pair<ListNode * , ListNode* >  temp1 = help( head );

        ListNode*  temp = temp1.first; 
        
        return temp;
    }
};