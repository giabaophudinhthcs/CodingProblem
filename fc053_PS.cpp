// Link: https://oj.vnoi.info/problem/fc053_ps

#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define ff first
#define ss second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vll;

const int nMax = 1e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;

int t, n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
	    cin >> n;
	    int a[n + 1], m[n + 1], M[n + 1], cnt = 0;
	    vector<int> ans;
	    FOR(x, 1, n) cin >> a[x];
	    m[n] = a[n];
	    M[1] = a[1];
	    FOR(x, 2, n) M[x] = max(M[x - 1], a[x]);
	    FORD(x, n - 1, 1) m[x] = min(m[x + 1], a[x]);
	    FOR(x, 1, n - 1){
	        if (M[x] <= m[x + 1]){
	            ans.pb(x);
	            cnt++;
	        }
	    }
	    cout << cnt << "\n";
	    for (auto x: ans) cout << x << " ";
	    cout << "\n";
	}
	return 0;
}
