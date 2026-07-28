using pp = pair<int ,  string >;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        map<string ,int > mpp;

        for( auto & a : wordList){
            mpp[a] = 1e9 ;
        }
        

        mpp[beginWord] = 1e9;

        if(!mpp.count(endWord)) return 0 ;

        priority_queue<pp , vector<pp> , greater<pp>> pq;

        int m = wordList.size();

        vector<int> dis( m , 0 );

        pq.push({ 1, beginWord});

        while( !pq.empty()){
            
            auto [ d , word] = pq.top();
            pq.pop();

            if( word == endWord) return d;

            if( d <  mpp[word]){
                mpp[word] = d ;

                for(int i = 0 ; i < word.size() ; i++){
                char s = word[i];
                for(char a = 'a' ; a <= 'z' ; a++){
                    word[i] = a;
                    if(mpp.count(word)){
                        pq.push({ d+1 , word});
                    }
                    word[i] = s;
                }
            }

            }

            
        }

        return 0;


    }
};