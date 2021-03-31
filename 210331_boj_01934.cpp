#include <iostream>
using namespace std;

int lcm(int a, int b){
    int ret = a * b;

    if(a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    int remain;
    while(1){
        remain = a % b;

        if(remain == 0){
            break;
        }

        a = b;
        b = remain;
    }

    return ret / b;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, a, b;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        cout<<lcm(a, b)<<"\n";
    }
    return 0;
}
