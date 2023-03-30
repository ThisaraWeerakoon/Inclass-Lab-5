#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

void findMedian(int arr[], int n) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    double median = arr[0];
    maxHeap.push(arr[0]);

    cout << fixed << setprecision(1) << median << endl;

    for (int i = 1; i < n; i++) {
        int x = arr[i];

        if (maxHeap.size() > minHeap.size()) {
            if (x < median) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            } else {
                minHeap.push(x);
            }
            median = (double)(maxHeap.top() + minHeap.top()) / 2;
        } else if (maxHeap.size() == minHeap.size()) {
            if (x < median) {
                maxHeap.push(x);
                median = (double)maxHeap.top();
            } else {
                minHeap.push(x);
                median = (double)minHeap.top();
            }
        } else {
            if (x > median) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            } else {
                maxHeap.push(x);
            }
            median = (double)(maxHeap.top() + minHeap.top()) / 2;
        }

        cout << fixed << setprecision(1) << median << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    findMedian(arr, n);

    return 0;
}
