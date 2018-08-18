// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "HeapPriorityQueue.h"
#include <cmath>

HeapPriorityQueue::HeapPriorityQueue(int binSize) {
	this->binSize = binSize;
	this->fillPoint = 0;
	this->binHeap = new PQEntry[binSize];

}

HeapPriorityQueue::~HeapPriorityQueue() {

}

void HeapPriorityQueue::changePriority(string value, int newPriority) {

	for (int i=1;i<=this->fillPoint;i++){
		if (this->binHeap[i-1].value==value){
			this->binHeap[i-1].priority=newPriority;
			break;
		}
	}
}

void HeapPriorityQueue::clear() {
    // TODO: implement

}

string HeapPriorityQueue::dequeue() {
    // TODO: implement
    return "";   // remove this
}

void HeapPriorityQueue::enqueue(string value, int priority) {
	binHeap[fillPoint++]=PQEntry(value, priority);
	//If we've reached binHeap capacity, create a new binHeap, copying the old elements into it.
	if (fillPoint==this->binSize){
		PQEntry* new_binHeap=new PQEntry[this->binSize*2]; 
		for (int i=1;i<=this->fillPoint;i++){
			new_binHeap[i-1]=this->binHeap[i-1];
		}
		delete[] this->binHeap;
		this->binHeap = new_binHeap;
	}

	//Bubble up
	int curPos=this->fillPoint;
	while (curPos>1){	
		int parentPos=floor(curPos/2);
		if (this->binHeap[curPos-1].priority>=this->binHeap[parentPos-1].priority) break; //Priority ordering is respected, done bubbling.
		PQEntry tmp_ptr=this->binHeap[curPos-1];
		this->binHeap[curPos-1]=this->binHeap[parentPos-1];
		this->binHeap[parentPos-1]=tmp_ptr;
	}	 


}

bool HeapPriorityQueue::isEmpty() const {
    // TODO: implement
    return false;   // remove this
}

string HeapPriorityQueue::peek() const {
    // TODO: implement
    return "";   // remove this
}

int HeapPriorityQueue::peekPriority() const {
    // TODO: implement
    return 0;   // remove this
}

int HeapPriorityQueue::size() const {
    // TODO: implement
    return 0;   // remove this
}

ostream& operator<<(ostream& out, const HeapPriorityQueue& queue) {
	out << "{";
	for (int i=1;i<=queue.fillPoint;i++){
		out << queue.binHeap[i-1] ;
	}
	out << "}";
    return out;
}
