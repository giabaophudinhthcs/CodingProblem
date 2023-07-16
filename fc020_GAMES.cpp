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

class DSU{
    public:
    	int parent[20010];
        int sz[20010];
    
    	void make(int v){
            this->parent[v] = v;
            sz[v] = 1;
        }
    
    	int find(int v){
            return (v == this->parent[v]) ? v : this->parent[v] = this->find(this->parent[v]);
        }
    
    	void combine(int x, int y){
            x = this->find(x);
            y = this->find(y);
            if (x != y){
                if (sz[x] < sz[y]) swap(x, y);
                this->parent[y] = x;
                sz[x] += sz[y];
            }
        }
};

DSU test;
int n, k, l, r, L, R, cnt = 0;
map<int, int> h;
string parity;

bool check(){
	FOR(x, 1, cnt){
		if (test.find(x) == test.find(x + 10000)) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	FOR(x, 1, 20000) test.make(x);
	cin >> n >> k;
	FOR(x, 1, k){
		cin >> l >> r >> parity;
		l--;
		if (!h[l]){
			cnt++;
			h[l] = cnt;
		}
		if (!h[r]){
			cnt++;
			h[r] = cnt;
		}
		l = h[l];
		r = h[r];
		L = l + 10000;
		R = r + 10000;
		if (parity == "odd"){
			test.combine(l, R);
			test.combine(L, r);
		}else{
			test.combine(l, r);
			test.combine(L, R);
		}
		if (!check()){
			cout << x - 1;
			return 0;
		}
	}
	cout << k;
	return 0;
}
