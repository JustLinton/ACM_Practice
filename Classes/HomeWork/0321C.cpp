#include <bits/stdc++.h>
using namespace std;

const int INF = 99999999;
typedef long long ll;

int N,A,B,tmp,ans;
unordered_map<int,vector<int>> nodes;
queue<int> nodeQueue;
unordered_map<int,int>dis;
unordered_map<int,bool>vis;

int dijkstra(){
    nodeQueue.push(A);
    for(int i=1;i<=N;i++){dis[i]=INF;vis[i]=false;}
    dis[A]=0;
    while (!nodeQueue.empty())
    {
        int theNode=nodeQueue.front(); 
        vector<int> nextNodes=nodes[theNode];
        nodeQueue.pop();
        for(int next:nextNodes){
            if(!vis[next]){
                vis[next]=true;
                nodeQueue.push(next);
                if(dis[next]>dis[theNode]+1)
                dis[next]=dis[theNode]+1;
                //cout<<next<<' '<<dis[next]<<endl;
            }
        }
    }
    return dis[B];
}

void solve(){
    for(int i=1;i<=N;i++){
        cin>>tmp;
        if(i-tmp>=1)nodes[i].push_back(i-tmp);
        if(i+tmp<=N)nodes[i].push_back(i+tmp);
    }
    ans=dijkstra();
    if(ans!=INF)cout<<ans<<endl;
    else cout<<-1<<endl;
    nodes.clear();
    vis.clear();
    dis.clear();
}

int main() {
	// freopen("/home/linton/Desktop/CSP/a.in", "r", stdin);
	// freopen("/home/linton/Desktop/CSP/a.out", "w", stdout);
    while (true)
    {
        cin>>N;
        if(N==0) break;
        cin>>A>>B;
        solve();
    }
}
