#include <iostream>
#include <map>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n, num;
    char op;
    cin>>t;
    for(int i=0;i<t;++i){
        map<int, int> m;

        cin>>n;
        for(int j=0;j<n;++j){
            cin>>op>>num;
            if(op == 'I'){
                if(m.find(num) != m.end()){
                    ++m[num];
                }else{
                    m[num] = 1;
                }
            }else{
                if(m.size() != 0){
                    if(num == -1){
                        if(m.begin()->second == 1){
                            m.erase(m.begin());
                        }else{
                            --m.begin()->second;
                        }
                    }else{
                        if((--m.end())->second == 1){
                            m.erase(--m.end());
                        }else{
                            --(--m.end())->second;
                        }
                    }
                }
            }
        }

        if(m.size() == 0){
            cout<<"EMPTY\n";
        }else{
            cout<<(--m.end())->first<<" "<<m.begin()->first<<"\n";
        }
    }

    return 0;
}

