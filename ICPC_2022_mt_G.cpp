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

ll s[nMax], dp_pos[nMax], dp_neg[nMax];
int t, n, k;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	s[0] = 0LL;
	
	while (t--){
		cin >> n >> k;
		FOR(x, 1, n){
			cin >> s[x];
			s[x] += s[x - 1];
		}
		
		FOR(x, 1, n){
		    dp_pos[x] = dp_neg[x] = 0;
		    if (x >= k){
		        dp_pos[x] = max(max(dp_neg[x - k] + s[x] - s[x - k], dp_pos[x - 1]), 0LL);
			    dp_neg[x] = max(max(dp_pos[x - k] - s[x] + s[x - k], dp_neg[x - 1]), 0LL);
		    }
		}
		
		cout << max(dp_pos[n], dp_neg[n]) << "\n";
	}
	
	return 0;
}
