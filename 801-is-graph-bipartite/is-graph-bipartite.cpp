class Solution {

    bool help( int node , int colour ,  vector<vector<int>> & graph  , vector<int> & vis){
        
        if(vis[node] != 0 && vis[node] != colour) return false;

        if( vis[node]) return true;

        vis[node] = colour;

        int nxt = colour == 1 ? 2 : 1;
        for(auto & a : graph[node]){
            if(!help( a , nxt , graph , vis)){
                return false;
            }
        } 

        return true;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // it is actually asking if i can color 1 , 2 
        
        queue<pair<int , int>> q;
        vector<int> vis(graph.size() , 0 );
        for (int i = 0; i < graph.size(); i++) {
        if (!vis[i]) {
            if (!help(i, 1, graph, vis))
                return false;
        }
    }

    return true;


    }
};