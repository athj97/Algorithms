#include <iostream>
#include "queue.h"
using namespace std;

//defining structure queue
struct Queue* make_queue()
{
  Queue *queue = new(struct Queue);
  queue -> back = NULL;//nullptr wasn't working
  queue -> front = NULL;
  return queue;
}

int front(struct Queue* queue)
{
  return queue -> front == NULL ? 0 : queue -> front -> value;
}

char empty(struct Queue* queue)
{
  return queue -> front == NULL ? '1' : '0';//checking if queue is empty
}

void enqueue(struct Queue* queue, int x)
{ 
  Node* temp_node = new(struct Node);
  temp_node -> value = x;
  if (queue->front == NULL)
  {
    queue->front = temp_node;
  }
  else
  {
    queue -> back -> next = temp_node;
  }
  queue -> back = temp_node;
  queue -> back -> next = queue -> front;
}

int dequeue(struct Queue* queue)
{
  if (empty(queue) == 1)
  {
    return 0;
  }
  //return 0 if queue is empty, successfully dequeued
  int ret_val;//value to be returned
  if (queue->front == queue->back)
  {
    ret_val = queue -> front -> value;
    free(queue -> front);
    queue -> front = NULL;
    queue -> back = NULL;
  }
  else 
  {
    Node* z = queue -> front;
    ret_val = z -> value;
    queue -> front = queue -> front -> next;
    queue -> back -> next = queue -> front;   
    free(z);
  }
  return ret_val;//value to be returned
}