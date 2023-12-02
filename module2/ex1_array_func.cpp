#include <iostream>
using std::cin;
using std::cout;

/* The function get two parameters: array of int and its size and will return
 * the min value (among elements).
 */
int min_element(int arr[], int size) {
  int min = arr[0]; // assume first element is min

  // Check with other elements
  for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i]; // update min if found smaller value
    }
  }
  return min;
}

int main() {
  // Ask user to input array size
  int size;
  cout << "Enter size for the array: ";
  cin >> size;

  // Define array with that size
  int arr[size];
  cout << "Enter values for the array: ";
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  // Call the function to get the min and print out result
  cout << ">> Min value is: " << min_element(arr, size) << "\n";

  return 0;
}