#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int value) {
	Node *temp = new Node;
	temp->data = value;
	temp->left = temp->right = NULL;
	return temp;
}

int findLevel(Node *root, int search_node, int level) {
	if (root == NULL)
		return -1;

	if (root->data == search_node)
		return level;

	int left_level = findLevel(root->left, search_node, level + 1);
	int right_level = findLevel(root->right, search_node, level + 1);

	return (left_level != -1) ? left_level : right_level;
}

// returns pointer to LCA of two given values n1 and n2. 
// level distance of current node from root
Node* findDistUtil (Node* root, int node1, int node2, int &dist_root_n1, int &dist_root_n2, int &dist_n1_n2, int level) {
	if (root == NULL)
		return NULL;

	if (root->data == node1) {
		dist_root_n1 = level;
		return root;
	}
	if (root->data == node2) {
		dist_root_n2 = level;
		return root;
	}

	//check for node1 and node2 in left and right sub tree
	Node *left_lca = findDistUtil(root->left, node1, node2, dist_root_n1, dist_root_n2, dist_n1_n2, level + 1);
	Node *right_lca = findDistUtil(root->right, node1, node2, dist_root_n1, dist_root_n2, dist_n1_n2, level + 1);

	// If both of the above calls return Non-NULL, then one key
	// is present in one subtree and other is present in other,
	// So this node is the LCA
	if (left_lca && right_lca) {
		dist_n1_n2 = dist_root_n1 + dist_root_n2 - 2 * level;
		return root;
	}

	// Otherwise check if left subtree or right subtree is LCA
	return (left_lca != NULL) ? left_lca : right_lca;
}

//returns distance between n1 and n2
int findDistance (Node *root, int node1, int node2) {
	int dist_root_n1 = -1, dist_root_n2 = -1;
	int dist_n1_n2, level = 1;

	Node *lca = findDistUtil (root, node1, node2, dist_root_n1, dist_root_n2, dist_n1_n2, level);

	//both nodes are in tree return distance.
	if (dist_root_n1 != -1 && dist_root_n2 != -1)
		return dist_n1_n2;

	// If n1 is ancestor of n2, consider n1 as root and find level 
	// of n2 in subtree rooted with n1
	if (dist_root_n1 != -1) {
		dist_n1_n2 = findLevel (lca, node2, 0);
		return dist_n1_n2;
	}

	// If n2 is ancestor of n1, consider n2 as root and find level 
	// of n1 in subtree rooted with n2
	if (dist_root_n2 != -1) {
		dist_n1_n2 = findLevel (lca, node1, 0);
		return dist_n1_n2;
	}

	return -1;
}

int main() {
	Node * root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
	cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
	cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
	cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
	cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
	cout << endl;
	return 0;
}
