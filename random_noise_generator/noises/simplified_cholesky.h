#pragma once

#include <Eigen/Dense>

#include "random_noise_base.h"

namespace rng
{
/**
 * \brief Noise represented by a simplified Cholesky decomposition of bivariate random variables.
 *        Reference: https://en.wikipedia.org/wiki/Cholesky_decomposition#Monte_Carlo_simulation
 */
class SimplifiedCholesky : public RandomNoiseBase
{
public:
  SimplifiedCholesky()
  {
    noise_x_ = Eigen::ArrayXf::Random(population_);

    // Correlation coefficient
    const float rho{ 0.8f };

    const Eigen::ArrayXf X2 = Eigen::ArrayXf::Random(population_);
    noise_y_ = noise_x_ * rho + X2 * std::sqrt(1 - rho * rho);
  };
};
} // namespace rng
