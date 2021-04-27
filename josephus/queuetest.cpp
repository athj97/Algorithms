#include <iostream>
#include "queue.h"
using namespace std;

//shifted mov_next function here from main.cpp
void move_next(struct Queue* queue)
{
  queue -> front = queue -> front -> next;
  queue -> back = queue -> back -> next;
}

int main( int argc, const char* argv[])
{
  Queue* queue = make_queue();
  int m, n, d;
  cout << "Enter Number of People (N):" << endl;
  cin >> n;//total number of people
  cout << "Enter Person to Eliminate (M):" << endl;
  cin >> m;//in josephus problem, eliminating mth person is required
  for(int i = 0; i < n; i++)
  {
    enqueue(queue, i);//making a queue of all the people(it'll just be a list of numbers from 1 to n)
  }
  cout << "Order Eliminated:" << endl;
  while(n >= 1)
  {
    for(int i = 1; i < m; i++)
    {
      move_next(queue);//skipping the person/people not to be eliminated
    }
    d = dequeue(queue);//eliminating person to be eliminated
    cout << d << " ";
    n--;
  }
}