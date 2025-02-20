#include "Functions.h"

__device__ double derivativeFunction(double x, double y, double a)
{
    return sin((x + y) / a);
}

__global__ void solveDifferentianEquationGPU_kernel(unsigned char* img, size_t rows, size_t cols, unsigned char a, unsigned char b)
{
    int id = blockIdx.x * blockDim.x + threadIdx.x;

    if (id < (rows * cols * 3)) {
        img[id] = static_cast<unsigned char>((img[id] - a) * 255 / (b - a));
    }
}

void solveDifferentianEquationGPU(int BLK, int TPB, unsigned char* img, size_t rows, size_t cols, unsigned char a, unsigned char b)
{
    solveDifferentianEquationGPU_kernel << <BLK, TPB >> > (img, rows, cols, a, b);
}