#include "algo.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;
// Driver program
int main()
{
  int nr_elem;
  int nr_queries;
  cin >> nr_elem >> nr_queries;
  std::vector<int> vec;
  for(int i = 0; i < nr_elem; i++) {
    int a;
    cin >> a;
    vec.push_back(a);
  }
  std::vector<std::pair<int, int> > vec_p;
  for(int i = 0; i < nr_queries; i++) {
    std::pair<int, int> p;
    cin >> p.first >> p.second;
    vec_p.push_back(p);

  }

  std::vector<int> rez;



  /* Your algorithm here */

  rez= rmq3(vec, vec_p);


  


  for (std::vector<int>::const_iterator i = rez.begin(); i != rez.end(); ++i)
     cout << *i << ' ';
  cout << endl;


  return 0;
}
