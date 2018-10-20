#include "BiTree.cc"

int main(){

	string filename;
	cout << "Enter a file name: ";
	cin >> filename;

	int numNodes;
	cout << "Enter number of nodes: ";
	cin >> numNodes;

	// creating an object of the class BinaryTree
	BinaryTree binaryTree(numNodes);

	ifstream fileReader(filename);

	if(!fileReader){
		cout << "File cannot be opened! ";
		return 0;
	}

	int numCharsPerLine =10;

	char *line = new char[numCharsPerLine];

	fileReader.getline(line, numCharsPerLine, '\n');

	while(fileReader){

		char* cptr = strtok(line, ",: ");

		string upstreamNodeToken(cptr);
		int upstreamNodeID = stoi(upstreamNodeToken);

		cptr = strtok(NULL, ",:");

		int childIndex = 0;

		while(cptr != 0){

			string downstreamNodeToken(cptr);
			int downstreamNodeID = stoi(downstreamNodeToken);

			if(childIndex == 0 && downstreamNodeID != - 1)
				binaryTree.assignLeftLink(upstreamNodeID, downstreamNodeID);

			if(childIndex == 0 && downstreamNodeID != - 1)
				binaryTree.assignRightLink(upstreamNodeID, downstreamNodeID);

			cptr = strtok(NULL, ",: ");
			childIndex++;

		}

		fileReader.getline(line, numCharsPerLine, '\n');

	}

	cout <<" This is the pre order Traversal(root, left, right):\n";
	binaryTree.PrintPreTraversal();
	cout <<" This is the post order Traversal(left, right, root):\n";
	binaryTree.PrintPostTraversal();
	cout <<" This is the In order Traversal( left, root, right):\n";
	binaryTree.PrintInTraversal();

	return 0;
}

		

