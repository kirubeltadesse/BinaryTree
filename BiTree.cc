#include "BiTree.hh"

/*** initializing the construtors of Binary Node***/
//       ^
//		( )  parent node
//		/ \
//	   /   \
//    ^     ^
//	(  )   (  ) Left and right childs
//

BTNode::BTNode(){}

// definiting accessors
int BTNode::getNodeId(){
	return nodeId;
}
int BTNode::getData(){
	return data;
}
int BTNode::getLevelNum(){
	return levelNum;
}
BTNode* BTNode::getLeftChildPtr(){
	return leftChildPtr;
}
BTNode* BTNode::getRightChildPtr(){
	return rightChildPtr;
}
int BTNode::getLeftChildID(){
	if(leftChildPtr == 0)
		return -1;
	return leftChildPtr->getNodeId();
}
int BTNode::getRightChildID(){
	if(rightChildPtr == 0)
		return -1;
	return rightChildPtr->getNodeId();
}

// definiting modifiers
void BTNode::assignNodeId(int id){
	nodeId = id;
}
void BTNode::assignData(int data_in){
	data = data_in;
}
void BTNode::assignLevelNum(int level){
	levelNum = level;
}
void BTNode::assignLeftChildPtr(BTNode* ptr){
	leftChildPtr = ptr;
}
void BTNode::assignRightChildPtr(BTNode* ptr){
	rightChildPtr = ptr;
}

	
/*** initializing the construtors of BinaryTree ***/

	//       ^   top of the tree (hight)
	//		( )  root node
	//		/ \
	//	   /   \
//        /     \
//       ^       ^
//	   ( )       ( )  parent node
//     / \     	 / \
// 	  /   \     /   \
//   ^     ^   ^     ^
//	(  ) (  )(  )   (  ) Left and right childs
//	/  \  /\  /\     /\    bottom of athe tree 




BinaryTree::BinaryTree(int n):numNodes(n), arrayOfBTNodes(new BTNode[numNodes]){
	// for each level initialize the tree 
	for (int id=0; id <numNodes; id++){
		// based on the number of nodes
		arrayOfBTNodes[id].assignNodeId(id);
		arrayOfBTNodes[id].assignLevelNum(-1);
		arrayOfBTNodes[id].assignLeftChildPtr(0);
		arrayOfBTNodes[id].assignRightChildPtr(0);
		}
}

// defining accessors funcitons
void BinaryTree::printLeafNodes(){
	for (int id = 0; id<numNodes; id++){
		if(arrayOfBTNodes[id].getLeftChildPtr() == 0 && arrayOfBTNodes[id].getRightChildPtr() == 0)
			cout << id << " ";
	}
	cout << endl;
}

bool BinaryTree::isLeafNode(int nodeId){
	// check if the right and left nodes are empty
	if(arrayOfBTNodes[nodeId].getLeftChildPtr() == 0 && arrayOfBTNodes[nodeId].getRightChildPtr() == 0)
		return true;
	return false;
}
int BinaryTree::getNodeHeight(int nodeId){

	// stop recursion 
	if (nodeId == -1 || isLeafNode(nodeId))
		return 0;

	int leftChildID = arrayOfBTNodes[nodeId].getLeftChildID();
	int rightChildID = arrayOfBTNodes[nodeId].getRightChildID();
	
	// recursive all on right and left child
	return max(getNodeHeight(leftChildID), getNodeHeight(rightChildID)) + 1;
}

int BinaryTree::getTreeHeight(){
	return getNodeHeight(0);
}
void BinaryTree::PreOrderTraversal(int nodeId){
	//     *
	//    /
	//   * - > *
	//
	if (nodeId == -1)
		return;
	cout << nodeId << " ";
	PreOrderTraversal(arrayOfBTNodes[nodeId].getLeftChildID());
	PreOrderTraversal(arrayOfBTNodes[nodeId].getRightChildID());
}

void BinaryTree::PostOrderTraversal(int nodeId){
	//     *
	//       \  the parent last
	//   * - > *
	//

	if (nodeId == -1)
		return;
	PostOrderTraversal(arrayOfBTNodes[nodeId].getLeftChildID());
	PostOrderTraversal(arrayOfBTNodes[nodeId].getRightChildID());
	cout << nodeId << " ";
}

void BinaryTree::InOrderTraversal(int nodeId){
	//      *
	//    ^  \
	//   /      
	//  *      *
	//

	if (nodeId == -1)
		return;
	InOrderTraversal(arrayOfBTNodes[nodeId].getLeftChildID());
	cout << nodeId << " ";
	InOrderTraversal(arrayOfBTNodes[nodeId].getRightChildID());
}
void BinaryTree::PrintPreTraversal(){
	PreOrderTraversal(0);
	cout << endl;
}
void BinaryTree::PrintPostTraversal(){
	PostOrderTraversal(0);
	cout << endl;
}
void BinaryTree::PrintInTraversal(){
	InOrderTraversal(0);
	cout << endl;
}

// defining modifiers functions

void BinaryTree::assignLeftLink(int parentID, int childID){
	arrayOfBTNodes[parentID].assignLeftChildPtr(&arrayOfBTNodes[childID]);
}

void BinaryTree::assignRightLink(int parentID, int childID){
	arrayOfBTNodes[parentID].assignRightChildPtr(&arrayOfBTNodes[childID]);
}



















