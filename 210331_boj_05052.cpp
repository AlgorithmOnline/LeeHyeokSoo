#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct trie{
    trie *next[11];
    bool numExist;

    trie(){
        for(int i=0;i<11;++i){
            next[i] = NULL;
            numExist = false;
        }
    }

    ~trie(){
        for(int i=0;i<11;++i){
            delete next[i];
        }
    }

    bool insert(trie *cur, string str, int len){
        int idx = 0;
        while(idx < len){

            int nextTrie = str[idx] - '0';
            if(!cur->next[nextTrie]){
                cur->next[nextTrie] = new trie;
            }

            if(cur->next[nextTrie]->numExist){
                return false;
            }
            cur = cur->next[nextTrie];
            ++idx;
        }

        cur->numExist = true;
        return true;
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n;

    cin>>t;
    for(int i=0;i<t;++i){
        trie *root = new trie;
        bool answer = true;

        cin>>n;
        vector<string> v(n);
        for(int j=0;j<n;++j){
            cin>>v[j];
        }

        sort(v.begin(), v.end());
        for(string str : v){
            if(!(root->insert(root, str, str.length()))){
                answer = false;
                break;
            }
        }

        if(answer){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

        delete root;
    }
    return 0;
}
