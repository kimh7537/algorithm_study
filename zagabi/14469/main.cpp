#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
int n, total_time, time_start, time_end;
vector<pair<int, int>> v;
 
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> time_start >> time_end;
    v.push_back({time_start, time_end});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
  {
    if (total_time < v[i].first)
    {
      total_time = v[i].first + v[i].second;
    }
    else
      total_time += v[i].second;
  }
  cout << total_time;
  return 0;
}
