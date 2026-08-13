class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        
        vector<vector<pair<int , int>>> adj(n);

        for( auto & fl : flights){
            int u = fl[0];
            int v = fl[1];

            int w = fl[2];
            adj[u].push_back({ v , w });
        }
        using pp = tuple<int , int , int> ;

        priority_queue<pp , vector<pp> , greater<pp>> pq;

        pq.push({ 0 , 0 , src });

        vector<vector<int>> dis( n , vector<int> ( k+2 , INT_MAX));
        

        while(!pq.empty()){

            auto [ d , t , node] = pq.top();
            pq.pop();

            if( t > k ) continue;

            for(auto & [a , w ] : adj[node] ){
                
                if( d  + w < dis[a][t+1]){
                    dis[a][t+1] = d+ w;
                    pq.push({d+w , t +1,a});
                }
            }
        }

        int mini = *min_element(dis[dst].begin() , dis[dst].end());

        return mini == INT_MAX ? -1 : mini;

    }
};