#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    bool isPrime[4000001];
    int n;
    cin>>n;

    if(n == 1){
        cout<<0;
        return 0;
    }

    for(int i=2;i<=n;++i){
        isPrime[i] = true;
    }

    for(int i=2;i*i<=n;++i){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=2;i<=n;++i){
        if(isPrime[i]){
            v.push_back(i);
        }
    }

    int l = 0, r = 0, cnt = 0, sum = 0, len = v.size();
    while(r <= len){
        if(sum == n){
            ++cnt;
            sum -= v[l];
            ++l;
        }else if(sum > n){
            sum -= v[l];
            ++l;
        }else{
            sum += v[r];
            ++r;
        }
    }

    cout<<cnt;

    return 0;
}

