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

int t, v;
string s, S;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> v >> s;
		
		if (int(s.len()) < v){
			cout << "NO\n";
			continue;
		}
		
		if (int(s.len()) > v){
			cout << "YES\n";
			continue;
		}
		
		S = "1";
		FOR(x, 1, v - 2) S += "0";
		S += "1";
		
		if (v == 1) S = "0";
		
		cout << ((s < S) ? "NO\n" : "YES\n");
	}
	return 0;
}
