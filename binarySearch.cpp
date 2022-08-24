#include <bits/stdc++.h>

using namespace std;

int search(int a[], int n, int x){
    int l = 0, r = n - 1;
    while (l < r){
        int m = l + (r - l) / 2;
        if (a[m] == x) return m;
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << search(a, n, x);
}
