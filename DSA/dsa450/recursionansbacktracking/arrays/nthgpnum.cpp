#include <bits/stdc++.h>
#include <cmath>
using namespace std;
long long mod = 1e9+7;
int nthTermOfGP(int N, int A, int R) {
    return (A *1ll* (pow(R,N-1))%mod)%mod;
    
}
int main()
{
    // 34 17 13
    cout<<nthTermOfGP(36,17,13);
}

