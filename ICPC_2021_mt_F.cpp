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

int t, n, pos[26], l[nMax], r[nMax];
ll res;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	FOR(test, 1, t){
		res = 0LL;
		
		cin >> s;
		n = int(s.len());
		s = " " + s;
		
		FOR(x, 0, 25) pos[x] = 0;
		
		FOR(x, 1, n){
			int c = int(s[x] - 'a');
			l[x] = pos[c];
			pos[c] = x;
		}
		
		FOR(x, 0, 25) pos[x] = n + 1;
		
		FORD(x, n, 1){
			int c = int(s[x] - 'a');
			r[x] = pos[c];
			pos[c] = x;
		}
		
		FOR(x, 1, n){
			ll L = l[x] + 1;
			ll R = r[x] - 1;
			
			L = x - L + 1;
			R = R - x + 1;
			
			res += L * R;
		}
		
		cout << res << "\n";
	}
	
	return 0;
}
