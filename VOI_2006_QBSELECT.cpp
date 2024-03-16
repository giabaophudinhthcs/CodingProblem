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

int n, mask[9], c = 0;
ll a[4][10005], dp[10005][9], res, MMM = -ooll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	FOR(x, 1, 3) mask[x] = x - 1;
	FOR(x, 4, 5) mask[x] = x;
	FOR(x, 6, 8) mask[x] = x + 2;
	
	cin >> n;
	FOR(x, 0, 3){
	    FOR(y, 1, n){
	        cin >> a[x][y];
	        MMM = max(MMM, a[x][y]);
	    }
	}
	
	if (MMM < 0){
	    cout << MMM;
	    return 0;
	}
	
	FOR(col, 1, n){
	    FOR(x, 1, 8){
	        int s = 0;
	        FOR(p, 0, 3){
	            if ((mask[x] >> p) & 1) s += a[p][col];
	        }
	        
	        if (col == 1){
	            dp[col][x] = s;
	            continue;
	        }
	        
	        dp[col][x] = -ooll;
	        
	        FOR(y, 1, 8){
	            if ((mask[x] & mask[y]) == 0){
	                dp[col][x] = max(dp[col][x], dp[col - 1][y]);
	            }
	        }
	        
	        dp[col][x] += s;
	    }
	}
	
	res = -ooll;
	FOR(x, 1, 8) res = max(res, dp[n][x]);
	cout << res;
	return 0;
}
