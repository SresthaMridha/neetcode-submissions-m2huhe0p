class TrieNode{
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        endOfWord = false;

        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for(auto c: word){
            int index = c - 'a';

            if(curr->children[index] == nullptr){
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }
        curr->endOfWord = true;
    }
    
    bool dfs(int i, string word, TrieNode* node){
        if(i == word.size()){
            return node->endOfWord;
        }

        char c = word[i];

        if(c != '.'){
            int index = c - 'a';

            if(node->children[index]==nullptr){
                return false;
            }

            return dfs(i+1, word, node->children[index]);
        }

        else{
            for(int j = 0; j < 26; j++){
                if(node->children[j] != nullptr){
                    if(dfs(i+1, word, node->children[j])){
                        return true;
                    }
                }
            }
            return false;
        }
    }

    bool search(string word) {
        return dfs(0, word, root);
    }
};
