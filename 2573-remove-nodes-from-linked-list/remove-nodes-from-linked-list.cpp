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
    void insertAtHead(ListNode* &newhead,int val)
    {
        ListNode* newNode = new ListNode(val);
        newNode->next = newhead;
        newhead = newNode;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;

        while(temp != NULL)
        {
            int val = temp->val;
            
            while(!st.empty() && val > st.top())
            {
                st.pop();
            }
            st.push(val);
            temp = temp->next;
        }

        ListNode* newhead = NULL;
        while(st.size() > 0)
        {
            insertAtHead(newhead,st.top());
            st.pop();
        }
        return newhead;
        
    }
};