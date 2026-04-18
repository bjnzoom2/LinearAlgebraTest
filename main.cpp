#include <iostream>
#include <vector>

std::vector<float> solveAxb(std::vector<std::vector<float>> A, std::vector<float> b) {
	for (size_t i = 0; i < A.size(); i++) {
		A[i].insert(A[i].begin() + A[i].size(), b[i]);
	}

	float pivot = 1.0f;
	float target = 1.0f;

	for (size_t i = 0; i < A.size(); i++) {
		pivot = A[i][i];
		for (size_t j = i + 1; j < A.size(); j++) {
			target = A[j][i];
			for (size_t k = 0; k < A[i].size(); k++) {
				A[j][k] -= (target / pivot) * A[i][k];
			}
		}
	}

	std::vector<float> x(A.size(), 0.0f);

	for (size_t i = A.size() - 1; i >= 0; i--) {
		float b_val = A[i][A.size()];
		float solved = 0.0f;

		for (size_t j = i + 1; j < A.size(); j++) {
			solved += A[i][j] * x[j];
		}

		x[i] = (b_val - solved) / A[i][i];
	}

	return x;
}

int main() {
	std::vector<float> x = solveAxb({ {1, 2, -1},
									  {2, -1, 1},
									  {1, 1, 2} }, { 2, 3, 9 });

	for (auto& val : x) {
		std::cout << val << '\n';
	}

	return 0;
}