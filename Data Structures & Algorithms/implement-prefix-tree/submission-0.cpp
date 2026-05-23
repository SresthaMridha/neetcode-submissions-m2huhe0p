class TrieNode {
   public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        endOfWord = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
   public:
    TrieNode* root;
    PrefixTree() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;

        for (auto c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;

        for (auto c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }

        return curr->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (auto c : prefix) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                return false;
            }

            curr = curr->children[index];
        }
        return true;
    }
};
