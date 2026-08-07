class Solution {

    string start , target;

    vector<int> ans;

    void help( int node , int par , vector<vector<pair< int ,int>>> & adj ){

        for(auto & [a , idx ] : adj[node]){
            if( par == a ) continue;
            help( a , node , adj );
            int t = start[a] != target[a];
            if( t ){
                ans.push_back(idx);
                start[a] = target[a];
                start[node]  = start[node] == '0' ? '1' : '0';
            }
        }


    }
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string s, string t ) {
        
        start = s;
        target = t ;
        if( s== t ) return{};
        vector<vector<pair<int , int>>> adj(n);

        for( int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({ v , i });
            adj[v].push_back({ u , i});
        }
        help( 0 , -1 , adj);

        if(start[0] != target[0]){
            return { -1};
        }

        sort( ans.begin() , ans.end());


        return ans;

    }
};