#pragma once

#include <Eigen/Dense>

#include "linear_fitting_base.h"

namespace lf
{
/**
 * \brief Least Squares line fitting solver.
 *        Reference: Molugaram K., Shanker Rao G. Statistical Techniques for
 *        Transportation Engineering (2017), Chapter 5 - Curve Fitting. Pages 281-292.
 */
class LeastSquares : public LinearFittingBase
{
public:
  Line Fit(const Eigen::ArrayXf& noise_x, const Eigen::ArrayXf& noise_y)
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
  };
};
} // namespace lf
