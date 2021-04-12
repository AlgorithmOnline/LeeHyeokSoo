#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void print(string str, vector<int> &v){
    int funcLen = str.length();
    int front = 0;
    int back = v.size();
    int tmp;
    char c;

    for(int j=0;j<funcLen;++j){
        c = str[j];
        if(c == 'R'){
            if(front < back){
                tmp = back;
                back = front-1;
                front = tmp-1;
            }else if( front > back){
                tmp = back;
                back = front+1;
                front = tmp+1;
            }
        }else{
            if(front == back){
                cout<<"error\n";
                return ;
            }else{
                if(front < back){
                    ++front;
                }else if(front > back){
                    --front;
                }
            }
        }
    }

    cout<<"[";
    if(front < back){
        for(int i=front;i<back;++i){
            if(i == front){
                cout<<v[i];
            }else{
                cout<<","<<v[i];
            }
        }
    }else if(front > back){
        for(int i=front;i>back;--i){
            if(i == front){
                cout<<v[i];
            }else{
                cout<<","<<v[i];
            }
        }
    }
    cout<<"]\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n, cur, prev;
    string func, arr;

    cin>>t;
    for(int i=0;i<t;++i){
        cin>>func>>n>>arr;

        vector<int> v;
        if(n == 0){
            print(func, v);
            continue;
        }

        arr.erase(arr.begin());
        arr.erase(arr.end()-1);
        prev = 0; cur = arr.find(',');

        while(cur != -1){
            string str = arr.substr(prev,cur-prev);
            v.push_back(stoi(str));
            prev = cur+1;
            cur = arr.find(',', prev);
        }
        v.push_back(stoi(arr.substr(prev,cur-prev)));
        print(func, v);
    }
    return 0;
}
