#include <iostream>
using namespace std;

void print01(int n, string answer) {
    if (n == 0) {
        cout << answer << endl;
    }
    // append 0s and 1s to answer string recursively
    else {
        print01(n - 1, answer + "0");
        print01(n - 1, answer + "1");
    }
}


int  main() {
    print01(1, "");
}
   