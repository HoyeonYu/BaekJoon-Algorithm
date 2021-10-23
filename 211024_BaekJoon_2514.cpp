#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int defaultVal, sprayTotal, inputGraph[8][8];
    cin >> defaultVal >> sprayTotal;

    int rowSum[8], colSum[8];
    fill_n(rowSum, 8, 0);
    fill_n(colSum, 8, 0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> inputGraph[i][j];

            inputGraph[i][j] -= defaultVal;
            rowSum[i] += inputGraph[i][j];
            colSum[j] += inputGraph[i][j];
        }
    }

    int sprayGraph[8][8], rowSpray[8], colSpray[8];
    fill_n(rowSpray, 8, 0);
    fill_n(colSpray, 8, 0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sprayGraph[i][j] = rowSum[i] + colSum[j] - inputGraph[i][j];

            if (sprayGraph[i][j] % 2) {
                rowSpray[i]++;
                colSpray[j]++;
            }
        }
    }

    int assumeGraph[8][8];
    fill_n(rowSum, 8, 0);
    fill_n(colSum, 8, 0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            assumeGraph[i][j] = rowSpray[i] + colSpray[j] - abs(sprayGraph[i][j] % 2);
            rowSum[i] += assumeGraph[i][j];
            colSum[j] += assumeGraph[i][j];
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int val = rowSum[i] + colSum[j] - assumeGraph[i][j];

            if (sprayGraph[i][j] % 2) {
                if ((sprayGraph[i][j] - val) % 4) {
                    cout << "- ";
                }

                else {
                    cout << "+ ";
                }
            }

            else {
                cout << ". ";
            }
        }

        cout << "\n";
    }
}