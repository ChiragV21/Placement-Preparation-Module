/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	void populateNext(Node* root)
	{
		if(!root)
			return;

		if(root->right != nullptr)
			root->left->next = root->right;
		if(root->next != nullptr  && root->next->left !=nullptr)
			root->right->next = root->next->left;

		populateNext(root->left);
		populateNext(root->right);

	}

	Node* connect(Node* root) {
		if(root != nullptr)
			populateNext(root);           
		return root;
	}
};