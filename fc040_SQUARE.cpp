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

int r[4], c[4], Area = 0, S, ok = 0, p[7][4], Perm = 1;

void C0(int i){
	if (i > 3){
		ok |= ((r[p[Perm][1]] == r[p[Perm][2]]) && (r[p[Perm][2]] == r[p[Perm][3]]) && (r[p[Perm][3]] == c[p[Perm][1]] + c[p[Perm][2]] + c[p[Perm][3]]));
		return;
	}
	
	C0(i + 1);
	swap(r[p[Perm][i]], c[p[Perm][i]]);
	C0(i + 1);
}

void C1(int i){
	if (i > 3){
		ok |= ((r[p[Perm][1]] + r[p[Perm][2]] == c[p[Perm][2]] + c[p[Perm][3]]) && (c[p[Perm][2]] + c[p[Perm][3]] == r[p[Perm][3]]) && (r[p[Perm][3]] == c[p[Perm][1]] + c[p[Perm][3]]));
		return;
	}
	
	C1(i + 1);
	swap(r[p[Perm][i]], c[p[Perm][i]]);
	C1(i + 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	FOR(x, 1, 3){
		cin >> r[x] >> c[x];
		Area += r[x] * c[x];
	}
	
	S = sqrt(Area);
	if (Area != S * S){
	    cout << "NO";
	    return 0;
	}
	
	p[1][1] = p[2][1] = p[3][2] = p[4][3] = p[5][2] = p[6][3] = 1;
	p[1][2] = p[2][3] = p[3][1] = p[4][1] = p[5][3] = p[6][2] = 2;
	p[1][3] = p[2][2] = p[3][3] = p[4][2] = p[5][1] = p[6][1] = 3;
	
	while (Perm <= 6){
		C0(1);
		C1(1);
		Perm++;
	}
	
	cout << ((ok) ? "YES" : "NO");
	return 0;
}
