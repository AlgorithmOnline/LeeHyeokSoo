#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, ans = -1;
    int num1[1000], num2[1000], asc[1000], dsc[1000];
    cin>>n;
    for(int i=0;i<n;++i){
        cin >> num1[i];
        num2[i] = num1[i];
    }

    reverse(num2, num2+n);
    for(int i=0;i<n;++i){
        asc[i] = 1;
        dsc[i] = 1;
        for(int j=0;j<i;++j){
            if(num1[j] < num1[i]){
                asc[i] = max(asc[j]+1, asc[i]);
            }
            if(num2[j] < num2[i]){
                dsc[i] = max(dsc[j]+1, dsc[i]);
            }
        }
    }

    reverse(dsc, dsc+n);
    for(int i=0;i<n;++i){
        ans = max(ans, asc[i]+dsc[i]-1);
    }
    
    cout<<ans;
    return 0;
}
