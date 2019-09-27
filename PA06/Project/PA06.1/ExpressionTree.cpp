/*In this laboratory, you construct an expression tree from the prefix form of an arithmetic expression.
 *
 *
 *
 */


#include <iostream>
#include "ExpressionTree.h"

using namespace std;

template<typename DataType>
ExprTree<DataType>::ExprTree()
{

}

template<typename DataType>
ExprTree<DataType>::ExprTree(const ExprTree &source)
{

}

template<typename DataType>
ExprTree<DataType>& ExprTree<DataType>::operator=(const ExprTree& sources)
{

}

template<typename DataType>
ExprTree<DataType>::~ExprTree()
{

}

template<typename DataType>
void ExprTree<DataType>::build()
{
    //Reads an arithmetic expression in prefix form from the keyboard and builds the corresponding expression tree.
        //Read the next arithmetic operator or numeric value
        //Create a node containing the operator or numeric value
        //If the node contains an operator
            //Recursively build the subtree that correspond to the operator's operands
        //else the node is a leaf node


    //Call Build helper by root by reference
        //if digit - Done and return
        //If Operator - do work, call buildHelper
    //Switch Statement?
}

template<typename DataType>
void ExprTree<DataType>::expression() const
{
    //Outputs the expression corresponding to the value of the tree in fully parenthesized infix form

    //prints with parentheses
    //infix notation with parentheses
    //in order traversal
}

template<typename DataType>
DataType ExprTree<DataType>:: evaluate() const throw(logic_error)
{
    //Returns the value of the corresponding arithmetic expression

    /*
     switch(node->data)
     {
        case '+': return (evaluateHelper(node->left) + evalHelper(node->right))
     }
     */
}

template<typename DataType>
void ExprTree<DataType>::clear()
{
    //Removes all the ata items in the expression tree
    //post traversal
}

template<typename DataType>
void ExprTree<DataType>::commute()
{
    //Commutes the operands for every arithmetic operator in the expression
    // a + b = b + a    ->  Should only be used for '+' and '*'
}

template<typename DataType>
bool ExprTree<DataType>::isEquivalent(const ExprTree &source) const
{
    //compares the expression tree to another expression tree for equivalence.
    //If the two trees are equivalent, then returns true. Otherwise, returns false
    //Two trees are equivalent if
        // the corresponding nodes are leaves with the same value
        // they have the same operator and equivalent subtrees as operands
        // they have the same commutable operator with equivalent, but commuted subtrees as operands
}

template<typename DataType>
ExprTree<DataType>::ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr)
{

}

template<typename DataType>
bool ExprTree<DataType>::isEmpty()const
{

}

template<typename DataType>
void ExprTree<DataType>::buildHelper(ExprTreeNode*& node)
{
    // "*&" means a reference to a pointer
}

template<typename DataType>
void ExprTree<DataType>::evalHelper(ExprTreeNode* nodePtr) const
{


    //Called with root
    //pass node pointer
        //evaluate helper left
        //evaluate helper right
    //check for digit or operator
        //if digit, returns value
    //change from char to int in this function
}

template<typename DataType>
void ExprTree<DataType>::expressionHelper()
{

}