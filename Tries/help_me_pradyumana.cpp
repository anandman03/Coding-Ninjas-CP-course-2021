#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int ll;

class trieNode{
    public:
        trieNode* store[26];
        bool isEndOfTrie;
        trieNode(){
            for(int i=0 ; i<26 ; i++) store[i] = NULL;
            isEndOfTrie = false;
        }
};

void insert(trieNode* root, string s) {
    trieNode* current = root;
    for(int i = 0 ; i < s.length() ; i++) {
        int idx = s[i] - 'a';
        if(current->store[idx] == NULL) {
            current->store[idx] = new trieNode();
        }
        current = current->store[idx];
    }
    current->isEndOfTrie = true;
}

void display(trieNode* head , string s) {
    if(head->isEndOfTrie) {
        cout  << s << endl;
    }
    for(int i=0 ; i<26 ; i++){
        if(head->store[i]){
            s.push_back(i + 'a');
            display(head->store[i], s);
            s.pop_back();
        }
    }
}

void query(trieNode* head , string s){
    trieNode* curr_node = head;
    for(int i=0 ; i<s.size() ; i++) {
        int index = s[i]-'a';
        if(curr_node->store[index]) {
            curr_node = curr_node->store[index];
        }
        else {
            cout << "No suggestions" << endl;
            insert(head,s);
            return;
        }
    }
    display(curr_node, s);
}

int main(int argc, char const *argv[])
{
    int n,q;
    string s;
    trieNode* head = new trieNode();
    cin >> n;
    while(n--){
        cin >> s;
        insert(head,s);
    }
    cin >> q;
    while(q--){
        cin >> s;
        query(head,s);
    }
    return 0;
}