#pragma once
//M
//MoloZzz

#include"complexInt.h"



#include<iostream>

using namespace std;


class RBTnode {
public:
	Complex data;

	bool color; // 0 - black, 1 - red

	RBTnode* right;

	RBTnode* left;
	
	RBTnode(Complex data) {
		this->data = data;
		this->color = 0;
		this->right = nullptr;
		this->left = nullptr;
	}

	RBTnode(Complex data,bool color) {
		this->data = data;
		this->color = color;
		this->right = nullptr;
		this->left = nullptr;
	}

};

class RBT {
public:
	RBTnode* root = nullptr;

	void insert(Complex newData) {

	RBTnode newNode(newData,1);	
		

		if (root == nullptr) {
			newNode.color = 0;
			root = &newNode;
			return;
		}

		RBTnode* curr = root;

		while (true) {

		if (newData < curr->data) {
			if (curr->left == nullptr) {
				curr->left = &newNode;
				return;
			}
			else {
				curr = curr->left;
			}
		}
		else {
			if (curr->right == nullptr) {
				curr->right = &newNode;
				return;
			}
			else {
				curr = curr->right;
			}
		}
		}


	}

	void rotateLeft();

	void rotateRight();


	void print(RBTnode *currNode) {
		if (root == nullptr) {
			cout << "empty" << endl;
			return;
		}


		if (currNode->color == 1) {
			cout << currNode->data.getString() << "(red)" << endl;
		}
		else {
			cout << currNode->data.getString() << "(black)" << endl;
		}


		if (currNode->left != nullptr) {
			
			/*cout << "Left of " << currNode->data.getString() << endl;*/
			/*cout << "left ";*/

			print(currNode->left);
		}
		
		if (currNode->right != nullptr) {

			/*cout << "Right of " << currNode->data.getString() << endl;*/
			/*cout << "right ";*/
			print(currNode->right);
		}
		
		
	}
};

