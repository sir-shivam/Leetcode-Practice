class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26 , 0);

        for(auto & a : s){
            freq[a - 'a'] ++;
        }

        string ans = "";

        for( int i = 0 ; i < 26 ; i++){
            while(freq[i] > 1) {
                ans += i + 'a';

                freq[i] -= 2;

            }
        }

        string temp = ans;
        reverse(temp.begin() , temp.end());

        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] == 1){
                ans += i + 'a';
                break;
            }
        }

        return ans + temp;
    }
};