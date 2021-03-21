#include <bits/stdc++.h>
using namespace std;

const int INF = 99999999;
typedef long long ll;

ll curNum = 1, n, k;
set<ll> players;
string curNumStr;

bool out() {
	stringstream sst;
	sst << curNum;
	sst >> curNumStr;
	reverse(curNumStr.begin(), curNumStr.end());
	//cout << curNumStr[0] << ' ' << k + '0' << ' ' << (curNumStr[0] == k + '0') << (curNum % k == 0) << endl;
	return curNumStr[0] == k + '0' || (curNum % k == 0);
}

int main() {
	//freopen("/home/linton/Desktop/CSP/a.in", "r", stdin);
	//freopen("/home/linton/Desktop/CSP/a.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)players.insert(i);
	auto ite = players.begin();
	while (players.size() > 1)
	{
		if (out()) ite = players.erase(ite);
		else ite++;
		curNum++;
		if (ite == players.end())ite = players.begin();
	}
	cout << *players.begin() << endl;
}
