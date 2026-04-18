#include <iostream>
using namespace std;

/* ===================== Q1 – Arrays & Searching ===================== */

// Q1.A.1
// Contiguous memory allocation means storing elements in adjacent memory locations.
// Arrays use it so elements can be accessed using index directly.
// Advantage: O(1) access time because address = base + index * size.

// Q1.A.2
// Memory leak occurs when memory is allocated but not deallocated.
// Example: int* arr = new int[10]; and never using delete[] arr;

// Q1.A.3
// Static array: fixed size at compile time.
// Dynamic array: size decided at runtime using new.
// Fixed size matters because it cannot grow, leading to limitations.

// Q1.A.4
// Array access is O(1) because index gives direct address.
// Linked list is not O(1) because traversal is required (O(n)).

// Linear Search
int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

// Find Min & Max in one loop
void findMinMax(int arr[], int size, int &minVal, int &maxVal) {
    minVal = maxVal = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < minVal)
		 minVal = arr[i];
        if(arr[i] > maxVal)
		 maxVal = arr[i];
    }
}

/* ===================== Q2 – Bubble Sort ===================== */

// Q2.A.1
// Bubble Sort repeatedly compares adjacent elements and swaps them if needed.
// Largest elements "bubble" to the end after each pass.

// Q2.A.2
// Best: O(n), Average: O(n^2), Worst: O(n^2)
// With optimization, best case becomes O(n) if already sorted.

// Q2.A.3
//Comparison between Bubble Sort & Selection Sort:
// Selection Sort does fewer swaps.
// Bubble Sort is easier and stable.
// Selection preferred when swaps are costly.

void bubbleSort(int arr[], int size, int &swapCount) {
    swapCount = 0;
    for(int i = 0; i < size - 1; i++) {
        bool swapped = false;
        cout << "Pass " << i+1 << ": ";
        
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapCount++;
                swapped = true;
            }
        }

        for(int k = 0; k < size; k++)
            cout << arr[k] << " ";
        cout << endl;

        if(!swapped) break;
    }
}

/* ===================== Q3 – Binary Search ===================== */

// Q3.A.1
// Array must be sorted for Binary Search.
// Otherwise, we cannot eliminate half correctly.

// Q3.A.2
// Dry Run:
// low=0, high=7 ? mid=3 (12)
// low=4, high=7 ? mid=5 (23) FOUND

// Q3.A.3
// Linear Search: O(n)
// Binary Search: O(log n)
// Binary is faster because it halves the search space each step.

int binarySearch(int arr[], int size, int key, int &iterations) {
    int low = 0, high = size - 1;
    iterations = 0;

    while(low <= high) {
        iterations++;
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/* ===================== Q4 – Big O ===================== */

// Q4.A.1
// Big O describes algorithm efficiency.
// We use it instead of seconds because hardware differs.

// Q4.A.2
// O: worst case
// O: best case
// T: exact case
// Analogy: travel time (fastest, slowest, average)

// Q4.A.3
// Fast ? Slow: O(1), O(log n), O(n), O(n log n), O(n^2)

// Q4.A.4
// Space complexity = memory used.
// Temporary array of size n ? O(n)

// Q4.A.5
// Incorrect: O(n log n) always beats O(n^2) for large n.

// Nested Loop ? O(n^2)
void nestedLoop(int arr[], int n) {
    // Outer loop: n
    // Inner loop: n
    // Total: n * n = O(n^2)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i] << " ";
        }
    }
}

// Single Loop ? O(n)
void singleLoop(int arr[], int n) {
    // Runs n times ? O(n)
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// Check if all elements of A exist in B
// Time Complexity: O(n^2)
bool checkElements(int A[], int B[], int n) {
    for(int i = 0; i < n; i++) {
        bool found = false;
        for(int j = 0; j < n; j++) {
            if(A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}

// More efficient approach:
// Sort B and use Binary Search ? O(n log n)

/* ===================== Q5 – Linked List ===================== */

// Q5.A.1
// Linked List stores elements non-contiguously using pointers.

// Q5.A.2
// Insert head: O(1)
// Insert tail: O(n)
// Delete: O(n)

// Q5.A.3
// Not deleting causes memory leak.

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node{val, NULL};
        if(!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void deleteByValue(int val) {
        if(!head) return;

        if(head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if(temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        } else {
            cout << "Value not found\n";
        }
    }
};

/* ===================== MAIN FUNCTION ===================== */

int main() {

    // Q1
    int arr1[10] = {4,15,7,23,1,9,42,18,6,30};
    int index = linearSearch(arr1, 10, 42);
    cout << "Linear Search Index: " << index << endl;

    int minVal, maxVal;
    findMinMax(arr1, 10, minVal, maxVal);
    cout << "Min: " << minVal << " Max: " << maxVal << endl;

    // Q2
    int arr2[7] = {64,34,25,12,22,11,90};
    int swaps;
    cout << "\nBubble Sort Process:\n";
    bubbleSort(arr2, 7, swaps);
    cout << "Total Swaps: " << swaps << endl;

    // Q3
    int arr3[10] = {2,5,8,12,16,23,38,45,56,72};
    int iterations;
    int res = binarySearch(arr3, 10, 56, iterations);
    cout << "\nBinary Search Found at: " << res << endl;
    cout << "Iterations: " << iterations << endl;

    // Not found case
    res = binarySearch(arr3, 10, 100, iterations);
    cout << "Not Found Index: " << res << endl;
    cout << "Iterations: " << iterations << endl;

    // Q5
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtTail(30);
    list.insertAtHead(2);

    cout << "\nLinked List:\n";
    list.display();

    list.deleteByValue(20);
    list.deleteByValue(100);

    cout << "After Deletion:\n";
    list.display();

    return 0;
}

// GitHub: https://github.com/YourUsername/YourRepoName
