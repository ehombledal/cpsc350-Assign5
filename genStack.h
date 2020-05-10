#include <iostream>
#include <string>

using namespace std;

template <typename T>
class genStack
{
  public:
    genStack(); //default
    genStack(int maxSize); //overloaded
    ~genStack(); //destructor

    //functions
    void push(T data); //insert
    T pop();  //remove

    //helper functions
    bool isFull();
    bool isEmpty();
    T peek();

    //variables
    int m_size;  //max size
    int top;    //keeps track of indeces representing top
    T *myArray; //pointer to array as we dont have the array built yet. Build at runtime.

};

//IMPLEMENTATION

template <typename T>
genStack<T>::genStack() //default constructor
{
  myArray = new T[128];
  m_size = 128;
  top = -1;
}

template <typename T>
genStack<T>::genStack(int maxSize) //overloaded
{
  myArray = new T[maxSize];
  m_size = maxSize;
  top = -1;

}

template <typename T>
genStack<T>::~genStack() //destructor
{
  delete myArray;
}

template <typename T>
void genStack<T>::push(T data)
{
  if (isFull() == true)
  {
    cout << "stack is full!" << endl;
    cout << "allocating more space..." << endl;
    myArray[++top] = data; //increments then adds data
  } else {
    myArray[++top] = data; //increments then adds data
  }
}

template <typename T>
T genStack<T>::pop()
{
  if (isEmpty() == true)
  {
    //throw "Can't pop from an empty stack!";
  } else {
    return myArray[top--]; //removes then increment
  }

}

template <typename T>
T genStack<T>::peek()
{
  if (isEmpty() == true)
  {
    cout << "stack is empty!" << endl;
    return 0;
  } else {
    return myArray[top]; //doesnt actually remove
  }
}

template <typename T>
bool genStack<T>::isFull()
{
  if (top == m_size-1)
  {
    T *newArray = new T[m_size * 2];
    for (int i = 0; i < m_size; ++i)
    {
      newArray[i] = myArray[i];
    }
    m_size = m_size * 2;

    delete myArray;
    myArray = newArray;
    return true;

  } else {
    return false;
  }
}

template <typename T>
bool genStack<T>::isEmpty()
{
  return (top == -1); //returns true if top == -1
}
