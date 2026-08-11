class Solution {

    bool comp(string &s1 , string &s2){

        if(s1.size() != s2.size() +1 ) return false;

        int i = 0 ;
        int j = 0 ;

        while(i < s1.size() && j <s2.size()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }else{
                i ++;
            }
        }

        return j == s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();

        int maxi = 0;
        vector<int> dp( n, 1);

        sort(words.begin(), words.end(), [](string &a, string &b) {
    return a.size() < b.size();
});

        for( int i = 0 ; i < n ; i++){
            for(int prev = 0 ; prev < i ; prev ++){

                if(comp(words[i] , words[prev]) && dp[prev] +1 >  dp[i] ){
                    dp[i] = dp[prev] +1 ;
                }
            }

            maxi = max( maxi , dp[i]);
        }

        return maxi ;

    }
};