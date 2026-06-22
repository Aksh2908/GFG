/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        // code here
        if(!headRef || !headRef->next) return headRef;
        
        Node* first=headRef;
        Node* second=headRef->next;
        
        while(first && second){
            if(first->data==second->data){
                second->prev=nullptr;
                second=second->next;
            }
            else{
                first->next=second;
                second->prev=first;
                first=first->next;
                second=second->next;
            }
        }
        
        if(first) first->next=second;
        if(second) second->prev=first;
        return headRef;
    }
};