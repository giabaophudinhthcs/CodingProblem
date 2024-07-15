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

int n, a[30], cnt[30], cnt2 = 0, cnt5 = 0;
string s;

int Cnt(int val, int p){
	int res = 0;
	
	while (val){
		val /= p;
		res += val;
	}
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> s;
	n = int(s.len());
	
	FOR(x, 0, n - 1) cnt[int(s[x] - 'a') + 1]++;
	
	FOR(x, 1, 26) a[x] = a[x - 1] + cnt[x];
	
	FOR(x, 1, 26){
		int Total, Contain;
		Total = n - a[x - 1];
		Contain = cnt[x];
		
		if (Contain == 0 || Contain == Total) continue;
		
		cnt2 += (Cnt(Total, 2) - Cnt(Contain, 2) - Cnt(Total - Contain, 2));
		cnt5 += (Cnt(Total, 5) - Cnt(Contain, 5) - Cnt(Total - Contain, 5));
	}
	
	cout << min(cnt2, cnt5);
	
	return 0;
}
