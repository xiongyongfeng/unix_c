#include <iostream>
#include <vector>
#include <mpi.h>
#include <unistd.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank;
    int size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // 创建一个vector
    //std::vector<int> VecSendBuf = {1, 2, 3, 4, 5};
    std::vector<int> VecSendBuf(5);
    std::vector<int> VecRecvBuf(5*size);
    int* pSendBuf = new int[5];
    int* pRecvBuf = new int[5*size];

    // 每个进程初始化VecSendBuf
    for(int i = 0; i<5;i++)
    {
      VecSendBuf[i] = 5*rank + i;
      pSendBuf[i] = 5*rank + i;
    }

    for(int irank = 0; irank < size; irank++)
    {
      MPI_Barrier(MPI_COMM_WORLD);
      if(irank==rank)
      {
        std::cout << "rank = " << rank << ", VecSendBuf size = " << VecSendBuf.size()<<":";
        for(int value:VecSendBuf){
          std::cout << " " << value;
        }
        std::cout << std::endl;
      }
    }

    //调用MPI_Allgather进行收集
    MPI_Allgather(VecSendBuf.data(),VecSendBuf.size(),MPI_INT,VecRecvBuf.data(),VecSendBuf.size(),MPI_INT,MPI_COMM_WORLD);
    MPI_Allgather(pSendBuf,5,MPI_INT,pRecvBuf,5,MPI_INT,MPI_COMM_WORLD);



    for(int irank = 0; irank < size; irank++)
    {
      MPI_Barrier(MPI_COMM_WORLD);
      if(irank==rank)
      {
        std::cout << "rank = " << rank << ", VecRecvBuf size = " << VecRecvBuf.size()<<":";
        for(int value:VecRecvBuf){
          std::cout << " " << value;
        }
        std::cout << std::endl;
        std::cout << "rank = " << rank << ", pRecvBuf size = " << 5*size<<":";
        for(int i=0;i<5*size;i++){
          std::cout << " " << pRecvBuf[i];
        }
        std::cout << std::endl;
      }
    }

    delete[] pSendBuf;
    delete[] pRecvBuf;
    MPI_Finalize();


    return 0;
}

