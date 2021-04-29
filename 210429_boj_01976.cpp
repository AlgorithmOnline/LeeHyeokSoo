#include <iostream>
#include <algorithm>
using namespace std;

int findParent(int arr[], int city){
    while(city != arr[city]){
        city = arr[city];
    }
    
    return city;
}

void unionParent(int arr[], int city1, int city2){
    int parent1 = findParent(arr, city1);
    int parent2 = findParent(arr, city2);

    if(parent1 < parent2){
        arr[parent2] = parent1;
    }else{
        arr[parent1] = parent2;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int parent[201], load[1000];
    int n, m, isConnect;

    cin>>n>>m;

    for(int i=1;i<=n;++i){
        parent[i] = i;
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>isConnect;
            if(i <= j && isConnect == 1){
                unionParent(parent, i, j);
            }
        }
    }

    for(int i=0;i<m;++i){
        cin>>load[i];
    }

    for(int i=1;i<m;++i){
        if(findParent(parent, load[i-1]) != findParent(parent, load[i])){
            cout<<"NO\n";
            return 0;
        }
    }

    cout<<"YES\n";
    return 0;
}
