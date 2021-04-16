#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string lamp[50];
int n, m, k, answer = -1;

int check(){
    bool on;
    int cnt = 0;

    for(int i=0;i<n;++i){
        on = true;

        for(int j=0;j<m;++j){
            if(lamp[i][j] == '0'){
                on = false;
                break;
            }
        }

        if(on){
            ++cnt;
        }
    }

    return cnt;
}

void recover(int col){
    for(int i=0;i<n;++i){
        if(lamp[i][col] == '1'){
            lamp[i][col] = '0';
        }else{
            lamp[i][col] = '1';
        }
    }
}

void click(int col, int cnt){
    for(int i=0;i<n;++i){
        if(lamp[i][col] == '1'){
            lamp[i][col] = '0';
        }else if(lamp[i][col] == '0'){
            lamp[i][col] = '1';
        }
    }

    if(cnt == k){
        answer = max(answer, check());
        return;
    }

    for(int i=0;i<m;++i){
        click(i, cnt+1);
        recover(i);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>lamp[i];
    }
    cin>>k;

    for(int i=0;i<m;++i){
        click(i, 1);
        recover(i);
    }

    cout<<answer;
    return 0;
}

