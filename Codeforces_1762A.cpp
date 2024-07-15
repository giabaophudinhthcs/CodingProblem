#include <iostream>

using namespace std;

const int nMax = 60;
const int oo = 2e9 + 10;

int t, n, a[nMax], steps[nMax], Min, s;

int step_even(int k){
    int temp = k, cnt = 0;
    while (k % 2 != 0){
        k /= 2;
        cnt++;
    }
    return cnt;
}

int step_odd(int k){
    int temp = k, cnt = 0;
    while (k % 2 == 0){
        k /= 2;
        cnt++;
    }
    return cnt;
}

int main(){
    cin >> t;
    for (int i = 1; i <= t; ++i){
        Min = oo;
        s = 0;
        cin >> n;
        for (int j = 1; j <= n; ++j){
            cin >> a[j];
            s += a[j];
            if (a[j] % 2 != 0) steps[j] = step_even(a[j]);
            else steps[j] = step_odd(a[j]);
            Min = min(Min, steps[j]);
        }
        cout << (s % 2 == 0 ? 0 : Min) << "\n";
    }
    return 0;
}
