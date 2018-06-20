#include <string>
#include <fstream>
#include <iostream>

#include "QueType.h"

template<class ItemType>
struct TreeNode;

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template<class ItemType>
class TreeType
{
public:
  TreeType();                     // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType<ItemType>& originalTree); 
  void operator=(const TreeType<ItemType>& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int LengthIs() const; 
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  void GetNextItem (ItemType& item, OrderType order, 
       bool& finished);
  void Print(std::ostream& outFile) const;
  void Ancestors(ItemType value);
  void Ancestors_re(ItemType item);
private:
  TreeNode<ItemType>* root;
  QueType<ItemType> preQue;
  QueType<ItemType> inQue;
  QueType<ItemType> postQue;
};

template<class ItemType>
struct TreeNode
{
	ItemType info;
	TreeNode<ItemType>* left;
	TreeNode<ItemType>* right;
};

template<class ItemType>
bool TreeType<ItemType>::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
	TreeNode<ItemType>* location;
	try
	{
		location = new TreeNode<ItemType>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

template<class ItemType>
bool TreeType<ItemType>::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
	return root == NULL;
}

template<class ItemType>
int CountNodes(TreeNode<ItemType>* tree);

template<class ItemType>
int TreeType<ItemType>::LengthIs() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
	return CountNodes(root);
}


template<class ItemType>
int CountNodes(TreeNode<ItemType>* tree)
// Post: returns the number of nodes in the tree.
{
	if (tree == NULL)
		return 0;
	else
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

template<class ItemType>
void Retrieve(TreeNode<ItemType>* tree,
	ItemType& item, bool& found);

template<class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
	Retrieve(root, item, found);
}

template<class ItemType>
void Retrieve(TreeNode<ItemType>* tree,
	ItemType& item, bool& found)
	// Recursively searches tree for item.
	// Post: If there is an element someItem whose key matches item's,
	//       found is true and item is set to a copy of someItem; 
	//       otherwise found is false and item is unchanged.
{
	if (tree == NULL)
		found = false;                     // item is not found.
	else if (item < tree->info)
		Retrieve(tree->left, item, found); // Search left subtree.
	else if (item > tree->info)
		Retrieve(tree->right, item, found);// Search right subtree.
	else
	{
		item = tree->info;                 // item is found.
		found = true;
	}
}

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item);

template<class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
	Insert(root, item);
}

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
	if (tree == NULL)
	{// Insertion place found.
		tree = new TreeNode<ItemType>;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
	}
	else if (item < tree->info)
		Insert(tree->left, item);    // Insert in left subtree.
	else
		Insert(tree->right, item);   // Insert in right subtree.
}

template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree);

template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item);

template<class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
	Delete(root, item);
}


template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
	if (item < tree->info)
		Delete(tree->left, item);   // Look in left subtree.
	else if (item > tree->info)
		Delete(tree->right, item);  // Look in right subtree.
	else
		DeleteNode(tree);           // Node found; call DeleteNode.
}

template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data);

template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only 
//       non-NULL child pointer the node pointed to by tree is 
//       deleted; otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is deleted.
{
	ItemType data;
	TreeNode<ItemType>* tempPtr;

	tempPtr = tree;
	if (tree->left == NULL)
	{
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == NULL)
	{
		tree = tree->left;
		delete tempPtr;
	}
	else
	{
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);  // Delete predecessor node.
	}
}

template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
	while (tree->right != NULL)
		tree = tree->right;
	data = tree->info;
}

template<class ItemType>
void PrintTree(TreeNode<ItemType>* tree, std::ostream& outFile)
// Prints info member of items in tree in sorted order on outFile.
{
	if (tree != NULL)
	{
		outFile << " -" <<tree->info;
		PrintTree(tree->left, outFile);   // Print left subtree.
		PrintTree(tree->right, outFile);  // Print right subtree.
	}
}

template<class ItemType>
void TreeType<ItemType>::Print(std::ostream& outFile) const 
// Calls recursive function Print to print items in the tree.
{
	PrintTree(root, outFile);
}

template<class ItemType>
TreeType<ItemType>::TreeType()
{
	root = NULL;
}

template<class ItemType>
void Destroy(TreeNode<ItemType>*& tree);

template<class ItemType>
TreeType<ItemType>::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
	Destroy(root);
}

template<class ItemType>
void Destroy(TreeNode<ItemType>*& tree)
// Post: tree is empty; nodes have been deallocated.
{
	if (tree != NULL)
	{
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
	}
}

template<class ItemType>
void TreeType<ItemType>::MakeEmpty()
{
	Destroy(root);
	root = NULL;
}

template<class ItemType>
void CopyTree(TreeNode<ItemType>*& copy,
	const TreeNode<ItemType>* originalTree);

template<class ItemType>
TreeType<ItemType>::TreeType(const TreeType<ItemType>& originalTree)
// Calls recursive function CopyTree to copy originalTree 
//  into root.
{
	CopyTree(root, originalTree.root);
}

template<class ItemType>
void TreeType<ItemType>::operator=
(const TreeType<ItemType>& originalTree)
// Calls recursive function CopyTree to copy originalTree 
// into root.
{
	{
		if (&originalTree == this)
			return;             // Ignore assigning self to self
		Destroy(root);      // Deallocate existing tree nodes
		CopyTree(root, originalTree.root);
	}

}

template<class ItemType>
void CopyTree(TreeNode<ItemType>*& copy,
	const TreeNode<ItemType>* originalTree)
	// Post: copy is the root of a tree that is a duplicate 
	//       of originalTree.
{
	if (originalTree == NULL)
		copy = NULL;
	else
	{
		copy = new TreeNode<ItemType>;
		copy->info = originalTree->info;
		CopyTree(copy->left, originalTree->left);
		CopyTree(copy->right, originalTree->right);
	}
}
// Function prototypes for auxiliary functions.

template<class ItemType>
void PreOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in preorder.

template<class ItemType>
void InOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in inorder.

template<class ItemType>
void PostOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in postorder.

template<class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in 
// the desired order.
{
	switch (order)
	{
	case PRE_ORDER: 
		PreOrder(root, preQue);
		
		break;
	case IN_ORDER: InOrder(root, inQue);
		break;
	case POST_ORDER: PostOrder(root, postQue);
		break;
	}
}

template<class ItemType>
void PreOrder(TreeNode<ItemType>* tree,
	QueType<ItemType>& preQue)
	// Post: preQue contains the tree items in preorder.
{
	if (tree != NULL)
	{

		preQue.Enqueue(tree->info);
		PreOrder(tree->left, preQue);
		PreOrder(tree->right, preQue);
	}
}

template<class ItemType>
void InOrder(TreeNode<ItemType>* tree,
	QueType<ItemType>& inQue)
	// Post: inQue contains the tree items in inorder.
{
	if (tree != NULL)
	{
		InOrder(tree->left, inQue);
		inQue.Enqueue(tree->info);
		InOrder(tree->right, inQue);
	}
}

template<class ItemType>
void PostOrder(TreeNode<ItemType>* tree,
	QueType<ItemType>& postQue)
	// Post: postQue contains the tree items in postorder.
{
	if (tree != NULL)
	{
		PostOrder(tree->left, postQue);
		PostOrder(tree->right, postQue);
		postQue.Enqueue(tree->info);
	}
}

template<class ItemType>
void TreeType<ItemType>::GetNextItem(ItemType& item,
	OrderType order, bool& finished)
	// Returns the next item in the desired order.
	// Post: For the desired order, item is the next item in the queue.
	//       If item is the last one in the queue, finished is true; 
	//       otherwise finished is false.
{
	finished = false;
	switch (order)
	{
	case PRE_ORDER: 
		preQue.Dequeue(item);
		if (preQue.IsEmpty())
			finished = true;
		break;
	case IN_ORDER: inQue.Dequeue(item);
		if (inQue.IsEmpty())
			finished = true;
		break;
	case  POST_ORDER: postQue.Dequeue(item);
		if (postQue.IsEmpty())
			finished = true;
		break;
	}
}

template<class ItemType>
void TreeType<ItemType>::Ancestors(ItemType value) {
	bool found = false;
	QueType<ItemType> path;

	TreeNode<ItemType> *currentNode = root;

	while (!found && currentNode != NULL)  // value를 가진 노드를 찾거나 트리 끝에 도달할 때까지
	{
		if (currentNode->info == value)  // value를 가진 노드를 찾으면
			found = true;
		else {
			path.Enqueue(currentNode->info); // path에 현재 노드의 값을 삽입
			if (currentNode->info > value)
				currentNode = currentNode->left; // 왼쪽 서브트리로 이동
			else
				currentNode = currentNode->right; // 오른쪽 서브트리로 이동
		}\
	}

	if (found) {// path에 있는 내용을 출력
		ItemType pathValue;
		while (!path.IsEmpty()) {
			path.Dequeue(pathValue);
			std::cout << pathValue << std::endl;
		}
	}
	else {// value를 찾을 수 없다고 출력
		std::cout << '\'' << value << '\'' << "를 찾을 수 없습니다." << std::endl;
	}

}

template<class ItemType>
bool Ancestors_recursive(TreeNode<ItemType>* tree, ItemType item)
{
	bool found = false;
	if (tree == NULL)
		return false;

	if (tree->info == item) // value를 찾은 경우
		return true;

	if (tree->info>item)
		found = Ancestors_recursive(tree->left, item); // 왼쪽 서브트리 호출
	else
		found = Ancestors_recursive(tree->right, item); // 오른쪽 서브트리 호출

	if (found) // 재귀호출 후 value값을 찾았으면
		std::cout << tree->info << std::endl;	   // 현재 노드의 값을 출력

	return found;
}

template<class ItemType>
void TreeType<ItemType>::Ancestors_re(ItemType value)
{
	Ancestors_recursive(root, value);
}

