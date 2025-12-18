/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(!head) return 0;
        int cnt=0,flag=0;
        Node* slow=head,*fast=head->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=1;
                break;
            }
        }
        
        if(flag){
            fast=fast->next;
            while(fast!=slow){
                cnt++;
                fast=fast->next;
            }
            return cnt+1;
        }
        return 0;
    }
};