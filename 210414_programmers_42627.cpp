#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curTime, totalTime, waitTime, taskTime;
    int cnt = 0, jobIdx = 0, len = jobs.size();
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    sort(jobs.begin(), jobs.end());
    totalTime = 0;
    curTime = jobs[0][0];
    
    while(cnt < len){    
        while(jobIdx < len && jobs[jobIdx][0] <= curTime){
            pq.push({jobs[jobIdx][1], jobs[jobIdx][0]});
            ++jobIdx;
        }
        
        taskTime = pq.top().first;
        waitTime = curTime - pq.top().second;
        pq.pop();
        
        totalTime += taskTime + waitTime;
        curTime += taskTime;
        
        ++cnt;
        
        if(pq.empty() && jobIdx < len){
            curTime = max(jobs[jobIdx][0], curTime);
        }
    }    
    
    return answer = totalTime / len;
}
