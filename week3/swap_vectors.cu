#include <stdio.h>


const int DSIZE = 40960;
const int block_size = 256;
const int grid_size = DSIZE/block_size;


__global__ void swap_vectors(float *A, float *B, int v_size) {

    //FIXME:
    // Express the vector index in terms of threads and blocks
    int idx =  threadIdx.x + blockDim.x * blockIdx.x;
    // Swap the vector elements - make sure you are not out of range
    if (idx < v_size){
	    float a = A[idx];
	    A[idx] = B[idx];
	    B[idx] = a;
    }
}


int main() {


    float *h_A, *h_B, *d_A, *d_B;
    h_A = new float[DSIZE];
    h_B = new float[DSIZE];


    for (int i = 0; i < DSIZE; i++) {
        h_A[i] = rand()/(float)RAND_MAX;
        h_B[i] = rand()/(float)RAND_MAX;
    }
    // Print old vectors
    printf("before: A[0] = %f\n", h_A[0]);
    printf("before: B[0] = %f\n", h_B[0]);



    // Allocate memory for host and device pointers 
    cudaMalloc(&d_A, DSIZE*sizeof(float));
    cudaMalloc(&d_B, DSIZE*sizeof(float));
    
    // Copy from host to device
    cudaMemcpy(d_A, h_A, DSIZE*sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, DSIZE*sizeof(float), cudaMemcpyHostToDevice);
    // Launch the kernel
    swap_vectors<<<grid_size, block_size>>>(d_A, d_B, DSIZE);

    // Copy back to host 
    cudaMemcpy(h_A, d_A, DSIZE*sizeof(float), cudaMemcpyDeviceToHost);
    cudaMemcpy(h_B, d_B, DSIZE*sizeof(float), cudaMemcpyDeviceToHost);

    // Print and check some elements to make sure swapping was successfull
    printf("after: A[0] = %f\n", h_A[0]);
    printf("after: B[0] = %f\n", h_B[0]);


    // Free the memory 
    free(h_A);
    free(h_B);
 
    cudaFree(d_A);
    cudaFree(d_B);
    
}
