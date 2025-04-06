//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


// } Driver Code Ends

// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
    private:
    Node* createLL(Node* tail,int key){
        Node* temp=new Node(key);
        if(!temp){
            return temp;
        }
        if(tail) tail->next=temp;
        return temp;
    }
  public:
    Node* constructLL(vector<int>& arr) {
        Node* head=NULL;
        Node* tail=NULL;
        int i,n=arr.size();
        for(i=0;i<n;i++){
            if(!head)head=tail=createLL(tail,arr[i]);
            else tail=createLL(tail,arr[i]);
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        Node* ans = ob.constructLL(arr);
        while (ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends