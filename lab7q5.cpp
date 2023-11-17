//#include <iostream>
//using namespace std;
//
//
//int nCr(int n, int r) {
//  
//    if (r == 0 || r == n)
//        return 1;  // stop recursion, we know the answer.
//    return nCr(n - 1, r - 1) + nCr(n - 1, r); // the answer is made of the sum of two "easier" ones
//}
//
//int  main() {
//  
//    cout << nCr(5, 3) << endl;
//    cout << nCr(9, 4) << endl;
//}