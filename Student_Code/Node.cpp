/*
 * Node.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: msivraj
 */

#include "Node.h"

namespace std {

Node::Node(int dataIn) {
	data = dataIn;
	left = NULL;
	right = NULL;
	parent = NULL;
	leftSubTreeHeight = 0;
	rightSubTreeHeight = 0;
	// TODO Auto-generated constructor stub

}

Node::~Node() {
	left = NULL;
	right = NULL;
	parent = NULL;
	leftSubTreeHeight = 0;
	rightSubTreeHeight = 0;
	// TODO Auto-generated destructor stub
}

void Node::setLeftSubTreeHeight(int heightIn) {
	leftSubTreeHeight = heightIn;
}
void Node::setRightSubTreeHeight(int heightIn) {
	rightSubTreeHeight = heightIn;
}
int Node::getLeftSubTreeHeight() {
	return leftSubTreeHeight;
}
int Node::getRightSubTreeHeight() {
	return rightSubTreeHeight;
}

void Node::setLeft(NodeInterface* leftIn) {
	left = leftIn;
}
void Node::setRight(NodeInterface* rightIn) {
	right = rightIn;
}

NodeInterface* Node::getParent() {
	return parent;
}
void Node::setParent(NodeInterface* parIn) {
	parent = parIn;
}

/*
 * Returns the data stored in this node
 *
 * @return the data stored in this node.
 */
int Node::getData() {
	return data;
}

/*
 * Returns the left child of this node or null if empty left child.
 *
 * @return the left child of this node or null if empty left child.
 */
NodeInterface * Node::getLeftChild() {
	return left;
}

/*
 * Returns the right child of this node or null if empty right child.
 *
 * @return the right child of this node or null if empty right child.
 */
NodeInterface * Node::getRightChild() {
	return right;
}

/*
 * Returns the height of this node. The height is the number of nodes
 * along the longest path from this node to a leaf.  While a conventional
 * interface only gives information on the functionality of a class and does
 * not comment on how a class should be implemented, this function has been
 * provided to point you in the right direction for your solution.  For an
 * example on height, see page 448 of the text book.
 *
 * @return the height of this tree with this node as the local root.
 */
int Node::getHeight() {
	//algorithum for depth
//	if (this->getParent() == NULL) {
//		return 0;
//	} else {
//		return (this->getParent()->getHeight()) + 1;
//	}
	//put in algorithm that we wrote
	int longLeft = 0;
	int longRight = 0;
	if (this->getLeftChild() != NULL) {
		longLeft = this->getLeftChild()->getHeight();
		longLeft++;
	}
	if (this->getRightChild() != NULL) {
		longRight = this->getRightChild()->getHeight();
		longRight++;
	}
	return longLeft > longRight ? longLeft : longRight;	// short hand if statement ? if condition is met return what is after ? else return what is after :

}

} /* namespace std */
