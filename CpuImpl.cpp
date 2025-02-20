#include "Functions.h"

void solveDifferentianEquation(DiffEquationInfo& diffEquationInfo)
{
    int n = diffEquationInfo.numIterations;
    double x_0 = diffEquationInfo.x_0;
    double x_1 = diffEquationInfo.x_1;
    double const h = (x_1 - x_0) / static_cast<double>(n);

    double y_0 = diffEquationInfo.y_0;
    double a = diffEquationInfo.a;

    diffEquationInfo.solution = std::vector<double>(n);

    double x = x_0;
    double y = y_0;

    // итерации по методу Эйлера
    for (int i = 0; i < n; ++i)
    {
        y += h * sin((x + y) / a);
        x += h;
        
        diffEquationInfo.solution[i] = y;
    }
}