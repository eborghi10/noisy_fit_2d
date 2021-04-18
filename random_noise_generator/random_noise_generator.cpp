#include "random_noise_generator.h"

namespace rng
{
/**
 * \brief Linear noise.
 */
void RandomNoiseGenerator::Linear()
{
  // TODO: Improve how to characterize models from CLI
  const float m{ -2.0f };
  const float b{ 5.0f };
  const Eigen::ArrayXf X1 = Eigen::ArrayXf::Random(size_);
  noise_x_ = X1;
  const Eigen::ArrayXf X2 = Eigen::ArrayXf::Random(size_) * 0.1;
  noise_y_ = m * noise_x_ + b + X2;
}

/**
 * \brief Quadratic noise.
 */
void RandomNoiseGenerator::Quadratic()
{
  const Eigen::ArrayXf X1 = Eigen::ArrayXf::Random(size_);
  noise_x_ = X1;
  const Eigen::ArrayXf X2 = Eigen::ArrayXf::Random(size_) * 0.1;
  noise_y_ = 2 * noise_x_ * noise_x_ + X2;
}

/**
 * \brief Simplified Cholesky decomposition. Reference:
 *        https://en.wikipedia.org/wiki/Cholesky_decomposition#Monte_Carlo_simulation
 */
void RandomNoiseGenerator::SimplifiedCholesky()
{
  // Correlation coefficient
  float rho_{ 0.8f };
  // Random variables
  const Eigen::ArrayXf X1 = Eigen::ArrayXf::Random(size_);
  const Eigen::ArrayXf X2 = Eigen::ArrayXf::Random(size_);

  noise_x_ = X1;
  noise_y_ = X1 * rho_ + X2 * std::sqrt(1 - rho_ * rho_);
}

/**
 * \brief Constructor.
 * \param type Type of noise generator. Available options are: Linear, Quadratic and Cholesky.
 */
RandomNoiseGenerator::RandomNoiseGenerator(const std::string& type)
{
  std::cout << "Noise = " << type << std::endl;
  const auto itr = callbacks_.find(type);
  if (itr != callbacks_.end()) {
      (itr->second)();
  }
}
} // namespace rng

