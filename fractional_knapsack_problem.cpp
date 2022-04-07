#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL N, W;
vector<pair<ULL, ULL> > ItemsInfo;

bool cmp(const pair<ULL, ULL> &p1, const pair<ULL, ULL> &p2) {
	return p1.first * p2.second > p2.first * p1.second;
}

void solve() {
	ULL curWeight;
	double curValue;

	sort(ItemsInfo.begin(), ItemsInfo.end(), cmp);

	curValue = 0;
	for (int i = 0; i < N; ++i) {
		curWeight = ItemsInfo[i].second;
		if (curWeight > W) {
			curValue += ItemsInfo[i].first * W / (double)curWeight;
			break;
		}
		curValue += ItemsInfo[i].first;
		W -= curWeight;
	}
	
	cout << fixed << setprecision(8) << curValue << endl;
}

int main() {
	int v, w;

	cin >> N >> W;
	for (int i = 0; i < N; ++i) {
		cin >> v >> w;
		ItemsInfo.push_back({ v,w });
	}
	solve();

	return 0;
}
