#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

struct trie{
    map<string, trie*> next;
    int nextCnt;

    trie(){
        nextCnt = 0;
    }

    void insert(trie *cur, vector<string> &line){
        for(int i=0;i<line.size();++i){
            if(cur->next.find(line[i]) == cur->next.end()){
                cur->next[line[i]] = new trie;
                cur->nextCnt += 1;
            }
            cur = cur->next[line[i]];
        }
    }

    void printDash(int depth){
        for(int i=0;i<depth;++i){
            cout<<"--";
        }
    }

    void print(trie *cur, int depth){
        if(cur->nextCnt != 0){
            for(auto i : cur->next){
                printDash(depth);
                cout<<i.first<<"\n";
                print(i.second, depth+1);
            }
        }
    }
};

int main() {
    int n, k;
    trie *root = new trie;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>k;
        vector<string> v(k);
        for(int j=0;j<k;++j){
            cin>>v[j];
        }
        root->insert(root, v);
    }

    root->print(root, 0);
    return 0;
}
