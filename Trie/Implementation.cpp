// it is used for doing efficient operations on words in dictionary
// search, insert,delete,prefix search(we enter starting of any word),lexographical ordering
#include <iostream>
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

bool searchInTrie(string& key);
void insertInTrie(string& key);

TrieNode* root = new TrieNode();

bool searchInTrie(string& key) {
    TrieNode* curr = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL) {
            return false;
        }
        curr = curr->child[index];
    }
    return curr->isEnd;
}

void insertInTrie(string& key) {
    TrieNode* curr = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL) {
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
}

bool isEmpty(TrieNode *root){
    for(int i=0;i<26;i++){
        if(root->child[i] != NULL){
            return false;
        }
    }
    return true;
}

TrieNode *deleteInTrie(TrieNode *root,string &key,int i){
    if(root==NULL){
        return NULL;
    }
    if(i = key.length()){
        root->isEnd = false;
        if(isEmpty(root)){
            delete(root);
            root = NULL;
        }
    }
    int index = key[i]-'a';
    root->child[index] = deleteInTrie(root->child[index],key,i+1);
    if(isEmpty(root) && root->isEnd == false){
        delete(root);
        root = NULL;
    }
    return root;
}

int main() {
    insertInTrie("tushar");
    insertInTrie("geeks");
    cout << searchInTrie("tushar");
}
