#include <iostream>
#include <vector>
#include<math.h>
vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt)
  {
    vector<bool> used = vector<bool>(height.size());
    vector<int> res;
    for (size_t i=0;i<height.size();++i)
    {
      int mxH = 0;
      int pos = -1;
      for (size_t j=0;j<height.size();++j)
      {
        if (used[j]) continue;
        bool found = true;
        for (size_t k=0;k<height.size();++k)
        {
          if (used[k]) continue;
          bool blocking = !(wilt[j]<bloom[k] || (bloom[j]>wilt[k]) );
          if( (height[j]>height[k]) && blocking )
          {
            found = false; break;
          }
        }
        if ( found && (mxH<height[j]) )
        {
          mxH = height[j];
          pos = j;
        }
      }
      res.push_back(height[pos]);
      used[pos] = true;
    }
    return res;
using namespace std;
int main()
{
    
}