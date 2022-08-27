#include <bits/stdc++.h>
using namespace std;

const int nMax = 1e6 + 10;
const int MOD = 1e9 + 7;

int p[nMax], cnt[nMax];
vector<int> factor;

void initEratos(){
	for (int i = 2; i * i <= nMax; ++i){
		if (!p[i]){
			for (int j = i * i; j <= nMax; j += i) p[j] = i;
		}
	}
	
	for (int i = 2; i <= nMax; ++i){
		if (!p[i]){
			p[i] = i;
		}
	}
}

void analyze(int n){
	for ( ; n > 1; n /= p[n]){
		if (!cnt[p[n]]) factor.push_back(p[n]);
		++cnt[p[n]];
	}
}

void initFactor(){
	factor.clear();
}

void solve(){
	int a, b;
	cin >> a >> b;
	
	for (int i = a; i <= b; ++i) analyze(i);
	
	long long res = 1;
	for (int i = 0; i < factor.size(); ++i){
		res = res * (2 * cnt[factor[i]] + 1) % MOD;
		cnt[factor[i]] = 0;
	}
	
	cout << res << "\n";
}

int main(){
	initEratos();
	int test;
	cin >> test;
	
	while (test--){
		initFactor();
		solve();
	}
}
