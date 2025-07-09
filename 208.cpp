#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node*links[26];
    bool isword=false;

    bool hasletter(char x){
        return (links[x-'a']!=NULL);
    }
};

class Trie {
private:
Node *root;

public:
    Trie(string s) {
        root =new Node();
        cout<< "New Trie "<<s<<"\n";
    }
    
    void insert(string word) {
        Node *cur=root;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(!cur->hasletter(c)){
                cur->links[c-'a']=new Node();
            }
            cur=cur->links[c-'a'];
        }
        cur->isword=true;
    }
    
    bool search(string word) {
        Node *cur=root;
        for(int i=0;i<word.size();i++){
            char c=word[i];
            cur=cur->links[c-'a'];
            if(cur==nullptr)
                return false;
        }
        return cur->isword;
    }
    
    bool startsWith(string prefix) {
        Node *cur=root;
        for(int i=0;i<prefix.size();i++){
            char c=prefix[i];
            cur=cur->links[c-'a'];
            if(cur==NULL)
                return false;
        }
        return true;
    }
};

int main(){
    string s;
    cin>>s;
    Trie trie(s);
    trie.insert(s);
    cout<< trie.search(s.substr(0,s.size()-1))<<"\n";
    cout<< trie.search(s)<<"\n";

    cout<< trie.startsWith(s.substr(0,s.size()-1))<<"\n";
    cout<< trie.startsWith(s)<<"\n";
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */