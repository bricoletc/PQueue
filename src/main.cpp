#include "HeapPriorityQueue.h"
using namespace std;

int main(){
	HeapPriorityQueue test;
	string c="Test";
	int priority=2;
	test.enqueue(c,priority);

	cout << test << endl;
	c="Higher";
	priority=1;
	test.enqueue(c,priority);

	cout << test << endl;
}
