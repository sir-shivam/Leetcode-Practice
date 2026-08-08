class Trie {
public:
    bool end ;
    vector<Trie *> tree;
    Trie() {
        end = false;
        tree.resize(26 , NULL);
    }
    
    void insert(string word) {

        Trie* curr = this ;
        for( int i = 0 ; i < word.size() ; i++){
            if(curr-> tree[word[i] - 'a'] == NULL){
                curr -> tree[word[i] -'a'] = new Trie();
            }
            curr = curr -> tree[word[i] -'a'];
        }

        curr -> end = true;
    }
    
    bool search(string word) {
        Trie* curr = this;

        int i = 0 ;
        while(i < word.size() && curr -> tree[word[i] - 'a'] != NULL){
            curr = curr -> tree[word[i] - 'a'];
            i ++;
        }

        return i == word.size() && curr -> end == true; 
    }
    
    bool startsWith(string word) {
        Trie* curr = this;

        int i = 0 ;
        while(i < word.size() && curr -> tree[word[i] - 'a'] != NULL){
            curr = curr -> tree[word[i] - 'a'];
            i ++;
        }

        return i == word.size();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */