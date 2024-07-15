#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
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
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int test, n, R[nMax], P[nMax], S[nMax], g = 0, res;
string s;

void solve(){
	g = 0;
	cin >> s;
	n = int(s.len());
	res = n + 1;
	s = " " + s;
	FOR(x, 1, n){
		R[x] = R[x - 1] + (s[x] == 'R');
		P[x] = P[x - 1] + (s[x] == 'P');
		S[x] = S[x - 1] + (s[x] == 'S');
	}
	FORD(k, n, 2){
		int total = 0;
		int m = n / k;
		m *= k;
		for(int x = 1; x <= m - k + 1; x += k){
			int l = x;
			int r = x + k - 1;
			total += max(R[r] - R[l - 1], max(S[r] - S[l - 1], P[r] - P[l - 1]));
		}
		if (m < n) total += max(R[n] - R[m], max(S[n] - S[m], P[n] - P[m]));
		if (g < total){
			res = k;
			g = total;
		}
	}
	cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> test;
	while (test--) solve();
	return 0;
}
