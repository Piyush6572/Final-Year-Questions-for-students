// In Fractional Knapsack, we can break items for maximizing the total value of knapsack.
// This problem in which we can break an item is also called the fractional knapsack problem.
// Input :
// Items as (value, weight) pairs
//   arr[] = {{60, 10}, {100, 20}, {120, 30}}
//   Knapsack Capacity, W = 50;
// Output :
//    Maximum possible value = 240
//    By taking full items of 10 kg, 20 kg and 2/3rd of last item of 30 kg

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int fractionalKnapsack(vector<pair<int,int> > vec,int weight){
  for(int i=0;i<vec.size();i++){
    vec[i].first=vec[i].first/vec[i].second;
  }
  sort(vec.begin(),vec.end());
  int ans=0;
  for(int i=vec.size()-1;i>=0 && weight>0;i--){
    if(weight>=vec[i].second){
      weight-=vec[i].second;
      ans+=(vec[i].first)*(vec[i].second);

    }else{
      ans+=weight*(vec[i].first);
      weight=0;
    }
  }
  // for(int i=0;i<vec.size();i++){
  //   cout<<vec[i].first<<" "<<vec[i].second<<"\n";
  // }

  return ans;

}
// *********************
//To improve querry time we can also use prefix sum and then using binary search find position
// *********************
int main() {
    int weight = 50;
    vector<pair<int,int> > vec,cop;
    vec.push_back(make_pair(60,10));
    vec.push_back(make_pair(100,20));
    vec.push_back(make_pair(120,30));
    cop=vec;
    cout << "Maximum value we can obtain = " << fractionalKnapsack(vec,weight)<<"\n";
    return 0;
}
