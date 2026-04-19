#pragma once

#include <cstdlib>
#include <stdexcept>
#include <vector>

class Vector {
private:
	std::vector<float> vals;
public:
	Vector(std::vector<float> _vals = {}) : vals(_vals) {}

	std::vector<float> getVals() {
		return vals;
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
};

class Matrix {
private:
	std::vector<std::vector<float>> vals = {};
public:
	Matrix(std::vector<std::vector<float>> _vals = { {} }) : vals(_vals) {}

	std::vector<std::vector<float>> getVals() {
		return vals;
	}

	Matrix operator+(const Matrix& rhs) {
		if (this->vals.size() * this->vals[0].size() != rhs.vals.size() * rhs.vals[0].size()) {
			throw std::runtime_error("Matrix sizes are not equal, unable to compute addition");
			exit(EXIT_FAILURE);
		}

		std::vector<std::vector<float>> result = { {} };
		for (size_t i = 0; i < this->vals.size(); i++) {
			std::vector<float> resultVec = {};
			for (size_t j = 0; j < this->vals[i].size(); j++) {
				resultVec.push_back(this->vals[i][j] + rhs.vals[i][j]);
			}
			result.push_back(resultVec);
		}

		return Matrix(result);
	}

	Matrix operator-(const Matrix& rhs) {
		if (this->vals.size() * this->vals[0].size() != rhs.vals.size() * rhs.vals[0].size()) {
			throw std::runtime_error("Matrix sizes are not equal, unable to compute subtraction");
			exit(EXIT_FAILURE);
		}

		std::vector<std::vector<float>> result = { {} };
		for (size_t i = 0; i < this->vals.size(); i++) {
			std::vector<float> resultVec = {};
			for (size_t j = 0; j < this->vals[i].size(); j++) {
				resultVec.push_back(this->vals[i][j] - rhs.vals[i][j]);
			}
			result.push_back(resultVec);
		}

		return Matrix(result);
	}

	Matrix operator*(Vector& rhs) {
		if (this->vals.size() != rhs.getVals().size()) {
			throw std::runtime_error("Matrix sizes are not equal, unable to compute subtraction");
			exit(EXIT_FAILURE);
		}

		std::vector<std::vector<float>> result = { {} };
		for (size_t i = 0; i < this->vals.size(); i++) {
			std::vector<float> resultVec = {};
			for (size_t j = 0; j < this->vals[i].size(); j++) {
				resultVec.push_back(this->vals[i][j] * rhs.getVals()[i]);
			}
			result.push_back(resultVec);
		}

		return Matrix(result);
	}
};