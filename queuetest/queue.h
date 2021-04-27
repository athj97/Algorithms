//A Queue by Mark Boady

#ifndef _QUEUE_H_
#define _QUEUE_H_

//The Node
struct Node
{
	int value;
	struct Node* next;
};

//The Queue
struct Queue
{
	struct Node* front;
	struct Node* back;
};

//The Methods

//Create A New Queue
struct Queue* make_queue();

//Print out the Queue
void print(struct Queue* queue);

//What is at the front of the queue?
int front(struct Queue* queue);

//Is the Queue empty? 1=Yes 0=No
char empty(struct Queue* queue);

//Add a new item to the back of the Queue
void enqueue(struct Queue* queue, int x);

//Remove an item from the front of the queue
//Return the item you removed
int dequeue(struct Queue* queue);

#endif