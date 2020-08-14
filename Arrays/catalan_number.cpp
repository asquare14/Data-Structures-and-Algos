// Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.
// 1) Count the number of expressions containing n pairs of parentheses which are correctly matched. 
// For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

// 2) Count the number of possible Binary Search Trees with n keys (See this)

// 3) Count the number of full binary trees 
// (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.

// 4) Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points 
// such that no 2 chords intersect.
// https://www.geeksforgeeks.org/program-nth-catalan-number/
#include<bits/stdc++.h>
using namespace std;
unsigned long int catalanDP(unsigned int n) 
{ 
    // Table to store results of subproblems 
    unsigned long int catalan[n+1]; 
  
    // Initialize first two values in table 
    catalan[0] = catalan[1] = 1; 
  
    // Fill entries in catalan[] using recursive formula 
    for (int i=2; i<=n; i++) 
    { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++) 
            catalan[i] += catalan[j] * catalan[i-j-1]; 
    } 
  
    // Return last entry 
    return catalan[n]; 
} 
int main() {
    for (int i = 0; i < 10; i++) 
        cout << catalanDP(i) << " "; 
    return 0; 
}