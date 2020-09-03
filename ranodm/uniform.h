#pragma once
#include <random>
#include "distribution_generator.h"

class Dist_Uniform : public Dist_Genrator {
  public:
	explicit Dist_Uniform(int64_t min, int64_t max, uint64_t seed = 0)
		: gen_(seed),
		  dist_(std::uniform_int_distribution<int64_t>(min, max)) {
	}

	~Dist_Uniform() override { }

	// return [min, max];
	int64_t Next() override {
		return dist_(gen_);
	}

	virtual std::string Name() const {
		return "uniform distribution";
	}

  private:
  	std::mt19937 gen_;
	std::uniform_int_distribution<int64_t> dist_;
};