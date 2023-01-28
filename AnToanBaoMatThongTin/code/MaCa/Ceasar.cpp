#include <iostream>

using namespace std;

int main() {
    string s;
    int n;
    cout << "First string: ";
    cin >> s;
    cout << "Input key: ";
    cin >> n;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i] - 'a' + n) % 26 + 'a';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] - 'A' + n) % 26 + 'A';
        }
    }
    cout << "First string after encryption: " << s << endl;
    cout << "Result: " << s << endl;

    return 0;
}
