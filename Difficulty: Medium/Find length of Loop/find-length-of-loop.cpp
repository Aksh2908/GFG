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
        Node* slow=head;
        Node* fast=head;
        
        int flag=0;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=1;
                break;
            }
        }
        int cnt=0;
        if(!flag) return cnt;
        else{
            slow=slow->next;
            
            while(slow!=fast){
                cnt++;
                slow=slow->next;
            }
        }
        
        return cnt+1;
    }
};