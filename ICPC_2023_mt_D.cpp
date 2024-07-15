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

int n, m, k, res = -1;
vector<vi> monster;

bool Is_Ok(int v){
	int cnt_need = 0;
	
	for (const auto& c: monster){
		int last = -1;
		for (auto pos: c){
			if (last < pos){
				cnt_need++;
				last = pos + (v << 1);
			}
		}
	}
	
	return (cnt_need <= k);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	string s[n];
	FOR(x, 0, n - 1) cin >> s[x];
	
	FOR(x, 0, n - 1){
		vi cur_mons;
		FOR(y, 0, m - 1){
			if (s[x][y] == 'x') cur_mons.pb(y);
			if (s[x][y] == '#' && !cur_mons.empty()){
				monster.pb(cur_mons);
				cur_mons.clear();
			}
		}
		if (!cur_mons.empty()) monster.pb(cur_mons);
	}
	
	int lo = 0, hi = m;
	while (lo <= hi){
		int mid = (lo + hi) >> 1;
		
		if (Is_Ok(mid)){
			res = mid;
			hi = mid - 1;
		}else lo = mid + 1;
	}
	
	cout << res;
	return 0;
}
