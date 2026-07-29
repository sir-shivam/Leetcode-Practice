class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // trying topo sort 

        vector<vector<int>> adj(n);

        vector<int> inDeg( n , 0 );

        for( auto & p : pre){
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);

            inDeg[v] ++;
        }

        queue<int> q;

        for(int i = 0 ; i < n ; i++){
            if( inDeg[i] == 0 ){
                q.push(i);
            }
        }


        vector<int> topo;

        int cnt = 0 ;
        while(!q.empty()){
            auto node = q.front();

            q.pop();

            cnt ++;

            topo.push_back(node);

            for(auto & a : adj[node]){
                inDeg[a] --;
                if(inDeg[a] == 0 ){
                    q.push(a);
                }
            }
        }


        return cnt == n ;

        
    }
};