#include <stdio.h>
#include <iostream>
#include <random>
#include <climits>

const int DSIZE = 512;
const int RADIUS = 2;

// 2d stencil function
void stencil_2d(int input[DSIZE][DSIZE], float output[DSIZE][DSIZE]) {

	for (int i =0; i<DSIZE; i++) {
		for (int j=0; j<DSIZE;j++){
			output[i][j]=0;
		}
	}

        for (int i = RADIUS; i < DSIZE - RADIUS; i++){
		for (int j = RADIUS; j < DSIZE - RADIUS; j++) {
			for (int dx = -RADIUS; dx <= RADIUS; dx++){
				for (int dy = -RADIUS; dy <= RADIUS; dy++) {
					output[i][j] += input[i+dx][j+dy]/100.0;
				}
			}
		}
	}	
}

// matrix multiplication function (from week3 hw)
void matrix_mul(float A[DSIZE][DSIZE], float B[DSIZE][DSIZE], float C[DSIZE][DSIZE], int size) {
  for (int i=0; i<size; i++){
         for (int j=0; j<size; j++){
                 int temp = 0;
                 for (int k = 0; k < size; k++){
                         temp += A[i][k] * B[k][j];
                 }

                 C[i][j] = temp;
          }
  }
}

int main() {
	
	// create two 2-dimensional square matrices A and B of size DSIZE >= 512	

	// building matrices A and B 
	int A[DSIZE][DSIZE];
	int B[DSIZE][DSIZE];
	for (int i=0; i <DSIZE; i++){
		for (int j=0; j<DSIZE; j++) {
			A[i][j] = i;
			B[i][j] = j;
			}
		}

	// perform 2-d stencil operation
	float stencil_A[DSIZE][DSIZE];
	float stencil_B[DSIZE][DSIZE];

	stencil_2d(A, stencil_A);
	stencil_2d(B, stencil_B);

	std::cout << "Sample of A:\n";
        for (int i = DSIZE / 2 - 1; i <= DSIZE / 2 + 1; ++i) {
                for (int j = DSIZE / 2 - 1; j <= DSIZE / 2 + 1; ++j) {
                        std::cout << A[i][j] << " ";
                }
                std::cout << "\n";
        }

	// checking if stencil makes sense
	std::cout << "Sample of stencil_A:\n";
    	for (int i = DSIZE / 2 - 1; i <= DSIZE / 2 + 1; ++i) {
        	for (int j = DSIZE / 2 - 1; j <= DSIZE / 2 + 1; ++j) {
			std::cout << stencil_A[i][j] << " ";
        	}
        	std::cout << "\n";
    	}

	std::cout << "Sample of B:\n";
        for (int i = DSIZE / 2 - 1; i <= DSIZE / 2 + 1; ++i) {
                for (int j = DSIZE / 2 - 1; j <= DSIZE / 2 + 1; ++j) {
                        std::cout << B[i][j] << " ";
                }
                std::cout << "\n";
        }

    	std::cout << "Sample of stencil_B:\n";
    	for (int i = DSIZE / 2 - 1; i <= DSIZE / 2 + 1; ++i) {
        	for (int j = DSIZE / 2 - 1; j <= DSIZE / 2 + 1; ++j) {
            	std::cout << stencil_B[i][j] << " ";
        	}
        	std::cout << "\n";
    	}

	// perform matrix multiplication of matrices after stencil application 
	float C[DSIZE][DSIZE];
	matrix_mul(stencil_A, stencil_B, C, DSIZE);

	// checking multiplication output 
	// turns out values were overflowing - which is why i divided by 100 in stencil
	std::cout << "Sample of C:\n";
        for (int i = DSIZE / 2 - 1; i <= DSIZE / 2 + 1; ++i) {
                for (int j = DSIZE / 2 - 1; j <= DSIZE / 2 + 1; ++j) {
                std::cout << C[i][j] << " ";
                }
                std::cout << "\n";
        }

	return 0;

}

