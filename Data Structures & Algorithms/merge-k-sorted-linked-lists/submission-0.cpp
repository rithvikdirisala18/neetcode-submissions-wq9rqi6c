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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        ListNode* sent = new ListNode();
        ListNode* curr = sent;
        for(auto& k: lists){
            pq.push({-1*k->val, k});
        }
        while(!pq.empty()){
            auto [_, node] = pq.top(); pq.pop();
            curr->next = node;
            curr = curr->next;
            if(node->next){
                pq.push({-1*node->next->val, node->next});
            }
        }
        ListNode* res = sent->next;
        delete sent;
        return res;
    }
};
