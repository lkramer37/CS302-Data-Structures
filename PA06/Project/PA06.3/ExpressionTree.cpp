/*In this laboratory, you construct an expression tree from the prefix form of an arithmetic expression.
 *
 *
 *
 */


#include <iostream>
#include "ExpressionTree.h"
#include "show8.cpp"
#include <limits>

using namespace std;

template<typename DataType>
ExprTree<DataType>::ExprTree()
{
    root = NULL;
}

template<typename DataType>
ExprTree<DataType>::ExprTree(const ExprTree &source)
{
    root = NULL;
    ExprTreeNode* sourcePtr = source.root;
    ExprTreeNode* newPtr = root;

    copyHelper(sourcePtr, root);
}

template <typename DataType>
void ExprTree<DataType>::copyHelper(ExprTreeNode*& sourcePtr, ExprTreeNode*& newPtr)
{
    if(sourcePtr!=NULL)
    {
        newPtr = new ExprTreeNode(sourcePtr->dataItem, NULL, NULL);
        copyHelper(sourcePtr->left, newPtr->left);
        copyHelper(sourcePtr->right, newPtr->right);
    }
}

template<typename DataType>
ExprTree<DataType>& ExprTree<DataType>::operator=(const ExprTree& sources)
{
    if(this == & sources) {return *this;}
    clear();
    ExprTreeNode* sourcePtr = sources.root;
    ExprTreeNode* newPtr = root;

    copyHelper(sourcePtr, newPtr);
}

template<typename DataType>
ExprTree<DataType>::~ExprTree()
{
    clear();
}

template<typename DataType>
void ExprTree<DataType>::build()
{
    buildHelper(root);
}

template<typename DataType>
void ExprTree<DataType>::buildHelper(ExprTreeNode*& node)
{
    //if operator
        //buildHelper (left)
        //buildHelper (right)
    // if number - return

    char temp;
    do {
        cin >> temp;
    }  while(temp == ' ');

    node = new ExprTreeNode(temp, NULL, NULL);

    if(temp == '+' || temp == '-' || temp == '*' || temp == '/' )
    {
        buildHelper(node->left);
        buildHelper(node->right);
    }
    if(48<=temp<=57) {return;}

    //Reads an arithmetic expression in prefix form from the keyboard and builds the corresponding expression tree.
    //Read the next arithmetic operator or numeric value
    //Create a node containing the operator or numeric value
    //If the node contains an operator
    //Recursively build the subtree that correspond to the operator's operands
    //else the node is a leaf node
}

template<typename DataType>
void ExprTree<DataType>::expression() const
{
    expressionHelper(root);
}


template<typename DataType>
void ExprTree<DataType>::expressionHelper(ExprTreeNode* nodePtr) const
{
    //Outputs the expression corresponding to the value of the tree in fully parenthesized infix form
        //prints infix notation with parentheses
    if(nodePtr != NULL)
    {
        if(nodePtr->left != NULL) {cout << "(";}
        expressionHelper(nodePtr->left);
        cout << nodePtr->dataItem;
        expressionHelper(nodePtr->right);
        if(nodePtr->right != NULL) {cout << ")";}
    }

}

template<typename DataType>
DataType ExprTree<DataType>:: evaluate() const throw(logic_error)
{
    //Returns the value of the corresponding arithmetic expression
    int answer = evalHelper(root);
    return answer;
}

template<typename DataType>
DataType ExprTree<DataType>::evalHelper(ExprTreeNode* nodePtr) const
{
    //evaluate helper left
    //evaluate helper right
    //check for digit or operator
    //if digit, returns value
    //change from char to int in this function
    if((nodePtr->dataItem == '+') || (nodePtr->dataItem == '-') || (nodePtr->dataItem == '*') || (nodePtr->dataItem == '/'))
    switch(nodePtr->dataItem)
    {
        case '+': return (evalHelper(nodePtr->left) + evalHelper(nodePtr->right));
        case '-': return (evalHelper(nodePtr->left) - evalHelper(nodePtr->right));
        case '*': return (evalHelper(nodePtr->left) * evalHelper(nodePtr->right));
        case '/':
            float left = (evalHelper(nodePtr->left));
            float right = (evalHelper(nodePtr->right));
            cout << "Test Right: " << right;
            if (right == 0) {return numeric_limits<float>::infinity();}
            return left/right;
    }

    if(48<=(nodePtr->dataItem)<=57)
    {
        int ch = nodePtr->dataItem;
        ch -='0';
        //cout << "Test ch:" << ch << " ";
        return ch;
    }
}

template<typename DataType>
void ExprTree<DataType>::clear()
{
    //Removes nodes in post traversal order
    ExprTreeNode* ptr = root;
    if(48<=(ptr->dataItem)<=57)
    {
        delete ptr;
        root = NULL;
        return;
    }
    clearHelper(ptr);
}

template <typename DataType>
void ExprTree<DataType>::clearHelper(ExprTreeNode*& nodePtr)
{
    if(nodePtr!=NULL)
    {
        clearHelper(nodePtr->left);
        clearHelper(nodePtr->right);
        delete nodePtr;
        root = NULL;
    }
}

template<typename DataType>
void ExprTree<DataType>::commute()
{
    //Commutes the operands for every arithmetic operator in the expression
    // a + b = b + a    ->  Should only be used for '+' and '*'
    commuteHelper(root);
}

template <typename DataType>
void ExprTree<DataType>::commuteHelper(ExprTreeNode*& node)
{
    if(node != NULL)
    {
        ExprTreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        commuteHelper(node->left);
        commuteHelper(node->right);
    }
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
    dataItem = elem;
    left=leftPtr;
    right=rightPtr;
}

template<typename DataType>
bool ExprTree<DataType>::isEmpty()const
{
    if (root == NULL) { return true; }
    return false;
}



