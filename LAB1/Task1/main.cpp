#include <iostream>

using namespace std;

#include <iostream>

// Function declarations
int summation(int arr[], int n);
int maximum(int arr[], int n);

int main() {
    int n;

    // Obtaining length of array from the user
    cout<< "A PROGRAM TO CALCULATE SUM OF NUMBERS AND THE MAXIMUM NUMBER IN THE ARRAY"<<endl;
    cout<< "_________________________________________________________________________"<<endl;
    cout << "Enter the length of the array: ";
    cin >> n;

    // Declaring an array of length n
    int* userArray = new int[n];

    // Receiving the user's  n integers and store them in the array
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Enter integer #" << (i + 1) << ": ";
        cin >> userArray[i];
    }

    // Calling the summation function a
    int sum = summation(userArray, n);
    // Displaying the result
    cout << "Sum of the integers: " << sum << endl;

    // Calling the maximum function
    int maxNum = maximum(userArray, n);
    // Displaying the result
    cout << "Maximum integer: " << maxNum << endl;

    // Freeing  the dynamically allocated memory for the array
    delete[] userArray;

    return 0;
}

// Function to calculate the sum of integers in the array
int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the maximum integer in the array
int maximum(int arr[], int n) {
    int maxNum = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }
    return maxNum;
}
