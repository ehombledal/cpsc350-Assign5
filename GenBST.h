#include <iostream>
using namespace std;

template <typename T>
class GenTreeNode
{
  public:
    GenTreeNode();
    GenTreeNode(T value);
    //TreeNode(int key, T value)

    ~GenTreeNode();
    //when working with template classes,
    //virtual ~GenTreeNode();

    T value;
    GenTreeNode *left;
    GenTreeNode *right;
};

template <typename T>
GenTreeNode<T>::GenTreeNode()
{
  value = NULL;
  left = NULL;
  right = NULL;
}

template <typename T>
GenTreeNode<T>::GenTreeNode(T value)
{
  this -> value = value;
  left = NULL;
  right = NULL;
}

template <typename T>
GenTreeNode<T>::~GenTreeNode()
{
  //implement later
}


//TREE IMPLEMENTATION
template <typename T>
class GenBST
{
public:
  GenBST();
  ~GenBST();
  //virtual ~BinarySearchTree();

  void insert(T value); //in this example is also key
  bool searchNode(int idToFind);
  GenTreeNode<T>* getNode(int idToFind);
  bool deleteNode(T value);

  bool isEmpty();
  GenTreeNode<T>* getMin();
  GenTreeNode<T>* getMax();

  GenTreeNode<T>* getSuccessor(GenTreeNode<T> *d);
  void printTree(GenTreeNode<T> *node);

  GenTreeNode<T> *root;

};


//IMPLEMENTATION
template <typename T>
GenBST<T>::GenBST()
{
  root = NULL;
}

template <typename T>
GenBST<T>::~GenBST()
{
  //build character
}

//modified to work with student and faculty classes.
template <typename T>
void GenBST<T>::printTree(GenTreeNode<T> *node)
{
  if (node == NULL)
  {
    return;
  }

  printTree(node->left);
  node -> value -> printInfo();
  printTree(node->right);
}

template <typename T>
GenTreeNode<T>* GenBST<T>::getMax()
{
  GenTreeNode<T> *curr = root;

  if (root == NULL)
  {
    return NULL; //tree is empty
  }

  while (curr -> right != NULL)
  {
    curr = curr -> right;
  }

  return curr; //which is the node.
}

template <typename T>
GenTreeNode<T>* GenBST<T>::getMin()
{
  GenTreeNode<T> *curr = root;

  if (root == NULL)
  {
    return NULL; //tree is empty
  }

  while (curr -> left != NULL)
  {
    curr = curr -> left;
  }

  return curr; //which is the node.
}

template <typename T>
bool GenBST<T>::isEmpty()
{
  return (root == NULL);
}

template <typename T>
void GenBST<T>::insert(T value)
{
  GenTreeNode<T> *node = new GenTreeNode<T>(value);
  //cout << "made node" << endl;
  if (root == NULL)
  {
    //cout << "node made as root" << endl;
    //we have an empty tree, so put the node as the root.
    root = node;
  } else {
    //tree is not empty, find location
    GenTreeNode<T> *curr = root;
    GenTreeNode<T> *parent; //empty node

    while (true)
    {
      parent = curr;
      if (node -> value -> m_ID < curr -> value -> m_ID)
      {
        //go left
        //cout << "checked value: " << curr -> value -> m_ID << " value to be added: " << node -> value -> m_ID << endl;
        //cout << " value to be added is smaller than checked, go left" << endl;
        curr = curr->left;
        if (curr == NULL)
        {
          parent ->left = node;
          break;
        }
      } else {
        //go right
        //cout << "checked value: " << curr -> value -> m_ID << " value to be added: " << node -> value -> m_ID << endl;
        //cout << "value to be added is bigger than checked, go right" << endl;
        curr = curr->right;
        if (curr == NULL)
        {
          parent -> right = node;
          break;
        }
      }
    }
  }
}

template <typename T>
//Modified to work with student and faculty classes.
bool GenBST<T>::searchNode(int idToFind)
{
  if (isEmpty())
  {
    cout << "was found empty!" << endl;
    return false;
  } else {
    //tree is not empty
    GenTreeNode<T> *current = root;
    while (current->value->m_ID != idToFind)
    {
      //cout << "id of node being looked at " << current -> value -> m_ID << endl;
      if (idToFind < current -> value-> m_ID)
      {
        current = current -> left;
      } else {
        current = current -> right;
      }

      if (current == NULL)
      {
        //cout << "ID not Found! Please try again." << endl;
        return false;
      }
    }
    return true;
  }
}

template <typename T>
//modified for use with student and faculty classes.
GenTreeNode<T>* GenBST<T>::getNode(int idToFind)
{
  if (isEmpty())
  {
    return NULL;
  } else {
    //tree is not empty
    GenTreeNode<T> *current = root;
    while (current->value->m_ID != idToFind)
    {
      if (idToFind < current -> value-> m_ID)
      {
        current = current -> left;
      } else {
        current = current -> right;
      }

      if (current == NULL)
      {
        return NULL;
      }
    }
    return current;
  }
}

template <typename T>
bool GenBST<T>::deleteNode(T value)
{
  if (isEmpty())
  {
    return false;
  }
  else if(!searchNode(value -> m_ID))
  {
      return false;
  }

  GenTreeNode<T> *current = root;
  GenTreeNode<T> *parent = root;
  bool isLeft = true;
  //usual code to find node
  //we will also update pointers
  while (current -> value != value)
  {
    parent = current;
    if (value < current-> value)
    {
      isLeft = true;
      current = current -> left;
    } else {
      isLeft = false;
      current = current -> right;
    }

    if (current == NULL)
    {
      return false;
    }
  }

  //if you made it here, youve found node.
  if (current -> left == NULL && current -> right == NULL) //this is a leaf with no children
  {
    if (current == root)
    {
      root = NULL;
    } else if (isLeft)
    {
      parent->left == NULL;
    } else {
      parent -> right == NULL;
    }

  } else if (current -> right == NULL)   //one child case and the child is left
  {
    if (current == root)
    {
      root = current -> left;
    } else if (isLeft)
    {
      parent->left == current -> left;
    } else {
      parent -> right == current -> left;
    }

  } else if (current -> left == NULL)   //one child case and the child is right
  {
    if (current == root)
    {
      root = current -> right;
    } else if (isLeft)
    {
      parent->left == current -> right;
    } else {
      parent -> right == current -> right;
    }
  } else {  //node has two children
    GenTreeNode<T> *successor = getSuccessor(current);
    if (current == root)
    {
      root = successor;
    } else if(isLeft)
    {
      parent -> left = successor;
    } else {
      parent -> right = successor;
    }

    successor -> left = current -> left;
    return true;
  }
}

template <typename T>
GenTreeNode<T>* GenBST<T>::getSuccessor(GenTreeNode<T> *d)
{
  //d is the node to be deleted.
  GenTreeNode<T> *sp = d;
  GenTreeNode<T> *successor = d;
  GenTreeNode<T> *current = d -> right;

  while (current != NULL)
  {
    sp = successor;
    successor = current;
    current = current -> left;
  }

  if (successor != d-> right)
  {
    sp -> left = successor -> right;
    successor -> right = d -> right;
  }

  return successor;
}
