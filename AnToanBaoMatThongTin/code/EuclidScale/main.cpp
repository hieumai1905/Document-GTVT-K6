#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result;
}

int def(int a, int m) {
    Reset:
    int res = 0;
    int a1, a2, b1, b2;
    (a1, a2) = (0, m);
    (b1, b2) = (1, a);
    if (b2 == 0) {
        return 0;
    } else {
        return b2 > 0 ? b2 : b2 + m;
    }
    int q = (int) b1 / b2;
    int t1, t2;
    (t1, t2) = ((a1 - b1 * q), (a2 - b2 * q));
    (a1, a2) = (b1, b2);
    (b1, b2) = (t1, t2);
    goto Reset;
}

int main() {
    int a, m;
    cin >> a >> m;
    int res = def(a, m);
    if (res == 1) {
        cout << "khong co" << endl;
    } else
        cout << "res = " << res << endl;
    return 0;
}
