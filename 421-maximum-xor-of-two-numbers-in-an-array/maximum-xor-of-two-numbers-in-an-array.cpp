class Trie{

public:

    Trie* child[2];

    Trie(){

        child[0] = NULL;
        child[1] = NULL;
    }

    void insert(int num){

        Trie* curr = this;

        for(int i = 31 ; i >= 0 ; i--){

            int bit = (num >> i) & 1;

            if(curr->child[bit] == NULL){
                curr->child[bit] = new Trie();
            }

            curr = curr->child[bit];
        }
    }

    int findMax(int num){

        Trie* curr = this;

        int ans = 0;

        for(int i = 31 ; i >= 0 ; i--){

            int bit = (num >> i) & 1;

            int opp = 1 - bit;

            if(curr->child[opp] != NULL){

                ans |= (1 << i);
                curr = curr->child[opp];
            }

            else{
                curr = curr->child[bit];
            }
        }

        return ans;
    }
};


class Solution {
public:

    int findMaximumXOR(vector<int>& nums) {

        Trie root;

        for(auto &a : nums){
            root.insert(a);
        }

        int ans = 0;

        for(auto &a : nums){
            ans = max(ans , root.findMax(a));
        }

        return ans;
    }
};