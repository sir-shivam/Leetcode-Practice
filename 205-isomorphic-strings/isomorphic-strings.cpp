class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();

        map<char , char> mpp;
        map<char , char > mpp2;

        for(int i = 0 ; i < n ; i++ ){

                if( mpp.count(s[i]) && mpp[s[i]] != t[i]) return false;

                if( mpp2.count(t[i]) && mpp2[t[i]] != s[i]) return false;
        
                mpp[s[i]] = t[i];
                mpp2[t[i]] = s[i];
        }

        return true;
    }
};