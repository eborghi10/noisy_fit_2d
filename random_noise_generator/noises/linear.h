#pragma once

#include <Eigen/Dense>

#include "random_noise_base.h"

namespace rng
{
/**
 * \brief Noise represented by a linear combination of a single random variable.
 */
class LinearNoise : public RandomNoiseBase
{
private:
  const float m_{ -2.0f };
  const float b_{ 5.0f };
public:
  LinearNoise()
  {
    noise_x_ = Eigen::ArrayXf::Random(population_);
    const Eigen::ArrayXf X2 = Eigen::ArrayXf::Random(population_) * 0.1;
    // TODO: Improve how to characterize models from CLI
    noise_y_ = m_ * noise_x_ + b_ + X2;
  };
};
} // namespace rng
