// Given an array of n unique integers where each element in the array is in the range [1, n].
//  The array has all distinct elements and the size of the array is (n-2). Hence Two numbers from the 
// range are missing from this array. Find the two missing numbers.
// Examples : 
// Input  : arr[] = {1, 3, 5, 6}
// Output : 2 4
// Input : arr[] = {1, 2, 4}
// Output : 3 5
// Input : arr[] = {1, 2}
// Output : 3 4

// METHOD 1 : BOOLEAN ARRAY : O(n) time complexity and O(N) Extra Space

void findTwoMissingNumbers(int arr[], int n)
{
    vector<bool> mark(n+1, false);
    for (int i = 0; i < n-2; i++)
        mark[arr[i]] = true;
 
    for (int i = 1; i <= n; i++)
       if (!mark[i])
           cout << i << " ";
           cout << endl;
}


// METHOD 2: O(n) time complexity and O(1) Extra Space

int getSum(int arr[],int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
 
void findTwoMissingNumbers(int arr[],int n)
{
    int sum = (n*(n + 1)) /2 - getSum(arr, n-2); 
    int avg = (sum / 2);
    int sumSmallerHalf = 0, sumGreaterHalf = 0;
    for (int i = 0; i < n-2; i++)
    {
        if (arr[i] <= avg)
            sumSmallerHalf += arr[i];
        else
            sumGreaterHalf += arr[i];
    }
    int totalSmallerHalf = (avg*(avg + 1)) / 2;
    int smallerElement = totalSmallerHalf - sumSmallerHalf;
    cout << smallerElement << " ";
    cout << sum - smallerElement;
}
