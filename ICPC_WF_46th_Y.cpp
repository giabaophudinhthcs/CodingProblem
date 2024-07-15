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

string s;
int n, zeros = 0, ones = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> s;
	n = int(s.len());
	
	FOR(x, 0, n - 1){
		zeros += (s[x] == '0');
		ones += (s[x] == '1');
	}
	
	if (zeros == n) cout << "0";
	else if (ones == n) cout << "1";
	else if (s[0] == '1' && s[n - 1] == '0') cout << "10";
	else if (s[0] == '0' && s[n - 1] == '1') cout << "01";
	else if (s[0] == '1' && s[n - 1] == '1') cout << "101";
	else if (s[0] == '0' && s[n - 1] == '0') cout << "010";
	
	return 0;
}
