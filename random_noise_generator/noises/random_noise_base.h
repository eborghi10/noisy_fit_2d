#pragma once

#include <Eigen/Dense>

namespace rng
{
class RandomNoiseBase
{
public:
  /**
   * \brief Get the X component of the noise.
   * \return Eigen ArrayXf with the X component of the noise.
   */
  Eigen::ArrayXf GetX() const { return noise_x_; };
  /**
   * \brief Get the Y component of the noise.
   * \return Eigen ArrayXf with the Y component of the noise.
   */
  Eigen::ArrayXf GetY() const { return noise_y_; };
protected:
  // Size of the population on each dimension
  const size_t population_{ 100 };
  // Noise components
  Eigen::ArrayXf noise_x_{ population_ };
  Eigen::ArrayXf noise_y_{ population_ };
};
} // namespace rng
