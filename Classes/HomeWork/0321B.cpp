#include <bits/stdc++.h>
using namespace std;

const int INF = 99999999;
typedef long long ll;

vector<int> jumps;
int tmp,score,lastScore;

int main() {
	// freopen("/home/linton/Desktop/CSP/a.in", "r", stdin);
	// freopen("/home/linton/Desktop/CSP/a.out", "w", stdout);

    while (true)
    {
        cin>>tmp;
        if(tmp==0)break;
        jumps.push_back(tmp);
    }
    
    for(auto ite=jumps.begin();ite!=jumps.end();ite++){
        if(*ite==1){
            score++;
            lastScore=1;
        }else{
            if(lastScore>=2){
                score+=lastScore+2;
                lastScore+=2;
            }else{
                score+=2;
                lastScore=2;
            }
        }
    }
    cout<<score<<endl;
}
