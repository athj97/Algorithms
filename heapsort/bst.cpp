//Atharv Joshi - CS520 - HW8
//Created By Mark Boady
//Drexel 2020

#include "bst.h"
#include <cstdlib>
#include <iostream>

using namespace std;

BST* makeBST()
{
  BST* B = new BST();
  B->root = NULL;
  return B;
}

Node* getRoot(BST* T)
{
  return T->root;
}

void insert(int value, BST* T)
{
  T->root = insert_value(value,T->root);
}


bool find(int value, BST* T)
{
  return find_value(value, T->root);
}

void delete_from_tree(int value, BST* T)
{
  T->root = delete_value(value,T->root);
}

int min(BST* T)
{
  return find_min(T->root);
}

void inorder(BST* T)
{
  inorder_walker(T->root);
  std::cout << std::endl;
}

void preorder(BST* T)
{
  preorder_walker(T->root);
  cout << endl;
}

void postorder(BST* T)
{
  postorder_walker(T->root);
  cout << endl;
}

int height(BST* T)
{
  return node_height(T->root);
}

//You have to start implementing from here down
//Do a walk starting at the node given
//Print the results to cout
//Print N for nulls
//Print a space after each value
//Print out an N for null positions

//Made changes in the code below

void inorder_walker(Node* current)
{
  if (current == nullptr)
  {
    cout << "N ";
    return;
  }

  inorder_walker(current->left);
  cout << current->value << " ";
  inorder_walker(current->right);
}


void preorder_walker(Node* current)
{
  if (current == nullptr)
  {
    cout << "N ";
    return;
  }

  cout << current->value << " ";
  preorder_walker(current->left);
  preorder_walker(current->right);
}

void postorder_walker(Node* current)
{
  if (current == nullptr)
  {
    cout << "N ";
    return;
  }

  postorder_walker(current->left);
  postorder_walker(current->right);
  cout << current->value << " ";
}

//Insert value v starting at node current
Node* insert_value(int v, Node* current)
{
  if (current == nullptr)
  {
    current = new Node();
    current->value = v;
    current->left = nullptr;
    current->right = nullptr;
  }
  else
  {
    if (v > current->value)
    {
      current->right = insert_value(v, current->right);
    }
    else if (v < current->value)
    {
      current->left = insert_value(v, current->left);
    }
  }

  return current;
}

//Find value starting at current node
bool find_value(int value, Node* current)
{

  if (current == nullptr || current == NULL)
  {
    return false;
  }

  if (current->value == value)
  {
    return true;
  }

  if (current->value < value)
  {
    return find_value(value, current->left);
  }
  return find_value(value, current->right);
}

//Find the min of the tree starting at current node
//Return -1 on current is null
int find_min(Node* current)
{
  if (current == nullptr)
  {
    return -1;
  }

  //Return current value if there's no left child at min 
  if (current->left == nullptr)
  {
    return current->value;
  }

  //Keep searching otherwise
  return find_min(current->left);
}

//Determine the node height of the current node
//Hint: The height of a null is -1
int node_height(Node* current)
{
  if (current == nullptr)
  {
    return -1;
  }

  int l_height = node_height(current->left);//left height
  int r_height = node_height(current->right);//right height

  if (l_height > r_height)
  {
    return l_height + 1;
  }
  return r_height + 1;
}

//I will provide you with delete
//Noice!!!!
//had to change the formatting, so that code looks uniform
Node* delete_value(int v, Node* current)
{
  if(current==NULL)
  {
    return NULL;
  }
  else if(current->value == v)
  {
    Node* x = delete_node(current);
    return x;
  }
  else if(current->value > v)
  {
    current->left=delete_value(v,current->left);
    return current;
  }
  else
  {
    current->right=delete_value(v,current->right);
    return current;
  }
}
Node* delete_node(Node* current)
{
  if(current->left == NULL)
  {
    return current->right;
  }
  if(current->right==NULL)
  {
    return current->left;
  }
  int minval = find_min(current->right);
  current->value = minval;
  current->right = delete_value(minval,current->right);
  return current;
}