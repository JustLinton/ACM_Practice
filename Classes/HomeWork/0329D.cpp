#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;
const int INF = 1e9;

unordered_map<int, double> shells, prefix;
int n, m;
double maxMass, inputSum;
const double EPS = 1e-5;

bool C() {
	double lowerSum = 0;
	for (int i = m; i <= n; i++) {
		if (prefix[i] - lowerSum >= 0)return true;
		if (prefix[i - m + 1] - lowerSum < 0) {
			lowerSum = prefix[i - m + 1]; 
		}
	}
	return false;
}

void solve() {
	double lb = 0, ub = inputSum, mid = 0;
	while (ub - lb > EPS)
	{
		mid = (ub + lb) / 2.0;
		for (int i = 1; i <= n; i++) {
			shells[i] -= mid;
			prefix[i] = prefix[i - 1] + shells[i];
		}
		if (C())lb = mid;
		else ub = mid;
		for (int i = 1; i <= n; i++)shells[i] += mid;
	}
	cout << (int)(ub * 1000) << endl;
}

int main() {
	//freopen("C:\\Users\\Lenovo\\Desktop\\a.in","r",stdin);
	//freopen("C:\\Users\\Lenovo\\Desktop\\a.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> shells[i]; 
		//prefix[i] = prefix[i-1] + shells[i];
		if (shells[i] > maxMass)maxMass = shells[i];
		inputSum += shells[i];
	}
	solve();
}