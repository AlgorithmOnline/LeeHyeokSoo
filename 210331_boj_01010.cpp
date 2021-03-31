#include <iostream>
using namespace std;

int memo[30][30];

int calc(int n, int m){
    int &v = memo[n][m];

    if(n == m){
        v = 1;
    }

    if(m == 1){
        v = n;
    }

    if(v != 0){
        return v;
    }

    v = calc(n-1, m) + calc(n-1, m-1);
    return v;
}

int main() {
    int t, n, m;

    cin>>t;
    for(int i=0;i<t;++i){
        cin>>n>>m;

        if(n < m){
            int tmp = n;
            n = m;
            m = tmp;
        }

        cout<<calc(n, m)<<"\n";
    }
    return 0;
}
