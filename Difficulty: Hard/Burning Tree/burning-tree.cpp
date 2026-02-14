/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    void createMap(Node* root, map<Node*,Node*>& mpp){
        queue<Node*> q;

        q.push(root);

        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    mpp[node->left]=node;
                }

                if(node->right){
                    q.push(node->right);
                    mpp[node->right]=node;
                }
            }
        }
    }

    int solve(map<Node*,Node*>& mpp, Node* target){
        int cnt=0;

        queue<Node*> q;
        unordered_set<Node*> visited;
        q.push(target);
        
        while(!q.empty()){         
            int size=q.size();
            bool burned=false;
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                
                visited.insert(node);
                if(node->left && visited.find(node->left)==visited.end()){
                    burned=true;
                    q.push(node->left);
                }

                if(node->right && visited.find(node->right)==visited.end()){
                    burned=true;
                    q.push(node->right);
                }

                if(mpp.count(node) && visited.find(mpp[node])==visited.end()){
                    burned=true;
                    q.push(mpp[node]);
                }
            }
            if(burned) cnt++;
        }   

        return cnt;
    }
    
    Node* find(Node* root, int target){
        if(!root || root->data==target) return root;
        
        Node* left=find(root->left,target);
        if(left) return left;
        return find(root->right,target);
    }
    
  public:
    int minTime(Node* root, int target) {
        // code here
        if(!root) return 0;

        map<Node*,Node*> mpp;

        createMap(root,mpp); 
        
        Node* node=find(root,target);
        return solve(mpp,node);
    }
};