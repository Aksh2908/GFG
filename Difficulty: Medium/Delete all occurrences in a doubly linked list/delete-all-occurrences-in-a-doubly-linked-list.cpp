/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {

        // code here
        if(!head) return head;
        
        while(head && head->data==x){
            Node* temp=head;
            head=head->next;
            delete(temp);
        }
        
        Node* temp=head;
        if(temp) head->prev=nullptr;
        while(temp){
            if(temp->data==x){
                Node* del=temp;
                temp=temp->next;
                if(del->prev) del->prev->next=del->next; 
                if(del->next) del->next->prev=del->prev;
                delete(del);
            }
            else
            temp=temp->next;
        }
        
        return head;
    }
};