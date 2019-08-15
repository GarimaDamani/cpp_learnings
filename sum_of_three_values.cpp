#include <iostream>

using namespace std;

void print_numbers(int *a, int size_a) {
    for (int i = 0; i < size_a; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void selection_sort(int *a, int size_a) {
    int min_indx;
    for (int i = 0; i < size_a - 1; i++) {
        min_indx = i;
        for (int j = i+1; j < size_a; j++) {
            if (a[j] < a[min_indx])
                min_indx = j;
        }
        if (min_indx != i)
            swap(a[min_indx], a[i]);
    }
}

void swap(int *x, int *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void find_triplates(int *a, int size_a, int sum) {
    int temp = 0;
    cout << "Below three numbers sum is " << sum << endl;
    for (int i = size_a-1; i >= 0; i--) {
        if (sum > a[i]) {
            temp += a[i];
            if (temp == sum) {
               cout << a[i] << endl;
               break;
            }
            if (temp >= sum)
                temp -= a[i];
            else
                cout << a[i] << " ";
        }
    }
}

int main() {
    cout << "Hello Garima Welcome back!!" << endl;
    int a[] = {1,4,45,6,10,8};
    int sum = 22;
    int a_size = sizeof(a) / sizeof(a[0]);
    cout << "Array of numbers: ";
    print_numbers(a, a_size);
    selection_sort(a, a_size);
    cout << "After slection sort: ";
    print_numbers(a, a_size);
    find_triplates(a, a_size, sum);
}
