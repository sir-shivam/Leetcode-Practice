class Solution {

    int res = 0 ;

    int help( int node , int par , vector<vector<int>> & adj , string & s  ){
        
        int first = 0 ;
        int second = 0 ;

        for(int a : adj[node]){
            if( a == par ) continue;

            int child = help(a , node , adj , s );

            if(s[a] == s[node]) continue;
            if(child > first ){
                second = first ;
                first = child;
            }else if( child > second ){
                second = child;
            }
        }

        res = max( res , 1 + first + second );

        return 1 + first ;

    }
public:
    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size();
        vector<vector<int>> adj( n );

        for( int i = 1 ; i < n ; i++){

            adj[i].push_back(parent[i]);

            adj[parent[i]].push_back(i);
        }
        // vector<int> 
            int first = 0 ;
            int second = 0 ;

    
        help( 0 , - 1 , adj , s );

        return res;
        return 0 ;
    }
};