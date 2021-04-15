#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1000][1000];
    int dy[3] = {1, 0, -1};
    int dx[3] = {0, 1, -1};
    
    int num = 1;
    int y = -1, x= 0;
    for(int i=0;i<n;++i){
        int d = i % 3;
        for(int j=0;j<n-i;++j){
            y += dy[d];
            x += dx[d];
            
            arr[y][x] = num;
            ++num;
        }
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}
