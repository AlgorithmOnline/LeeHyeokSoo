#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    stack<int> s;
    int n, num;

    cin>>n;
    vector<int> v1(n);
    vector<int> v2(n);
    for(int i=0;i<n;++i){
        cin>>num;
        v2[i] = num;

        if(s.empty()){
            s.push(i);
        }else{
            if(v2[s.top()] < num){
                while(!s.empty() && v2[s.top()] < num){
                    v1[s.top()] = num;
                    s.pop();
                }
            }
            s.push(i);
        }
    }

    while(!s.empty()){
        v1[s.top()] = -1;
        s.pop();
    }

    for(int i : v1){
        cout<<i<<" ";
    }

    return 0;
}
