// Project4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
using namespace std;
class sequencelist {
private:
	struct node {
		int e;
		node* prev;
		node* next;
	};
public:
	class iterator {
	private:
		node* v;
		iterator(node* u);
	public:
		int& operator*();
		bool operator==(const iterator& p) const;
		bool operator!=(const iterator& p) const;
		iterator& operator++();
		iterator& operator--();
		friend class sequencelist;
	};
private:
	int n;
	node* header;
	node* trailer;
public:
	sequencelist();
	int size() const;
	bool empty() const;
	iterator begin() const;
	iterator end() const;
	void insertfront(const int& e);
	void insertback(const int& e);
	void insert(const iterator& p, const int& e);
	void erasefront();
	void eraseback();
	void erase(const iterator& p);
	iterator atindex(int i) const;
	int indexof(const iterator& p) const;
};
sequencelist::sequencelist() {
	n = 0;
	header = new node;
	trailer = new node;
	header->next = trailer;
	trailer->prev = header;
}
void sequencelist::insert(const sequencelist::iterator& p, const int& e)
{
	node* w = p.v;
	node* u = w->prev;
	node* v = new node;
	v->e = e;
	v->next = w; w->prev = v;
	v->prev = u; u->next = v;
	this->n++;
}
void sequencelist::insertfront(const int& e) {
	insert(begin(), e);
}
void sequencelist::insertback(const int& e) {
	insert(end(), e);
}
void sequencelist::erase(const iterator& p) {
	node* v = p.v;
	node* w = v->next;
	node* u = v->prev;
	u->next = w; w->prev = u;
	delete v;
	this->n--;
}
void sequencelist::erasefront() {
	erase(begin());
}
void sequencelist::eraseback() {
	erase(--end());
}
int sequencelist::size()const {
	return n;
}
bool sequencelist::empty()const {
	return (n == 0);
}
sequencelist::iterator::iterator(node* u) {
	v = u;
}
sequencelist::iterator sequencelist::begin() const {
	return iterator(header->next);
}
sequencelist::iterator sequencelist::end() const {
	return iterator(trailer);
}
int& sequencelist::iterator::operator*() {
	return v->e;
}
bool sequencelist::iterator::operator==(const iterator& p) const {
	return v == p.v;
}
bool sequencelist::iterator::operator!=(const iterator& p) const {
	return v != p.v;
}
sequencelist::iterator& sequencelist::iterator::operator++() {
	v = v->next;
	return *this;
}
sequencelist::iterator& sequencelist::iterator::operator--() {
	v = v->prev;
	return *this;
}
sequencelist::iterator sequencelist::atindex(int i) const {
	iterator p = begin();
	for (int j = 0; j < i; j++) {
		++p;
	}
	return p;
}
int sequencelist::indexof(const iterator& p) const {
	iterator q = begin();
	int j = 0;
	while (q != p) {
		++q;
		++j;
	}
	return j;
}

int main(){
	sequencelist arr;
	arr();
	int t;
	cin >> t;
	string command;
	while (t > 0) {
		getline(cin, command);
		if (command == "insert") {
			int i;
			cin >> i;
			arr.insert(i);
		}
		else if (command == "erase") {
			arr.erase();
		}
		else if (command == "begin") {
			arr.begin();
		}
		else if (command == "end") {
			arr.end();
		}
		else if (command == "++") {
			
		}
		else if (command == "--") {

		}
		else if (command == "print") {
			arr.print();
		}
		else if (command == "size") {
			arr size();
		}
		t--;
	}
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
