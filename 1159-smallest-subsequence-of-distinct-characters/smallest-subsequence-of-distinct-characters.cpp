class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int> freq(26 , 0 );

        int n = s.size();

        for( int i = 0 ; i < n  ; i++){
            freq[s[i] - 'a'] ++;
        }

        string ans = "";

        vector<int> taken(26 , 0 );

        for( int i = 0 ; i < n ; i++){
            freq[s[i] - 'a'] --;

            if(taken[s[i] - 'a']) continue;

            while( ans != "" && ans.back() > s[i] && freq[ans.back() - 'a'] > 0){
                taken[ans.back() -'a'] = 0 ;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            taken[s[i] - 'a'] = 1;
            

        }

        return ans;

    }
};