//--------------------------------------------------------------------
//
//  Laboratory 12                                      WeightedGraph.h
//
//  Class declaration for the adjacency matrix implementation of
//  the Weighted Graph ADT
//
//--------------------------------------------------------------------

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <stdexcept>
#include <iostream>
#include <climits>    // For INT_MAX
#include <string>     // Used for labels
#include <new>        // from 2.h

using namespace std;

class WeightedGraph
{
  public:
    static const int 
	MAX_GRAPH_SIZE = 10,         // Default number of vertices
	INFINITE_EDGE_WT = INT_MAX;  // "Weight" of a missing edge

    class Vertex
    {
      public:
	
	void setLabel( const string& newLabel ) { label=newLabel; }
	string getLabel( ) const { return label; }
	void setColor(char newColor) { color = newColor; }
	char getColor() const { return color; }
	
	string label;	
	char color; //Vertex color
    };

    // Constructors
    WeightedGraph ( int maxNumber = MAX_GRAPH_SIZE );
    WeightedGraph ( const WeightedGraph& other );
    WeightedGraph& operator= ( const WeightedGraph& other );
    ~WeightedGraph ();

    // Graph manipulation operations
    void insertVertex ( const Vertex& newVertex ) throw ( logic_error ); // Insert vertex
    void insertEdge ( string& v1, string& v2, int wt ) throw ( logic_error ); // Insert edge
    bool retrieveVertex ( const string& v, Vertex& vData ) const; // Get vertex
    bool getEdgeWeight ( const string& v1, const string& v2, int& wt ) const throw ( logic_error );  // Get edge wt.
    void removeVertex ( const string& v ) throw ( logic_error ); // Remove vertex
    void removeEdge ( const string& v1, const string& v2 ) throw ( logic_error ); // Remove edge
        
    void clear (); // Clear graph
    
    // Graph status operations
    bool isEmpty () const; // Graph is empty
    bool isFull () const; // Graph is full
    
    // Output the graph structure
    void showStructure () const;
   
    // Programming exercise operations
    void showShortestPaths () const;
    bool hasProperColoring() const;
    bool areAllEven () const;
    void computePaths();   // Computes path matrix

  private:

    // Facilitator functions
    int getIndex ( string& v ) const; // Converts vertex label to an adjacency matrix index
    int getEdge ( int row, int col ) const;    // Get edge weight using adjacency matrix indices
    void setEdge ( int row, int col, int wt);  // Set edge weight using adjacency matrix indices

    int  getPath ( int row, int col ) const;   // Get path weight using path matrix indices
    void setPath ( int row, int col, int wt);  // Set path weight using path matrix indices

    // Data members
    int maxSize,          // Maximum number of vertices in the graph
        size;             // Actual number of vertices in the graph
    Vertex *vertexList;   // Vertex list - Stores the vertices
    int *adjMatrix;       // Adjacency matrix - Stores the edges
    int *pathMatrix;      // Path matrix -
};

#endif		// #ifndef WEIGHTEDGRAPH_H
