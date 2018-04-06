/*
 * AVLTree.h
 *
 *  Created on: Nov 29, 2016
 *      Author: msivraj
 */
#include "AVLInterface.h"
#include "Node.h"
#include "NodeInterface.h"
#ifndef AVLTREE_H_
#define AVLTREE_H_

namespace std {

class AVLTree: public AVLInterface {
private:
	NodeInterface* root = NULL;
	NodeInterface* curr = NULL;
public:
	AVLTree();
	virtual ~AVLTree();

	void clearByRecursion(NodeInterface* nodeIn);
	void checkHeights(NodeInterface* nodeIn);
	int setSubTreeHeights(NodeInterface* nodeIn);
	void leftRotation(NodeInterface* nodeIn);
	void rightRotation(NodeInterface* nodeIn);
	bool addRecursion(NodeInterface* nodeIn, int dataIn);
	NodeInterface* find(int data, NodeInterface* nodeIn);
	NodeInterface* getInorderPredecessor(NodeInterface* nodeIn);
	NodeInterface* getRightMostChild(NodeInterface* nodeIn);
	void rebalance(NodeInterface* nodeIn);
	virtual NodeInterface * getRootNode();
	virtual bool add(int data);
	virtual bool remove(int data);
};

} /* namespace std */

#endif /* AVLTREE_H_ */
