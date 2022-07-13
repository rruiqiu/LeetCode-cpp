/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> L; //int won't work in this part because it will pass the address of each node in the list instead of the integer, each address is unique and it can be put in the hashset instead of the integer./ it won't work if the integer is repeated in the linked list for the first cycle but it can find the same address if it is repeated.
        while(head!=NULL){
            if(L.find(head) == L.end()){
                L.insert(head);
            }else{
                return true;
            }
            head = head->next;
        }

        return false;
    }
};

//Two pointer method
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
