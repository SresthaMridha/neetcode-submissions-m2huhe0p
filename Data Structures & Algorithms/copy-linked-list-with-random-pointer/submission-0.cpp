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
        //edge case
        if(head == nullptr) return nullptr;

        Node* curr = head;

        //creating copy in the LL
        while(curr){
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        }

        //linking  random pointers

        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            
            curr = curr->next->next;
            
        }

        //separating the copy

        Node* dummy = new Node(0);
        Node* newcopy = dummy;

        curr = head;

        while(curr){
            Node* copy = curr->next;

            newcopy->next = copy;
            newcopy = copy;

            curr->next = copy->next;
            curr = curr->next;
        }

        return dummy->next;


    }
};
