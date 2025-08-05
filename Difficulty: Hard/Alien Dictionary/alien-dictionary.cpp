class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n=words.size();
        vector<vector<char>> graph(26);
        vector<int> present(26,0);
        
        for(auto it:words){
            for(int i=0;i<it.length();i++){
                present[it[i]-'a']=1;
            }
        }
        
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int j=0,k=0;
            
            while(j<s1.length() && k<s2.length()){
                if(s1[j]==s2[k]){
                    j++;
                    k++;
                }
                else{
                    graph[s1[j]-'a'].push_back(s2[k]);
                    break;
                }
            }
            
            if (j == s1.length() || k == s2.length()) {
                if (s1.length() > s2.length()) return "";
            }
            
        }
        
        int v=graph.size();
        vector<int> indeg(26,0);
        vector<int> visited(26,0);
        queue<char> q;
        
        for(int i=0;i<26;i++){
            for(char x:graph[i]){
                indeg[x-'a']++;
            }
        }
        
        for(int i=0;i<26;i++){
            if(!indeg[i] && present[i]){
                q.push(i+'a');
                visited[i]=1;
            }
        }
        
        string ans="";
        
        while(!q.empty()){
            char node=q.front();
            ans+=node;
            q.pop();
            
            for(auto it:graph[node-'a']){
                indeg[it-'a']--;
                if(!indeg[it-'a']){
                    q.push(it);
                    visited[it-'a']=1;
                }
            }
        }
        int cnt=accumulate(present.begin(),present.end(),0);
        if(ans.size()!=cnt) return "";
        return ans;
    }
};