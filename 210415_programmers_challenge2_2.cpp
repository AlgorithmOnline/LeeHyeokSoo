#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool check(string str){
    stack<char> s;
    bool ret = true;
    
    for(char c : str){
        if(c == ']'){
            if(s.empty() || s.top() != '['){
                ret = false;
                break;
            }else{
                s.pop();
            }
        }else if(c == '}'){
            if(s.empty() || s.top() != '{'){
                ret = false;
                break;
            }else{
                s.pop();
            }
        }else if(c == ')'){
            if(s.empty() || s.top() != '('){
                ret = false;
                break;
            }else{
                s.pop();
            }
        }else{
            s.push(c);
        }
    }
    
    if(!s.empty()){
        ret = false;
    }
    
    return ret;
}

int solution(string s) {
    int answer = 0;
    int len = s.length();
    
    for(int i=0;i<len;++i){
        s.push_back(s[0]);
        s.erase(0, 1);
        
        if(check(s)){
            ++answer;
        }
    }
    
    return answer;
}
