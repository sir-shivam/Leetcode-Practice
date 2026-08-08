class Solution {



    void help( int room ,vector<vector<int>>& rooms , vector<int> & vis ){

        if(vis[room]) return ;

        vis[room] = 1;
        for( auto &  key : rooms[room]){
            help(key , rooms , vis);
        }

    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<int> vis( n , 0 );


        help( 0 , rooms , vis);

        for( int i = 0 ; i < n ; i++){
            if(vis[i] == 0 ) return false;
        }
        

        return true;
        
    }
};