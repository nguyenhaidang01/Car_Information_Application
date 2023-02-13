#include "binaryTree.h"

binaryTree::binaryTree() {
  
}

binaryTree::~binaryTree() {

}

node* binaryTree::insertKeyTree(node* pNode, Setting* input) {
	if (pNode == NULL) {
		node* temp = new node;
		temp->data = input;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else {
		if (stoi(input->getPersonalKey()) < stoi(pNode->data->getPersonalKey())) {
			pNode->left = insertKeyTree(pNode->left, input);
			return pNode;
		}
		else {
			pNode->right = insertKeyTree(pNode->right, input);
			return pNode;
		}
	}
}

node* binaryTree::insertNameTree(node* pNode, Setting* input) {
	if (pNode == NULL) {
		node* temp = new node;
		temp->data = input;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else {
		if (input->getCarName()[0] < pNode->data->getCarName()[0]) {
			pNode->left = insertNameTree(pNode->left, input);
			return pNode;
		}
		else {
			pNode->right = insertNameTree(pNode->right, input);
			return pNode;
		}
	}
}

int binaryTree::checkExist(node* pNode, Setting* input) {
	if (pNode == NULL) return 0;
	if (pNode->data->getPersonalKey() == input->getPersonalKey()) return 1 + checkExist(pNode->left, input) + checkExist(pNode->right, input);
	else if (pNode->data < input) return  checkExist(pNode->right, input);
	return  checkExist(pNode->left, input);
}

void binaryTree::replaceData(node* pNode, Setting* input, string type) {
	if (pNode != NULL) {
		replaceData(pNode->left, input, type);
		if (pNode->data->getPersonalKey() == input->getPersonalKey()) {
			pNode->data->setCarName(input->getCarName());
			pNode->data->setEmail(input->getEmail());
			pNode->data->setODO(input->getODO());
			pNode->data->setServiceRemind(input->getServiceRemind());
			if (type == "Display") {
				pNode->data->getDisplay()->set_light_level(input->getDisplay()->get_light_level());
				pNode->data->getDisplay()->set_screen_light_level(input->getDisplay()->get_screen_light_level());
				pNode->data->getDisplay()->set_taplo_light_level(input->getDisplay()->get_taplo_light_level());
			}
			if (type == "Sound") {
				pNode->data->getSound()->set_call_level(input->getSound()->get_call_level());
				pNode->data->getSound()->set_media_level(input->getSound()->get_media_level());
				pNode->data->getSound()->set_navi_level(input->getSound()->get_navi_level());
				pNode->data->getSound()->set_notification_level(input->getSound()->get_notification_level());
			}
			if (type == "General") {
				pNode->data->getGeneral()->setTimezone(input->getGeneral()->getTimezone());
				pNode->data->getGeneral()->setLanguage(input->getGeneral()->getLanguage());
			}
		}
		replaceData(pNode->right, input, type);
	}
}

void binaryTree::writeNodeInfo(node* pNode) {
	ofstream fileOut("Setting.txt", ios::app);
	try {
		if (fileOut.is_open()) {
			if (pNode != NULL) {
				writeNodeInfo(pNode->left);
				fileOut << "Common: " << pNode->data->getCarName() << "," << pNode->data->getEmail() << ","
					<< pNode->data->getPersonalKey() << "," << pNode->data->getODO() << "," << pNode->data->getServiceRemind() << " "

					<< "Display: " << pNode->data->getDisplay()->get_light_level() << ","
					<< pNode->data->getDisplay()->get_screen_light_level() << "," << pNode->data->getDisplay()->get_taplo_light_level() << ";"

					<< "Sound: " << pNode->data->getSound()->get_call_level() << "," << pNode->data->getSound()->get_media_level() << ","
					<< pNode->data->getSound()->get_navi_level() << "," << pNode->data->getSound()->get_notification_level() << ";"

					<< "General: " << pNode->data->getGeneral()->getTimezone() << "," << pNode->data->getGeneral()->getLanguage() << ";" << endl;
				writeNodeInfo(pNode->right);
			}
			fileOut.close();
		}
		else {
			throw exception();
		}
	}
	catch (...) {
		cout << "Loi ghi file!" << endl;
	}	
}

int binaryTree::countNumNode(node* pNode) {
	if (pNode == NULL) return 0;
	else return 1 + countNumNode(pNode->left) + countNumNode(pNode->right);
}

void  binaryTree::searchNode(node* pNode, string type, string data, bool* infoExist) {
	if (pNode != NULL) {
		searchNode(pNode->left, type, data, infoExist);
		if ((type == "Name" && pNode->data->getCarName() == data)||(type == "Key" && stoi(pNode->data->getPersonalKey()) == stoi(data))) {
			*infoExist = true;
			cout << left << setw(3);
			coutSerial();
			cout << left << setw(25) << "Owner Name" << left << setw(20) << "Email" << left << setw(13) << "Key number" << left << setw(13) << "ODO number" << left << setw(19) << "Remind service (km)" << endl;
			cout << left << setw(3) << "" << left << setw(25) << pNode->data->getCarName() << left << setw(20) << pNode->data->getEmail() << left << setw(13) << pNode->data->getPersonalKey() << left << setw(13) << pNode->data->getODO() << left << setw(19) << pNode->data->getServiceRemind() << endl;
			cout << left << setw(3) << "" << left << setw(13) << "Display:" << left << setw(8) << "Light" << left << setw(15) << "Screen light" << left << setw(14) << "Taplo light" << endl;
			cout << left << setw(3) << "" << left << setw(13) << "" << left << setw(8) << pNode->data->getDisplay()->get_light_level() << left << setw(15) << pNode->data->getDisplay()->get_screen_light_level() << left << setw(14) << pNode->data->getDisplay()->get_taplo_light_level() << endl;
			cout << left << setw(3) << "" << left << setw(13) << "Sound:" << left << setw(8) << "Media" << left << setw(8) << "Call" << left << setw(13) << "Navigation" << left << setw(15) << "Notification" << endl;
			cout << left << setw(3) << "" << left << setw(13) << "" << left << setw(8) << pNode->data->getSound()->get_media_level() << left << setw(8) << pNode->data->getSound()->get_call_level() << left << setw(13) << pNode->data->getSound()->get_navi_level() << left << setw(15) << pNode->data->getSound()->get_notification_level() << endl;
			cout << left << setw(3) << "" << left << setw(13) << "General:" << left << setw(12) << "Timezone" << left << setw(15) << "Language" << endl;
			cout << left << setw(3) << "" << left << setw(13) << "" << left << setw(12) << pNode->data->getGeneral()->getTimezone() << left << setw(15) << pNode->data->getGeneral()->getLanguage() << endl;
		}
		searchNode(pNode->right, type, data, infoExist);
	}
}

void binaryTree::coutSerial(bool reset) {
	if (!reset) {
		cout << serial;
		serial++;
	}
	else {
		serial = 1;
	}
}

void binaryTree::showNodeInfor(node* pNode, string type) {
	if (pNode != NULL) {
		showNodeInfor(pNode->left, type);
		if (type == "All") {
			cout << left << setw(3);
			coutSerial();
			cout << left << setw(25) << "Owner Name" << left << setw(20) << "Email" << left << setw(13) << "Key number" << left << setw(13) << "ODO number" << left << setw(19) << "Remind service (km)" << endl;
			cout << left << setw(3) << "" << left << setw(25) << pNode->data->getCarName() << left << setw(20) << pNode->data->getEmail() << left << setw(13) << pNode->data->getPersonalKey() << left << setw(13) << pNode->data->getODO() << left << setw(19) << pNode->data->getServiceRemind() << endl;
			cout << left << setw(3) << "" << left << setw(13) << "Display:" << left << setw(8) << "Light" << left << setw(15) << "Screen light" << left << setw(14) << "Taplo light" << endl;
			cout << left << setw(3) << "" << left << setw(13) << "" << left << setw(8) << pNode->data->getDisplay()->get_light_level() << left << setw(15) << pNode->data->getDisplay()->get_screen_light_level() << left << setw(14) << pNode->data->getDisplay()->get_taplo_light_level() << endl;
			cout << left << setw(3) << "" << left << setw(13) << "Sound:" << left << setw(8) << "Media" << left << setw(8) << "Call" << left << setw(13) << "Navigation" << left << setw(15) << "Notification" << endl;
			cout << left << setw(3) << "" << left << setw(13) << "" << left << setw(8) << pNode->data->getSound()->get_media_level() << left << setw(8) << pNode->data->getSound()->get_call_level() << left << setw(13) << pNode->data->getSound()->get_navi_level() << left << setw(15) << pNode->data->getSound()->get_notification_level() << endl;
			cout << left << setw(3) << "" << left << setw(13) << "General:" << left << setw(12) << "Timezone" << left << setw(15) << "Language" << endl;
			cout << left << setw(3) << "" << left << setw(13) << "" << left << setw(12) << pNode->data->getGeneral()->getTimezone() << left << setw(15) << pNode->data->getGeneral()->getLanguage() << endl;
		}
		else {
			cout << left << setw(25) << pNode->data->getCarName() << left << setw(20) << pNode->data->getEmail() << left << setw(12) << pNode->data->getPersonalKey()
				<< left << setw(10) << pNode->data->getODO() << left << setw(10) << pNode->data->getServiceRemind() << left;
			if (type == "Display") {
				cout << setw(10) << pNode->data->getDisplay()->get_light_level() << left << setw(10) << pNode->data->getDisplay()->get_screen_light_level()
					<< left << setw(10) << pNode->data->getDisplay()->get_taplo_light_level() << endl;
			}
			if (type == "Sound") {
				cout << setw(10) << pNode->data->getSound()->get_media_level() << left << setw(10) << pNode->data->getSound()->get_call_level()
					<< left << setw(10) << pNode->data->getSound()->get_navi_level() << left << setw(10) << pNode->data->getSound()->get_notification_level() << endl;
			}
			if (type == "General") {
				cout << setw(15) << pNode->data->getGeneral()->getTimezone() << left << setw(15) << pNode->data->getGeneral()->getLanguage() << endl;
			}
		}		
		showNodeInfor(pNode->right, type);
	}
}
