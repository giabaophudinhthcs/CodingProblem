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

int test;
string s, t, S1, S2, T1, T2;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> test;
	while (test--){
		S1 = S2 = T1 = T2 = "";
		cin >> s >> t;
		
		FOR(x, 0, int(s.len()) - 1){
			if (x & 1) S1 += s[x];
			else S2 += s[x];
		}
		
		FOR(x, 0, int(t.len()) - 1){
			if (x & 1) T1 += t[x];
			else T2 += t[x];
		}
		
		sort(all(S1));
		sort(all(S2));
		sort(all(T1));
		sort(all(T2));
		
		cout << ((S1 == T1 && S2 == T2) ? "YES\n" : "NO\n");
	}
	return 0;
}
