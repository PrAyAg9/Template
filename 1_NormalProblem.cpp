#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        string a;
        cin >> a;

        string b = "";
        // Reverse the string and transform characters
        for (int i = a.length() - 1; i >= 0; i--) {
            if (a[i] == 'p') {
                b += 'q';
            } else if (a[i] == 'q') {
                b += 'p';
            } else { // 'w' remains the same
                b += 'w';
            }
        }

        cout << b << endl; // Output the transformed string
    }

    return 0;
}
