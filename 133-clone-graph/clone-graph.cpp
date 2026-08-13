/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

map<int , Node* > mpp;

void help( Node* curr){

    Node * copyCurr ;
    if( mpp.count(curr -> val)){
        copyCurr = mpp[curr -> val];
    }else{
        copyCurr = new Node(curr -> val);
        mpp[curr -> val ] = copyCurr;
    }

    for(auto & a : curr -> neighbors){

        if(mpp.count(a -> val)){
            copyCurr -> neighbors.push_back(mpp[a -> val]);
            continue;
        }
        Node * copy = new Node(a  -> val);
        mpp[a -> val ] = copy ;
        copyCurr -> neighbors.push_back(copy);

        help( a );
        
    }
}

class Solution {
public:
    Node* cloneGraph(Node* node) {

        mpp.clear();
        
        if( node == NULL ) return NULL;
        help( node);

        return mpp[node -> val];
    }
};