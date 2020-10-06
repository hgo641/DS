// Project3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

class array {
public:
	int arr_size = 10000;
	float* arr;
	array() {
		srand(9999);
		this->arr = new float[10000];
		for (int i = 0; i < 10000; i++) {
			arr[i] = rand() % 30000;
		}
	}

	
	int at(int idx) {};
	void set(int idx, int value) {};
	void delete(int idx) {};
	void reserve(int N) {};
};

class node {
public:
	int data;
	node* next;
	node(int data) {
		this->data = data;
		this->next = NULL;
	}
};
class s_linkedlist{
public:
	node* head;
	node* tail;
	s_linkedlist() {
		head = NULL;
		tail = NULL;
	}
	int empty() {
		if (head == NULL && tail == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int list_size() {
		int list_size = 1;
		node* cur_node;
		cur_node = head;
		if (empty()) {
			return 0;
		}
		else {

		}
	}
	int print() {
		node* cur_node = head;
		if (empty()) {
			return -1;
		}
		else {

		}
	}
	void append(int data) {
		if (empty()) {

		}
		else {

		}
	}
	int delete_node(int idx) {
		if (empty() or list_size() < idx) {
			return -1;
		}
		else if (idx == 0) {

		}
		else {

		}
	}
	void insert(int idx, int data) {
		if (idx == 0) {
			if (empty()) {
				head = new_node;
				tail = new_node;
			}
			else {

			}
		}
		else if (idx <0 or idx>list_size()) {
			return;
		}
		elef if (idx == list_size()) {
			append(data);
		}
		else {

		}
		print();
	}
};
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
