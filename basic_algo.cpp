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

clock_t start;
double duration;

start = clock();

/* Your algorithm here */

rez= basic_rmq(vec, vec_p);


duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;


for (std::vector<int>::const_iterator i = rez.begin(); i != rez.end(); ++i)
   cout << *i << ' ';
cout << endl;

ofstream outputFile;
outputFile.open("other_tests/Algo_Time", std::ios_base::app);
outputFile <<"Algo_basic\t"<<vec.size()<<"\t"<<vec_p.size()<<"\t"<< duration * 1000 << endl;
outputFile.close();

  return 0;
}
