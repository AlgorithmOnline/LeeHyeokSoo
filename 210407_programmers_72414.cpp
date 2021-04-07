#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int playTime, adTime;
long long prefixSum[360001];

vector<string> parse(string str, char c){
    int prev = 0;
    int cur = 0;
    vector<string> ret;

    cur = str.find(c);
    while(cur != -1){
        ret.push_back(str.substr(prev, cur-prev));
        prev = cur + 1;
        cur = str.find(c, prev);
    }
    ret.push_back(str.substr(prev, -1));

    return ret;
}

int transferTime(string str){
    int sum = 0;
    vector<string> v = parse(str, ':');

    sum += stoi(v[2]);
    sum += stoi(v[1]) * 60;
    sum += stoi(v[0]) * 60 * 60;

    return sum;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    long long sum = -1, tmpSum = -1;
    int len = logs.size(), ans = 0;
    playTime = transferTime(play_time);
    adTime = transferTime(adv_time);

    sort(logs.begin(), logs.end());
    for(string str : logs){
        vector<string> v = parse(str, '-');
        prefixSum[transferTime(v[0])] = 1;
        prefixSum[transferTime(v[1])] = -1;
    }

    for(int i=1;i<=playTime;++i){
        prefixSum[i] += prefixSum[i-1];
    }

    for(int i=1;i<=playTime;++i){
        prefixSum[i] += prefixSum[i-1];
    }
    
    for(int i=adTime;i<=playTime;++i){
        tmpSum = prefixSum[i] - prefixSum[i-adTime];
        if(tmpSum > sum){
            sum = tmpSum;
            ans = i - adTime + 1;
        }
    }

    int h = ans / 3600;
    ans %= 3600;
    int m = ans / 60;
    ans %= 60;
    int s = ans;

    if(h < 10){
        answer.push_back('0');
    }
    answer.append(to_string(h));
    answer.push_back(':');

    if(m < 10){
        answer.push_back('0');
    }
    answer.append(to_string(m));
    answer.push_back(':');

    if(s < 10){
        answer.push_back('0');
    }
    answer.append(to_string(s));

    return answer;
}
