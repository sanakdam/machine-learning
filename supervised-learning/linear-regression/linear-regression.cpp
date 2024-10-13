#include <iostream>
#include <vector>

class LinearRegression
{
public:
  LinearRegression() : b0(0), b1(0) {}

  void fit(const std::vector<double> &x, const std::vector<double> &y)
  {
    int n = x.size();
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;

    for (int i = 0; i < n; ++i)
    {
      sum_x += x[i];
      sum_y += y[i];
      sum_xy += x[i] * y[i];
      sum_xx += x[i] * x[i];
    }

    // Calculate coefficients
    b1 = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    b0 = (sum_y - b1 * sum_x) / n;
  }

  double predict(double x)
  {
    return b0 + b1 * x;
  }

private:
  double b0; // Intercept
  double b1; // Slope
};

int main()
{
  LinearRegression lr;

  // Sample data
  std::vector<double> x = {1, 2, 3, 4, 5};
  std::vector<double> y = {2, 3, 5, 7, 11};

  lr.fit(x, y);

  double test_value = 6;
  std::cout << "Predicted value for x = " << test_value << " is " << lr.predict(test_value) << std::endl;

  return 0;
}
