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
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, m;
ll k, mem[105][10005];

ll DP(int pos, int inv){
	if (pos == n) return ((inv == 0) ? 1 : 0);
	
	if (mem[pos][inv] >= 0) return mem[pos][inv];
	
	ll res = 0LL;
	FOR(c, 0, n - pos - 1){
		if (inv >= c){
			res += DP(pos + 1, inv - c);
			res = min(res, ooll);
		}
	}
	
	return mem[pos][inv] = res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(mem, -1, sizeof(mem));
	
	cin >> n >> m >> k;
	
	if (DP(0, m) < k){
		cout << -1;
		return 0;
	}
	
	vi rem(n);
	iota(all(rem), 0);
	vi Res;
	
	FOR(p, 0, n - 1){
		ll cnt = 0LL;
		
		FOR(ele, 0, int(rem.size()) - 1){
			ll c = DP(p + 1, m - ele);
			
			if (cnt + c >= k){
				Res.pb(rem[ele]);
				rem.erase(rem.begin() + ele);
				
				k -= cnt;
				m -= ele;
				
				break;
			}
			
			cnt += c;
		}
	}
	
	for (auto v: Res) cout << v + 1 << " ";
	return 0;
}
