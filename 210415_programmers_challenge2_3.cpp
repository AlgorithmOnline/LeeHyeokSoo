#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, vector<int>> m;
bool visit[300000];
long long cnt = 0;

long long postorder(int n, vector<long long> &newA){
    long long &ret = newA[n];
    long long tmp;

    visit[n] = true;
    for(int i : m[n]){
        if(!visit[i]){
            tmp = postorder(i, newA);
            if(tmp > 0){
                ret += tmp;
                cnt += tmp;
            }else{
                ret += tmp;
                cnt -= tmp;
            }
        }
        
    }

    return ret;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -1;
    int root;
    vector<long long> newA;

    for(int i : a){
        newA.push_back(i);
    }
    
    for(vector<int> v : edges){
        m[v[0]].push_back(v[1]);
        m[v[1]].push_back(v[0]);
    }

    for(auto i : m){
        if(i.second.size() == 1){
            root = i.first;
            break;
        }
    }

    if(postorder(root, newA) == 0){
        answer = cnt;
    }

    return answer;
}
