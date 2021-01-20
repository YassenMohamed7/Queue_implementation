#include <iostream>

using namespace std;

#define ARRAY_BASED_QUEUE
#include  "queue.cpp"


int main()
{
	queue q;
	createQueue(&q);
	if(!full(&q)){
		enqueue(4, &q);
		enqueue(5, &q);
	}
	displayQueue(&q);

    return 0;
}
