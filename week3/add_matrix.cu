#include <stdio.h>


const int DSIZE_X = 256;
const int DSIZE_Y = 256;

__global__ void add_matrix(const float *A, const float *B, float *C, int Nx, int Ny)
{
    //FIXME:
    // Express in terms of threads and blocks
    int idx = threadIdx.x + blockDim.x * blockIdx.x;
    int idy = threadIdx.y + blockDim.y * blockIdx.y;
    // Add the two matrices - make sure you are not out of range
    if (idx <  Nx && idy < Ny ){
	int index = idy*Nx + idx;
        C[index] =  A[index] + B[index];
    }
}

int main()
{

    // Create and allocate memory for host and device pointers 
    float *h_A, *h_B, *h_C, *d_A, *d_B, *d_C;
    h_A = new float[DSIZE_X * DSIZE_Y];
    h_B = new float[DSIZE_X * DSIZE_Y];
    h_C = new float[DSIZE_X * DSIZE_Y];

    // Fill in the matrices
    for (int i = 0; i < DSIZE_X; i++) {
        for (int j = 0; j < DSIZE_Y; j++) {
            int ind = i*DSIZE_Y + j;
            h_A[ind] = rand()/(float)RAND_MAX;
	    h_B[ind] = rand()/(float)RAND_MAX;
        }
    }

    // Copy from host to device
    cudaMalloc(&d_A, DSIZE_X * DSIZE_Y * sizeof(float));
    cudaMalloc(&d_B, DSIZE_X * DSIZE_Y * sizeof(float));
    cudaMalloc(&d_C, DSIZE_X * DSIZE_Y * sizeof(float));
    cudaMemcpy(d_A, h_A, DSIZE_X * DSIZE_Y * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, DSIZE_X * DSIZE_Y * sizeof(float), cudaMemcpyHostToDevice);
    // Launch the kernel
    // dim3 is a built in CUDA type that allows you to define the block 
    // size and grid size in more than 1 dimentions
    // Syntax : dim3(Nx,Ny,Nz)
    dim3 blockSize(16,16); 
    dim3 gridSize((DSIZE_X + blockSize.x-1)/blockSize.x,(DSIZE_Y + blockSize.y -1)/blockSize.y); 
    
    add_matrix<<<gridSize, blockSize>>>(d_A, d_B, d_C, DSIZE_X, DSIZE_Y);
    
    // Copy back to host 
    cudaMemcpy(h_C, d_C, DSIZE_X * DSIZE_Y * sizeof(float), cudaMemcpyDeviceToHost);

    // Print and check some elements to make the addition was succesfull
    printf("A[0,0]] = %f\n", h_A[0]);
    printf("B[0,0] = %f\n", h_B[0]);
    printf("C[0,0] = %f\n", h_C[0]);
    // Free the memory     

    free(h_A);
    free(h_B);
    free(h_C);


    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    return 0;
}
