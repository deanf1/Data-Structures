/******************************************************************************
 ** File:    BinarySearchTree.h
 ** Project: CMSC 341 Project 3, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    3/15/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for a binary search tree object.
 ** A binary search tree is a binary tree that is ordered. This code is taken
 ** from Blackboard/book and is not mine, except for the following functions:
 **
 ** I wrote:
 **		- height
 **		- printLevelOrder
 **
 ** I modified:
 ** 	- findMax (declaration was there but it was empty)
 **		- printTree
 **
 *****************************************************************************/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "dsexceptions.h"
#include <iostream>    // For NULL
using namespace std;

// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class BinarySearchTree
{
public:
	
    BinarySearchTree( ) :root( NULL )
    {
    }

    BinarySearchTree( const BinarySearchTree & rhs ) : root( NULL )
    {
        *this = rhs;
    }

    /**
     * Destructor for the tree
     */
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }

    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == NULL;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x ) { insert( x, root ); }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }

    /**
     * Deep copy.
     */
    const BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }

	//---------------------------------------------------------------------
	// Name:			height
	// Precondition:	None
	// Postcondition:	The height of the tree is returned
	//---------------------------------------------------------------------
	int height() const
	{
		return height(root);
	}

	//---------------------------------------------------------------------
	// Name:			printLevelOrder
	// Precondition:	Level to print to is greater than zero
	// Postcondition:	Level order data is printed
	//---------------------------------------------------------------------
	void printLevelOrder(int level, ostream &out = cout) const
	{
		out << "\nLevel order print of normal BST:";
		for (int i = 0; i <= (height(root) + 1) && i <= (level + 1); i++)
		{
			// skips over an extraneous "Level x:" print, prints rest
			if (i > 0)
			{
				out << "Level " << (i - 1) << ": ";
			}
			
			printLevelOrder(i, root, out);
			
			out << endl;
			
		}
	}

private:  

	// this private BinaryNode is within BST
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
            : element( theElement ), left( lt ), right( rt ) { }
    };

    BinaryNode *root;
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
		if( t == NULL ) { t = new BinaryNode( x, NULL, NULL ); } // no node present yet
        else if( x < t->element ) { insert( x, t->left ); } // value in CURRENT root 't' < new value
		else if( t->element < x ) { insert( x, t->right ); }
        else;  // Duplicate; do nothing
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == NULL )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != NULL && t->right != NULL ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != NULL ) ? t->left : t->right;
            delete oldNode;
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        if( t->left == NULL )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode * findMax( BinaryNode *t ) const
    {
		if( t == NULL )
            return NULL;
        if( t->right == NULL )
            return t;
        return findMax( t->right );
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if( t == NULL )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
    /****** NONRECURSIVE VERSION*************************
        bool contains( const Comparable & x, BinaryNode *t ) const
        {
            while( t != NULL )
                if( x < t->element )
                    t = t->left;
                else if( t->element < x )
                    t = t->right;
                else
                    return true;    // Match

            return false;   // No match
        }
    *****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( BinaryNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t == NULL )
			return;
		
		printTree(t->left, out);
		out << t->element << " ";
		printTree(t->right, out);
    }

    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new BinaryNode( t->element, clone( t->left ), clone( t->right 
) );
	}

	// height
	// Finds the height of the binary search tree
	int height(BinaryNode *t) const
	{
		if (t == NULL)
		{
			return -1;
		}
		else
		{
			return max(height(t->left), height(t->right)) + 1;
		}			
	}
	
	// printLevelOrder
	// Prints the level order data of the tree
	void printLevelOrder(int level, BinaryNode *t, ostream &out) const
	{
		if (t == NULL)
		{
			if (t == root)
			{
				out << "\nEmpty Tree";
			}
			
			return;
		}
		else if (level == 1)
		{
			out << t->element << " ";
		}
		else
		{
			printLevelOrder(level - 1, t->left, out);
			printLevelOrder(level - 1, t->right, out);
		}
	}
};


#endif