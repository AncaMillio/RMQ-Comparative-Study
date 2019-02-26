#ifndef ALGO_H
#define ALGO_H

#include <vector>

/**
 * For a given input vector V, computes the minimum element between any two indices in V.
 *
 * @input: elements of type int
 * @queries: a query is made of a pair <x, y>: What is the minimum element between positions x and y (inclusive)?
 *
 * The function returns a vector with the corresponding answers.
 */

// Sparse Table Algorithm
std::vector<int> rmq1(const std::vector<int>& input, const std::vector< std::pair<int, int> >& queries);


//Square Root Decomposition
std::vector<int> rmq2(const std::vector<int>& input, const std::vector< std::pair<int, int> >& queries);

//Segment tree
std::vector<int> rmq3(const std::vector<int>& input, const std::vector< std::pair<int, int> >& queries);

//The basic solution
std::vector<int> basic_rmq(const std::vector<int>& input, const std::vector< std::pair<int, int> >& queries);

#endif
