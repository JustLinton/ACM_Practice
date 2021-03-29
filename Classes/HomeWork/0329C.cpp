#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;
const int INF = 1e9;

unordered_map<int, int> stones;
int n, m;
int maxMass, inputSum;

bool C(int d) {
	int massSum = 0, divides = 0;

	for (int i = 1; i <= n; i++) {
		if (massSum + stones[i] > d) {
			divides++;
			massSum = stones[i];
		}
		else massSum += stones[i];
	}
	if (divides >= m)return false;
	return true;
}

void solve() {
	int lb = maxMass, ub = inputSum, mid = 0, ans = 0;
	while (lb<=ub)
	{
		mid = (ub + lb) / 2;
		if (C(mid)) {
			ans = mid;
			ub = mid - 1;
		}
		else lb = mid + 1;
	}
	cout << ans << endl;
}

int main() {
	//freopen("C:\\Users\\Lenovo\\Desktop\\a.in","r",stdin);
	//freopen("C:\\Users\\Lenovo\\Desktop\\a.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> stones[i]; 
		if (stones[i] > maxMass)maxMass = stones[i];
		inputSum += stones[i];
	}
	solve();
}