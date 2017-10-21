#ifndef CONTAINER_TREE
#define CONTAINER_TREE


template<class T>
class Tree {
public:
	struct Node {
		Node* left = nullptr;
		Node* right = nullptr;
		T content;

		Node() {}
		Node(T& content_arg, T* left_arg, T* right_arg) 
		    : content(content_arg),
		    left(left_arg),
		    right(right_arg) {}
	};

	Node* root = nullptr;

public:
	Tree() {}
	Tree(Tree& other);

	void add(T value) {
		if(root = nullptr) { root = new Node(value, nullptr, nullptr);
			return; }
		if(root->left != nullptr)
			root->left->content = value;
		else if(root->right != nullptr)
			root->right->content = value;
		else {
			if(!add(*root->left, value))
				add(*root->right, value);
		}
	}

private:
	bool add(Node& node, T value) {
		if(root->left != nullptr)
			root->left->content = value;
		else if(root->right != nullptr)
			root->right->content = value;
		else {
			return false;
			if(!add(*root->left, value))
				add(*root->right, value);
		}
		return true;
	}
};


#endif
