#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include "Common.h"
#include "Setting.h"

class node {
public:
	node* left;
	node* right;
	Setting* data;
	node() {
		left = NULL;
		right = NULL;
	}
};

class binaryTree {
public:
	binaryTree();
	~binaryTree();

	int checkExist(node* pNode, Setting* input); // kiểm tra xe đã tồn tại hay chưa
	node* insertKeyTree(node* pNode, Setting* input); // thêm vào cây nhị phân xếp theo Key
	node* insertNameTree(node* pNode, Setting* input); // thêm vào cây nhị phân xếp theo Name
	void replaceData(node* pNode, Setting* input, string type); // thay thế data khi node đã tồn tại
	void writeNodeInfo(node* pNode); // ghi cây nhị phân vào file Setting.txt
	
	int countNumNode(node* pNode); // đếm tổng số xe
	
	void showNodeInfor(node* pNode, string type); // show info xe
	void searchNode(node* pNode, string type, string data, bool* exist); // in ra setting khi search bằng key hoặc name
	void coutSerial(bool reset = false); // in STT của xe khi Show All Infor, STT về lại 1 khi biến reset = true

private:
	int serial = 1;
};
#endif /* BINARYTREE_H_ */

