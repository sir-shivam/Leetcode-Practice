class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        int i = 0;
        int j = 0;
        
        unordered_map<char , int> freq;
        int ans = 0;

        while(j < n ){
            freq[s[j]] ++;

            while(freq.size() == 3){
                ans += n - j;

                freq[s[i]]--;
                if(freq[s[i]] == 0){
                    freq.erase(s[i]);
                }
                i++;
            }


            j++;

        }

        return ans;



    }
};