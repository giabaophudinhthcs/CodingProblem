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

string s;
int k, n;
pair<char, char> res, cw, ccw;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> k;
	n = int(s.len());
	res = {'z', 'z'};
	FOR(x, 0, n - 2){
		cw.ff = ccw.ss = s[x];
		ccw.ff = cw.ss = s[x + 1];
		res = min(res, min(cw, ccw));
	}
	FOR(x, 1, k) cout << ((x & 1) ? res.ff : res.ss);
	return 0;
}
