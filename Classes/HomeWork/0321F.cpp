#include <bits/stdc++.h>
using namespace std;

const int INF = 99999999;
typedef long long ll;

unordered_map<int,unordered_map<int,int>> avSlots;
unordered_map<int,bool> validRows,validCols;
unordered_map<int,int> placedQueens;
int n,k;
ll ans;
string inputStr;

void dfs(int depth){
    if(depth==k){
        ans++;
        // for(auto ite=placedQueens.begin();ite!=placedQueens.end();ite++)cout<<ite->first<<'-'<<ite->second<<' ';
        // cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(!validRows[i])continue;
        for(int j=1;j<=n;j++){
            if(placedQueens[depth-1]<i*10+j&&avSlots[i][j]&&validRows[i]&&validCols[j]){
                validRows[i]=false;
                validCols[j]=false;
                placedQueens[depth]=i*10+j;
                dfs(depth+1);
                placedQueens.erase(depth);
                validRows[i]=true;
                validCols[j]=true;
            }
        }
    }
}

int main() {
	// freopen("/home/linton/Desktop/CSP/a.in", "r", stdin);
	// freopen("/home/linton/Desktop/CSP/a.out", "w", stdout);

    while (true)
    {
        cin>>n>>k;
        if(n==-1&&k==-1)break;
        for(int i=1;i<=n;i++)validRows[i]=true;
        for(int i=1;i<=n;i++)validCols[i]=true;
        for(int i=1;i<=n;i++){
            cin>>inputStr;
            for(int j=0;j<=n-1;j++)if(inputStr[j]=='#')avSlots[i][j+1]=1;
        }
        
        dfs(0);
        cout<<ans<<endl;
        
        validCols.clear();
        validRows.clear();
        avSlots.clear();
        placedQueens.clear();
        ans=0;
    }
    

}
