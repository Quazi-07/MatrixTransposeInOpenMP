/**********************************************
Author: Md. Saifur Rahman
Date: December 5, 2020
email: mdsaifur.rahman.1@und.edu/iamsaif07@gmail.com
***************************************************/


#include <iostream>
#include <string>
#include <omp.h>

//using namespace std;

int main(int argc,char **argv){
  
  int i,j,rows,cols,team_size;
  std::string prnt;
  
  if( argc != 5 ){
    printf("\t\t Very Few Arguments. Please insert 5 arguments.\n ");
    printf("\t\t Syntax : <./outfile> <rows> <colums> <print tag(y/n)> <team size>\n");
    exit(1);
  }

  rows = atoi(argv[1]);
  cols = atoi(argv[2]);
  prnt = argv[3];
  team_size = atoi(argv[4]);

  //Dynamacilly allocate memory for A matrix
  int **A = new int *[rows];
  for(int i=0;i<rows;i++){
    A[i]=new int[cols];
  }
  
  //insert data to the matrix A
  //std::cout<<"\nA:"<<"\n";
  for(int i=0;i<rows;i++){
    for (int j = 0; j<cols;j++){
      A[i][j]= (((i*j)*5)+i); // simple math to get a value for A matrix
      //std::cout<<A[i][j]<<" ";
    }
    //std::cout<<"\n";
  }

  // Dynamacilly allocate memory for AT matrix
  //std::cout<<"AT\n";
  int **AT = new int *[cols];
  for(int i=0;i<cols;i++){
    AT[i]=new int[rows];
  }
  for(int i=0;i<cols;i++){
    for (int j = 0; j<rows;j++){
      AT[i][j] = 0; // initialize AT matrix with all 0
      //std::cout<<AT[i][j]<<" ";
    }
    //std::cout<<"\n";
  }

  //number of threads come from command line
  omp_set_num_threads(team_size);

  // Start time before transpose the matrix
  double start = omp_get_wtime();

  // transpose the matrix in the parallel section
  #pragma omp parallel for private(i,j)
     for(int i=0;i<rows;i++){
        for (int j = 0; j<cols;j++){
            AT[j][i]= A[i][j];
            //std::cout<<AT[j][i]<<" ";
        }
      //std::cout<<"\n";
     }

  // Get time after finishing transpose the matrix 
  double stop = omp_get_wtime();

  // Print info
  std::cout<<"Total threads used for this operation:"<<team_size<<"\n"; 
  std::cout<<"\nStart time before the transpose operation:"<<start<<"\n";
  std::cout<<"\nStop time after the transpose operation:"<<stop<<"\n";
  std::cout<<"\nTotal times take for single transpose operation:"<<stop-start<<"\n";

  // Average time calculation
  int iter = 5;
  double totl = 0;
  //double totl1 = 0;
  for (int c=0; c < iter; c++){
    // Start time before transpose the matrix
    double start1 = omp_get_wtime();
    // transpose the matrix in the parallel section
    #pragma omp parallel for private(i,j)
        for(int i=0;i<rows;i++){
            for (int j = 0; j<cols;j++){
               AT[j][i]= A[i][j];
               //std::cout<<AT[j][i]<<" ";
            }
        //std::cout<<"\n";
        }
    // Get time after finishing transpose the matrix 
    double stop1 = omp_get_wtime();
    //totl1 = (stop1-start1);
    totl = totl+(stop1 - start1);
    //std::cout<<"\ntotal ["<<c<<"]:"<<totl1<<"\n";
	}
  //std::cout<<"\ntotal:"<<totl<<"\n";
  // Print info
  std::cout<<"\nAverage times for doing ["<<iter<<"] times transpose operations:"<<totl/iter<<"\n";
  
  
  //if (prnt == 1){
  if (prnt == "y" || prnt == "Y"){
  //Print the matrix A

     std::cout<<"\nA:"<<"\n";
     for(int i=0;i<rows;i++){
        for (int j = 0; j<cols;j++){
            //A[rows][cols]= arr[i][j];
            //A[i][j]= arr[i][j];
            std::cout<<A[i][j]<<" ";
            //std::cout<<A[rows][cols]<<" ";
        }
	std::cout<<"\n";
     }
    

  // Print transpose of the matrix, AT
     std::cout<<"\nAT:"<<"\n";
     for(int i=0;i<cols;i++){
        for (int j = 0; j<rows;j++){
        std::cout<<AT[i][j]<<" ";
        }
     std::cout<<"\n";
     }
   }
     
  // delete dynamically allocated memory for A
  for(int i=0;i<rows;i++){
  delete []A[i];
  }
  delete []A;
  A = nullptr;
 
 // delete dynamically allocated memory for AT
  for(int i=0;i<rows;i++){
    delete []AT[i];
  }
  delete []AT;
  AT = nullptr;
   
}

