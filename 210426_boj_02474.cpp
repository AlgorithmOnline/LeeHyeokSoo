#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, num1, num2, num3, l, r, idx;
    vector<int> v;
    long long sum = 3000000000, tmpSum;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num1;
        v.push_back(num1);
    }
    sort(v.begin(), v.end());

    for(int i=0;i<n-2;++i){
        l = i+1;
        r = n-1;
        while(l < r){
            tmpSum = v[i] + v[l] + v[r];

            if(abs(sum) > abs(tmpSum)){
                sum = tmpSum;
                num1 = v[i];
                num2 = v[l];
                num3 = v[r];
            }

            if(tmpSum == 0){
                break;
            }else if(tmpSum > 0){
                --r;
            }else{
                ++l;
            }
        }
    }

    cout<<num1<<" "<<num2<<" "<<num3;
}

