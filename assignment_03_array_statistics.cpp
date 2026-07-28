// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================
#include <iostream>
#include <vector>
#include <iomanip> // for setprecision
using namespace std;

// Compute the sum of the numbers using a loop
double calculateSum(const vector<double>& nums) {
    double s = 0.0;
    for (size_t i = 0; i < nums.size(); ++i) {
        s += nums[i];
    }
    return s;
}

// Compute the average using the sum function
double calculateAverage(const vector<double>& nums) {
    if (nums.empty()) return 0.0;
    return calculateSum(nums) / static_cast<double>(nums.size());
}

// Find the maximum using a loop
double findMaximum(const vector<double>& nums) {
    double maxVal = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > maxVal) maxVal = nums[i];
    }
    return maxVal;
}

// Find the minimum using a loop
double findMinimum(const vector<double>& nums) {
    double minVal = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] < minVal) minVal = nums[i];
    }
    return minVal;
}

int main() {
    cout << "How many numbers? ";
    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    vector<double> numbers;
    numbers.reserve(n);
    for (int i = 0; i < n; ++i) {
        double value;
        cout << "Enter number " << (i + 1) << ": ";
        cin >> value;
        numbers.push_back(value);
    }

    cout << endl << "Results:" << endl;
    cout << "Sum:     " << calculateSum(numbers) << endl;
    // print average with one decimal place like the example
    cout << "Average: " << fixed << setprecision(1) << calculateAverage(numbers) << defaultfloat << endl;
    cout << "Maximum: " << findMaximum(numbers) << endl;
    cout << "Minimum: " << findMinimum(numbers) << endl;

    return 0;
}



