// Project10.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* par;
	vector<Node*> chi_v;

	Node(int data) {
		this->data = data;
		this->par = NULL;
	}
	~Node() {}

	void setParent(Node* parent) {
		this->par = parent;
	}

	void insertChild(Node* child) {
		this->chi_v.push_back(child);
	}
	void deChild(Node* child) {
		for (unsigned i = 0; i < this->chi_v.size(); i++) {
			if (this->chi_v[i] == child) {
				this->chi_v.erase(this->chi_v.begin() + i);
			}
		}
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> node_list;

	Tree(int);
	~Tree() {};
	int size();
	void insertNode(int, int);
	//void delNode(int);
	//void printChi(int);
	//void printSib(int);
	void preorder(Node*);
	/*void print() {
		for (int i = 0; i++; i < node_list.size()) {
			cout << node_list[i] << " ";
		};
	};*/
};
void Tree::preorder(Node* node) {
	
	if (!node) return;
	cout << node->data << " ";
	for (int i = 0; i < node->chi_v.size(); i++) {
		preorder(node->chi_v[i]);
	}

}
int Tree::size() {
	return node_list.size();
}
Tree::Tree(int data) {
	Node* node = new Node(data);
	root = node;
	node_list.push_back(node);
}
void Tree::insertNode(int par_data, int data) {
	for (int i = 0; i < size(); i++) {
		if (node_list[i]->data == par_data) {
			Node* node = new Node(data);
			node->setParent(node_list[i]);
			node_list[i]->insertChild(node);
			node_list.push_back(node);
			return;
		}
	}
}
/*
void Tree::delNode(int data) {
	Node* nownode;
	Node* par;
	for (int i = 0; i < this->node_list.size(); i++) {
		if (this->node_list[i]->data == data) {
			nownode = node_list[i];
			if (nownode == root) {
				return;
			}
			par = nownode->par;
			for (Node*& child : nownode->chi_v) {
				par->insertChild(child);
				child->par = par;
			}
			par->deleteChild(nownode);
			this->node_list.erase(this->node_list.begin() + i);
			delete nownode;
		}
	}
	return;
}
void Tree::printChi(int data) {
	for (int i = 0; i < size(); i++) {
		if (node_list[i]->data == data) {
			if (node_list[i]->chi_v.size() == 0) {
				cout << "0" << endl;
				return;
			}
			for (int j = 0; j < node_list[i]->chi_v.size(); j++) {
				cout << node_list[i]->chi_v[j]->data << " ";
			}
			cout << endl;
			return;
		}
	}
}
void Tree::printSib(int data) {
	for (int i = 0; i < size(); i++) {
		if (node_list[i]->data == data) {
			if (node_list[i]->par == NULL) cout << data << endl;
			else {
				Node* par_node = node_list[i]->par;
				for (int j = 0; j < par_node->chi_v.size(); j++) {
					cout << par_node->chi_v[j]->data << " ";
				}
				cout << endl;
				return;
			}-

		}
	}
	cout << 0 << endl;
}
*/
int main()
{
	int count;
	cin >> count;
	Tree T(1);
	while (count > 0) {
		int par_data;
		int data;
		cin >> par_data >> data;
		T.insertNode(par_data, data);
		count--;
	}
	T.preorder(T.root);
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
