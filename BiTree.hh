#ifndef _ENTRY_H_INCLUDED_ 
#define _ENTRY_H_INCLUDED_ 


#include <iostream>
#include <fstream>
#include <string>
// for string tokenizer and c-style string processing

#include <cstring>
// max function
#include <algorithm>

using namespace std;

class BTNode{
	private:
		int nodeId;
		int data;
		int levelNum;
		BTNode* leftChildPtr;
		BTNode* rightChildPtr;
	public:
		// Constractor
		BTNode();

		// accessors
		int getNodeId();
		int getData();
		int getLevelNum();
		BTNode* getLeftChildPtr();
		BTNode* getRightChildPtr();
		int getLeftChildID();
		int getRightChildID();

		// modifiers
		void assignNodeId(int id);
		void assignData(int data_in);
		void assignLevelNum(int level);
		void assignLeftChildPtr(BTNode* ptr);
		void assignRightChildPtr(BTNode* ptr);
};
class BinaryTree{
	private:
		int numNodes;
		BTNode* arrayOfBTNodes;
	public:
		// Constractor
		BinaryTree(int n);

		// accessors
		void printLeafNodes();
		bool isLeafNode(int nodeId);
		int getNodeHeight(int nodeId);
		int getTreeHeight();
		void PreOrderTraversal(int nodeId);
		void PostOrderTraversal(int nodeId);
		void InOrderTraversal(int nodeId);
		void PrintPreTraversal();
		void PrintPostTraversal();
		void PrintInTraversal();

		// modifiers
		void assignLeftLink(int parentID, int childID);
		void assignRightLink(int parentID, int childID);
};

#endif 

