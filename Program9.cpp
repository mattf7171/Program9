#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix_2x2 = {{1, 2}, {3, 4}};
vector<vector<int>> matrix_2x3 = {{1, 2, 3}, {4, 5, 6}};
vector<vector<int>> matrix_3x2 = {{1, 2}, {3, 4}, {5, 6}};
vector<vector<int>> matrix_3x3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> addMatrices(const vector<vector<int>>& M, const vector<vector<int>>& N) {
    vector<vector<int>> result(M.size(), vector<int>(M[0].size(), 0));
    for (size_t i = 0; i < M.size(); ++i) {
        for (size_t j = 0; j < M[0].size(); ++j) {
            result[i][j] = M[i][j] + N[i][j];
        }
    }
    return result;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& M, const vector<vector<int>>& N) {
    vector<vector<int>> result(M.size(), vector<int>(N[0].size(), 0));
    for (size_t i = 0; i < M.size(); ++i) {
        for (size_t j = 0; j < N[0].size(); ++j) {
            for (size_t k = 0; k < N.size(); ++k) {
                result[i][j] += M[i][k] * N[k][j];
            }
        }
    }
    return result;
}

int main() {
    int choiceM, choiceN, operation;

    cout << "1. 2x2 Matrix:\n"; printMatrix(matrix_2x2);
    cout << "2. 2x3 Matrix:\n"; printMatrix(matrix_2x3);
    cout << "3. 3x2 Matrix:\n"; printMatrix(matrix_3x2);
    cout << "4. 3x3 Matrix:\n"; printMatrix(matrix_3x3);

    cout << "\nSelect Matrix M (1-4): ";
    cin >> choiceM;
    cout << "Select Matrix N (1-4): ";
    cin >> choiceN;
    cout << "Select operation (1 for addition, 2 for multiplication): ";
    cin >> operation;

    vector<vector<int>> M, N;
    switch (choiceM) {
        case 1: M = matrix_2x2; break;
        case 2: M = matrix_2x3; break;
        case 3: M = matrix_3x2; break;
        case 4: M = matrix_3x3; break;
        default: cout << "Invalid choice for Matrix M.\n"; return 1;
    }
    switch (choiceN) {
        case 1: N = matrix_2x2; break;
        case 2: N = matrix_2x3; break;
        case 3: N = matrix_3x2; break;
        case 4: N = matrix_3x3; break;
        default: cout << "Invalid choice for Matrix N.\n"; return 1;
    }

    if (operation == 1) {
        if (M.size() == N.size() && M[0].size() == N[0].size()) {
            cout << "\nMatrix M:\n"; printMatrix(M);
            cout << "\nMatrix N:\n"; printMatrix(N);
            vector<vector<int>> result = addMatrices(M, N);
            cout << "\nResult of addition:\n"; printMatrix(result);
        } else {
            cout << "Addition is not possible with matrices of different sizes.\n";
        }
    } else if (operation == 2) {
        if (M[0].size() == N.size()) {
            cout << "\nMatrix M:\n"; printMatrix(M);
            cout << "\nMatrix N:\n"; printMatrix(N);
            vector<vector<int>> result = multiplyMatrices(M, N);
            cout << "\nResult of multiplication:\n"; printMatrix(result);
        } else {
            cout << "Multiplication is not possible with these matrices.\n";
        }
    } else {
        cout << "Invalid operation choice.\n";
    }

    return 0;
}
