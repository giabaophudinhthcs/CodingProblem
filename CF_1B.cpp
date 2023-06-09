// Link: https://codeforces.com/contest/1/problem/B

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

int n, ok, S, r, c, col;
string s, row, colN, colA;
map<char, int> H;
char t;

bool isNum(char c){
    return ('0' <= c && c <= '9');
}

bool isAl(char c){
    return ('A' <= c && c <= 'Z');
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	t = 'A';
	FOR(x, 1, 26){
	    H[t] = x;
	    t = char(t + 1);
	}
	cin >> n;
	FOR(k, 1, n){
	    ok = 0;
	    cin >> s;
	    S = int(s.length());
	    FOR(x, 1, S - 2){
	        if (isNum(s[x - 1]) && (s[x] == 'C') && isNum(s[x + 1])){
	            ok = 1;
	            c = x;
	        }
	    }
	    if (ok){
	        colA = "";
	        r = 0;
	        row = s.substr(1, c - 1);
	        colN = s.substr(c + 1, S - c - 1);
	        col = 0;
	        FOR(x, 0, int(colN.len()) - 1){
	            int num = int(colN[x] - '0');
	            col = 10 * col + num;
	        }
	        while (col){
	            int hash = col % 26;
	            if (!hash) hash += 26;
	            char get = char('A' + hash - 1);
	            colA = get + colA;
	            col -= hash;
	            col /= 26;
	        }
	        cout << colA << row << "\n";
	    }else{
	        int start = 0;
	        col = 0;
	        while (isAl(s[start])) start++;
	        colA = s.substr(0, start);
	        FOR(x, 0, int(colA.len()) - 1){
	            int hash = H[colA[x]];
	            col = 26 * col + hash;
	        }
	        row = s.substr(start, S - start);
	        cout << "R" << row << "C" << col << "\n";
	    }
	}
	return 0;
}
