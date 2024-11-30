#include <stdio.h>
#include <time.h>


#define BLOCK_SIZE 32

const int DSIZE = 256;
const int a = 1;
const int b = 1;

// error checking macro
#define cudaCheckErrors()                                       \
	do {                                                        \
		cudaError_t __err = cudaGetLastError();                 \
		if (__err != cudaSuccess) {                             \
			fprintf(stderr, "Error:  %s at %s:%d \n",           \
			cudaGetErrorString(__err),__FILE__, __LINE__);      \
			fprintf(stderr, "*** FAILED - ABORTING***\n");      \
			exit(1);                                            \
		}                                                       \
	} while (0)


// CUDA kernel that runs on the GPU
__global__ void dot_product(const int *A, const int *B, int *C, int N) {

	int idx = threadIdx.x + blockDim.x * blockIdx.x;
        if (idx < N){
                atomicAdd(C,A[i] * B[i]);
        }

}


int main() {
	
	// Create the device and host pointers
	int *h_A, *h_B, *h_C, *d_A, *d_B, *d_C;

	// Fill in the host pointers 
	h_A = new int[DSIZE];
	h_B = new int[DSIZE];
	h_C = new int;
	for (int i = 0; i < DSIZE; i++){
		h_A[i] = a;
		h_B[i] = b;
	}

	*h_C = 0;


	// Allocate device memory 
	cudaMalloc(&d_A, sizeof(int)*DSIZE);
        cudaMalloc(&d_B,sizeof(int)*DSIZE);
        cudaMalloc($d_C,sizeof(int));

	// Check memory allocation for errors
	cudaCheckErrors();

	// Copy the matrices on GPU
	cudaMemcpy(&d_A, sizeof(int)*DSIZE, cudaMemcpyHostToDevice);
        cudaMemcpy(&d_B, sizeof(int)*DSIZE, cudaMemcpyHostToDevice);
        cudaMemcpy(&d_C, sizeof(int), cudaMemcpyHostToDevice);

	// Check memory copy for errors
	cudaCheckErrors();

	// Define block/grid dimentions and launch kernel
	dim3 blockSize(BLOCK_SIZE);  // 32 threads in x, 16 threads in y
        dim3 gridSize((DSIZE+BLOCK_SIZE-1)/BLOCK_SIZE);
	dot_product<<<grid_size,block_size>>>(d_A, d_B, d_C, DSIZE);

	// Copy results back to host
	 cudaMemcpy(h_C,d_C, sizeof(int), cudaMemcpyDeviceToHost);

    // Check copy for errors
	 cudaCheckErrors();

	// Verify result
	std::cout<<*h_A,*h_B,*h_C<<std::endl;

	// Free allocated memory
	free(h_A);
        free(h_B);
        free(h_C);

        cudaFree(d_A);
        cudaFree(d_B);
        cudaFree(d_C);


	return 0;

}
