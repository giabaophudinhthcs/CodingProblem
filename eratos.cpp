#include <bits/stdc++.h>
using namespace std;

const int nMax = 1e6 + 10;

bool p[nMax];
int n;

void eratos(){
	memset(p, true, sizeof(p));
	for (int i = 2; i * i <= nMax; ++i){
		if (p[i]){
			for (int j = i * i; j <= nMax; j += i) p[j] = false;
		}
	}
}

void solve(){
	cin >> n;
	if (p[n]) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	eratos();
	
	int t;
	cin >> t;
	
	while (t--){
		solve();
	}
}
