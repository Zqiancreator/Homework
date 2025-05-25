long long minCuttingCost(int n, int m, int k)
{
    int res = 0;
    if (n > k) {
        res += (long long)k * (n - k);
    }
    if (m > k) {
        res += (long long)k * (m - k);
    }
    return res;
}
