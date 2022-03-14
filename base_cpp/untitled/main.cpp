#include <stdio.h>
#include <iostream>
using namespace std;

__global__ void hello_from_gpu()
{
    const int b = blockIdx.x;
    const int tx = threadIdx.x;
    const int ty = threadIdx.y;
   // cout<<b<<endl;
    printf("Hello World from block-%d and thread-(%d, %d)!\n", b, tx, ty);
}

int main(void)
{
    const dim3 block_size(2, 4);
    hello_from_gpu<<<2, block_size>>>();
    cudaDeviceSynchronize();
    return 0;
}
