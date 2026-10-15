
struct MyTreeNode {
    char val = '0';
    unordered_map<char,MyTreeNode*> subnodes;  
    explicit MyTreeNode(char x = '0') : val(x){}
};

class Trie {
private:
    MyTreeNode *root;

    void destroy(MyTreeNode* node){
        if(!node) return;
        for(auto& [c,child] : node->subnodes){
            destroy(child);
        }
        delete node;
    }
public:
    Trie() {
        root = new MyTreeNode();
    }
    ~Trie(){
        destroy(root);
    }

    void insert(string word) {
        MyTreeNode* ptr = root;
        for(char letter : word){
            auto it = ptr->subnodes.find(letter);
            if(it!=ptr->subnodes.end()){
                ptr = it->second;
            }else{
                MyTreeNode* newnode;
                newnode = new MyTreeNode(letter);
                auto result = ptr->subnodes.emplace(letter,newnode);
                ptr = result.first->second;
            }
            
        }
        auto& end = ptr->subnodes['\0'];
        if (!end) end = new MyTreeNode('\0');
    }
    
    bool search(string word) {
        MyTreeNode* ptr = root;
        for(char letter : word){
            auto it = ptr->subnodes.find(letter);
            if(it!=ptr->subnodes.end()){
                ptr = it->second;
            }else{
                return false;
            }
        }
        return ptr->subnodes.find('\0') != ptr->subnodes.end();
    }
    
    bool startsWith(string prefix) {
        MyTreeNode* ptr = root;
        for(char letter : prefix){
            auto it = ptr->subnodes.find(letter);
            if(it!=ptr->subnodes.end()){
                ptr = it->second;
            }else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */