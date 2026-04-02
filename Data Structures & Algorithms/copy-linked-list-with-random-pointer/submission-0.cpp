/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        
        Node* curr = head;
        while(curr){
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        Node* cp = head->next;
        Node* og = head;
        while(og){
            if(og->random){
                og->next->random = og->random->next;
            }
            og = og->next->next;
        }

        og = head;
        while(og){
            Node* tmp = og->next;
            og->next = tmp->next;
            if(tmp->next){
                tmp->next = tmp->next->next;
            }
            og = og->next;
        }
        return cp;
    }
};
