%%cu
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define N 10
#define M 512

_global_ 
void mul(double a[][N], double b[][N], double c[][N])
{
	int index = blockIdx.x * blockDim.x + threadIdx.x;
	while(index<N)
	{
		for (int i = 0; i < N; i++)
		{
			c[index][i] = 0; 
			for (int j = 0; j < N; j++)
				c[index][i] += a[index][j] * b[j][i];
		}
		index+=blockDim.x*gridDim.x;
	}
}
int main()
{
    int threads[]={1,1,1,1,1,1,1,1,10,20,30,40,50,M,M/2,M/4,M/8,M,M,M,M};
    int blocks[]={1,10,20,30,40,50,N,10,10,10,10,10,10,10,M,M,M,M,M/2,M/4,M/8};
    double a[N][N], b[N][N], c[N][N];
    double(*d_a)[N], (*d_b)[N], (*d_c)[N];
    double size = N * N * sizeof(double);
    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMalloc((void **)&d_c, size);
    int k =1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j]=k*10.236;
            k++;
            if(i==j)
                b[i][j]=1;
            else
                b[i][j]=0;            
            c[i][j] =0.0;
        }
    }
    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);
    for(int k=0;k<21;k++)
    {
      	float elapsed=0;
    	cudaEvent_t start, stop;
    	cudaEventCreate(&start);
    	cudaEventCreate(&stop);
    	cudaEventRecord(start, 0);
    	mul<<<blocks[k],threads[k]>>>(d_a, d_b, d_c);
    	cudaDeviceSynchronize(); 
    	cudaError err= cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);
    	if(err!=cudaSuccess) 
   		{
      		printf("CUDA error copying to Host: %s\n", cudaGetErrorString(err));
    	}
   		cudaEventRecord(stop, 0);
    	cudaEventSynchronize (stop);

   		cudaEventElapsedTime(&elapsed, start, stop);

   		cudaEventDestroy(start);
   		cudaEventDestroy(stop);
   		printf(" %.5f \n",elapsed);  
    }
    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
    
    return 0;
}