/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  private:
    Node* reverseList(Node* head){
        if(!head || !head->next) return head;
        Node* newHead=reverseList(head->next);
        Node* front= head->next;
        front->next=head;
        head->next=nullptr;
        return newHead; 
    }
  public:
    Node* addOne(Node* head) {
        if(!head) return head;
        int carry = 1;
        Node* revHead=reverseList(head);
        Node* temp=revHead;
        int sum=0,val;
        Node* dummy=new Node(-1);
        Node* temp_dummy=dummy;
        
        while(temp){
            sum=0;
            sum+=temp->data;
            if(carry) sum+=carry;
            carry=sum/10;
            val=sum%10;
            temp_dummy->next=new Node(val);
            temp=temp->next;
            temp_dummy=temp_dummy->next;
        }
        
        if(carry){
            temp_dummy->next=new Node(carry);
        }
        
        head=reverseList(dummy->next);
        
        return head;
    }
};