#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        double val = pow(0.143 * N, N);
        int result = (val - floor(val) < 0.5) ? floor(val) : floor(val) + 1;

        cout << result << endl;
    }

    return 0;
}
