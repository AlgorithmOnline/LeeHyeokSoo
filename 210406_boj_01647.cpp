#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, maxW = -1;
vector<pair<int, int>> v[100001];
bool visit[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    cin>>n>>m;
    int a, b, c;

    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    visit[1] = true;
    for(pair<int, int> e : v[1]){
        pq.push(e);
    }

    int next, w, sum = 0;
    while(!pq.empty()){
        w = pq.top().first;
        next = pq.top().second;
        pq.pop();

        if(visit[next]){
            continue;
        }

        sum += w;
        maxW = max(w, maxW);
        visit[next] = true;

        for(pair<int, int> p : v[next]){
            if(!visit[p.second]){
                pq.push(p);
            }
        }
    }

    cout<<sum - maxW;
    return 0;
}
