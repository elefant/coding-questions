/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : children(256) {

    }

    ~TrieNode() {
        for (auto c: children) {
            delete c;
        }
    }

    bool mIsString = false;
    vector<TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* ptr = root;
        for (auto c: word) {
            auto& next = ptr->children[c];
            if (!next) {
                next = new TrieNode();
            }
            ptr = next;
        }
        ptr->mIsString = true;
    }

    TrieNode* find(string word) {
        auto ptr = root;
        for (auto c: word) {
            ptr = ptr->children[c];
            if (!ptr) {
                return nullptr;
            }
        }
        return ptr;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto ptr = find(word);
        return ptr ? ptr->mIsString : false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return !!find(prefix);
    }

private:
    TrieNode* root;
};