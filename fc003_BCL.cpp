// Link: https://oj.vnoi.info/problem/fc003_bcl

#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
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

int n, l, r;
char c[2050];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(x, 1, n) cin >> c[x];
	l = 1;
	r = n;
	FOR(x, 1, n){
	    if (l == r) cout << c[l];
	    else if (c[l] < c[r]){
	        cout << c[l];
	        l++;
	    }else if (c[l] > c[r]){
	        cout << c[r];
	        r--;
	    }else{
	        int L = l, R = r;
	        while (c[L] == c[R]){
	            L++;
	            R--;
	        }
	        if (c[L] < c[R]){
	            cout << c[l];
	            l++;
	        }else{
	            cout << c[r];
	            r--;
	        }
	    }
	    if (x % 80 == 0) cout << "\n";
	}
	return 0;
}
