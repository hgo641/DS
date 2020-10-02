// Project3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

class arrayvector {
private:
	int capacity;
	int n;
	int* a;
public:
	arrayvector(int size);
	int size();
	bool empty();
	int& operator[](int i);
	int at(int i);
	void erase(int i);
	void insert(int i, const int& e);
	void reserve(int N);
};
arrayvector::arrayvector(int size) {
	this->capacity = size;
	this->n = 0;
	this->a = new int[size];
}
void arrayvector::reserve(int N) {
	if (capacity >= N) return;
	int* b = new int[N];
	for (int j = 0; j < n; j++)
		b[j] = a[j];
	if (a != NULL)delete[] a;
	a = b;
	capacity = N;
}
void arrayvector::insert(int i, const int& e) {
	if (capacity <= n) {
		reserve(max(1, 2 * capacity));
	}
	for (int j = n - 1; j >= i; j--)
		a[j + 1] = a[j];
	a[i] = e;
	n++;
}
void arrayvector::erase(int i) {
	for (int j = i + 1; j < n; j++)
		a[j - 1] = a[j];
	n--;
}
int arrayvector::at(int i) {
	if (i < 0 or i >= n)
		return a[i];
}
int arrayvector::size()
{
	return n;
}
bool arrayvector::empty() {
	return size() == 0;
}
int& arrayvector::operator[](int i) { return a[i]; }
int main()
{

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
