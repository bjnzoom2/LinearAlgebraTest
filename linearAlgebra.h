#pragma once

#include <cstdlib>
#include <stdexcept>
#include <vector>

class Vector {
private:
	std::vector<float> vals;
public:
	friend OperationHandler;

	Vector(std::vector<float> _vals = {}) : vals(_vals) {}

	const float operator[](size_t index) const {
		return vals[index];
	}

	const size_t size() const {
		return vals.size();
	}

	Vector operator+(const Vector& rhs) {
		if (this->vals.size() != rhs.vals.size()) {
			throw std::runtime_error("Vector sizes are not equal, unable to compute addition");
			exit(EXIT_FAILURE);
		}

		std::vector<float> result = {};
		for (size_t i = 0; i < this->vals.size(); i++) {
			result.push_back(this->vals[i] + rhs.vals[i]);
		}

		return Vector(result);
	}

	Vector operator-(const Vector& rhs) {
		if (this->vals.size() != rhs.vals.size()) {
			throw std::runtime_error("Vector sizes are not equal, unable to compute subtraction");
			exit(EXIT_FAILURE);
		}

		std::vector<float> result = {};
		for (size_t i = 0; i < this->vals.size(); i++) {
			result.push_back(this->vals[i] - rhs.vals[i]);
		}

		return Vector(result);
	}
	
	Vector operator*(const float scalar) {
		std::vector<float> result = {};
		for (size_t i = 0; i < this->vals.size(); i++) {
			result.push_back(this->vals[i] * scalar);
		}

		return Vector(result);
	}

	Vector operator*(const Vector& rhs) {
		if (this->vals.size() != rhs.vals.size()) {
			throw std::runtime_error("Vector sizes are not equal, unable to compute element wise multiplication");
			exit(EXIT_FAILURE);
		}

		std::vector<float> result = {};
		for (size_t i = 0; i < this->vals.size(); i++) {
			result.push_back(this->vals[i] * rhs.vals[i]);
		}

		return Vector(result);
	}

	float dot(const Vector& other) {
		if ((*this).size() != other.size()) {
			throw std::runtime_error("Vector sizes are not equal, unable to compute dot product");
			exit(EXIT_FAILURE);
		}

		float result = 0.0f;
		for (size_t i = 0; i < (*this).size(); i++) {
			result += (*this)[i] * other[i];
		}

		return result;
	}
};

class Matrix {
private:
	std::vector<Vector> vals = {};
public:
	friend OperationHandler;

	Matrix(std::vector<Vector> _vals = {}) : vals(_vals) {}
	Matrix(std::vector<std::vector<float>> _vals = { {} }) {
		for (size_t i = 0; i < _vals.size(); i++) {
			vals.push_back(Vector(_vals[i]));
		}
	}

	const Vector& operator[](size_t index) const {
		return vals[index];
	}

	const size_t size() const {
		return vals.size();
	}

	Matrix operator+(const Matrix& rhs) {
		if (this->size() * this[0].size() != rhs.size() * rhs[0].size()) {
			throw std::runtime_error("Matrix sizes are not equal, unable to compute addition");
			exit(EXIT_FAILURE);
		}

		std::vector<std::vector<float>> result = { {} };
		for (size_t i = 0; i < (*this).size(); i++) {
			std::vector<float> resultVec = {};
			for (size_t j = 0; j < (*this)[i].size(); j++) {
				resultVec.push_back((*this)[i][j] + rhs[i][j]);
			}
			result.push_back(resultVec);
		}

		return Matrix(result);
	}

	Matrix operator-(const Matrix& rhs) {
		if ((*this).size() * (*this)[0].size() != rhs.size() * rhs[0].size()) {
			throw std::runtime_error("Matrix sizes are not equal, unable to compute subtraction");
			exit(EXIT_FAILURE);
		}

		std::vector<std::vector<float>> result = { {} };
		for (size_t i = 0; i < (*this).size(); i++) {
			std::vector<float> resultVec = {};
			for (size_t j = 0; j < (*this)[i].size(); j++) {
				resultVec.push_back((*this)[i][j] - rhs[i][j]);
			}
			result.push_back(resultVec);
		}

		return Matrix(result);
	}

	Matrix operator*(Vector& rhs) {
		if (this->size() != rhs.size()) {
			throw std::runtime_error("Matrix sizes are not equal, unable to compute vector-matrix multiplication");
			exit(EXIT_FAILURE);
		}

		std::vector<std::vector<float>> result = { {} };
		for (size_t i = 0; i < (*this).size(); i++) {
			std::vector<float> resultVec = {};
			for (size_t j = 0; j < (*this).size(); j++) {
				resultVec.push_back((*this)[i][j] * rhs[i]);
			}
			result.push_back(resultVec);
		}

		return Matrix(result);
	}

	//Matrix operator*(Matrix& rhs) {
	//	if (this->vals[0].size() != rhs.vals.size()) {
	//		throw std::runtime_error("Row * Column rule not met, unable to compute matrix multplication");
	//		exit(EXIT_FAILURE);
	//	}

	//	std::vector<std::vector<float>> result = { {} };
	//	for (size_t i = 0; i < this->vals.size(); i++) {
	//		std::vector<float> resultVec = {};
	//		for (size_t j = 0; j < this->vals[i].size(); j++) {
	//			resultVec.push_back(this->vals[i][j] * rhs[i][j]);
	//		}
	//		result.push_back(resultVec);
	//	}

	//	return Matrix(result);

	//	std::vector<Vector> result = {};
	//	for (size_t i = 0; i < (*this)[0].size(); i++) {
	//		for (size_t j = 0; i < rhs.size(); j++) {

	//		}
	//	}
	//}
};

class OperationHandler {
public:
	OperationHandler() {}

	Matrix matrixMul(Matrix& lhs, Matrix& rhs) {
		if (lhs.size() != rhs.size()) {
			throw std::runtime_error("Row * Column rule not met, unable to compute matrix multplication");
			exit(EXIT_FAILURE);
		}

		std::vector<Vector> result = {};
		for (size_t i = 0; i < rhs.size(); i++) {
			std::vector<float> vec = {};
			for (size_t j = 0; j < lhs[i].size(); j++) {
				vec.push_back(lhs[i][j]);
			}
			Vector column(vec);
			float dotProduct = column.dot(rhs[i]);
		}
	}
};