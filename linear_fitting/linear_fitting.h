#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

#include <Eigen/Dense>

namespace lf
{
class LinearFitting
{
protected:
  // Helper struct
  struct Line{
    float m;
    float b;
  };
private:
  // Solver generators
  Line LeastSquares(const Eigen::ArrayXf& noise_x, const Eigen::ArrayXf& noise_y);
  using unordered_map_t = std::unordered_map<std::string, std::function<Line(const Eigen::ArrayXf&, const Eigen::ArrayXf&)>>;
  // Callback to register generators
  unordered_map_t callbacks_ {
    std::make_pair("", [this](const Eigen::ArrayXf& x, const Eigen::ArrayXf& y){ return LeastSquares(x, y); }),  // Default
    std::make_pair("least_squares", [this](const Eigen::ArrayXf& x, const Eigen::ArrayXf& y){ return LeastSquares(x, y); }),
  };
  // Solver type
  std::string type_;
  // Line represented as two array
  Eigen::ArrayXf samples_x_;
  Eigen::ArrayXf samples_y_;
public:
  LinearFitting(const std::string& type = "least_squares");
  Line Fit(const Eigen::ArrayXf& noise_x, const Eigen::ArrayXf& noise_y);
  Eigen::ArrayXf GetX() const { return samples_x_; };
  Eigen::ArrayXf GetY() const { return samples_y_; };
};
} // namespace lf

