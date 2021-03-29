#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;
const int INF = 1e9;

struct Person
{
	int a=1, b=1;
	bool isA;
	Person(int a_, int b_,bool isA_) :a(a_), b(b_),isA(isA_) {};
	bool operator<(const Person& p) const {	
		if (isA) return a < p.a;
		return b > p.b;
	}
};

int n;
unordered_map<int, int>a, b;
vector<Person> peopleA;
vector<Person> peopleB;
vector<int> aEnd;
int aTimeAcc = 0, bEnd = 0, bCntr = 0;

int main() {
	freopen("C:\\Users\\Lenovo\\Desktop\\a.in","r",stdin);
	freopen("C:\\Users\\Lenovo\\Desktop\\a.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)cin >> b[i];
	for (int i = 1; i <= n; i++)a[i] <= b[i] ? peopleA.emplace_back(a[i], b[i],true) : peopleB.emplace_back(a[i], b[i],false);
	sort(peopleA.begin(), peopleA.end());
	sort(peopleB.begin(), peopleB.end());
	for (auto ite = peopleA.begin(); ite != peopleA.end(); ite++) {
		aTimeAcc += ite->a;
		aEnd.push_back(aTimeAcc);
	}
	for (auto ite = peopleB.begin(); ite != peopleB.end(); ite++) {
		aTimeAcc += ite->a;
		aEnd.push_back(aTimeAcc);
	}
	for (auto ite = peopleA.begin(); ite != peopleA.end(); ite++) {
		if (bEnd < aEnd[bCntr]) bEnd = aEnd[bCntr];
		bEnd += ite->b;
		bCntr++;
	}
	for (auto ite = peopleB.begin(); ite != peopleB.end(); ite++) {
		if (bEnd < aEnd[bCntr]) bEnd = aEnd[bCntr];
		bEnd += ite->b;
		bCntr++;
	}
	cout << max(bEnd, aTimeAcc) << endl;
}