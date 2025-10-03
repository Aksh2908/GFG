class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int V=words.size();
        vector<vector<int>> graph(26,vector<int>());
        vector<int> present(26,0);
        
        
        for(auto it:words){
            for(int i=0;i<it.length();i++){
                present[it[i]-'a']=1;
            }
        }
        
        for(int i=0;i<V-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int j=0,k=0;
            
            while(j<s1.length() && k<s2.length()){
                if(s1[j]==s2[k]){
                    j++;k++;
                }
                else{
                    graph[s1[j]-'a'].push_back(s2[k]-'a');
                    //cout << s1[j] << " " << s2[k] << endl;
                    break;
                }
            }
            if (j == s2.length() && s1.length() > s2.length()){
                return "";
            }
        }
        
        // for(int i=0;i<26;i++){
        //     for(auto it:graph[i]){
        //         cout << i << "->" << it << " ";
        //     }
        //     cout << endl;
        // }
        
        vector<int> indeg(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                indeg[it]++;
            }
        }
        // cout << endl;
        // for(auto it:indeg){
        //     cout << it << " ";
        // }
        
        queue<int> q;
        
        for(int i=0;i<indeg.size();i++){
            if(!indeg[i] && present[i]==1) q.push(i);
        }
        
        string st="";
        
        while(!q.empty()){
            int node=q.front();
            st+=(node+'a');
            q.pop();
            
            for(auto it:graph[node]){
                indeg[it]--;
                if(!indeg[it] && present[it]) q.push(it);
            }
        }
        
        //cout << st << " ";
        
        int cnt=accumulate(present.begin(),present.end(),0);
        if(cnt!=st.length()) return "";
        
        return st;
    }
};