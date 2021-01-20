
#ifdef ARRAY_BASED_QUEUE

#define maxQueue 100
typedef int queueEntry;

typedef struct Queue
{
    queueEntry entry[maxQueue];
    int front,rear,size;
} queue;

void createQueue(queue* pq);

bool full(queue* pq);

void enqueue(queueEntry value, queue* pq);

bool empty(queue* pq);

queueEntry dequeue(queue* pq);

void displayQueue(queue* pq);

int queueSize(queue* pq);

void clearQueue(queue* pq);


#else

typedef int queueEntry;

struct queueNode
{
    queueEntry data;
    queueNode* next;
};
struct queue
{
    queueNode* front;
    queueNode* rear;
    int size;
};
void createQueue(queue* pq);

bool empty(queue* pq);

bool full(queue* pq);

void enqueue(queueEntry value, queue* pq);

queueEntry dequeue(queue* pq);

void displayQueue(queue* pq);

void clearQueue(queue* pq);

int queueSize(queue* pq);

#endif