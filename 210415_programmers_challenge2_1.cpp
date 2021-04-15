#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int len = absolutes.size();
    int num;
    
    for(int i=0;i<len;++i){
        num = absolutes[i];
        if(signs[i]){
            answer += num;
        }else{
            answer -= num;
        }
    }

    return answer;
}
