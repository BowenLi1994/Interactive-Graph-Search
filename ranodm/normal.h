#pragma once
#include <random>
#include "distribution_generator.h"

class Dist_Normal : public Dist_Genrator {
  public:
	explicit Dist_Normal(int64_t mean, int64_t stddev, uint64_t seed = 0)
		: gen_(seed),
		  dist_(std::normal_distribution<double>(mean, stddev)) {
	}

	~Dist_Normal() override { }

	int64_t Next() override {
		return dist_(gen_);
	}

	virtual std::string Name() const {
		return "normal distribution";
	}

  private:
	std::mt19937 gen_;
	std::normal_distribution<double> dist_;
};