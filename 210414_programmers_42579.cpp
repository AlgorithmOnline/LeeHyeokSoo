#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> m;
    priority_queue<pair<int, string>> pq;
    
    int len = genres.size();
    for(int i=0;i<len;++i){
        m[genres[i]].push_back({i, plays[i]});
    }
    
    for(auto i : m){
        int total = 0;
        for(pair<int, int> p : i.second){
            total += p.second;
        }
        pq.push({total, i.first});
    }
    
    while(!pq.empty()){
        string g = pq.top().second;
        pq.pop();
        
        sort(m[g].begin(), m[g].end(), cmp);
        int cnt = 0;
        for(pair<int, int> p : m[g]){
            answer.push_back(p.first);
            ++cnt;
            
            if(cnt == 2){
                break;
            }
        }
    }
        
    return answer;
}
