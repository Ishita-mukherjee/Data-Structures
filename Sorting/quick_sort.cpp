#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high)
{
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
  if (low < high)
    {
    int pi = partition(array, low, high);
    // Sort the elements on the left of pivot
    quickSort(array, low, pi - 1);
    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    {
        cout<<array[i]<<" ";
    }
  cout<<"\n";
}
int main()
{
    int i,n,arr[20];
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: \n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"\nGiven array is :\n";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout<<"Sorted array in ascending order: \n";
    printArray(arr, n);
    return 0;
}
