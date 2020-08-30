//https://leetcode.com/problems/add-two-numbers/submissions/
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
        ListNode *current_1 = l1, *current_2 = l2;
        ListNode *head = nullptr, *tail = nullptr;
        
        int carry = 0;
        int sum = 0;
        
        while(current_1 != nullptr and current_2 != nullptr) {
            sum = (current_1 -> val + current_2 -> val + carry);
            ListNode *new_node = new ListNode(sum % 10);    
            carry = sum / 10;
            if(head == nullptr)
                head = tail = new_node;
            else {
                tail -> next = new_node;
                tail = new_node;
            }
            
            current_1 = current_1 -> next;
            current_2 = current_2 -> next;
        }
        
        while(current_1 != nullptr) {
            sum = (current_1 -> val + carry);
            ListNode *new_node = new ListNode(sum % 10);
            tail -> next = new_node;
            tail = new_node;
            carry = sum / 10;
            current_1 = current_1 -> next;
        }
        
        while(current_2 != nullptr) {
            sum = (current_2 -> val + carry);
            ListNode *new_node = new ListNode(sum % 10);
            tail -> next = new_node;
            tail = new_node;
            carry = sum / 10;
            current_2 = current_2 -> next;
        }
        
        if(carry > 0) {
            ListNode *new_node = new ListNode(carry);
            tail -> next = new_node;
            tail = new_node;
        }
        
            
        return head;
    }
};