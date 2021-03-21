#include <bits/stdc++.h>
using namespace std;

const int INF = 99999999;
typedef long long ll;

int n,k,tmp,ans;
vector<ll> xi;
vector<bool> vis;
unordered_map<int,ll> nums;

bool prime(int n)
{
        if (n==1) return false;
        if (n==2) return true;
	for(int i=2;i*i<=n;i++)
	   if (n%i==0) return false;
	return true; 
}

void dfs(int depth){
    if(depth==k){
        // for(int i=1;i<=k;i++)cout<<nums[i-1]<<' ';
        // cout<<endl;
        tmp=0;
        for(int i=1;i<=k;i++)tmp+=nums[i-1];
        if(prime(tmp))ans++;
    }
    for(int i=0;i<=n-1;i++){
        if(!vis[i]&&xi[i]>nums[depth-1]){
            vis[i]=true;
            nums[depth]=xi[i];
            dfs(depth+1);
            vis[i]=false;
        }
    }
}

int main() {
	// freopen("/home/linton/Desktop/CSP/a.in", "r", stdin);
	// freopen("/home/linton/Desktop/CSP/a.out", "w", stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        xi.push_back(tmp);
        vis.push_back(false);
    }
    
    sort(xi.begin(),xi.end());
    dfs(0);
    cout<<ans<<endl;
}
