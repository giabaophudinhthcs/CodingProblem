#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define len length

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

const int nMax = 1e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
// const auto seed = chrono::steady_clock::now().time_since_epoch().count();

string s;
int n, q, kmp[nMax], cnt[nMax], res[nMax];

void calc_kmp_func(){
	kmp[1] = 0;
	FOR(x, 2, n){
		kmp[x] = kmp[x - 1];
		
		while (kmp[x] > 0 && s[kmp[x] + 1] != s[x]) kmp[x] = kmp[kmp[x]];
		
		if (s[kmp[x] + 1] == s[x]) kmp[x]++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	n = int(s.len());
	
	s = " " + s;
	calc_kmp_func();
	
	FOR(x, 1, n){
		cnt[x] = 1;
		res[x] = 0;
	}
	
	FORD(x, n, 2){
		if (kmp[x] > 0) cnt[kmp[x]] += cnt[x];
	}
	
	int pos = kmp[n];
	while (pos > 0){
		res[pos] = cnt[pos];
		pos = kmp[pos];
	}
	
	cin >> q;
	FOR(test, 1, q){
		int l;
		cin >> l;
		if (res[l] >= 3){
			cout << "YES " << res[l] << "\n";
		}else cout << "NO\n";
	}
	return 0;
}
