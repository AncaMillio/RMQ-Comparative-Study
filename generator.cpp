#include "algo.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
  int nr_elem;
  int nr_query;
  cin>>nr_elem>>nr_query;
  cout<<nr_elem<<' '<<nr_query<<endl;
srand((int)time(0));
	int i = 0;
	while(i++ < nr_elem) {
		int r = (rand() % 1000);
		cout << r << " ";
	}
  cout<<endl;
  i = 0;
  while(i++ < nr_query) {
    int r = (rand() % nr_elem);
    cout<<r<<' ';
    int c  = r+(rand() % (nr_elem - r));
    cout<<c<<endl;
  }

  return 0;
}
