/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre=nullptr;
        Node* succ=nullptr;
        Node* curr=root;
        
        while(curr){
            if(curr->data<key){
                pre=curr;
                curr=curr->right;
            }
            else if(curr->data>key){
                succ=curr;
                curr=curr->left;
            }
            else{
                if(curr->left){
                    Node* temp=curr->left;
                    
                    while(temp->right){ 
                        temp=temp->right;
                    }
                    
                    pre=temp;
                }
                
                if(curr->right){
                    Node* temp=curr->right;
                    
                    while(temp->left){
                        temp=temp->left;
                    }
                    
                    succ=temp;
                }
                break;
            }
        }
        
        return {pre,succ};
    }
};