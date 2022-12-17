// Suffix array

#include <bits/stdc++.h>

#define len length
#define st first
#define nd second

using namespace std;

void count_sort(vector<int> &x, vector<int> &y){
	int sz = x.size();
	vector<int> cnt(sz), pos(sz), x_new(sz);
	pos[0] = 0;
	for (auto t: y) cnt[t]++;
	for (int i = 1; i < sz; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
	for (auto t: x){
		int i = y[t];
		x_new[pos[i]] = t;
		pos[i]++;
	}
	x = x_new;
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
		for (int i = 0; i < n; ++i) p[i] = (p[i] - (1 << k) + n) % n;
		
		// sort(b.begin(), b.end()); -> O(n*log(n))
		count_sort(p, c); // -> O(n)
		// => EMOTIONAL DAMAGE !!!
		
		vector<int> c_new(n);
		c_new[p[0]] = 0;
		for (int i = 1; i < n; ++i){
			pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
			pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
			if (now == prev) c_new[p[i]] = c_new[p[i - 1]];
			else c_new[p[i]] = c_new[p[i - 1]] + 1;
		}
		c = c_new;
		
		k++;
	}
	for (int i = 0; i < n; ++i) cout << p[i] << " ";
}
