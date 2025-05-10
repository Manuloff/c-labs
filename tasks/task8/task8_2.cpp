//
// Created by nikita on 03.05.2025.
//

#include <iostream>
#include "../tasks.h"

using namespace std;

template <typename T>
void printMatrix(const T** matrix, const int rows, const int cols) {
    if (matrix == nullptr || rows < 0 || cols < 0) {
        return;
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << matrix[row][col] << ' ' << endl;
        }

        cout << endl;
    }
}

template <typename T>
void _task8_2() {

}

void task8_2() {
    _task8_2<float>();
}