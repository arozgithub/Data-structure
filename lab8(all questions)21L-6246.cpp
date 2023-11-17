#include<iostream>
using namespace std;
class BST;
class TreeNode
{
	friend class BST;
	int data; // The value in the node 
	TreeNode* left; // Pointer to left child node 
	TreeNode* right; // Pointer to right child node 
	int Size;
};
class BST
{

	TreeNode* root;

	int* arr = new int[size()];
	int i = 0;
	int* inOrder(TreeNode* t)
	{

		if (t != 0)
		{
			inOrder(t->left);
			arr[i] = t->data;
			cout << t->data << " ";
			i++;
			inOrder(t->right);
		}
		return arr;

	}
	void preOrder(TreeNode* t)
	{
		if (t != 0)
		{
			cout << t->data << " ";
			inOrder(t->left);
			inOrder(t->right);
		}
	}
	void postOrder(TreeNode* t)
	{
		if (t != 0)
		{
			inOrder(t->left);
			inOrder(t->right);
			cout << t->data << " ";
		}
	}
	//We are catching the root value by-reference so we dont need any extra function to connect the newly created node
	//to the tree.
	bool insert(TreeNode*& t, int val)

	{
		if (t == 0)
		{
			t = new TreeNode;
			t->data = val;
			t->left = nullptr;
			t->right = nullptr;

			return true;
		}
		else if (search(val) == false) {
			if (val < t->data)
			{

				insert(t->left, val);
				return true;
			}
			else if (val > t->data)
			{

				insert(t->right, val);
				return true;
			}
		}
		else return false;


	}
	int minimum(TreeNode* t)
	{
		while (t && t->left != 0)
		{
			t = t->left;
		}
		return t->data;
	}
	int maximum(TreeNode* t)
	{
		while (t && t->right != 0)
		{
			t = t->right;
		}
		return t->data;
	}

	int maxDepth(TreeNode* node)
	{
		if (node == NULL)
			return 0;
		else {
			/* compute the depth of each subtree */
			int lDepth = maxDepth(node->left);
			int rDepth = maxDepth(node->right);

			/* use the larger one */
			if (lDepth > rDepth)
				return (lDepth + 1);
			else
				return (rDepth + 1);
		}
	}

	int size(TreeNode* node)
	{
		if (node == NULL)
			return 0;
		else
			return(size(node->left) + 1 + size(node->right));
	}
	void levelorderPrint(TreeNode* t) {

		int h = maxDepth(root);
		int i;
		for (i = 1; i <= h; i++)
			printCurrentLevel(root, i);
	}
	void printCurrentLevel(TreeNode* root, int level)
	{
		if (root == NULL)
			return;
		if (level == 1)
			cout << root->data << " ";
		else if (level > 1) {
			printCurrentLevel(root->left, level - 1);
			printCurrentLevel(root->right, level - 1);
		}
	}
public:

	BST()
	{
		root = nullptr;
	}
	~BST()
	{}
	int* inOrder()
	{
		return inOrder(root);
	}
	void preOrder()
	{
		preOrder(root);
	}
	void postOrder()
	{
		postOrder(root);
	}
	void insert(int val)
	{
		insert(root, val);
	}
	bool search(int val)
	{
		TreeNode* t = root;
		while (t != 0)
		{
			if (t->data == val)
			{
				/*cout << val<<" exists...!\n";*/
				return true;
			}
			else if (val < t->data)
				t = t->left;
			else
				t = t->right;
		}
		/*cout << val << " does not exist...!\n";*/
		return false;
	}
	int minimum()
	{
		return minimum(root);
	}
	int maximum()
	{
		return maximum(root);
	}
	bool Delete(int val)
	{
		TreeNode* curr = root, * parent = 0;
		while (curr != 0 && curr->data != val)
		{
			parent = curr;
			if (val < curr->data)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (curr == 0)
			return false;
		else
		{
			if (curr->left != 0 && curr->right != 0)
			{
				TreeNode* l = curr->left, * pl = curr;
				while (l->right != 0)
				{
					pl = l;
					l = l->right;
				}
				curr->data = l->data;
				curr = l;
				parent = pl;
			}
			TreeNode* child;
			if (curr->left != 0)
			{
				child = curr->left;
			}
			else
			{
				child = curr->right;
			}
			if (curr == root)
			{
				root = child;
			}
			else
			{
				if (curr == parent->left)
					parent->left = child;
				else
					parent->right = child;
			}
			delete curr;
			curr = 0;
			return true;
		}
	}
	int kthsmallestelement(int k) {

		int* a;
		a = inOrder();
		return a[k - 1];


	}
	int kthlargestelement(int k) {
		int* b;
		b = inOrder();
		int s;
		s = (size() - k);
		return(b[s]);


	}

	int maxDepth() {
		return maxDepth(root);
	}
	int size() {

		return size(root);

	}
	void levelorderPrint() {
		levelorderPrint(root);

	}
	void printCurrentLevel() {

		printCurrentLevel(root, i);
	}


};
int main()
{
	BST b1;
	b1.insert(20);
	b1.insert(24);
	b1.insert(22);
	b1.insert(28);
	b1.insert(25);
	b1.insert(10);
	b1.insert(13);
	b1.insert(11);
	b1.insert(12);
	b1.insert(8);
	b1.insert(9);
	b1.insert(7);

	cout << "Tree's data through In-Order Traversal: ";

	cout << endl;
	/*cout << "Tree's data through Pre-Order Traversal: ";
	b1.preOrder();
	cout << endl;
	cout << "Tree's data through Post-Order Traversal: ";
	b1.postOrder();*/
	cout << endl;
	b1.search(2);
	cout << "Minimum value of BST is: " << b1.minimum() << endl;
	cout << "Maximum value of BST is: " << b1.maximum() << endl;
	/*b1.Delete(20);*/
	cout << "Tree's data through In-Order Traversal: ";
	b1.inOrder();
	cout << endl;
	/*cout << "Tree's data through Pre-Order Traversal: ";
	b1.preOrder();
	cout << endl;
	cout << "Tree's data through Post-Order Traversal: "<<endl;
	b1.postOrder();*/
	int d;
	d = b1.kthsmallestelement(7);
	cout << endl << "kth smallest:" << d << endl;

	int x;
	x = b1.kthlargestelement(7);
	cout << endl << "kth largest :  " << x << endl;

	cout << endl << "depth=" << b1.maxDepth() << endl;
	cout << "length=" << b1.size() << endl;
	b1.levelorderPrint();
	return 0;
}