#include <iostream>
#define MAX_TYPE 20 + 1
#define MAX_AMOUNT 10000 + 1
using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int coinType, targetAmount;
        cin >> coinType;

        int coin[MAX_TYPE] = { 0 };

        for (int j = 1; j <= coinType; j++) {
            cin >> coin[j];
        }

        cin >> targetAmount;

        int coinDP[MAX_AMOUNT] = { 0 };
        coinDP[0] = 1;

        for (int j = 1; j <= coinType; j++) {
            for (int k = coin[j]; k <= targetAmount; k++) {
                coinDP[k] += coinDP[k - coin[j]];
            }
        }

        cout << coinDP[targetAmount] << "\n";
    }

    return 0;
}