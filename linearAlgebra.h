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

	Vector operator/(const float scalar) {
		std::vector<float> result = {};
		for (size_t i = 0; i < this->vals.size(); i++) {
			result.push_back(this->vals[i] / scalar);
		}

		return Vector(result);
	}
};