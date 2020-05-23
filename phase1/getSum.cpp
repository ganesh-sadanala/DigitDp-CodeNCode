// source: codeNcode

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define N 2e5 + 5
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define int long long int
#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = l; i < r; i++)
#define sz(a) (int)((a).size())
#define ll long long
#define ar array

int n;

// sum is the current digit sum of the number
int getSum(int pos, int n, int sum)
{
  if (pos > n)
    return sum;

  int res = 0;
  forn(i, 0, 10)
  {
    res += getSum(pos + 1, n, sum + i);
  }
  return res;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0)
  {
    cin >> n;
    cout << getSum(1, n, 0) << "\n";
  }
}
