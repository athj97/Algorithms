//Mark Boady - CS520
//Heap Data Structure

//Made some changes
//I realized functions were given after I did half of the code, so just changed here accordingly

#ifndef _HEAP_H_
#define _HEAP_H_

//*********Functions Required to make a heap***********
//Heapsort Sort
//Sort using a heap data structure
void heap_sort(int* x, int y);
//The Heap data structure
struct heap//variable name changes here
{
  int* dset;
  int upper_limit;
  int current;
};
//Make a new Heap
struct Heap* makenull(int cap);//did not use this
//Is the heap empty?
char empty(struct Heap* H);//did not use this either
//What is the min?
int lowest(struct Heap* h);//changed function name
//Delete the min
void del_min(struct Heap* h);//changed function name
//Downheap a value at index x
void down_heap(struct Heap* H, int x);//changed function name
//Insert a new value
void put_new_val(int x, struct Heap* H);//changed function name
//Upheap a value at index x
void up_heap(struct Heap* H,int x);//changed function name
//Get Index of Parent
int parent_index(int n);//changed function name
//Get index of Left Child
int left_child(int n);
//Get index of Right Child
int right_child(int n);
//Swap i and j in heap
void swap(struct Heap* H, int i, int j);
//Just to help debug
//You can have this do whatever you want.
//We suggest you have a way to print the heap
//So you can test it when you get errors
void print_heap(struct Heap* H);

#endif