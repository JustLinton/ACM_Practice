#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;
int INF = 1e9;

struct requirment
{
	int l;
	int r;
	int k;

	bool operator< (requirment re)const {
		return r < re.r;
	}
	requirment(int l_,int r_,int k_):l(l_),r(r_),k(k_){}
};

int n, m;
int l, r, k;
int exsist, ans;
unordered_map<int, bool> sts;
multiset<requirment> inputs;

int main() {
	//freopen("C:\\Users\\Lenovo\\Desktop\\a.in","r",stdin);
	//freopen("C:\\Users\\Lenovo\\Desktop\\a.out", "w", stdout);
	cin >> n >> m;
	for (int yq = 1; yq <= m; yq++) {
		scanf("%d %d %d", &l, &r, &k);
		inputs.emplace(l, r, k);
	}
	//sort(inputs.begin(), inputs.end());
	for (auto ite = inputs.begin(); ite != inputs.end();ite++) {
		exsist = 0;
		for (int i = ite->r; i >= ite->l; i--) if (sts[i]) { 
			exsist++; 
			if (exsist >= ite->k)break;
		}
		if (exsist < ite->k) {
			for (int i = ite->r; i >= ite->l; i--) {
				if (exsist >= ite->k)break;
				if (!sts[i]) {
					sts[i] = true;
					exsist++;
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}