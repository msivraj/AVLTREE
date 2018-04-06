/*
 * Node.h
 *
 *  Created on: Nov 29, 2016
 *      Author: msivraj
 */
#include "NodeInterface.h"

#ifndef NODE_H_
#define NODE_H_

namespace std {

class Node: public NodeInterface {
private:
	int data;
	NodeInterface* left;
	NodeInterface* right;
	NodeInterface* parent;
	int leftSubTreeHeight;
	int rightSubTreeHeight;
public:
	Node(int dataIn);
	virtual ~Node();

	void setLeftSubTreeHeight(int heightIn);
	void setRightSubTreeHeight(int heightIn);
	int getLeftSubTreeHeight();
	int getRightSubTreeHeight();
	NodeInterface* getParent();
	void setParent(NodeInterface* parIn);
	void setLeft(NodeInterface* leftIn);
	void setRight(NodeInterface* rightIn);
	virtual int getData();
	virtual NodeInterface * getLeftChild();
	virtual NodeInterface * getRightChild();
	virtual int getHeight();
};

} /* namespace std */

#endif /* NODE_H_ */
