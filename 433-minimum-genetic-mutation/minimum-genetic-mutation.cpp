class Solution {

    string s = "ACGT";
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        set<string> spp( bank.begin() , bank.end());
        set<string> vis;

        if(!spp.count(endGene)) return -1;
        using pp = tuple<int , string>;
        priority_queue<pp , vector<pp> ,greater<pp>> pq;

        pq.push({ 0 , startGene});

        while(!pq.empty()){
            auto [ d , gene ] = pq.top();

            pq.pop();

            if(vis.count(gene)) continue;
            vis.insert(gene);
            if( gene == endGene) return d ;

            for( auto & a : gene ){
                char ch = a ;
                for(auto & c : s){
                    a = c ;
                    if(spp.count(gene)){
                        pq.push({d+1 , gene});
                    }
                }
                a = ch;
            }
        }

        return -1;

    }
};