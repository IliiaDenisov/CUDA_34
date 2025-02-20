#pragma once
#include "cuda_runtime.h"
#include <functional>
#include <vector>
#include "device_launch_parameters.h"

struct DiffEquationInfo
{
    double x_0;
    double x_1;
    double y_0;
    double a;
    size_t numIterations;

    std::vector<double> solution;
};


void solveDifferentianEquation(DiffEquationInfo& diffEquationInfo);

int solveDifferentianEquationGPU();