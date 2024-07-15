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

const int nMax = 3e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

ull Mul(ull a, ull b, ull m){
	return __int128_t(a) * b % m;
}

ull Pow(ull X, ull Y, ull M){
    if (Y == 0) return 1LL;
    
    ull tmp = Pow(X, Y >> 1LL, M);
    tmp = Mul(tmp, tmp, M);
    
    return ((Y & 1) ? Mul(tmp, X, M) : tmp);
}

bool Test(ull A, ull N, ull K, ull M){
    ull P = Pow(A, M, N);
    if (P == 1 || P == N - 1) return true;
    
    FOR(L, 1, K - 1){
        P = Mul(P, P, N);
        if (P == N - 1) return true;
    }
    
    return false;
}

bool Check(ull N){
    if (N <= 10) return (N == 2 || N == 3 || N == 5 || N == 7);
    if (N <= 20) return (N == 11 || N == 13 || N == 17 || N == 19);
    if (N <= 40) return (N == 23 || N == 29 || N == 31 || N == 37);
    
    if (N % 2 == 0 || N % 3 == 0 || N % 5 == 0 || N % 7 == 0) return false;
    if (N % 11 == 0 || N % 13 == 0 || N % 17 == 0 || N % 19 == 0) return false;
    if (N % 23 == 0 || N % 29 == 0 || N % 31 == 0 || N % 37 == 0) return false;
    
    ull k = 0, m = N - 1;
    while (!(m & 1LL)){
        m >>= 1LL;
        k++;
    }
    
    ull a[5] = {2,3,5,7,11};
    
    FOR(i, 0, 4){
        if (!Test(a[i], N, k, m)) return false;
    }
    
    return true;
}

int ok[2154445], p[nMax], cnt = 0;

void eratos(){
	FOR(i, 0, 2154444) ok[i] = 1;
	ok[0] = ok[1] = 0;
	
	for (int i = 2; i * i <= 2154444; ++i){
		if (ok[i]){
			for (int j = i * i; j <= 2154444; j += i) ok[j] = 0;
		}
	}
	
	FOR(i, 0, 2154444){
		if (ok[i]) p[++cnt] = i;
	}
}

map<ull, bool> mark;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	eratos();
	
	ull BIG = 1e19;
	
	FOR(k, 3, 15){
		FOR(i, 1, cnt - k + 1){
			ull g = 1;
			int okok = 1;
			
			FOR(j, i, i + k - 1){
				if (g <= BIG / p[j]) g *= p[j];
				else{
					okok = 0;
					break;
				}
			}
			
			if (okok) mark[g] = true;
		}
	}
	
	int test;
	cin >> test;
	
	while (test--){
		ull n;
		cin >> n;
		
		if (n == 1 || n == 4){
		    cout << "UGLY\n";
		    continue;
		}
		
		if (Check(n)){
			cout << "NICE\n";
			continue;
		}
		
		ull lo = 1, hi = 3162277661, val = -1;
		while (lo <= hi){
			ull mid = (lo + hi) >> 1;
			
			if (mid * mid >= n){
				val = mid;
				hi = mid - 1;
			}else lo = mid + 1;
		}
		
		ull l = val - 1;
		while (!Check(l)) l--;
		
		ull r = val;
		while (!Check(r)) r++;
		
		if (l * r == n){
			cout << "NICE\n";
			continue;
		}
		
		cout << (mark[n] ? "NICE\n" : "UGLY\n");
	}
	
	return 0;
}
