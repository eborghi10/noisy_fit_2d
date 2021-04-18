#include <iostream>
#include <memory>
#include <string>

// Base class
#include "solvers/linear_fitting_base.h"

// Solver classes
#include "solvers/least_squares.h"

namespace lf
{
using LinearFittingBasePtr = std::unique_ptr<LinearFittingBase>;

class LinearFittingFactory
{
public:
  /**
   * \brief Generator of LinearFittingBase.
   * \param type Type of solver generator. Available options are: least_squares.
   * \return Pointer to LinearFittingBase.
   */
  static LinearFittingBasePtr Make(const std::string& type = "least_squares")
  {
    std::cout << "Solver = " << type << std::endl;
    if(type == "least_squares") {
      return std::make_unique<LeastSquares>();
    }
    else {
      // Default uses least_squares
      return std::make_unique<LeastSquares>();
    }
    // TODO: Add gradient descent
  }
};
} // namespace lf
