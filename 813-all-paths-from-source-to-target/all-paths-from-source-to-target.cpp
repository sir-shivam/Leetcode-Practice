class Solution {

    int N ;
    vector<vector<int>> ans;

    void help( int node , vector<vector<int>>& adj , vector<int> & curr){

        if( node == N-1){
            ans.push_back(curr);
            return ;
        }
        for(auto & a : adj[node]){
            curr.push_back(a);

            help( a, adj , curr);

            curr.pop_back();
        }
        
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        N = graph.size();
        vector<int> curr;
        curr.push_back( 0 );

        help(0 , graph , curr );

        return ans;
    }
};