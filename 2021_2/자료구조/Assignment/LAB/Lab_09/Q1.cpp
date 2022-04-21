// Lab Q1 test용 : 맨 아래의 주석처리된 함수들을 TreeType.h와 cpp에 추가하자.

#include <iostream>
#include "TreeType.h"

//char case1[4] = { '3','1','4','5' };
//char case2[5] = { '3','1','4','5','2' };
//char case1[4] = { '3','2','4','5' };
//char case2[5] = { '3','2','4','5','1' };
char case1[3] = { '3','2','5' };
char case2[4] = { '3','2','5','1' };
TreeType tree1, tree2;
TreeNode* root1, * root2;
TreeNode* node1, * node2;

int main() {
	for (char elem : case1)
		tree1.InsertItem(elem);

	for (char elem : case2)
		tree2.InsertItem(elem);

	// Before PtrToSuccessor
	tree1.PrintCOUT();
	std::cout << std::endl;
	//std::cout << node1->info << std::endl;
	tree2.PrintCOUT();
	std::cout << std::endl; 
	std::cout << std::endl;

	root1 = tree1.RootIs();
	root2 = tree2.RootIs();

	/*node1 = tree1.PtrToSuccessor_recur(root1);
	node2 = tree2.PtrToSuccessor_recur(root2);*/
	node1 = tree1.PtrToSuccessor_nonrecur(root1);
	node2 = tree2.PtrToSuccessor_nonrecur(root2);

	tree1.PrintCOUT();
	std::cout << std::endl;

	tree2.PrintCOUT();
	std::cout << std::endl;

	return 0;
}

//// For test PrtToSuccessor function
//TreeNode* TreeType::RootIs()
//{
//	return root;
//}
//
//// Debug
//void PrintTreeCOUT(TreeNode* tree)
//// Prints info member of items in tree in sorted order on Terminal.
//{
//
//	if (tree != NULL)
//	{
//		std::cout << "debug::" << tree->info << " " << tree->left << " " << tree->right << '\n';
//		PrintTreeCOUT(tree->left);   // Print left subtree.
//		std::cout << tree->info << " ";
//		PrintTreeCOUT(tree->right);  // Print right subtree.
//	}
//}
//
//// Debug
//void TreeType::PrintCOUT() const
//{
//	PrintTreeCOUT(root);
//}
//
//TreeType::TreeType()
//{
//	root = NULL;
//}