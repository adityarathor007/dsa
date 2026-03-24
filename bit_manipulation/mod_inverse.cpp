long long power(long long a, long long b, int MOD) {
    long long res = 1;
    while (b) {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

long long modInverse(long long b, int MOD) {
    return power(b, MOD - 2, MOD);
}
