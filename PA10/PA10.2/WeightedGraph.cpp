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

void WeightedGraph:: showStructure () const {
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
               if ( (wt == INFINITE_EDGE_WT) || (wt == 0))
                  cout << "- \t";
               else
                  cout << wt << '\t';
           }
           cout << endl;
       }
    }
}

WeightedGraph::WeightedGraph ( int maxNumber ) {
	maxSize = maxNumber;
	size = 0;
    vertexList = new Vertex[maxNumber];
    adjMatrix = new int[maxNumber*maxNumber];
    for (int i=0; i<(maxNumber*maxNumber); i++){
        adjMatrix[i] = INT_MAX;
    }
    pathMatrix = new int[maxSize*maxSize];
    for (int i=0; i<(maxNumber*maxNumber); i++){
        pathMatrix[i] = INT_MAX;
    }
}

WeightedGraph::WeightedGraph ( const WeightedGraph& other ) {

}
WeightedGraph& WeightedGraph:: operator= ( const WeightedGraph& other ){

}
WeightedGraph::~WeightedGraph () {

}

void WeightedGraph::insertVertex ( const Vertex& newVertex ) throw ( logic_error ) {
    vertexList[size] = newVertex;
    ++size;
    setEdge (size, size, 0);
}
void WeightedGraph::insertEdge ( string& v1, string& v2, int wt ) throw ( logic_error ) {
    int index1 = getIndex(v1);
    int index2 = getIndex(v2);
    setEdge(index1, index2, wt);
    setEdge(index2, index1, wt);
}

bool WeightedGraph::retrieveVertex ( const string& v, Vertex& vData ) const {
    //Searches a graph for vertex v. If this vertex is found, then places the value of the vertex's data in vData and returns true. Otherwise, returns false with vData undefined.
    for (int i=0; i<size; i++){
        if (v == vertexList[i].label){
            vData = vertexList[i];
            return true;
        }
    }
    return false;
}

bool WeightedGraph::getEdgeWeight ( string& v1, string& v2, int& wt ) const throw ( logic_error ) {
    int index1 = getIndex(v1);
    int index2 = getIndex(v2);
    wt = getEdge(index1, index2);
    if(wt!=0){return true;}
    return false;
}

void WeightedGraph::removeVertex ( string& v ) throw ( logic_error ) {
    //Requirements: Graph includes vertex v
    //Results: Removes vertex v from the graph and any edges connected to v

    int index = getIndex(v);

    //Shift Columns left one into deleted column
    for(int r=0; r<size; r++){
        for(int c=index; c<=size; c++){
            setEdge(r,c,getEdge(r,c+1));
        }
    }

    //Shift Rows up one by deleted row
    for(int c=0; c<=size; c++){
        for(int r=index; r<=size; r++){
            setEdge(r, c, getEdge(r+1, c));
        }
    }

    --size;

    //Shift remaining vertexes
    for (int i=index; i<size; i++){
        vertexList[i] = vertexList[i+1];
    }
}

void WeightedGraph::removeEdge ( string& v1, string& v2 ) throw ( logic_error ) {
    int index1 = getIndex(v1);
    int index2 = getIndex(v2);
    setEdge(index1, index2, INFINITE_EDGE_WT);
    setEdge(index2, index1, INFINITE_EDGE_WT);
}

void WeightedGraph::clear () {
    size = 0;
}

bool WeightedGraph::isEmpty () const {
    if (size == 0) {return true;}
    return false;
}
bool WeightedGraph::isFull () const {
    if (size == MAX_GRAPH_SIZE) {return true;}
    return false;
}

void WeightedGraph::showShortestPaths () {

    computePaths();

    cout << endl << "Path matrix : " << endl << '\t';
    for ( int col = 0 ; col < size ; col++ )
        cout << col << '\t';
    cout << endl;
    for ( int row = 0 ; row < size ; row++ )
    {
        cout << row << '\t';
        for ( int col = 0 ; col < size ; col++ )
        {
            int wt = getPath(row,col);
            if( row == col ){
                cout << 0 << '\t';
            }
            else if ( wt == INFINITE_EDGE_WT ){
                cout << "- \t";
            }
            else
                cout << wt << '\t';
        }
        cout << endl;
    }
}
bool WeightedGraph::hasProperColoring() const {

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if((getEdge(i,j)!= INFINITE_EDGE_WT) || (getEdge(i,j)!=0)){
                if (vertexList[i].color == vertexList[j].color){
                    return false;
                }
            }
        }
    }
    return true;
}
bool WeightedGraph::areAllEven () const {
    int edgeNum=0;

    for(int i=0; i<size; i++) {
        if (edgeNum % 2 != 0) {
            return false;
        }
        else {
            edgeNum =0;
        }
        for (int j = 0; j < size; j++) {
            if ((getEdge(i, j) != INFINITE_EDGE_WT) || (getEdge(i, j) != 0)) {
                edgeNum++;
            }
        }
    }
}
void WeightedGraph::computePaths() {
    //Initialize the path matrix so that it is the same as the edge matrix (all edges are paths).

    for (int i=0; i<maxSize; i++){
        for(int j=0; j<maxSize; j++)
        setPath(i,j,getEdge(i,j));
        //pathMatrix[i]= adjMatrix[i];
    }
    int jm, mk;
    for(int m = 0; m<size; m++){
        for (int j = 0; j<size; j++){
            for (int k=0; k<size; k++){
                if (getPath(j,m) != INFINITE_EDGE_WT){ //If there exists a path from vertex j to vertex m and
                    jm = getPath(j,m);
                    if(getPath(m,k) != INFINITE_EDGE_WT){ //there exists a path from vertex m to vertex k and
                        mk = getPath(m,k);
                        if((jm+mk) < getPath(j,k)){ //the sum of entries (j,m) and (m,k) is less than entry (j,k) in the path matrix,
                            //then replace entry (j,k) with the sum of entries (j,m) and (m,k)
                            setPath(j,k,(jm+mk));
                        }
                    }
                }
            }
        }
    }
}

int WeightedGraph::getIndex ( string& v ) const {
   for(int i=0; i<size; i++)
   {
       if ( v == vertexList[i].label)
       {
           return i;
       }
   }
}

int WeightedGraph::getEdge ( int row, int col ) const {
    int arrayIndex = row * maxSize + col;
    return adjMatrix[arrayIndex];
}
void WeightedGraph::setEdge ( int row, int col, int wt) {
    int arrayIndex = row * maxSize + col;
    adjMatrix[arrayIndex] = wt;
}

int  WeightedGraph::getPath ( int row, int col ) const {
    int arrayIndex = row * maxSize + col;
    return pathMatrix[arrayIndex];
}
void WeightedGraph::setPath ( int row, int col, int wt) {
    int arrayIndex = row * maxSize + col;
    pathMatrix[arrayIndex] = wt;
}