#pragma once
#include <string>


class Dist_Genrator {
  public:
	explicit Dist_Genrator() { }

	virtual ~Dist_Genrator() { }

	virtual int64_t Next() = 0;

	virtual std::string Name() const = 0;
};