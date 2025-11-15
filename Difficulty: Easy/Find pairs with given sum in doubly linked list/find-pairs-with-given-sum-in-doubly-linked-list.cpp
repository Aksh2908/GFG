// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  private:
    Node* findTail(Node* head){
        if(!head || !head->next) return head;
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        return temp;
    }
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        if(!head) return{};
       
        Node* tail=findTail(head);
        Node* temp=head;
        vector<pair<int,int>> ans;
        
        while(temp->data<tail->data){
            int sum=temp->data+tail->data;
            if(sum==target){
                ans.push_back({temp->data,tail->data});
                temp=temp->next;
                tail=tail->prev;
            }
            else if(sum<target){
                temp=temp->next;
            }
            else{
                tail=tail->prev;
            }
        }
        return ans;
    }
};