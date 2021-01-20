#ifdef ARRAY_BASED_QUEUE

#include "../include/queue.h"

void createQueue(queue* pq)
{
    pq->front= 0;
    pq->rear = -1;
    pq->size = 0;
}
bool full(queue* pq)
{
    return (pq->size == maxQueue);
//    if(pq->size == maxQueue)
//        return true;
//    return false;
}
void enqueue(queueEntry value,  queue* pq)
{
    if(!full(pq))
    {
        pq->entry[(++pq->rear)%maxQueue] = value;
        pq->size++;
    }
}
bool empty(queue* pq)
{
    return !pq->size;
   //if(pq->size == 0)
   //    return true;
   // return false;
}
queueEntry dequeue(queue* pq)
{
    if(!empty(pq))
    {
        pq->size--;
        return pq->entry[(pq->front++)%maxQueue];
    }
}
void displayQueue(queue* pq)
{
    int p1 = pq->front;
    int p2 = pq->rear+1;
    while(p1 != p2)
    {
        cout << pq->entry[(p1++)%maxQueue] << " ";
    }
    cout << '\n';
}
int queueSize(queue* pq)
{
    return pq->size;
}
void clearQueue(queue* pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

#else

#include "../include/queue.h"

void createQueue(queue* pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

bool empty(queue* pq)
{
    return !(pq->front);
}

bool full(queue* pq)
{
    return false;
}

void enqueue(queueEntry value, queue* pq)
{
    queueNode* newnode = new(nothrow)queueNode;
        newnode->data = value;
        newnode->next = NULL;
        if(!pq->rear)
            pq->front = newnode;
        else
            pq->rear->next = newnode;
        pq->rear = newnode;
        pq->size++;
}

queueEntry dequeue(queue* pq)
{
    if(!empty(pq))
    {
        queueNode* pn = pq->front;
        pq->front = pq->front->next;
        if(!pq->front)
            pq->rear = NULL;
        pq->size--;
        queueEntry element = pn->data;
        delete pn;
        return element;
    }
}

void displayQueue(queue* pq)
{
    if(!empty(pq))
    {
        queueNode* pn = pq->front;
        while(pn)
        {
            cout << pn->data << " ";
            pn = pn->next;
        }
        cout << '\n';
    }
}

void clearQueue(queue* pq)
{
    while(pq->front)
    {
        pq->rear = pq->front->next;
        delete pq->front;
        pq->front = pq->rear;
    }
    pq->size = 0;
}

int queueSize(queue* pq)
{
    return pq->size;
}

#endif