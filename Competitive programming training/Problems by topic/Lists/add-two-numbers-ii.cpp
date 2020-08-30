//https://leetcode.com/problems/add-two-numbers-ii/
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

    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solveWithStack(l1, l2);
    }
    
    ListNode* reverseLinkedList(ListNode *head) {
        ListNode *current = head;
        ListNode *next = head;
        ListNode *prev = nullptr;
        while(current != nullptr) {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    ListNode *solveWithStack(ListNode *l1, ListNode* l2) {
        stack<int> S1, S2;
        ListNode *current_l1 = l1, *current_l2 = l2; 
        ListNode *head, *tail;
        head = tail = nullptr;
        int val_S1, val_S2;
        
        int carry = 0;
        int sum = 0;
        while(current_l1 != nullptr) {
            S1.push(current_l1 -> val);
            current_l1 = current_l1 -> next;
        }
        
        while(current_l2 != nullptr) {
            S2.push(current_l2 -> val);
            current_l2 = current_l2 -> next;
        }
        
        while(!S1.empty() or !S2.empty() or carry != 0) {
            if(S1.empty())
                val_S1 = 0;
            else
                val_S1 = S1.top(), S1.pop();
            
            if(S2.empty())
                val_S2 = 0;
            else
                val_S2 = S2.top(), S2.pop();
            
            sum = val_S1 + val_S2 + carry;
            
            ListNode *new_node = new ListNode(sum % 10);
            if(head == nullptr)
                head = new_node;
            else 
                tail -> next = new_node;
            tail = new_node;
            
            carry = sum / 10;
        }
        
        
        return reverseLinkedList(head);
            
    }
    
};