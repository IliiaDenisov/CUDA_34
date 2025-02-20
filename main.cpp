#include <iostream>
#include <format>
#include "Functions.h"

using namespace std;

int main(int argc, char** argv)
{
#pragma region Init
	//cudaEvent_t startCUDA, stopCUDA;

	//float elapsedTimeCUDA, elapsedTimeCPU;
	//cudaEventCreate(&startCUDA);
	//cudaEventCreate(&stopCUDA);

	//unsigned char* device_img;

#pragma endregion

#pragma region CPU
	clock_t startCPU, stopCPU;
	DiffEquationInfo equationInfo;
	equationInfo.x_0 = 0;
	equationInfo.x_1 = 1;
	equationInfo.y_0 = 0;
	equationInfo.a = 1;
	equationInfo.numIterations = 100;

	startCPU = clock();
	solveDifferentianEquation(equationInfo);
	stopCPU = clock();

	float elapsedTimeCPU = (double)(stopCPU - startCPU) / CLOCKS_PER_SEC;
	cout << "CPU sum time = " << elapsedTimeCPU * 1000 << " ms\n";

	for (auto i = 0; i < equationInfo.solution.size(); ++i) {
		std::cout << equationInfo.solution[i] << std::endl;
	}

#pragma endregion

#pragma region GPU
	//cudaMalloc(&device_img, N * sizeof(unsigned char));
	//cudaMemcpy(device_img, img_gpu.ptr<unsigned char>(), N * sizeof(unsigned char), cudaMemcpyHostToDevice);


	//const int TPB = 512;
	//const int BLK = (img.rows * img.cols * 3 + TPB - 1) / TPB;

	//cudaEventRecord(startCUDA, 0);
	//adjustBrightnessGPU(BLK, TPB, device_img, img_gpu.rows, img_gpu.cols, a, b);
	//cudaEventRecord(stopCUDA, 0);
	//cudaEventSynchronize(stopCUDA);

	//cudaEventElapsedTime(&elapsedTimeCUDA, startCUDA, stopCUDA);
	//cudaMemcpy(img_gpu.data, device_img, N * sizeof(unsigned char), cudaMemcpyDeviceToHost);
	//cudaFree(device_img);

	//cout << "CUDA sum time = " << elapsedTimeCUDA << " ms\n";
	//cout << "CUDA memory throughput = " << static_cast<unsigned long long>(N) * sizeof(unsigned char) / elapsedTimeCUDA / 1024 / 1024 / 1.024 << " Gb/s\n";
#pragma endregion

#pragma region Results

	//int mismatched = 0;
	//for (int i = 0; i < N; i++)
	//{
	//	int a = img_cpu.data[i];
	//	int b = img_gpu.data[i];
	//	if (abs(a - b) > 3)
	//	{
	//		mismatched++;
	//	}
	//}
	//cout << "Mismatched: " << mismatched << endl;
#pragma endregion
}