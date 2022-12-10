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
#include <cmath>

class Solution {

private:

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL ;
        ListNode* cur = NULL ;
        ListNode* tail = NULL ;
        int sum = 0 ;
        bool carry = false ;
        while ( l1 != NULL && l2 != NULL ) {

            if ( cur == NULL ) {
                sum = l1->val + l2->val ;
                cur = new ListNode( sum % 10 ) ;
                cur->next = NULL ;
                result = cur ;
                tail = cur ;
            } // if
            
            else {
                sum = l1->val + l2->val ;
                if ( carry )
                    sum++ ;
                cur = new ListNode( sum % 10 ) ;
                cur->next = NULL ;
                tail->next = cur ;
                tail = cur ;
            } // else

            l1 = l1->next ;
            l2 = l2->next ;

            if ( sum > 9 )
                carry = true ;
            else {
                carry = false ;
            } // else

        } // while
        
        // l1和l2一樣長
        if ( l1 == NULL && l2 == NULL ) {
          if ( carry ) {
              cur = new ListNode(1) ;
              cur->next = NULL ;
              tail->next = cur ;
          } // if

        } // if

        // l1和l2不一樣長
        else {
            // l2比較長
            if ( l1 == NULL ) {
                tail->next = l2 ;
                while ( carry && l2 != NULL ) {
                    l2->val++ ;
                    if ( l2->val < 10 ) {
                        carry = false ;
                    } // if
                    else {
                        l2->val = 0 ;
                        carry = true ;
                    } // else

                    tail = l2 ;
                    l2 = l2->next ;
                } // while
                if ( carry ) {
                    cur = new ListNode(1) ;
                    cur->next = NULL ;
                    tail->next = cur ;
                } // if
            } // if
                
            // l1比較長
            else {
                tail->next = l1 ;
                while ( carry && l1 != NULL ) {
                    l1->val++ ;
                    if ( l1->val < 10 ) {
                        carry = false ;
                    } // if
                    else {
                        l1->val = 0 ;
                        carry = true ;
                    } // else

                    tail = l1 ;
                    l1 = l1->next ;
                } // while
                if ( carry ) {
                    cur = new ListNode(1) ;
                    cur->next = NULL ;
                    tail->next = cur ;
                } // if
            } // else

        } // else

        return result ;
    }
};
