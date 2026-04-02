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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* mid = head;
        ListNode* fast = head;
        while(fast && fast->next){
            mid = mid->next;
            fast = fast->next->next;
        }
        // reverse second half
        ListNode* curr = mid->next;
        mid->next = nullptr;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //Intertwine from mid
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while(p2){
            ListNode* n1 = p1->next;
            ListNode* n2 = p2->next;
            
            p1->next = p2;
            p2->next = n1;

            p1 = n1;
            p2 = n2;
        }
    }
};
