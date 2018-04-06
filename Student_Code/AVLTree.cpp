/*
 * AVLTree.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: msivraj
 */

#include "AVLTree.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>


namespace std {

AVLTree::AVLTree() {
	// TODO Auto-generated constructor stub

}

AVLTree::~AVLTree() {
	clearByRecursion(root);
	// TODO Auto-generated destructor stub
}
void AVLTree::clearByRecursion(NodeInterface* nodeIn) {
	if (root == NULL) {
		return;
	}
	NodeInterface* iterator = nodeIn;
	NodeInterface* iteratorParent; //= ((Node*) iterator)->getParent();
//	NodeInterface* deleteIterator = iterator;
//	if (deleteIterator->getData() == 8) {
//		cout << "your error is imminent";
//	}
//	cout << nodeIn->getData() << "\n";
	if (iterator->getLeftChild() != NULL) {
		//iteratorParent = iterator;
		clearByRecursion(iterator->getLeftChild());
	}

	else if (iterator->getRightChild() != NULL) { //case of rightchild
		//iteratorParent = iterator;
		clearByRecursion(iterator->getRightChild());
	}

	else { //case of no rightchild
		//if (iterator->getRightChild() == NULL)
		NodeInterface* deleteIterator = iterator;
		iteratorParent = ((Node*) iterator)->getParent();
		if (iteratorParent == NULL) {
			((Node*) deleteIterator)->setLeft(NULL);
			((Node*) deleteIterator)->setRight(NULL);
			((Node*) deleteIterator)->setParent(NULL);
			//cout << "DELETE VALUE" << deleteIterator->getData() << "\n";
			delete deleteIterator;
			curr = NULL;
			root = NULL;
			return;

		}
		if (iteratorParent->getRightChild() == deleteIterator) {
			((Node*) iteratorParent)->setRight(NULL);
		} else {
			((Node*) iteratorParent)->setLeft(NULL);
		}
		((Node*) deleteIterator)->setParent(NULL);
		((Node*) deleteIterator)->setRight(NULL);
		((Node*) deleteIterator)->setLeft(NULL);
		//cout << "DELETE VALUE" << deleteIterator->getData() << "\n";
		delete deleteIterator;

		clearByRecursion(iteratorParent);

	}


}

void AVLTree::rightRotation(NodeInterface* nodeIn) {

	NodeInterface* nodeInLeftChild = ((Node*) nodeIn)->getLeftChild();
	NodeInterface* nodeInPar = ((Node*) nodeIn)->getParent();
	NodeInterface* nodeInLeftChildRightChild = nodeInLeftChild->getRightChild();
	if (nodeIn == root) {
		((Node*) nodeIn)->setParent(nodeInLeftChild);
		((Node*) nodeIn)->setLeft(NULL); //dont uncomment
		((Node*) nodeInLeftChild)->setRight(nodeIn);
		((Node*) nodeInLeftChild)->setParent(NULL);
		root = nodeInLeftChild;
	} else {
		((Node*) nodeInLeftChild)->setParent(nodeInPar);
		if (nodeInPar->getData() > nodeIn->getData()) {
			((Node*) nodeInPar)->setLeft(nodeInLeftChild);
		} else {
			((Node*) nodeInPar)->setRight(nodeInLeftChild);
		}
		((Node*) nodeIn)->setParent(nodeInLeftChild);
		((Node*) nodeInLeftChild)->setRight(nodeIn);
		((Node*) nodeIn)->setLeft(NULL);
	}
	if (nodeInLeftChildRightChild != NULL) {
		((Node*) nodeIn)->setLeft(nodeInLeftChildRightChild);
		((Node*) nodeInLeftChildRightChild)->setParent(nodeIn);
	}
}

void AVLTree::leftRotation(NodeInterface* nodeIn) {

	NodeInterface* nodeInRightChild = ((Node*) nodeIn)->getRightChild();
	NodeInterface* nodeInPar = ((Node*) nodeIn)->getParent();
	NodeInterface* nodeInRightChildLeftChild = nodeInRightChild->getLeftChild();
	if (nodeIn == root) {
		((Node*) nodeIn)->setParent(nodeInRightChild);
		((Node*) nodeInRightChild)->setLeft(nodeIn);
		((Node*) nodeIn)->setRight(NULL);
		((Node*) nodeInRightChild)->setParent(NULL);
		root = nodeInRightChild;
	} else {
		((Node*) nodeInRightChild)->setParent(nodeInPar);
		if (nodeInPar->getData() > nodeIn->getData()) {
			((Node*) nodeInPar)->setLeft(nodeInRightChild);
		} else {
			((Node*) nodeInPar)->setRight(nodeInRightChild);
		}
		((Node*) nodeIn)->setParent(nodeInRightChild);
		((Node*) nodeInRightChild)->setLeft(nodeIn);
		((Node*) nodeIn)->setRight(NULL);

	}
	if (nodeInRightChildLeftChild != NULL) {
		((Node*) nodeIn)->setRight(nodeInRightChildLeftChild);
		((Node*) nodeInRightChildLeftChild)->setParent(nodeIn);
	}
}

void AVLTree::checkHeights(NodeInterface* nodeIn) {
	if (nodeIn == NULL) {
		//		longLeft = 0;
		//		longRight = 0;
		return;
	}
	else {
		if (nodeIn->getLeftChild() != NULL) {
			checkHeights(nodeIn->getLeftChild());
		}
		if (nodeIn->getRightChild() != NULL) {
			checkHeights(nodeIn->getRightChild());
		}
		if (abs(
				((Node*) nodeIn)->getLeftSubTreeHeight()
						- ((Node*) nodeIn)->getRightSubTreeHeight()) >= 2) {
			rebalance(nodeIn);
		}
	}
}

int AVLTree::setSubTreeHeights(NodeInterface* nodeIn) {
	int longLeft = 0;
	int longRight = 0;
	if (nodeIn == NULL) {

		return 0;
	}
	else {
		if (nodeIn->getLeftChild() != NULL) {

			longLeft = setSubTreeHeights(nodeIn->getLeftChild()); //  FIX
			longLeft++;
			((Node*) nodeIn)->setLeftSubTreeHeight(longLeft);
		} else {
			((Node*) nodeIn)->setLeftSubTreeHeight(0);
		}
		if (nodeIn->getRightChild() != NULL) {

			longRight = setSubTreeHeights(nodeIn->getRightChild()); //  FIX
			longRight++;
			((Node*) nodeIn)->setRightSubTreeHeight(longRight);
		} else {
			((Node*) nodeIn)->setRightSubTreeHeight(0);
		}
	}
	

	return longLeft > longRight ? longLeft : longRight;	// short hand if statement ? if condition is met return what is after ? else return what is after :

}

void AVLTree::rebalance(NodeInterface* nodeIn) {// nodeIn is the imbalanced node

	NodeInterface* imbalancedNodeRightChild = ((Node*) nodeIn)->getRightChild();
	NodeInterface* imbalancedNodeLeftChild = ((Node*) nodeIn)->getLeftChild();


		if (((Node*) nodeIn)->getRightSubTreeHeight()
			>= ((Node*) nodeIn)->getLeftSubTreeHeight()
				&& ((Node*) imbalancedNodeRightChild)->getRightSubTreeHeight()
					>= ((Node*) imbalancedNodeRightChild)->getLeftSubTreeHeight()) { //Right Right imbalance Left Rotation
			leftRotation(nodeIn);
		setSubTreeHeights(root);
		checkHeights(root);

		}


		else if (((Node*) nodeIn)->getRightSubTreeHeight()
				> ((Node*) nodeIn)->getLeftSubTreeHeight()
				&& ((Node*) imbalancedNodeRightChild)->getLeftSubTreeHeight()
						> ((Node*) imbalancedNodeRightChild)->getRightSubTreeHeight()) { //Right Left imbalance

		rightRotation(imbalancedNodeRightChild); //right rotation on imbalanced right child
			leftRotation(nodeIn); //left rotation on imbalanced node
		setSubTreeHeights(root);
		checkHeights(root);
		}

		else if (((Node*) nodeIn)->getLeftSubTreeHeight()
			>= ((Node*) nodeIn)->getRightSubTreeHeight()
				&& ((Node*) imbalancedNodeLeftChild)->getLeftSubTreeHeight()
					>= ((Node*) imbalancedNodeLeftChild)->getRightSubTreeHeight()) { //Left Left imbalance Right Rotation

			rightRotation(nodeIn);
		setSubTreeHeights(root);
		checkHeights(root);
		}


		else //NodeIn getleftsubtreeheight>getrightsubtreeheight && imbalancednodeLeftChild getrightsubtreeheight>getleftsubtreeheight
		{ //Left Right imbalance

			leftRotation(imbalancedNodeLeftChild);
			rightRotation(nodeIn);
		setSubTreeHeights(root);
		checkHeights(root);
		}
}

bool AVLTree::addRecursion(NodeInterface* nodeIn, int dataIn) {
	curr = nodeIn;
	if (root == NULL) {
		Node* aNode = new Node(dataIn);
		root = aNode;
		
		setSubTreeHeights(root);
		checkHeights(root);
		
		return true;
	}
	if (dataIn > curr->getData()) {
		if (curr->getRightChild() == NULL) {
			Node* aNode = new Node(dataIn);
			aNode->setParent(curr);
			((Node*) curr)->setRight(aNode);
			((Node*) aNode)->setParent(curr);
			
			setSubTreeHeights(root);
			checkHeights(root);
			
			return true;
		} else { //dataIn > curr->getData() && curr->getRightChild()!=NULL
			addRecursion(curr->getRightChild(), dataIn);
		}

	} else if (dataIn < curr->getData()) {
		if (curr->getLeftChild() == NULL) {
			Node* aNode = new Node(dataIn);
			aNode->setParent(curr);
			((Node*) curr)->setLeft(aNode);
			((Node*) aNode)->setParent(curr);

			setSubTreeHeights(root);
			checkHeights(root);

			return true;
		}

		else {
			addRecursion(curr->getLeftChild(), dataIn);
		}
	} else {
		return false;
	}

}

NodeInterface * AVLTree::getInorderPredecessor(NodeInterface* nodeIn) {
	

	if (nodeIn == root && nodeIn->getLeftChild() == NULL) {
		return nodeIn;
	}
	nodeIn = nodeIn->getLeftChild();
	if (nodeIn->getRightChild() == NULL) {
		return nodeIn;
	}
	NodeInterface* rightMostNode = getRightMostChild(nodeIn);
	return rightMostNode;	//nodeIn
}

NodeInterface* AVLTree::find(int data, NodeInterface* nodeIn) {
	if (nodeIn == NULL) {
		return NULL;
	}
	//curr = root;
	if (data == nodeIn->getData()) {
		return nodeIn;
	} else if (nodeIn->getData() < data) {
		return find(data, nodeIn->getRightChild());
	} else {
		return find(data, nodeIn->getLeftChild());
	}
	}

NodeInterface* AVLTree::getRightMostChild(NodeInterface* nodeIn) {
	NodeInterface* iterator = nodeIn;
	if (iterator->getRightChild() != NULL) {
		iterator = getRightMostChild(iterator->getRightChild());

	}
	return iterator;
}





//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
NodeInterface * AVLTree::getRootNode() {
	return root;
}

/*
 * Attempts to add the given int to the AVL tree
 * ----------------------------------------------------------------------------Re-balances the tree if data is successfully added
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
bool AVLTree::add(int data) {
	return addRecursion(root, data);
}

/*
 * Attempts to remove the given int from the AVL tree
 * ---------------------------------------------------------------------------Re-balances the tree if data is successfully removed
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
bool AVLTree::remove(int data) {
	NodeInterface* removalNode = find(data, root);
	if (root == NULL || removalNode == NULL) {
		return false;
	}
	NodeInterface* removalNodeParent = ((Node*) removalNode)->getParent();
	NodeInterface* removalRightChild = removalNode->getRightChild();
	NodeInterface* removalLeftChild = removalNode->getLeftChild();

	if (removalNode->getLeftChild() == NULL
			&& removalNode->getRightChild() == NULL) { // if node to remove is a leaf or zero children SET PARENT LEFT OR RIGHT WHICH EVER SIDE IT IS DELETED FROM TO NULL


			if (removalNodeParent == NULL) {
			root = NULL;
		} else if (removalNodeParent->getLeftChild() == removalNode) {
			((Node*) removalNodeParent)->setLeft(NULL);

		} else {
			((Node*) removalNodeParent)->setRight(NULL);
		}
		delete removalNode;

		setSubTreeHeights(root); //CALL TO setSubTreeHeights
		checkHeights(root);

		return true;
		}

	//////////////////////////////////////////////////////////////////////////////////////////////////case for one child
	else if (removalNode->getLeftChild() == NULL
			|| removalNode->getRightChild() == NULL) { // case is for one child
		if (removalNode->getData()
				== root->getData() && removalRightChild == NULL) {
			NodeInterface* dummyRoot = root;
			root = dummyRoot->getLeftChild();
			((Node*) root)->setParent(NULL);
			delete dummyRoot;

			setSubTreeHeights(root); //CALL TO setSubTreeHeights
			checkHeights(root);

			return true;
		} else if (removalNode->getData()
				== root->getData() && removalLeftChild==NULL) {
			NodeInterface* dummyRoot = root;
			root = dummyRoot->getRightChild();
			((Node*) root)->setParent(NULL);
			delete dummyRoot;

			setSubTreeHeights(root); //CALL TO setSubTreeHeights
			checkHeights(root);

			return true;
			}
			else if (removalNodeParent->getData() > removalNode->getData()) {
			if (removalLeftChild == NULL) {
				((Node *) removalNodeParent)->setLeft(removalRightChild);
				((Node*) removalRightChild)->setParent(removalNodeParent);
			} else { //removalNode->getRightChild == NULL
				((Node*) removalNodeParent)->setLeft(removalLeftChild);
				((Node*) removalLeftChild)->setParent(removalNodeParent);
			}
		} else { //removalNodeParent->getData < removalNode->getData
			if (removalLeftChild == NULL) {
				((Node*) removalNodeParent)->setRight(removalRightChild);
				((Node*) removalRightChild)->setParent(removalNodeParent);
			} else { //removalRightChild==NULL
				((Node*) removalNodeParent)->setRight(removalLeftChild);
				((Node*) removalLeftChild)->setParent(removalNodeParent);
			}
			}
		delete removalNode;

		setSubTreeHeights(root); //CALL TO setSubTreeHeights
		checkHeights(root);

		return true;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////case for two children
	else {
		NodeInterface* inorderPredecessor = getInorderPredecessor(removalNode);
		NodeInterface* inorderPredecessorLeftChild =
				inorderPredecessor->getLeftChild();
		NodeInterface* inorderPredecessorParent =
				((Node*) inorderPredecessor)->getParent();
		if (removalNode->getData() == root->getData()) {
			NodeInterface* deleteRoot = root;

			if (inorderPredecessorParent
					== deleteRoot&& inorderPredecessorLeftChild == NULL) {
				//NodeInterface* inorderPredecessorRightChild =
				//inorderPredecessor->getRightChild();
				//root = inorderPredecessorRightChild;
				//((Node*) inorderPredecessorRightChild)->setParent(NULL);
				root = inorderPredecessor;
				((Node*) root)->setRight(removalRightChild);
				((Node*) removalRightChild)->setParent(root);
				((Node*) root)->setParent(NULL);

			}

			else if (inorderPredecessorLeftChild == NULL) {
				root = inorderPredecessor;
				((Node*) root)->setParent(NULL);
				//((Node*) removalNodeParent)->setLeft(inorderPredecessor);
				//((Node*) inorderPredecessor)->setParent(removalNodeParent);
				((Node*) removalLeftChild)->setParent(inorderPredecessor);
				((Node*) inorderPredecessor)->setLeft(removalLeftChild);
				((Node*) removalRightChild)->setParent(inorderPredecessor);
				((Node*) inorderPredecessor)->setRight(removalRightChild);
				((Node*) inorderPredecessorParent)->setRight(NULL);
			} else if (inorderPredecessorLeftChild != NULL
					&& inorderPredecessorParent == removalNode) {
				NodeInterface* deleteRootRightChild =
						deleteRoot->getRightChild();
				root = inorderPredecessor;
				((Node*) root)->setParent(NULL);
				((Node*) root)->setRight(deleteRoot->getRightChild());
				((Node*) deleteRootRightChild)->setParent(root);

			} else {
				root = inorderPredecessor;
				((Node*) root)->setParent(NULL);
				((Node*) removalLeftChild)->setParent(inorderPredecessor);
				((Node*) inorderPredecessor)->setLeft(removalLeftChild);
				((Node*) removalRightChild)->setParent(inorderPredecessor);
				((Node*) inorderPredecessor)->setRight(removalRightChild);
				((Node*) inorderPredecessorParent)->setRight(NULL);
				((Node*) inorderPredecessorLeftChild)->setParent(
						inorderPredecessorParent);
				((Node*) inorderPredecessorParent)->setRight(
						inorderPredecessorLeftChild);
			}
			delete deleteRoot;

			setSubTreeHeights(root); //CALL TO setSubTreeHeights
			checkHeights(root);

			return true;

			}

		//		((Node*) getInorderPredecessor)->setRight(NULL);
		//
		else {
			if (removalNodeParent->getData() > removalNode->getData()) {
				((Node*) removalNodeParent)->setLeft(inorderPredecessor);
			} else {
				((Node*) removalNodeParent)->setRight(inorderPredecessor);
			}

			((Node*) inorderPredecessor)->setParent(removalNodeParent);
			((Node*) removalRightChild)->setParent(inorderPredecessor);
			((Node*) inorderPredecessor)->setRight(removalRightChild);



				if (removalLeftChild->getData()
						!= inorderPredecessor->getData()) {
				((Node*) removalLeftChild)->setParent(inorderPredecessor);
				((Node*) inorderPredecessor)->setLeft(removalLeftChild);
				((Node*) inorderPredecessorParent)->setRight(NULL);
				}
				if (inorderPredecessorLeftChild != NULL) {
					((Node*) inorderPredecessorLeftChild)->setParent(
							inorderPredecessorParent);
					((Node*) inorderPredecessorParent)->setRight(
							inorderPredecessorLeftChild);
				}

		}

		delete removalNode;

		setSubTreeHeights(root); //CALL TO setSubTreeHeights
		checkHeights(root);

		return true;
	}
	return false;
	}

} /* namespace std */
