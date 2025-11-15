// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        if(!head || !head->next) return head;
        
        Node* dummy=new Node(-1);
        dummy->next=head;
        Node* curr=head;
        Node* prev=dummy;
        
        while(curr){
            Node* nextt=curr->next;
            while(nextt && curr->data==nextt->data){
                nextt=nextt->next;
            }
            
            if(curr->next==nextt){
                prev=curr;
            }
            else{
                prev->next=nextt;
            }
            curr=nextt;
        }
        return dummy->next;
    }
};