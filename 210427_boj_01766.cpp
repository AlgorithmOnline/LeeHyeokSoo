#include <iostream>
#include <queue>
#include <map>
using namespace std;

int arr[32001];
map<int, vector<int>> edge;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, m, pre, post;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        cin>>pre>>post;
        ++arr[post];
        edge[pre].push_back(post);
    }

    for(int i=1;i<=n;++i){
        if(arr[i] == 0){
            pq.push(i);
        }
    }

    int cur;
    while(!pq.empty()){
        cur = pq.top();
        pq.pop();
        cout<<cur<<" ";

        for(int i : edge[cur]){
            --arr[i];
            if(arr[i] == 0){
                pq.push(i);
            }
        }
    }

    return 0;
}
