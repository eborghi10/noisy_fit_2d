#pragma once

#include <Eigen/Dense>

namespace lf
{
class LinearFittingBase
{
protected:
  // Helper struct
  struct Line{
    float m;
    float b;
  };
  // Line fit components
  Eigen::ArrayXf samples_x_;
  Eigen::ArrayXf samples_y_;
public:
  /**
   * \brief Fit a line to the 2D noise data received as input.
   * \param noise_x X component of the 2D noise data.
   * \param noise_y Y component of the 2D noise data.
   * \return Line parameters of the fitted line.
   */
  virtual Line Fit(const Eigen::ArrayXf& noise_x, const Eigen::ArrayXf& noise_y) = 0;
  /**
   * \brief Get the X component of the noise.
   * \return Eigen ArrayXf with the X component of the noise.
   */
  Eigen::ArrayXf GetX() const { return samples_x_; };
  /**
   * \brief Get the Y component of the noise.
   * \return Eigen ArrayXf with the Y component of the noise.
   */
  Eigen::ArrayXf GetY() const { return samples_y_; };
};
} // namespace lf
