//--------------------------------------------------------------------
//
//  Laboratory 13                                        wtgraph.cpp
//
//  SOLUTION: Adjacency matrix implementation of the Weighted
//            Graph ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "WeightedGraph.h"

using namespace std;

void WeightedGraph:: showStructure () const
{
    if ( size == 0 ) {
       cout << "Empty graph" << endl;
    } else {
       cout << endl << "Vertex list : " << endl;
       for ( int row = 0 ; row < size ; row++ )
           cout << row << '\t' << vertexList[row].label
#if LAB12_TEST2
		<< vertexList[row].color
#endif
		<< endl;

       cout << endl << "Edge matrix : " << endl << '\t';
       for ( int col = 0 ; col < size ; col++ )
           cout << col << '\t';
       cout << endl;
       for ( int row = 0 ; row < size ; row++ )
       {
           cout << row << '\t';
           for ( int col = 0 ; col < size ; col++ )
           {
               int wt = getEdge(row,col);
               if ( wt == INFINITE_EDGE_WT )
                  cout << "- \t";
               else
                  cout << wt << '\t';
           }
           cout << endl;
       }
    }
}

WeightedGraph::WeightedGraph ( int maxNumber )
{
	maxSize = maxNumber;
	size = 0;
    vertexList = new Vertex[maxNumber];
    adjMatrix = new int[maxNumber*maxNumber];
}

WeightedGraph::WeightedGraph ( const WeightedGraph& other )
{

}

WeightedGraph& WeightedGraph:: operator= ( const WeightedGraph& other )
{

}

WeightedGraph::~WeightedGraph ()
{

}

void WeightedGraph::insertVertex ( const Vertex& newVertex ) throw ( logic_error )
{
    //Inserts newVertex into a graph. If the vertex already exists in the graph, then updates it.

    vertexList[size] = newVertex;

    ++size;
}
void WeightedGraph::insertEdge ( string& v1, string& v2, int wt ) throw ( logic_error )
{
    //Inserts an undirected edge connecting vertices v1 nd v2 into the graph. The weight of the edge is wt. If there is already an edge connecting these vertices, then updates the weight of the edge.

    int index1 = getIndex(v1);
    int index2 = getIndex(v2);
    setEdge(index1, index2, wt);
}

bool WeightedGraph::retrieveVertex ( const string& v, Vertex& vData ) const
{
    //Searches a graph for vertex v. If this vertex is found, then places the value of the vertex's data in vData and returns true. Otherwise, returns false with vData undefined.


}

bool WeightedGraph::getEdgeWeight ( const string& v1, const string& v2, int& wt ) const throw ( logic_error )
{

}

void WeightedGraph::removeVertex ( const string& v ) throw ( logic_error )
{

}

void WeightedGraph::removeEdge ( const string& v1, const string& v2 ) throw ( logic_error )
{

}

void WeightedGraph::clear ()
{

}

bool WeightedGraph::isEmpty () const
{

}

bool WeightedGraph::isFull () const
{

}

void WeightedGraph::showShortestPaths () const
{

}

bool WeightedGraph::hasProperColoring() const
{

}

bool WeightedGraph::areAllEven () const
{

}

void WeightedGraph::computePaths()
{

}

int WeightedGraph::getIndex ( string& v ) const
{
   for(int i=0; i<size; i++)
   {
       if ( v == vertexList[i].label)
       {
           return i;
       }
   }
}

int WeightedGraph::getEdge ( int row, int col ) const
{

}

void WeightedGraph::setEdge ( int row, int col, int wt)
{
    int arrayIndex = row * maxSize + col;
    adjMatrix[arrayIndex] = wt;
}

int  WeightedGraph::getPath ( int row, int col ) const
{

}

void WeightedGraph::setPath ( int row, int col, int wt)
{

}