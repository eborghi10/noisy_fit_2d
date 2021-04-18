#include "linear_fitting.h"

namespace lf
{
/**
 * \brief Constructor.
 * \param type Type of solver generator.
 */
LinearFitting::LinearFitting(const std::string& type)
  : type_{ type }
{
  std::cout << "Solver = " << type << std::endl;
}

/**
 * \brief Least Squares line fitting solver.
 *        Reference: Molugaram K., Shanker Rao G. Statistical Techniques for
 *        Transportation Engineering (2017), Chapter 5 - Curve Fitting. Pages 281-292.
 * \param noise_x X component of the 2D noise data.
 * \param noise_y Y component of the 2D noise data.
 * \return Line parameters of the fitted line.
 */
LinearFitting::Line LinearFitting::LeastSquares(const Eigen::ArrayXf& noise_x, const Eigen::ArrayXf& noise_y)
{
  const float sum_x{ noise_x.sum() };
  const float sum_y{ noise_y.sum() };
  const float sum_x2{ (noise_x*noise_x).sum() };
  const float sum_xy{ (noise_x*noise_y).sum() };

  const float n = noise_x.size();
  Line line;
  line.m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
  line.b = (sum_y - line.m * sum_x) / n;

  samples_x_ = noise_x;
  samples_y_ = line.m * samples_x_ + line.b;

  return line;
}

/**
 * \brief Fit a line to the 2D noise data received as input.
 * \param noise_x X component of the 2D noise data.
 * \param noise_y Y component of the 2D noise data.
 * \return Line parameters of the fitted line.
 */
LinearFitting::Line LinearFitting::Fit(const Eigen::ArrayXf& noise_x, const Eigen::ArrayXf& noise_y)
{
  const auto itr = callbacks_.find(type_);
  if (itr != callbacks_.end()) {
    return (itr->second)(noise_x, noise_y);
  }
  return Line{};
}
} // namespace lf

