//Atharv Joshi - CS520 - HW8
//Created By Mark Boady
//Drexel 2020


//Tests for Binary Search Tree

#include "bst.h"
#include <iostream> //For printing
#include <cstdlib> //For null pointers
#include <iomanip> //For formatting
#include <cstdlib> //For Random Numbers
#include <ctime> //To find out what time it is

using namespace std;

void test_insert(int v, BST* B);
void test_delete(int v, BST* B);
int single_experiment(int n);
void run_experiment();

int main()
{
  //Set up the random number generator
  srand(time(0));
  //First we do some simple examples.
  BST* B = makeBST();
  //Insert some numbers to make an expected tree
  test_insert(6,B);
  test_insert(4,B);
  test_insert(1,B);
  test_insert(10,B);
  test_insert(8,B);
  test_insert(5,B);
  test_insert(12,B);
  //Check the height
  cout << "The Tree Height is " << height(B) << endl;
  //Check find
  for(int i=0; i < 13; i++)
  {
    cout << "Is " << i << " in the tree? " << std::endl;
    cout << find(i,B) << endl;
  }
  //Delete the values in order
  test_delete(6,B);
  test_delete(4,B);
  test_delete(1,B);
  test_delete(10,B);
  test_delete(8,B);
  test_delete(5,B);
  test_delete(12,B);
    
  //Implement this once you have
  //Everything else working
  run_experiment();
  return 0;
}

void test_insert(int v, BST* B)
{
  insert(v,B);
  cout <<"Tree After Insertion of " << v << endl;
  cout <<"Inorder:"<<endl;
  inorder(B);
  cout <<"Preorder:"<<endl;
  preorder(B);
  cout <<"Postorder:"<<endl;
  postorder(B);
}

void test_delete(int v, BST* B)
{
  delete_from_tree(v,B);
  cout << "Tree After Deletion of " << v << endl;
  cout << "Inorder:" << endl;
  inorder(B);
  cout << "Preorder:" << endl;
  preorder(B);
  cout << "Postorder:" << endl;
  postorder(B);
}

//**Time to Run Your Experiment
void run_experiment()
{
  cout << "Experiments" << endl;
  cout << "|  N  |  T1  |  T2  |  T3  |  T4  |  T5  | Average |" << endl;
  int n=2;
  for(int i=1; i < 11; i++)
  {
    //Print the Row
    cout << "|" << left << setw(5) << setfill(' ') << n;
    //Run 5 Tests
    float avg=0;
    for(int j=0; j < 5; j++)
    {
      int res = single_experiment(n);
      cout << "|" << std::left << setw(6) << setfill(' ') << res;
      avg=avg+static_cast<float>(res);
    }
    cout << "|" << left << setw(9) << setfill(' ') << (avg/5);
    //End
    cout << "|" << endl;
    n = n * 2;
  }
}

//Have this function run 1 test
//Generate a random tree with n elements
//and return it's height
//This function should insert n random numbers
//into a BST.
//Then return the height of the tree
int single_experiment(int n)
{
  BST* B = makeBST();
  for(int i = 1; i < n ; i++)
  {
    insert(rand(),B);
  }

  return height(B);
}