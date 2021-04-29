#include <iostream>
#include <string>
using namespace std;

int n,x;
int main() {
    cin>>n>>x;
    string ans;
    int tmp = 0, idx;
    if(26*n < x || n > x){
        cout<<"!";
        return 0;
    }

    while(n > 0){
        tmp = (n-1)*26;
        if(tmp > x){
            ans.push_back('A');
            --n; --x;
        }else{
            if(tmp < x){
                ans.push_back(x-tmp+64);
                --n; x -= (x-tmp);
            }
            break;
        }
    }

    idx = x / 26;
    for(int i=0;i<idx;++i){
        ans.push_back('Z');
    }

    cout<<ans;
    return 0;
}
