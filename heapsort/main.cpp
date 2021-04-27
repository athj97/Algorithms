//Atharv V Joshi - CS520 - HW9

#include <iostream>
#include "heap.h"
using namespace std;


//create a new heap
struct heap* empty(int cap)//used instead of makenull
{
  heap* h = new heap();//h is the new emptied heap
  h->dset = new int(cap);
  h->upper_limit = cap;
  h->current = 0;
  return h;
};

//used boolean instead of character, I think it is easier this way
bool is_this_empty(struct heap* h)
{
  return (h->current == 0);
}

int parent_index(int n)
{
  if (n == 0)
  {
    return -1;
  }
  return (n - 1) / 2;
}

//index of left child
int left_child(int n)
{
  return 2 * n + 1;
}

//index of right child
int right_child(int n)
{
  return 2 * n + 2;
}

//swapping values
void swap(struct heap* h, int x, int p)
{
  int temp = h->dset[x];
  h->dset[x] = h->dset[p];
  h->dset[p] = temp;
  return;
}

//upheap value at index x
void up_heap(struct heap* h, int x)
{
  int parent = parent_index(x);
  if (parent < 0)
  {
    return;
  }
  int y = h->dset[parent];
  if (y <= h->dset[x])
  {
    return;
  }
  swap(h, x, parent);
  up_heap(h, parent);
}

//downheap value at index x
void down_heap(struct heap* h, int x)
{
  int l = left_child(x);//left index
  int r = right_child(x);//right index
  if (l >= h->current)
  {
    return;
  }
  int m;//minimum value index
  if ((r >= h->current) || (h->dset[l] < h->dset[r]))
  {
    m = l;
  }
  else
  {
    m = r;
  }
  if (h->dset[x] > h->dset[m])
  {
    swap(h, x, m);
    down_heap(h, m);
  }
}

void del_min(struct heap* h)
{
  if (is_this_empty(h))
  {
    return;
  }
  swap(h, 0, h->current - 1);
  h->current -= 1;
  down_heap(h, 0);
}

//To avoid segmentation fault
void enlarge(struct heap* h)
{
  int size = 2 * h->current;
  int* new_dset = new int(size);
  for (int i = 0; i < h->current ; i++)
  {
    new_dset[i] = h->dset[i];//copying current data
  }
  h->dset = new_dset;
  h->upper_limit = size;
  return;
}

//inserting new value
void put_new_val(int x, struct heap* h)
{
  if (h->current == h->upper_limit)
  {
    enlarge(h);
  }
  h->dset[h->current] = x;
  h->current = h->current + 1;
  up_heap(h, h->current - 1);
}

//to find if it is the lowest value
int lowest(struct heap* h)
{
  if (is_this_empty(h))
  {
    return 0;
  }
  return h->dset[0];
}

/*
//For testing
void print_heap(struct heap* h)
{
  printf("Heap Current Size: %d\n", h->current);
  printf("Heap Max Size: %d\n", h->upper_limit);
  printf("Contents;\n");
  for (int i = 0; i < h->upper_limit; i++)
  {
    printf("%d ", h->dset[i]);
  }
  printf("\n");
}
*/

//heapsort function
void heap_sort(int* x, int y)
{
  heap* h = empty(y);//y represents size
  for (int i = 0; i < y; i++)
  {
    put_new_val(x[i], h);
  }
  //print_heap(h);
  for (int j = 0; j < y; j++)
  {
    x[j] = lowest(h);
    del_min(h);
  }
  //print_heap(h);
}