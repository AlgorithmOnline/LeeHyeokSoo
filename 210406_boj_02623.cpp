#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n, m, t, singer;
int cnt[1001];
bool visit[1001];
vector<int> s[1001];
vector<int> v, answer;

int main() {

    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>t;
        for(int j=0;j<t;++j){
            cin>>singer;
            v.push_back(singer);
        }

        for(int j=1;j<t;++j){
            s[v[j-1]].push_back(v[j]);
            ++cnt[v[j]];
        }

        v.clear();
    }

    for(int i=1;i<=n;++i){
        if(cnt[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int next = q.front();
        answer.push_back(next);
        q.pop();

        for(int i : s[next]){
            --cnt[i];
            if(cnt[i] == 0){
                q.push(i);
            }
        }
    }

    if(answer.size() == n){
        for(int i : answer){
            cout<<i<<"\n";
        }

        return 0;
    }

    cout<<"0";
    return 0;
}

