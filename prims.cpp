/**
* @file prims.cpp
* @brief defintion file for prims.h	 
* @author Nitesh Bhargava
* @date 6/11/12
* @par approach:
* - here we have implemented the algorithm as described in the cormen book
*/	
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "prims.h"
#include <vector>
using namespace std;


struct vertex{
    int key; /// the minimum value edge will be associated to its parent in minimum spanning tree(mst)
    int parent; /// parent of the node in the mst
    int value;  /// value will be 1 for first node
  
	
};
struct keyComparison{ /// overloading the '()' operator so that we can use it to create min heap
	bool operator()(vertex*  a, vertex* b) {
		return a->key > b->key;	/// condition for min heap
	}
};

/**
 * init for every iteration of the input
 **
* @par Algorithm:
* - MST-PRIM(G,w,r)
* 	-for each u ∈V[G]
* 	-do key[u] ← ∞
*	- 	π[u]← NIL
* 	- 	key[r] ← 0
*  	-Q ← V [G]
* 	-while(q is not empty)
* 	-	do u ← EXTRACT-MIN(Q)
* 	-	foreachv∈Adj[u]
*  	-	do ifv∈Qandw(u,v) <key[v]
* 	-     	thenπ[v]←u
* 	- 		key[v]←w(u,v)
*
* @complexity O(ElogV)
 */
void prims::init() {
	
    int noEdges,noVertex,m,n,edgeWght;
	
    cin>>noVertex; /// input number of vertices
    cin>>noEdges;  /// input number of edges
    vertex arr[noVertex]; /// array of vetex structure
    bool isvisited[noVertex];  /// array to maintain whether node is visited
    	
  
    int adMatrix[noVertex][noVertex];  /// adjacency matrix
	
		/// initializing adjacency matrix to zero and all vertices to not visited
	for(int i=0;i<noVertex;i++)
    {
		isvisited[i] = false;  //// not visited
        for(int j=0;j<noVertex;j++){

            adMatrix[i][j] = 0; //// all zero

	}

    }
    int loop = noEdges;  //// temp variable
	
    while(loop>0) //// loop to input all edges
    {
		/// input edges from m to n with edge weight edgewght
        cin>>m;  
        cin>>n;
        cin>>edgeWght;
        adMatrix[m-1][n-1] = edgeWght; /// filling adjacency matrix 
        adMatrix[n-1][m-1] = edgeWght; /// adjacency matrix is symmetric
        loop--;
    }
    /// inserting the information of all vertices of graph into 'arr' array
    for(int i=0;i<noVertex;i++)
    {
		arr[i].value = i;   /// value of that node
        arr[i].key = 10000; /// max possible value (positive infinity)
        arr[i].parent = -1; /// setting all parent to -1 means they have no parent ryt now
    }
    arr[0].key = 0; /// 1 node is our starting point of mst

	vector<vertex*> vertexSet;    /// initialing vector called 'vertexSet' ---> we will use this vector to create min heap containing vertices
	for(int i=0;i<noVertex;i++)
    {
      vertexSet.push_back(&arr[i]);   /// inserting values in vectorSet 
    }

	make_heap(vertexSet.begin(),vertexSet.end(),keyComparison());  /// using in buld heap from standard template library <algorithm>
	vertex* temp;

	int tmp = noVertex;	
	while(tmp>1)  //// perform till we visit all the vertices in the heap
	{
		temp = 	vertexSet.front(); /// get the min element of the heap
		isvisited[temp->value] =true;  /// visit that vertex
		pop_heap(vertexSet.begin(),vertexSet.end(),keyComparison()); /// remove that vertex 
		vertexSet.pop_back();  /// same as above
		loop = noVertex; 
		while(loop>0) /// loop for all adjacent vertices of the temp vertex
		{
			if(adMatrix[temp->value][noVertex-loop]!=0 && isvisited[noVertex-loop] !=true && adMatrix[temp->value][noVertex-loop]< arr[noVertex-loop].key)
			/// condition that vertex adjacent to temp and is in  Q and w(u,temp) < key[v]
			{	
				arr[noVertex-loop].parent = temp->value; /// set values of parent
				arr[noVertex-loop].key = adMatrix[temp->value][noVertex-loop]; ///setting the key
			}
		
		make_heap(vertexSet.begin(),vertexSet.end(),keyComparison()); ///heapify after removing the element
		loop--;
		
		
		}
		if(vertexSet.front()->parent+1)
		cout<<"edge "<<vertexSet.front()->parent+1<<","<<vertexSet.front()->value+1<<"\t"<<vertexSet.front()->key<<"\n"; 
    	tmp--;
	}
	
 }