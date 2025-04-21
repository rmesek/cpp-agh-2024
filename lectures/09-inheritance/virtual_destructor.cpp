#include <iostream>
using namespace std;

class Node {
public:
	Node() = default;
	virtual
	~Node() { cout << "~Node()" << endl; }
	virtual void print_elem (ostream &) const = 0;
};

class IntegerNode : public Node {

public:
	explicit IntegerNode (int n) { data = n; }
	~IntegerNode() override {
		cout << "~IntegerNode()" << endl;
	}
	void print_elem (ostream &out) const override {
		out << "Integer : " << data << endl;
	}

private:
	int data;
};

class DoubleNode : public Node {

public:
	explicit DoubleNode (double n) { data = n; }
	~DoubleNode() override {
		cout << "~DoubleNode()" << endl;
	}
	void print_elem (ostream &out) const override {
		out << "Double  : " << data << endl;
	}

private:
	double data;
};

class StringNode : public Node {

public:
	explicit StringNode (string n) : data(std::move(n)) {}
	~StringNode() override {
		cout << "~StringNode()" << endl;
	}
	void print_elem (ostream &out) const override {
		out << "String  : " << data << endl;
	}

private:
	string data;
};

ostream& operator<< (ostream &out, const Node &node) {
	node.print_elem(out);
	return out;
}

int main () {
	Node *array[]{
		new IntegerNode(4),
		new DoubleNode(1.1),
		new StringNode("String"),
		new DoubleNode(3.4),
		new IntegerNode(6),
		new StringNode("Any text"),
		new DoubleNode(6.4)
	};
	for (auto *node : array) {
		node->print_elem(cout);
	}

	cout << "----- Delete array ------" << endl;
	for (auto *node : array) {
		delete node;
	}

	return EXIT_SUCCESS;
}

