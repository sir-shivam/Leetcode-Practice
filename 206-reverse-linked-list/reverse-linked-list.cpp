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

    ListNode* help( ListNode * temp  , ListNode* prev ){
        

        ListNode* front = temp -> next ;
        temp -> next = prev;

        if(!front) {
            return temp;
        }

        // ListNode* next = front -> next;

        // temp  -> next =  prev ;


        return help( front , temp );
        
    }
public:
    ListNode* reverseList(ListNode* head) {
        // trying recursive way 

        if( head == NULL ) return NULL;
        
        ListNode*  temp = help( head , NULL );

        // head -> next = NULL;
        
        
        return temp;
    }
};