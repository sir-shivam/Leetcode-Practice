class Solution {
public:
    int minimumPushes(string word) {
        
        vector<pair<int, int>> freq( 26  );

        for(int i = 0 ; i < 26 ; i ++){
            freq[i] = {0 , i };
        }

        for(auto & ch : word){
            freq[ch - 'a'].first ++;
        }

        sort(freq.begin() , freq.end() , greater<>());

        int i = 0 ; 
        int round = 1;

        int ans  = 0 ;

        for( auto & [ cnt  , idx] : freq){
            ans += round *  cnt ;

            i ++;
            if( i >= 8 ){
                round ++;
                i = 0 ;
            }
        }

        return ans;
    }
};