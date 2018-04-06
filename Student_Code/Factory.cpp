#include "Factory.h"
#include "iostream"
//You may add #include statements here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getAVL()

	Creates and returns an object whose class extends AVLInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "AVL", you might say, "return new AVL();".
*/
AVLInterface * Factory::getAVL()
{
	return new AVLTree; //Modify this line
}
//int main() {
//	AVLTree myTree;
////	myTree.add(0);
////	myTree.add(-1);
////	myTree.add(-2);
////	myTree.add(-3);
////
////	myTree.add(-4);
////	myTree.add(-5);
////	myTree.add(-6);
////	myTree.add(-7);
////	myTree.add(-8);
////	myTree.add(-9);
////	myTree.add(-10);
////
////	//add again
////	myTree.add(-11);
////	myTree.add(-12);
////	myTree.add(-13);
////	myTree.add(-14);
////
////	myTree.add(-15);
////	myTree.add(-16);
////	myTree.add(-17);
////	myTree.add(-18);
////	myTree.add(-19);
////	myTree.add(-20);
////	myTree.add(-21);
////
////	myTree.add(-22);
////	myTree.add(-23);
////	myTree.add(-24);
////	myTree.add(-25);
////
////	myTree.add(-26);
////	myTree.add(-27);
////	myTree.add(-28);
////	myTree.add(-29);
////	myTree.add(-30);
////	myTree.add(-31);
////	myTree.add(-32);
////
////	//remove again
////	myTree.add(-33);
////	myTree.add(-34);
////	myTree.add(-35);
////	myTree.add(-36);
////
////	myTree.add(-37);
////	myTree.add(-38);
////	myTree.add(-39);
////	myTree.add(-40);
////
////	myTree.add(-41);
////	myTree.add(-42);
////	myTree.add(-43);
////	myTree.add(-44);
////	myTree.add(-45);
////	myTree.add(-46);
////	myTree.add(-47);
////	myTree.add(-48);
////	myTree.add(-49);
////
////	//add again
////	myTree.add(-50);
//////	myTree.add(-51);
//////	myTree.add(-52);
////
////	//remove 0--50
////	myTree.remove(0);
////	myTree.remove(-1);
////	myTree.remove(-2);
////	myTree.remove(-3);
////
////	myTree.remove(-4);
////	myTree.remove(-5);
////	myTree.remove(-6);
////	myTree.remove(-7);
////	myTree.remove(-8);
////	myTree.remove(-9);
////	myTree.remove(-10);
////
////	//add again
////	myTree.remove(-11);
////	myTree.remove(-12);
////	myTree.remove(-13);
////	myTree.remove(-14);
////
////	myTree.remove(-15);
////	myTree.remove(-16);
////	myTree.remove(-17);
////	myTree.remove(-18);
////	myTree.remove(-19);
////	myTree.remove(-20);
////	myTree.remove(-21);
////
////	myTree.remove(-22);
////	myTree.remove(-23);
////	myTree.remove(-24);
////	myTree.remove(-25);
////
////	myTree.remove(-26);
////	myTree.remove(-27);
////	myTree.remove(-28);
////	myTree.remove(-29);
////	myTree.remove(-30);
////	myTree.remove(-31);
////	myTree.remove(-32);
////
////	//remove again
////	myTree.remove(-33);
////	myTree.remove(-34);
////	myTree.remove(-35);
////	myTree.remove(-36);
////
////	myTree.remove(-37);
////	myTree.remove(-38);
////	myTree.remove(-39);
////	myTree.remove(-40);
////
////	myTree.remove(-41);
////	myTree.remove(-42);
////	myTree.remove(-43);
////	myTree.remove(-44);
////	myTree.remove(-45);
////	myTree.remove(-46);
////	myTree.remove(-47);
////
////	//add again
////	myTree.remove(-50);
////
//
//// ADD POSITIVE
//
//	myTree.add(0);
//	myTree.add(1);
//	myTree.add(2);
//	myTree.add(3);
//
//	myTree.add(4);
//	myTree.add(5);
//	myTree.add(6);
//	myTree.add(7);
//	myTree.add(8);
//	myTree.add(9);
//	myTree.add(10);
//
//	//add again
//	myTree.add(11);
//	myTree.add(12);
//	myTree.add(13);
//	myTree.add(14);
//
//	myTree.add(15);
//	myTree.add(16);
//	myTree.add(17);
//	myTree.add(18);
//	myTree.add(19);
//	myTree.add(20);
//	myTree.add(21);
//
//	myTree.add(22);
//	myTree.add(23);
//	myTree.add(24);
//	myTree.add(25);
//
//	myTree.add(26);
//	myTree.add(27);
//	myTree.add(28);
//	myTree.add(29);
//	myTree.add(30);
//	myTree.add(31);
//	myTree.add(32);
//
//	//remove again
//	myTree.add(33);
//	myTree.add(34);
//	myTree.add(35);
//	myTree.add(36);
//
//	myTree.add(37);
//	myTree.add(38);
//	myTree.add(39);
//	myTree.add(40);
//
//	myTree.add(41);
//	myTree.add(42);
//	myTree.add(43);
//	myTree.add(44);
//	myTree.add(45);
//	myTree.add(46);
//	myTree.add(47);
//	myTree.add(48);
//	myTree.add(49);
//
//	//add again
//	myTree.add(50);
//
////REMOVE REVERSE
//
//	myTree.remove(50);
//	myTree.remove(48);
//	myTree.remove(49);
//	myTree.remove(47);
//
//	myTree.remove(46);
//	myTree.remove(45);
//	myTree.remove(44);
//	myTree.remove(43);
//	myTree.remove(42);
//	myTree.remove(41);
//	myTree.remove(40);
//
//	//add again
//	myTree.remove(39);
//	myTree.remove(38);
//	myTree.remove(37);
//	myTree.remove(36);
//
//	myTree.remove(35);
//	myTree.remove(34);
//	myTree.remove(33);
//	myTree.remove(32);
//	myTree.remove(31);
//	myTree.remove(30);
//	myTree.remove(29);
//
//	myTree.remove(28);
//	myTree.remove(27);
//	myTree.remove(26);
//	myTree.remove(25);
//
//	myTree.remove(24);
//	myTree.remove(23);
//	myTree.remove(22);
//	myTree.remove(21);
//	myTree.remove(20);
//	myTree.remove(19);
//	myTree.remove(18);
//
//	//remove again
//	myTree.remove(17);
//	myTree.remove(16);
//	myTree.remove(15);
//	myTree.remove(14);
//
//	myTree.remove(13);
//	myTree.remove(12);
//	myTree.remove(11);
//	myTree.remove(10);
//
//	myTree.remove(9);
//	myTree.remove(8);
//	myTree.remove(7);
//	myTree.remove(6);
//	myTree.remove(5);
//	myTree.remove(4);
//	myTree.remove(3);
//
//	//add again
//	myTree.remove(2);
//	myTree.remove(1);
//	myTree.remove(0);
//
//	cout << "done";
//}
