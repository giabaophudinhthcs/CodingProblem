// Link: https://oj.vnoi.info/problem/fc125_gcdarr

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

int n, a[nMax], ST[nMax][20], LG[nMax], res, l, r, Left, Right, m;

void genLG(){
	LG[0] = -1;
	FOR(v, 1, nMax - 1) LG[v] = LG[v >> 1] + 1;
}

int Gcd(int x, int y){
    return ((!y) ? x : Gcd(y, x % y));
}

int Query(int L, int R){
    int P = LG[R - L + 1];
    return (Gcd(ST[L][P], ST[R - (1 << P) + 1][P]) == 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	genLG();
	cin >> n;
	FOR(x, 1, n){
	    cin >> a[x];
	    ST[x][0] = a[x];
	}
	FOR(k, 1, LG[n]){
	    FOR(x, 1, n){
	        if (k <= LG[n - x + 1]) ST[x][k] = Gcd(ST[x][k - 1], ST[x + (1 << (k - 1))][k - 1]);
	    }
	}
	res = n + 1;
	FOR(x, 1, n){
	    l = x + 1;
	    r = n;
	    int pos = -1;
	    while (l <= r){
	        m = (l + r) >> 1;
	        if (Query(x, m)){
	            pos = m;
	            r = m - 1;
	        }else l = m + 1;
	    }
	    if (res > pos - x + 1 && pos != -1){
	        res = pos - x + 1;
	        Left = x;
	        Right = pos;
	    }
	}
	if (res == n + 1){
	    cout << -1;
	    return 0;
	}
	cout << res << " " << Left << " " << Right;
	return 0;
}
