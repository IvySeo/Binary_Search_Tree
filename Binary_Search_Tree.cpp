/*This is a program that implements an ordered list abstract data type using a pointer-based binary search tree. 
A binary search tree, which is called BST, is a binary tree in which the value at each node is greater 
than the values in its left subtree and less than the values in its right subtree. 
This project implements an ordered list using a BST and exercises that list in a menu-driven program. 
Commanded by an integer or a letter. It can be easily read in with the extractor operator ">>". 
An ordered list is a sequence of elements, it is ordered by the elements' values.*/

#include <iostream>
#include <stdlib.h>
using namespace std;

//Global Variables
const int MAX = 5000;
const int MIN = 0;



// Function Declaration
void heap_sort ( int heap_array[], int n, int &counter);
void reheap_down ( int heap_array[], int root, int last, int& counter);

int main()
{
    int num, seed, value;
    char input;
    int heap_counter =0;
    
    cout << "Enter the number of values to generate and sort, between 1 and 5000:" << endl;
    cin >> num;
    cout << "Enter an integer seed value:"<<endl;
    cin >> seed;
    srand(seed);

    
    int array_heap[num];

    for(int i = 0; i<num; i++)
    {

         value = rand()%5000 + 1;
        
        array_heap[i]= value;

    }

    //Ask the user for unsorted
    cout<<"Do you want to print unsorted values: ";
    cin>>input;
    if(input=='Y'||input=='y')
    {
        print(array_quick, num);
    }

    
    heap_sort ( array_heap, num, heap_counter);

    cout<<"Do you want to print sorted values: ";
    cin>>input;
    if(input=='Y'||input=='y')
    {   
        cout<<"\nHeap Sort: ";
        print(array_heap, num);
    }
     cout<<"\nHeap Sort count:\n"<<heap_counter;
  return 0;
}
void print(int arr[], int Size)
{
    for(int i = 0; i<Size; i++)
    {
        cout<<arr[i]<<endl;
    }
}



//Heap_sort
void heap_sort ( int heap_array[], int n, int &counter)
  {

    // Build the heap in an array
    for (int i=(n-2)/2; i>=0; --i)
      reheap_down(heap_array,i,n-1, counter);

    // Tear the heap down.
    for (int i=n-1; i>0; --i)
    {
      swap ( heap_array[0], heap_array[i] );
      reheap_down ( heap_array, 0, i-1, counter);
    }

  }

void reheap_down ( int a[], int root, int last, int& counter)
  // Swaps the element initially 
  {
    int parent;
    int max_child;
    bool completed;

    parent = root;
    completed = 0;


    // While loop which restores the heap property
    while (  last>2*parent && ! completed )
    {
        counter++;    // to keep the track of operations
      max_child = 2*parent + 1;
      if ( max_child < last && a[max_child+1] > a[max_child] )
        ++max_child;
      if ( a[parent] < a[max_child] )
      { // inbuilt swap function
        swap ( a[parent], a[max_child] );    
        parent = max_child;

      }
      else
        completed = 1;    // Boolean to get out of while loop
    }
  }
