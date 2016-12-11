/******************************************************************************
 ** File:    RandomizedBinarySearchTree.h
 ** Project: CMSC 341 Project 3, Spring 2015
 ** Author:  Dean Fleming
 ** Date:    3/15/15
 ** Section: 02
 ** E-mail:  deanf1@umbc.edu
 **
 ** This is the header file for a randomized binary search tree object.
 ** A randomized binary search tree is a binary search tree that is inserted
 ** in random order to try to keep it balanced.
 **
 ** Code taken from the book's BinarySearchTree.h:
 ** 	- Constructors and destructor
 ** 	- BinaryNode
 **		- makeEmpty
 ** 	- insert
 **
 *****************************************************************************/
 
#ifndef RANDOMIZED_BINARY_SEARCH_TREE_H
#define RANDOMIZED_BINARY_SEARCH_TREE_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <typename Comparable>
class RandomizedBinarySearchTree
{
	public:
		
		struct BinaryNode
		{
			Comparable element;
			BinaryNode *left;
			BinaryNode *right;

			BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
				: element(theElement), left(lt), right(rt) {}
		};
		
		RandomizedBinarySearchTree() : root(NULL)
		{
			srand(123456789);
		}
		
		RandomizedBinarySearchTree(const RandomizedBinarySearchTree &rhs) : root(NULL)
		{
			srand(123456789);
			*this = rhs;
		}

		/**
		 * Destructor for the tree
		 */
		~RandomizedBinarySearchTree()
		{
			makeEmpty();
		}
		
		/**
		 * Make the tree logically empty.
		 */
		void makeEmpty()
		{
			makeEmpty(root);
		}
	
		/**
		 * Print the tree contents in sorted order.
		 */
		void printTree(ostream &out = cout) const
		{
			if(size(root) == 0)
				out << "Empty tree" << endl;
			else
			{
				printTree(root, out);
				out << endl;
			}
		}
		
		/**
		 * Insert x into the tree; duplicates are ignored.
		 */
		void insert(const Comparable &x)
		{
			randomizedInsert(x, root);
		}
		
		BinaryNode* find(const Comparable &x) const
		{
			return find(x, root);
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
		// Name:			size
		// Precondition:	None
		// Postcondition:	The size of the tree is returned
		//---------------------------------------------------------------------
		int size() const
		{
			return size(root);
		}

		//---------------------------------------------------------------------
		// Name:			printLevelOrder
		// Precondition:	Level to print to is greater than zero
		// Postcondition:	Level order data is printed
		//---------------------------------------------------------------------
		void printLevelOrder(int level, ostream &out = cout) const
		{
			out << "\nLevel order print of randomized BST:";
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

		BinaryNode *root;
		
		/**
		 * Internal method to make subtree empty.
		 */
		void makeEmpty(BinaryNode *&t)
		{
			if(t != NULL)
			{
				makeEmpty(t->left);
				makeEmpty(t->right);
				delete t;
			}
			t = NULL;
		}
		
		/**
		 * Internal method to print a subtree rooted at t in sorted order.
		 */
		void printTree(BinaryNode *t, ostream &out) const
		{
			if(t == NULL)
				return;
			
			printTree(t->left, out);
			out << t->element << " ";
			printTree(t->right, out);
		}
		
		/**
		 * Internal method to insert into a subtree.
		 * x is the item to insert.
		 * t is the node that roots the subtree.
		 * Set the new root of the subtree.
		 */
		void insert(const Comparable &x, BinaryNode *&t)
		{
			if(t == NULL) {t = new BinaryNode(x, NULL, NULL); } // no node present yet
			else if(x < t->element) { insert(x, t->left); } // value in CURRENT root 't' < new value
			else if(t->element < x) { insert(x, t->right); }
			else;  // Duplicate; do nothing
		}
		
		BinaryNode* find(const Comparable &x, BinaryNode *t) const
		{
			if(t == NULL)
				return NULL;
			else if(x < t->element)
				return find(x, t->left);
			else if(t->element < x)
				return find(x, t->right);
			else
				return t;
		}
	
		// randomizedInsert
		// Inserts a new node randomly
		void randomizedInsert(const Comparable &x, BinaryNode *&t)
		{
			// picks the random number
			int randNum;
			if (size(t) == 0)
			{
				randNum = 0;
			}
			else
			{
				randNum = rand() % (size(t) + 1);
			}
			
			// inserts the node if the random number is the sub-tree size
			if (randNum == size(t))
			{
				insert(x, t);
				insertAtRoot(x, t);
			}
			
			// otherwise it recursively inserts it 
			else
			{
				if (x < t->element)
				{
					randomizedInsert(x, t->left);
				}
				else
				{
					randomizedInsert(x, t->right);
				}
			}
			
		}
		
		// insertAtRoot
		// Puts the new node in as a leaf and then rotates it to make it root
		void insertAtRoot(const Comparable &x, BinaryNode *&t)
		{
			// gets the node version of the data just inserted
			BinaryNode* xNode = find(x);
			
			// does not rotate if it should stay a leaf or if x is root now
			if (xNode == t)
			{
				return;
			}
			
			// does rotations until xNode is where t was
			else
			{
				// rotation towards the right
				if (xNode->element < t->element)
				{
					insertAtRoot(x, t->left);
					
					BinaryNode* temp;
					temp = t->left;
					t->left = temp->right;
					temp->right = t;
					t = temp;
				}
				
				// rotation towards left
				else
				{
					insertAtRoot(x, t->right);
					
					BinaryNode* temp;
					temp = t->right;
					t->right = temp->left;
					temp->left = t;
					t = temp;
				}				
			}
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
		
		// size
		// Finds the size of the binary search tree
		int size(BinaryNode *t) const
		{
			if (t == NULL)
			{
				return 0;
			}
			else
			{
				return (size(t->left) + size(t->right) + 1);
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