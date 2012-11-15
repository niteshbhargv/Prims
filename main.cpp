/**
* @file main.cpp
* @brief main execution file
* @mainpage The Prims Algorithm
* @par Problem Definition:
*Implement Prim's MST algorithm using heaps. Your program must take two le names as inputs
from the user. The input le will contain several test cases delimited by a $. Each test case is an
edge-weighted graph (on the vertex set f1; 2; : : : ; ng) formatted as follows. The rst line contains
2 integers n and m denoting the number of vertices and edges, respectively, in the graph. The
next m lines represent the adjacency information. Each such line contains 3 integers i, j and wij
that are interpreted as fi; j g being an edge of weight wij
in the graph. The last line of input le
contains a $$ to indicate end of all test cases. The output le should contain the list of edges of
the MST (with associated cost) for each graph in the input. Note that the input graphs could be
disconnected and in that case, no spanning tree exists.
*
* @par Algorithm:
* - MST-PRIM(G,w,r)
* 	- for each u ∈V[G]
* 	- do key[u] ← ∞
*	- 	  --π[u]← NIL
* 	- 	  --key[r] ← 0
*  	- Q ← V [G]
* 	- while(q is not empty)
* 	-	    --do u ← EXTRACT-MIN(Q)
* 	-	    --for each v∈Adj[u]
*  	-	    ----do if v∈Q and w(u,v) <key[v]
* 	-     	  ------then π[v]←u
* 	- 		    ------key[v]← w (u,v)
*
* @complexity O(ElogV)
 *
*@par Format of contents in a input file:
*	- 7 10
*	- 1 2 1
*	- 1 4 10
*	- 1 6 3
*	- 1 5 5
*	- 2 3 2
*	- 3 4 9
*	- 3 7 6
*	- 4 6 8
*	- 5 6 7
*	- 5 7 4
*	- $$
*
*@par Format of contents of expected output for the above input file:
*	- edge 1,2	1
*	- edge 2,3	2
*	- edge 1,6	3
*	- edge 1,5	5
*	- edge 5,7	4
*	- edge 6,4	8
*	- $$
*
*@author Nitesh Bhargava 
* @date 6/11/12
* 
*
*/
#include <iostream>
#include "prims.cpp"
#include <string>
using namespace std;
int main()
{
	bool f = true;
	string c,d="$$";
	prims p;
	while(f)
	{

		p.init();
		cin>>c;
		cout<<c<<endl;
		if(c.compare(d)==0)
			//cout<<"ferf";
			f = false;

	}
	
	return 0;
}