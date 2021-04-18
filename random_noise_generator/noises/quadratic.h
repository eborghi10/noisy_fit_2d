#pragma once

#include <Eigen/Dense>

#include "random_noise_base.h"

namespace rng
{
/**
 * \brief Noise represented by a quadratic combination of a single random variable.
 */
class QuadraticNoise : public RandomNoiseBase
{
public:
  QuadraticNoise()
  {
    noise_x_ = Eigen::ArrayXf::Random(population_);
    const Eigen::ArrayXf X2 = Eigen::ArrayXf::Random(population_) * 0.1;
    noise_y_ = 2.0f * noise_x_ * noise_x_ + X2;
  };
};
} // namespace rng
