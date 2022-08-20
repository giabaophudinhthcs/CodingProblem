#include <bits/stdc++.h>
using namespace std;

int t, m, n;
string I, P;

void solve(){
	getline(cin, I);
	getline(cin, P);
	m = I.length();
	n = P.length();
	if (m > n || (m == n && I != P)){
		cout << "IMPOSSIBLE\n";
		return;
	}
	if (I == P){
		cout << "0\n";
		return;
	}
	int x = 0, y = 0;
	while (x < m && y < n){
		if (I[x] == P[y]){
			++x;
			++y;
		}else{
			++y;
		}
	}
	if (x == m) cout << n - m << "\n";
	else cout << "IMPOSSIBLE\n";
}

int main(){
	cin >> t;
    cin.ignore();
	for (int i = 1; i <= t; ++i){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

