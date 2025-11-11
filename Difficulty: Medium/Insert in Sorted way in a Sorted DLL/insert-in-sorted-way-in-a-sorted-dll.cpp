/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        Node* newNode=new Node();
        newNode->data=x;
        newNode->prev=nullptr;
        newNode->next=nullptr;
        
        if(!head) return newNode;
        
        if(x<=head->data){
            newNode->next=head;
            head->prev=newNode;
            return newNode;
        }    
        Node* temp=head;
        
        while(temp->next && (temp->next->data)<x){
            temp=temp->next;
        }
        
        newNode->prev=temp;
        newNode->next=temp->next;
        if(temp->next) temp->next->prev=newNode;
        temp->next=newNode;
        return head;
    }
};