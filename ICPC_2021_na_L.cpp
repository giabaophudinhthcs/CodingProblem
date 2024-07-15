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

const int nMax = 1e7 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, a, v[nMax], cnt[nMax];
ll res = 0LL;

void eratos_extend(){
	FOR(x, 1, 1e7) v[x] = 1;
	
	FOR(x, 2, 1e7){
		if (v[x] == 1){
			for (int y = x; y <= 1e7; y += x) v[y] *= x;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	eratos_extend();
	
	cin >> n;
	FOR(x, 1, n){
		cin >> a;
		res += cnt[v[a]];
		cnt[v[a]]++;
	}
	
	cout << res;
	
	return 0;
}
