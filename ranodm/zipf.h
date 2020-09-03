#pragma once
#include <random>
#include <cmath>
#include "distribution_generator.h"

class Dist_Zipf : public Dist_Genrator {
  public:
	explicit Dist_Zipf(int64_t max, double alpha,
	                   bool quick_gen = false, uint64_t seed = 0)
		: max_(max),
		  alpha_(alpha),
		  cons_val_(0),
		  quick_gen_(quick_gen),
		  gen_(seed),
		  uniform_(std::uniform_real_distribution<double>(0.0, 1.0)),
		  pre_alloc_sum_prob_(nullptr) {
		// check
		if (max_ < 1) {
			fprintf(stderr, "zipf distribution doesn't support max < 1\n");
			return ;
		}

		// Compute normalization constant on first call only
		for (int64_t i = 1; i < max_; ++i) {
			cons_val_ += 1.0 / pow(static_cast<double>(i), alpha_);
		}
		cons_val_ = 1.0 / cons_val_;

		if (quick_gen_) {
			pre_alloc_sum_prob_ = (double*)malloc((max_ + 1) * sizeof(double));
			pre_alloc_sum_prob_[0] = 0;
			for (int64_t i = 1; i < max_; ++i) {
				pre_alloc_sum_prob_[i] = pre_alloc_sum_prob_[i - 1] +
				                         cons_val_ / (pow(static_cast<double>(i), alpha_));
			}
		}

	}

	~Dist_Zipf() override {
		if (pre_alloc_sum_prob_) delete pre_alloc_sum_prob_;
	};

	int64_t Next() override {
		if (quick_gen_) {
			return quick_zipf();
		} else {
			return zipf();
		}
	}

	virtual std::string Name() const {
		return "zipf distribution";
	}

  private:
	int64_t zipf() {
		double z;
		double sum_prob;
		int64_t zipf_value;

		// Pull a uniform random number (0 < z < 1)
		do {
			z = uniform_(gen_);
		} while (z == 0);

		// Map z to the value
		sum_prob = 0;
		for (int64_t i = 1; i <= max_; i++) {
			sum_prob += cons_val_ / pow(static_cast<double>(i), alpha_);
			if (sum_prob >= z) {
				zipf_value = i;
				break;
			}
		}

		return zipf_value;
	}

	int64_t quick_zipf() {
		double z;
		int64_t low = 1, high = max_, mid;
		int64_t zipf_value;

		// Pull a uniform random number (0 < z < 1)
		do {
			z = uniform_(gen_);
		} while (z == 0);

		// Map z to the value
		do {
			mid = floor((low + high) / 2);
			if (pre_alloc_sum_prob_[mid] >= z &&
			        pre_alloc_sum_prob_[mid - 1] < z) {
				zipf_value = mid;
				break;
			} else if (pre_alloc_sum_prob_[mid] >= z) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		} while (low <= high);

		return zipf_value;
	}

  private:
	int64_t max_;
	double alpha_;
	double cons_val_;
	bool quick_gen_;
	std::mt19937 gen_;
	std::uniform_real_distribution<double> uniform_;

	double *pre_alloc_sum_prob_;
};