#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000

int main(int argc, char **argv)
{
    int Myid, numprocs;
    int i, x, start, end,rem;
    float val=0, result,arr[N];
    double stime,etime;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &Myid);
    char pro_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(pro_name,&name_len);
    if(0 == Myid) 
    {
        stime=MPI_Wtime();
        for(i=0;i<N;i++)
            arr[i]=i+1.0;
    }
    //broadcast arr
    MPI_Bcast(arr, N, MPI_FLOAT, 0,MPI_COMM_WORLD);
    // add portion of arr 
    x = N/numprocs;
    start = Myid * x;
    end = start + x;
    for(i=start; i<end; i++) 
    {
        val += arr[i];
    }
    printf("Calculated %f in %d - %s\n", val,Myid,pro_name);
    // compute global sum 
    MPI_Reduce(&val,&result,1, MPI_FLOAT,MPI_SUM, 0,MPI_COMM_WORLD);
    if(0 == Myid) 
    {
        rem=N%numprocs;
        for(i=N-rem;i<N;i++) result+=arr[i];
            printf("Sum is %f.\n", result);
        etime=MPI_Wtime();
        printf("\nTime= %f",etime-stime);
    }
    MPI_Finalize();
    return(0);
}
