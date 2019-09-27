#include <iostream>
#include "QueueLinked.cpp"

using namespace std;

int main(){

	QueueLinked <int> testQueue;
	int length = testQueue.getLength();
	cout << length << endl;
	
	int A=1, B=2, C=3, D=4, E=5, F=6;
	testQueue.enqueue(A);
	testQueue.enqueue(B);
	testQueue.enqueue(C);
	testQueue.enqueue(D);
	testQueue.enqueue(E);
	testQueue.enqueue(F);

	length = testQueue.getLength();
	cout << length << endl;
	testQueue.showStructure();	


	QueueLinked <int> copyQueue(testQueue);
	copyQueue.showStructure();
	copyQueue.dequeue();
	copyQueue.showStructure();


	testQueue.showStructure();
	testQueue = copyQueue;
	testQueue.showStructure();	

return 0;
}
