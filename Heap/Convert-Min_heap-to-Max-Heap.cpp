// https://www.geeksforgeeks.org/convert-min-heap-to-max-heap/

// Given array representation of min Heap, convert it to max Heap in O(n) time. 
// Example : 
 

// Input: arr[] = [3 5 9 6 8 20 10 12 18 9]
//          3
//       /     \
//      5       9
//    /   \    /  \
//   6     8  20   10
//  /  \   /
// 12   18 9 


// Output: arr[] = [20 18 10 12 9 9 3 5 6 8] OR 
//        [any Max Heap formed from input elements]

//          20
//        /    \
//      18      10
//    /    \    /  \
//   12     9  9    3
//  /  \   /
// 5    6 8 

void MaxHeapify(int arr[], int i, int n)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if (l < n && arr[l] > arr[i])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, n);
    }
}
 
// This function basically builds max heap
void convertMaxHeap(int arr[], int n)
{
    // Start from bottommost and rightmost
    // internal mode and heapify all internal
    // modes in bottom up way
    for (int i = (n-2)/2; i >= 0; --i)
        MaxHeapify(arr, i, n);
}
