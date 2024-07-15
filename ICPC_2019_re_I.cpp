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

int n, LG[1005], res[1005], Query[1005], Judge_Out[1005], cnt;

void Ask(){
	cout << "ASK " << cnt << " ";
	FOR(x, 1, cnt) cout << Query[x] << " ";
	cout.flush();
	FOR(x, 1, cnt) cin >> Judge_Out[x];
}

void Answer(){
	cout << "ANSWER ";
	FOR(x, 1, n) cout << res[x] << " ";
	cout.flush();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	LG[1] = res[1] = 0;
	FOR(x, 2, 1000){
		LG[x] = LG[x >> 1] + 1;
		res[x] = 0;
	}
	
	cin >> n;
	
	FOR(k, 0, LG[n]){
		cnt = 0;
		FOR(x, 1, n){
			if ((x >> k) & 1){
				cnt++;
				Query[cnt] = x;
			}
		}
		
		Ask();
		
		FOR(x, 1, cnt) res[Judge_Out[x]] += (1 << k);
	}
	
	Answer();
	
	return 0;
}
