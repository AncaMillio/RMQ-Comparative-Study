//C++ program to do range minimum query in O(1) time with
// O(n Log n) extra space and O(n Log n) preprocessing time
#include "algo.h"
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include "math.h"
#define MAX 1000000

// lookup[i][j] is going to store index of minimum value in
// input[i..j].
int lookup[MAX][1000];

// Fills lookup array lookup[][] in bottom up manner.
void preprocess1(const std::vector<int>& input)
{
  // Initialize M for the intervals with length 1
  for (unsigned i = 0; i < input.size(); i++) {
    lookup[i][0] = i;
  }
  // Compute values from smaller to bigger intervals
  for (unsigned j=1; (unsigned(1)<<j)<=input.size(); j++)
  {
    // Compute minimum value for all intervals with size 2^j

    for (unsigned i=0; (i+(1<<j)-1) < input.size(); i++)
    {
      // For arr[2][10], we compare arr[lookup[0][3]] and
      // arr[lookup[3][3]]
      if (input[lookup[i][j-1]] < input[lookup[i + (1<<(j-1))][j-1]])
        lookup[i][j] = lookup[i][j-1];
      else
        lookup[i][j] = lookup[i + (1 << (j-1))][j-1];

    }
  }
}

// Returns minimum of pair interval
int query1(const std::vector<int>& input, std::pair<int, int> query)
{
  // For [2,10], j = 3
  int j = (int)log2(query.second-query.first+1);

  // For [2,10], we compare input[lookup[0][3]] and
  // input[lookup[3][3]],
 if (input[lookup[query.first][j]] <= input[lookup[query.second - (1<<j) + 1][j]])
   return input[lookup[query.first][j]];

else return input[lookup[query.second - (1<<j) + 1][j]];

}

ALGO_H
std::vector<int> rmq1(const std::vector<int>& input, const std::vector< std::pair<int, int> >& queries) {
    // TODO
    /*
    for (std::vector<int>::const_iterator i = input.begin(); i != input.end(); ++i)
       cout << *i << ' ';
    cout << endl;

    for(unsigned i = 0; i < queries.size(); i++)
    {
     cout << queries[i].first << ", " << queries[i].second << endl;
    }
    */
    std::vector<int> rez;
    // Fills table lookup[n][Log n]
    preprocess1(input);
    clock_t start;
    double duration;
    start = clock();
    for(unsigned i = 0; i < queries.size(); i++)
    {
     rez.push_back(query1(input, queries[i]));

    }
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    ofstream outputFile;
    outputFile.open("other_tests/Algo_Time", std::ios_base::app);
    outputFile <<"Algo1\t"<<input.size()<<"\t"<<queries.size()<<"\t"<< duration * 1000 << endl;
    outputFile.close();

    return rez;
}





// C++ program to demonstrate working of Square Root
// Decomposition.


std::vector<int> block;          // decomposed array
int blk_sz;                      // block size


// Time Complexity : O(sqrt(n))
int query2(const std::vector<int>& input, std::pair<int, int> query)
{
    int l = query.first;
    int r = query.second;
    int min = 1000000;
    while (l<r and l%blk_sz!=0 and l!=0)
    {
        // traversing first block in range
        //sum += arr[l];
        if(min > input[l]) {
            min = input[l];
        }
        l++;
    }


    while (l+blk_sz <= r)
    {
        // traversing completely overlapped blocks in range
        //sum += block[l/blk_sz];
        if(min > block[l/blk_sz]) {
            min = block[l/blk_sz];
        }
        l += blk_sz;
    }
    while (l<=r)
    {
        // traversing last block in range
        //sum += arr[l];
        if(min > input[l]) {
            min = input[l];
        }
        l++;
    }
    return min;
}

// Fills values in input[]
void preprocess2(const std::vector<int>& input)
{
    // initiating block pointer
    int blk_idx = -1;

    // calculating size of block
    blk_sz = sqrt(input.size());

    // building the decomposed array
    for (unsigned i=0; i<input.size(); i++)
    {

        if (i%blk_sz == 0)
        {
            // entering next block
            // incementing block pointer
            blk_idx++;
            block.push_back(1000000);
        }
        if(block[blk_idx] > input[i]) {
           block[blk_idx] = input[i];
        }
    }
}

ALGO_H
std::vector<int> rmq2(const std::vector<int>& input, const std::vector< std::pair<int, int> >& queries) {
    // TODO
    /*
    for (std::vector<int>::const_iterator i = input.begin(); i != input.end(); ++i)
       cout << *i << ' ';
    cout << endl;

    for(unsigned i = 0; i < queries.size(); i++)
    {
     cout << queries[i].first << ", " << queries[i].second << endl;
    }
    */
    std::vector<int> rez;

    preprocess2(input);
    clock_t start;
    double duration;

    start = clock();
    for(unsigned i = 0; i < queries.size(); i++)
    {
     rez.push_back(query2(input, queries[i]));
    }
      duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
      ofstream outputFile;
      outputFile.open("other_tests/Algo_Time", std::ios_base::app);
      outputFile <<"Algo2\t"<<input.size()<<"\t"<<queries.size()<<"\t"<< duration * 1000 << endl;
      outputFile.close();

    return rez;
}





//Segment tree
// CPP Program to implement iterative segment
// tree.


void construct_segment_tree(std::vector<int>& segtree,
						const std::vector<int>& input)
{

	// assign values to leaves of the segment tree
	for (unsigned i = 0; i < input.size(); i++)
		segtree[input.size() + i] = input[i];

	/* assign values to internal nodes
	to compute minimum in a given range */
	for (unsigned i = input.size() - 1; i >= 1; i--)
		segtree[i] = min(segtree[2 * i],
						segtree[2 * i + 1]);
}

/*
void update(vector<int>& segtree, int pos, int value,
											int n)
{
	// change the index to leaf node first
	pos += n;

	// update the value at the leaf node
	// at the exact index
	segtree[pos] = value;

	while (pos > 1) {

		// move up one level at a time in the tree
		pos >>= 1;

		// update the values in the nodes in
		// the next higher level
		segtree[pos] = min(segtree[2 * pos],
						segtree[2 * pos + 1]);
	}
}
*/

int range_query(std::vector<int>& segtree, std::pair<int, int> query , int n)
{
	/* Basically the left and right indices will move
		towards right and left respectively and with
		every each next higher level and compute the
		minimum at each height. */
	// change the index to leaf node first
  int left = query.first;
  int right = query.second;
	left += n;
	right += n;

	// initialize minimum to a very high value
	int mi = 1000000;

  if(left == right) {
    mi = min(mi, segtree[left]);
  }
	while (left < right) {

		// if left index in odd
		if (left & 1) {
			mi = min(mi, segtree[left]);

			// make left index even
			left++;
		}

		// if right index in odd
		if (right & 1) {

			// make right index even
			right--;

			mi = min(mi, segtree[right]);
		}

		// move to the next higher level
		left /= 2;
		right /= 2;
	}
	return mi;
}









ALGO_H
std::vector<int> rmq3(const std::vector<int>& input, const std::vector< std::pair<int, int> >& queries) {
    // TODO
    /*
    for (std::vector<int>::const_iterator i = input.begin(); i != input.end(); ++i)
       cout << *i << ' ';
    cout << endl;

    for(unsigned i = 0; i < queries.size(); i++)
    {
     cout << queries[i].first << ", " << queries[i].second << endl;
    }
    */
    std::vector<int> rez;

    /* Construct the segment tree by assigning
  	the values to the internal nodes*/
    int n = input.size();
  	std::vector<int> segtree (2 * n);
  	construct_segment_tree(segtree, input);
    clock_t start;
    double duration;

    start = clock();
    for(unsigned i = 0; i < queries.size(); i++)
    {
     rez.push_back(range_query(segtree, queries[i], input.size()));
    }
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    ofstream outputFile;
    outputFile.open("other_tests/Algo_Time", std::ios_base::app);
    outputFile <<"Algo3\t"<<input.size()<<"\t"<<queries.size()<<"\t"<< duration * 1000 << endl;
    outputFile.close();

    return rez;
}



//Basic solution
int query(const std::vector<int>& input, std::pair<int, int> query)
{
   int min = 1000000;
   for(int i = query.first; i <= query.second; i++ ) {
     if(min > input[i]) {
       min = input[i];
     }
   }
   return min;
}





ALGO_H
std::vector<int> basic_rmq(const std::vector<int>& input, const std::vector< std::pair<int, int> >& queries) {
    // TODO
    /*
    for (std::vector<int>::const_iterator i = input.begin(); i != input.end(); ++i)
       cout << *i << ' ';
    cout << endl;

    for(unsigned i = 0; i < queries.size(); i++)
    {
     cout << queries[i].first << ", " << queries[i].second << endl;
    }
    */
    std::vector<int> rez;

    for(unsigned i = 0; i < queries.size(); i++)
    {
     rez.push_back(query(input, queries[i]));
    }

    return rez;
}
