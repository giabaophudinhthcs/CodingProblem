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
const ll ooll = 5e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

string s, t;
int kmp[nMax], cnt[nMax], n, m, l;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> s >> t;
	n = int(s.len());
	m = int(t.len());
	s = " " + s;
	t = " " + t;
	
	kmp[1] = 0;
	
	FOR(i, 2, n){
	    l = kmp[i - 1];
	    while (l > 0 && s[i] != s[l + 1]) l = kmp[l];
	    
	    if (s[i] == s[l + 1]) l++;
	    kmp[i] = l;
	}
	
	FOR(i, 1, n) cnt[i] = 0;
	
	l = 0;
	FOR(i, 1, m){
	    while (l > 0 && t[i] != s[l + 1]) l = kmp[l];
	    
	    if (t[i] == s[l + 1]) l++;
	    cnt[l]++;
	}
	
	FORD(i, n, 1) cnt[kmp[i]] += cnt[i];
	
	FOR(i, 1, n) cout << cnt[i] << " ";
	
	return 0;
}
