#include "HeapPriorityQueue.h"
using namespace std;

int main(){
	HeapPriorityQueue test;
	string c="Test";
	int priority=4;
	test.enqueue(c,priority);

	c="Higher";
	priority=1;
	test.enqueue(c,priority);

	c="Less_High";
	priority=2;
	test.enqueue(c,priority);


	c="Lol";
	priority=5;
	test.enqueue(c,priority);

	cout << test << endl;

	string dequeued=test.dequeue();
	cout << test << endl;

	test.clear();
	cout << test << endl;
}
