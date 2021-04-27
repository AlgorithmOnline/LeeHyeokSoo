#include <iostream>
#include <vector>
#include <map>;
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n, m;
    long long answer = 0;
    int a[1000];
    int b[1000];
    int preA[1000];
    int preB[1000];
    map<int, int> aSum;
    map<int, int, greater<int>> bSum;

    cin>>t;
    cin>>n;
    for(int i=0;i<n;++i){
        cin >> a[i];
    }

    cin>>m;
    for(int i=0;i<m;++i){
        cin >> b[i];
    }

    int sum = 0;
    for(int i=0;i<n;++i){
        sum += a[i];
        preA[i] = sum;
    }

    for(int i=0;i<n;++i){
        aSum[preA[i]]++;
        for(int j=0;j<i;++j){
            aSum[preA[i] - preA[j]]++;
        }
    }

    sum = 0;
    for(int i=0;i<m;++i){
        sum += b[i];
        preB[i] = sum;
    }

    for(int i=0;i<m;++i){
        bSum[preB[i]]++;
        for(int j=0;j<i;++j){
            bSum[preB[i] - preB[j]]++;
        }
    }

    map<int, int>::iterator l = aSum.begin(), r = bSum.begin();
    int tmpA, tmpB;
    while(l != aSum.end() && r != bSum.end()){
        tmpA = l->first;
        tmpB = r->first;
        sum = tmpA + tmpB;

        if(sum == t){
            answer += (long long) l->second * r->second;
            ++l;++r;
        }else if(sum < t){
            ++l;
        }else{
            ++r;
        }
    }

    cout<<answer;

    return 0;
}
