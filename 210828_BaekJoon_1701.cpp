#include <iostream>
using namespace std;
int ans, n, pi[5001];
string str;

int main() {
    cin.sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        int k = 0;

        for (int j = i + 1; j < str.size(); j++) {
            while (k > 0 && str[j] != str[i + k]) k = pi[k - 1];

            if (str[j] == str[i + k]) {
                k++;

                if (ans < k) {
                    ans = k;
                }
            }

            pi[j - i] = k;
        }
    }

    cout << ans;
}