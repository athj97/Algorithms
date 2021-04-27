#include <iostream>
#include "queue.h"
using namespace std;//Easier typing

//Did not make any changes to the given code, except for reoving std::
//added a few functions

struct Queue* make_queue()
{
  Queue *queue = new(struct Queue);
  queue -> back = nullptr;
  queue -> front = nullptr;
  return queue;
}

void print(struct Queue* queue)
{
  if(queue -> front == nullptr)
  {
    cout << "Queue Empty" << endl;
  }
  else
  {
    cout << "FRONT -> ";
    struct Node* current = queue -> front;
    while(current != nullptr)
    {
      cout << current -> value << " -> ";
      current = current -> next;
    }
    cout << "END" << endl;
  }
}

int front(struct Queue* queue)
{
  return queue -> front == nullptr ? 0 : queue -> front -> value;
}

char empty(struct Queue* queue)
{
  return queue -> front == nullptr ? 1 : 0;//checking if queue is empty
}
void enqueue(struct Queue* queue, int x)
{
  Node* y = new(struct Node);
  y -> value = x;//y is temporary node
  y -> next = nullptr;
  if (queue -> front == nullptr)
  {
    queue -> front = queue -> back = y;//first value
  }
  else
  {
    queue -> back -> next = y;//last value
    queue -> back = y;
  }
}

int dequeue(struct Queue* queue)
{
    if (empty(queue) == 1)
    {
      return 0;
    }
    //return 0 if queue is empty, successfully dequeued
    Node* z = queue -> front;//z is temporary node
    queue -> front = queue -> front -> next;
    if (queue -> front == nullptr)
    {
      queue -> back = nullptr;
    }
    return z -> value;//return value
}