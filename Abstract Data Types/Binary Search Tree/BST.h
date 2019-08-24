#ifndef BST_H
#define BST_H

#include "../Stack/Stack_Array.h"
#include "../Queue/Queue_List.h"

class BST;

class BSTNode {
	friend class BST;
private:
	BSTNode *left, *right, *parent;
	int data, balance;
public:
	BSTNode(int data) { this->data = data; this->balance = 0; left = NULL; right = NULL; parent = NULL; }
};

class BST {
	BSTNode *root;
public:
	BST() { root = NULL; }
	
	void insert(int);
	void remove(int);
	BSTNode *getNode(int);
	BSTNode* getInorderSuccessor(BSTNode*);
	BSTNode* getInorderPredecessor(BSTNode*);
	void traverse(string);
	void inorderTrav(BSTNode*);
	void preorderTrav(BSTNode*);
	void postorderTrav(BSTNode*);
	void levelorderTrav(BSTNode*);
	int nodeCount();
	int height();
	int height(BSTNode*);
	void AVLUpdate(BSTNode*, int);
	void LLRotate(BSTNode*, int);
	void RRRotate(BSTNode*, int);
	void backtrack(BSTNode*);
};

void BST::insert(int data) {

	//CREATE NODE
	BSTNode *new_node = new BSTNode(data);

	//INSERT NODE
	BSTNode *current, *previous = NULL;
	if(!root) {
		root = new_node;
	} else {
		current = root;
		while(current != NULL) {
			previous = current;
			if(current->data > data) {
				current = current->left;
			} else {
				current = current->right;
			}
		}
		if(previous->data > data) {
			previous->left = new_node;
		} else {
			previous->right = new_node;
		}
		new_node->parent = previous;
	}

	//BALANCE UPDATE
	while(previous) {
		int root_flag = 0;
		previous->balance = height(previous->left) - height(previous->right);
		if(previous->balance < -1 || previous->balance > 1) {
			if(previous == root) { root_flag = 1; }
			AVLUpdate(previous, root_flag);
		}
		previous = previous->parent;
	}
}

void BST::remove(int data) {
	BSTNode *current, *previous;
	int flag;
	current = getNode(data);
	if(!current) {
		return;
	}
	if(current->parent) {
		previous = current->parent;
	}

	if(current->parent && current->parent->left == current) {
		flag = 0;
	} else {
		flag = 1;
	}

	//NODE HAVING 0 OR 1 CHILD
	if(!current->left || !current->right) {
		//ROOT CASE
		if(!current->parent) {
			if(current->right) {
				root = current->right;
			} else {
				root = current->left;
			}
		}
		//NON-ROOT CASES
		if(current->parent) {
			if(flag) {
				if(current->right) {
					(current->parent)->right = current->right;
				} else {
					(current->parent)->right = current->left;
				}
			} else {
				if(current->left) {
					(current->parent)->left = current->left;
				} else {
					(current->parent)->left = current->right;			
				}
			}
		}
		//LINKING CHILD-PARENT NODES/SUBTREES
		if(current->right) {
			current->right->parent = current->parent;					
		}
		if(current->left) {
			current->left->parent = current->parent;					
		}

		previous = current->parent;
	}

	//NODE HAVING TWO CHILDREN
	if(current->left && current->right) {
		BSTNode *temp_current = current;
		
		current = getInorderSuccessor(temp_current);

		//LINKING NEW NODE TO DELETED NODE'S CHILDREN
		current->left = temp_current->left;
		current->right = temp_current->right;
		
		//ROOT CASE
		if(!temp_current->parent) {
			current->balance = height(current->left) - height(current->right); //BALANCE UPDATE
			root = current;
			// current->parent = NULL;
			// return;
		}
		
		// NON-ROOT CASES
		//LINKING DELETED NODE'S PARENTS TO NEW NODE
		current->parent = temp_current->parent;
		if(current->parent) {
			if(flag) {
				(current->parent)->right = current;
			} else {
				(current->parent)->left = current;
			}
		}

		//LINKING DELETED NODE'S CHILDREN TO THE NEW NODE
		if(current->right) {
			current->right->parent = current;					
		}
		current->left->parent = current;					
		
		temp_current = NULL;
		delete(temp_current);
	
		previous = current;
	}

	//BALANCE UPDATE
	while(previous) {
		int root_flag = 0;
		previous->balance = height(previous->left) - height(previous->right);
		if(previous->balance < -1 || previous->balance > 1) {
			if(previous == root) { root_flag = 1; }
			AVLUpdate(previous, root_flag);
		}
		previous = previous->parent;
	}

	current = NULL; previous = NULL;
	delete(current); delete(previous);
}

BSTNode *BST::getNode(int val) {
	BSTNode *current = root;
	while(current) {
		if(current->data == val) {
			return current;
		} else if(current->data < val) {
			current = current->right;
		} else {
			current = current->left;
		}
	}
	return current;
}

BSTNode* BST::getInorderSuccessor(BSTNode* node) {
	BSTNode *current;
	if(node->right) {
		current = node->right;
	} else {
		current = NULL;
		return current;
	}
	while(current->left) {
		current = current->left;
	}

	//LINKING INORDER SUCCESSOR'S PARENTS TO ITS RIGHT CHILD
	if(current->parent->right == current) {
		current->parent->right = current->right;
	} else {
		current->parent->left = current->right;
	}

	//LINKING INORDER SUCCESSOR'S RIGHT CHILD TO IT'S PARENT
	if(current->right) {
		current->right->parent = current->parent;					
	}

	return current;
} 

BSTNode* BST::getInorderPredecessor(BSTNode* node) {
	BSTNode *current;
	if(node->left) {
		current = node->left;
	} else {
		current = NULL;
		return current;
	}
	while(current->right) {
		current = current->right;
	}

	//LINKING INORDER PREDECESSOR'S PARENTS TO ITS LEFT CHILD
	if(current->parent->right == current) {
		current->parent->right = current->left;
	} else {
		current->parent->left = current->right;
	}

	//LINKING INORDER PREDECESSOR'S LEFT CHILD TO IT'S PARENT
	if(current->left) {
		current->left->parent = current->parent;					
	}

	return current;
} 

void BST::inorderTrav(BSTNode *node) {
	if(nodeCount() == 0) {
		return;
	}
	BSTNode *current = node;
	Stack_Array stack;
	loop : while(current) {
		stack.push(current->data);
		current = current->left;
	}		
	while(!current && !stack.isEmpty()) {
		int val = stack.pop();
		BSTNode *temp = getNode(val);
		cout << val << " ";

		current = getNode(val)->right;
		if(current) {
			goto loop;						
		}
	}
	cout << endl;
}

void BST::preorderTrav(BSTNode *node) {
	if(nodeCount() == 0) {
		return;
	}
	BSTNode *current = node;
	Stack_Array stack;
	stack.push(current->data);
	while(!stack.isEmpty()) {
		int val = stack.pop();
		cout << val << " ";
		current = getNode(val);
		if(current->right) {
			stack.push(current->right->data);			
		}
		if(current->left) {
			stack.push(current->left->data);			
		}
	}
	cout << endl;
}

void BST::postorderTrav(BSTNode *node) {
	if(nodeCount() == 0) {
		return;
	}
	BSTNode *current = node;
	Stack_Array stack;
	do {
		if(current) {
			if(current->right) {
				stack.push(current->right->data);
			}
			stack.push(current->data);
			current = current->left;
		} else {
			int val = stack.pop();
			current = getNode(val);
			if(current->right && current->right->data == stack.peek()) {
				current = getNode(stack.pop());
				stack.push(val);
			} else {
				cout << val << " ";
				current = NULL;
			}
		}
	} while(!stack.isEmpty());
	cout << endl;
}

void BST::levelorderTrav(BSTNode *node) {
	BSTNode *current = node;
	Queue_List queue;
	queue.enqueue(current->data);
	while(!queue.isEmpty()) {
		int val = queue.dequeue();
		BSTNode *temp = getNode(val);
		cout << val << " ";
		if(temp->left) {
			queue.enqueue(temp->left->data);			
		}
		if(temp->right) {
		queue.enqueue(temp->right->data);			
		}
	}
	cout << endl;
}

void BST::traverse(string mode) {
	if(mode == "inorder") {
		inorderTrav(root);		
	}
	if(mode == "preorder") {
		preorderTrav(root);
	}
	if(mode == "postorder") {
		postorderTrav(root);
	}
	if(mode == "levelorder") {
		levelorderTrav(root);
	}
}

int BST::nodeCount() {
	BSTNode *current = root;
	Stack_Array stack;
	int count = 0;
	
	if(root) {
		stack.push(current->data);				
	}
	while(!stack.isEmpty()) {
		current = getNode(stack.pop());
		count++;
		if(current->left) {
			stack.push(current->left->data);
		}
		if(current->right) {
			stack.push(current->right->data);
		}
	}
	return count;
}

int BST::height() {
	height(root);
}

int BST::height(BSTNode *node) {
	BSTNode *current = node;
	if(!current) {
		return 0;
	}
	return (max(height(current->left), height(current->right)) + 1);
}

void BST::LLRotate(BSTNode *node, int root_flag) {
	BSTNode *temp = node->left;
	node->left = temp->right;
	if(temp->right) {
		temp->right->parent = node;
	}
	temp->right = node;
	temp->parent = node->parent;
	
	node->parent = temp;
	node->balance = height(node->left) - height(node->right);

	if(root_flag) {
		root = temp;
		temp->parent = NULL;
	} else {
		if(temp->parent->left == node) {
			temp->parent->left = temp;
		} else {
			temp->parent->right = temp;
		}
	}
}

void BST::RRRotate(BSTNode *node, int root_flag) {
	BSTNode *temp = node->right;
	node->right = temp->left;
	if(temp->left) {
		temp->left->parent = node;		
	}
	temp->left = node;
	temp->parent = node->parent;
	
	node->parent = temp;
	node->balance = height(node->left) - height(node->right);

	if(root_flag) {
		root = temp;
		temp->parent = NULL;
	} else {
		if(temp->parent->left == node) {
			temp->parent->left = temp;
		} else {
			temp->parent->right = temp;
		}
	}
}

void BST::AVLUpdate(BSTNode *node, int root_flag) {
	BSTNode *current = node;

	if(current->balance == 2) {
		//LL ROTATION
		if(current->left->balance == 1 || current->left->balance == 0) {
			LLRotate(current, root_flag);
			return;
		}
		
		//LR ROTATION
		if(current->left->balance == -1) {
			RRRotate(current->left, 0);
			LLRotate(current, root_flag);
			return;
		}
	} else if(current->balance == -2) {
		//RR ROTATION
		if(current->right->balance == -1 || current->right->balance == 0) {
			RRRotate(current, root_flag);
			return;
		}
		
		//RL ROTATION
		if(current->right->balance == 1) {
			LLRotate(current->right, 0);
			RRRotate(current, root_flag);
			return;
		}
	}	
}

void BST::backtrack(BSTNode *node) {
	if(root) {
		cout << "root -> " << root->data << endl;
	}
	while(node) {
		cout << node->data << " " << endl;
		node = node->parent;
	}
}

#endif