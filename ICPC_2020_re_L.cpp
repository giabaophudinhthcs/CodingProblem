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

int t, n, k, d[26], cnt[26];
string s;

bool check(){
	int m = -1;
	FOR(x, 0, 25) m = max(m, d[x]);
	return m <= 1LL * (k - 1) * (n - m + 1);
}

void solve(){
	cin >> s >> k;
	n = int(s.len());
	FOR(c, 0, 25) d[c] = cnt[c] = 0;
	FOR(x, 0, n - 1) d[int(s[x] - 'a')]++;
	
	if (!check()){
		cout << "OH NO!\n";
		return;
	}
	
	FOR(x, 1, int(s.len())){
		FOR(c, 0, 25){
			if ((!d[c]) || cnt[c] == k - 1) continue;
			
			d[c]--;
			n--;
			
			if (check()){
				cout << char(c + 'a');
				cnt[c]++;
				FOR(y, 0, 25) if (y != c) cnt[y] = 0;
				break;
			}
			
			d[c]++;
			n++;
		}
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}
