struct Node{
    int val ;
    vector<int> freq;

    Node( int val , int ch){
        this -> val = val;
        freq.resize(26 , 0 );
        freq[ch] = 1;
    }
};

class Solution {



    void help( int  node , int par , vector<vector<int >> & adj  , vector<Node* > &arr ){

        Node * curr = arr[node];

        for(auto & a : adj[node]){
            if( par == a ) continue;

            help( a , node , adj , arr);

            for(int i = 0 ; i < 26 ; i++){
                curr -> freq[i] += arr[a] -> freq[i];
            }

        }
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<vector<int >> adj( n );
        vector<Node* > arr( n , NULL );

        for(int i = 0 ; i < n ; i++){
            arr[i] = new Node( i , labels[i] - 'a');
        }

        for( auto & ed : edges){

            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }


        help( 0 , -1 , adj , arr);


        vector<int> ans( n );

        for(int i = 0 ; i < n ; i++){
            ans[i] = arr[i] -> freq[labels[i] - 'a'];
        }

        return ans;


    }
};