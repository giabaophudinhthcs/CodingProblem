// Suffix array

#include <bits/stdc++.h>

#define len length
#define st first
#define nd second

using namespace std;

void radix_sort(vector<pair<pair<int, int>, int>> &x){
	int sz = x.size();
	{
		vector<int> cnt(sz), pos(sz);
		pos[0] = 0;
		for (auto t: x) cnt[t.st.nd]++;
		vector<pair<pair<int, int>, int>> y(sz);
		for (int i = 1; i < sz; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
		for (auto t: x){
			int i = t.st.nd;
			y[pos[i]] = t;
			pos[i]++;
		}
		x = y;
	}
	
	{
		vector<int> cnt(sz), pos(sz);
		pos[0] = 0;
		for (auto t: x) cnt[t.st.st]++;
		vector<pair<pair<int, int>, int>> y(sz);
		for (int i = 1; i < sz; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
		for (auto t: x){
			int i = t.st.st;
			y[pos[i]] = t;
			pos[i]++;
		}
		x = y;
	}
}

int main(){
	string s;
	int n;
	cin >> s;
	s += '$';
	n = int(s.len());
	vector<int> p(n), c(n);
	vector<pair<char, int>> a(n);
	for (int i = 0; i < n; ++i) a[i] = {s[i], i};
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) p[i] = a[i].nd;
	c[p[0]] = 0;
	for (int i = 1; i < n; ++i){
		if (a[i].st == a[i - 1].st) c[p[i]] = c[p[i - 1]];
		else c[p[i]] = c[p[i - 1]] + 1;
	}
	int k = 0;
	while ((1 << k) < n){
		vector<pair<pair<int, int>, int>> b(n);
		for (int i = 0; i < n; ++i) b[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
		
		// sort(b.begin(), b.end()); -> O(n*log(n))
		radix_sort(b); // -> O(n)
		// => EMOTIONAL DAMAGE !!!
		
		for (int i = 0; i < n; ++i) p[i] = b[i].nd;
		c[p[0]] = 0;
		for (int i = 1; i < n; ++i){
			if (b[i].st == b[i - 1].st) c[p[i]] = c[p[i - 1]];
			else c[p[i]] = c[p[i - 1]] + 1;
		}
		k++;
	}
	for (int i = 0; i < n; ++i) cout << p[i] << " ";
}
