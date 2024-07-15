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
typedef unsigned long long ull;
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

int k, n, l = 1, r = 1, cnt[4], res = oo;
string s;

int Get(char c){
	if (c == 'V') return 1;
	if (c == 'C') return 2;
	if (c == 'A') return 3;
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> k >> s;
	n = int(s.len());
	s = " " + s;
	
	FOR(x, 1, 3) cnt[x] = 0;
	
	FOR(x, 1, n){
		if (Get(s[x]) == -1){
			cout << "ERROR: Invalid Input";
			return 0;
		}
	}
	
	cnt[Get(s[1])] = 1;
	
	while (l <= n && r <= n){
		while (cnt[1] < k || cnt[2] < k || cnt[3] < k){
			r++;
			if (r > n) break;
			cnt[Get(s[r])]++;
		}
		
		if (r > n) break;
		
		while (cnt[1] >= k && cnt[2] >= k && cnt[3] >= k){
			res = min(res, r - l + 1 - 3 * k);
			cnt[Get(s[l])]--;
			l++;
			if (l > r) break;
		}
	}
	
	cout << res;
	
	return 0;
}
