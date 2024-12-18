#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<bool> SSL(const vector<bool>& A, size_t k) {
    size_t n = A.size();
    vector<bool> result(n, false);
    for (size_t i = 0; i < n; ++i) {
        if (i + k < n) result[i] = A[i + k];
    }
    return result;
}

vector<bool> SRL(const vector<bool>& A, size_t k) {
    size_t n = A.size();
    vector<bool> result(n, false);
    for (size_t i = k; i < n; ++i) {
        result[i] = A[i - k];
    }
    return result;
}

vector<bool> SLC(const vector<bool>& A, size_t k) {
    size_t n = A.size();
    vector<bool> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = A[(i + k) % n];
    }
    return result;
}

vector<bool> AND(const vector<bool>& A, const vector<bool>& B) {
    size_t n = A.size();
    vector<bool> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = A[i] && B[i];
    }
    return result;
}

vector<bool> OR(const vector<bool>& A, const vector<bool>& B) {
    size_t n = A.size();
    vector<bool> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = A[i] || B[i];
    }
    return result;
}

vector<bool> XOR(const vector<bool>& A, const vector<bool>& B) {
    size_t n = A.size();
    vector<bool> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = A[i] ^ B[i];
    }
    return result;
}

vector<bool> XNOR(const vector<bool>& A, const vector<bool>& B) {
    size_t n = A.size();
    vector<bool> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = !(A[i] ^ B[i]);
    }
    return result;
}

vector<bool> IMPL(const vector<bool>& A, const vector<bool>& B) {
    size_t n = A.size();
    vector<bool> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = !A[i] || B[i];
    }
    return result;
}

vector<bool> flip(const vector<bool>& bit_string) {
    size_t n = bit_string.size();
    vector<bool> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = !bit_string[i];
    }
    return result;
}

vector<bool> flip(const vector<bool>& bit_string, size_t position) {
    vector<bool> result = bit_string;
    if (position < bit_string.size()) {
        result[position] = !result[position];
    }
    return result;
}

void printVector(const vector<bool>& vec) {
    for (bool bit : vec) {
        cout << bit << " ";
    }
    cout << endl;
}

int main() {
    vector<bool> A = { 1, 0, 1, 1, 0 };
    vector<bool> B = { 0, 1, 1, 0, 1 };

    cout << "A: ";
    printVector(A);
    cout << "B: ";
    printVector(B);

    cout << "\nSSL(A, 2): ";
    printVector(SSL(A, 2));

    cout << "SRL(A, 2): ";
    printVector(SRL(A, 2));

    cout << "SLC(A, 2): ";
    printVector(SLC(A, 2));

    cout << "AND(A, B): ";
    printVector(AND(A, B));

    cout << "OR(A, B): ";
    printVector(OR(A, B));

    cout << "XOR(A, B): ";
    printVector(XOR(A, B));

    cout << "XNOR(A, B): ";
    printVector(XNOR(A, B));

    cout << "IMPL(A, B): ";
    printVector(IMPL(A, B));

    cout << "flip(A): ";
    printVector(flip(A));

    cout << "flip(A, 2): ";
    printVector(flip(A, 2));

    return 0;
}