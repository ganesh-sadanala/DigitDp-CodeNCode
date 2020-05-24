// Problem with phase 1 is not considering position based elements

/*
Limit is defined as follows ::::::::::::::::::::::::::::::::::::::::::::
---> When filling the ith place, if """any""" previous place was filled with any
digit smaller than the allowed digit, then curr limit is 9.
---> Else curr limit = curr allowed digit
*/
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

int arr[1001];
string n;
int getSum(int pos, int n, int sum, bool flag)
{
  if (pos > n)
    return sum;

  int limit = 9;
  int res = 0;
  if (!flag)
    limit = arr[pos];

  for (int i = 0; i <= limit; i++)
  {
    if (flag || i < limit)
      res += getSum(pos + 1, n, sum + i, 1);
    else
      res += getSum(pos + 1, n, sum + i, 0);
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
    for (int i = 0; i < n.size(); i++)
    {
      arr[i + 1] = n[i] - '0';
    }
    cout << getSum(1, n.size(), 0, 0) << "\n";
  }
}
