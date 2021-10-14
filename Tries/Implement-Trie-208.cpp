// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie
//  (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously
//  inserted string word that has the prefix prefix, and false otherwise.
 // Example 1:
// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]
// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True 
// Constraints:
// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 104 calls in total will be made to insert, search, and startsWith.

class Trie {
public:
    struct TrieNode
    {
        char val;
        int count;
        int endsHere;
        TrieNode *children[26];
    };
    TrieNode *root;
    
    TrieNode *getNode(int index){
        TrieNode *newNode = new TrieNode;
        newNode->val = 'a' + index;
        newNode->count = newNode->endsHere = 0;
        for(int i = 0; i < 26; i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    
    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = getNode('/' - 'a');
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        int index;
        for(int i = 0; i < word.size(); i++){
            index = word[i] - 'a';
            if(curr->children[index] == NULL){
                curr->children[index] = getNode(index);
            }
            curr->children[index]->count += 1;
            curr = curr->children[index];
        }
        curr->endsHere += 1;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        int index;
        for(int i = 0; i < word.size(); i++){
            index = word[i] - 'a';
            if(curr->children[index]==NULL)
                return false;
            curr = curr->children[index];
        }
        return (curr->endsHere > 0);
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        int index;
        for(int i = 0; i < prefix.size(); i++){
            index = prefix[i] - 'a';
            if(curr->children[index] == NULL)
                return false;
            curr = curr->children[index];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */