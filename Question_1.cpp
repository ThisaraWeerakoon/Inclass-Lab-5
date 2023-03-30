#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;
 
int partition(int arr[], int startPoint, int endPoint)
{
 
    int pivot = arr[endPoint];
    int i = startPoint-1;
    for(int j=startPoint;j<endPoint;j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;


        }

    }
    i++;
    int temp = arr[i];
    arr[i]=arr[endPoint];
    arr[endPoint]=temp;
    return i;



}
 
void quickSortRecursive(int arr[], int startPoint, int endPoint)
{
 
    // base case
    if (startPoint >= endPoint)
        return;
 
    // partitioning the array
    int pivot = partition(arr, startPoint, endPoint);
 
    // Sorting the left part
    quickSortRecursive(arr, startPoint, pivot - 1);
 
    // Sorting the right part
    quickSortRecursive(arr, pivot + 1, endPoint);

}


void quickSortIterative(int arr[], int low, int high)
{
    // Create an auxiliary stack
    int list[high - low + 1];

    // Initialize top of stack
    int top = -1;

    // Push initial values of low and high indices to the stack
    list[++top] = low;
    list[++top] = high;

    // Continue until the stack is empty
    while (top >= 0)
    {
        // Pop the topmost high and low indices from the stack
        high = list[top--];
        low = list[top--];

        // Partition the array and get the pivot index
        int pivot = partition(arr, low, high);

        // If there are elements on the left side of pivot, push the left sub-array indices to the stack
        if (pivot - 1 > low)
        {
            list[++top] = low;
            list[++top] = pivot - 1;
        }

        // If there are elements on the right side of pivot, push the right sub-array indices to the stack
        if (pivot + 1 < high)
        {
            list[++top] = pivot + 1;
            list[++top] = high;
        }
    }
}

void IterativeSolve(int n){
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }
    
    
    auto start = high_resolution_clock::now();
    quickSortIterative(arr,0,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken in Iterative Method "<<duration.count() << endl;;
    //cout<<"--------------------"<<endl;
}

void RecursionSolve(int n){
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }
    
    auto start = high_resolution_clock::now();
    quickSortRecursive(arr,0,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time taken in Recursive Method "<<duration.count() << endl;;

}
 
int main()
{

    for(int i=0;i<5;i++){
        cout<<"total elements in array: ";
        int n;
        cin>>n;
        //RecursionSolve(n);
        IterativeSolve(n);
        RecursionSolve(n);


    }
}
