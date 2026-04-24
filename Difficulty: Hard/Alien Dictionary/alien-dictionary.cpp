class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        vector<int> present(26,0);
        
        for(auto it:words){
            for(int i=0;i<it.size();i++){
                present[it[i]-'a']=1;
            }
        }
        
        vector<vector<int>> graph(26,vector<int>());
        
        int i=0,j=0;
        
        for(int i=0;i<n-1;i++){
            int j=0,k=0;
            string s1=words[i];
            string s2=words[i+1];
            while(j<s1.size() && k<s2.size()){
                if(s1[j]==s2[k]){
                    j++;k++;
                }
                else{
                    graph[s1[j]-'a'].push_back(s2[k]-'a');
                    break;
                }
                if(j==s2.size() && s1.size()>s2.size()){
                    return "";
                }
            }
        }
        
        vector<int> indeg(graph.size(),0);
        
        for(int i=0;i<graph.size();i++){
            for(auto x:graph[i]){
                indeg[x]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<indeg.size();i++){
            if(!indeg[i] && present[i]) q.push(i);
        }
        
        string st="";
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            st+=(node+'a');
            
            for(auto it:graph[node]){
                indeg[it]--;
                if(indeg[it]==0 && present[it]) q.push(it);
            }
        }
        
        int cnt=accumulate(present.begin(),present.end(),0);
        if(cnt!=st.length()) return "";
        return st;
    }
};