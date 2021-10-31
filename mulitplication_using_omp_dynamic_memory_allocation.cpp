#include <iostream>  
#include "Timer.h"
#include <cstdlib>
#include <omp.h>
#include <ctime>
using namespace std;
int main()  
{  
Timer mul_time("Multiplication time for two matrices");
srand((unsigned) time(0));
int rows,coulmns,i,j,k;    
cout<<"Enter number of rows :>>";    
cin>>rows;    
cout<<"Enter number of coulmns :>>";    
cin>>coulmns;
int** a = new int*[rows];
int** b = new int*[rows];
int** mul = new int*[rows];
if(rows==coulmns){
        // Decalaring arrays 
        for (int i = 0; i < rows; i++) {
        a[i] = new int[rows]; 
        b[i] = new int[rows];
        mul[i] = new int[rows];
         }
        for(i=0;i<rows;i++)    
        {    
        for(j=0;j<coulmns;j++)    
        {    
        //Generating random numbers from 1 to 100
        a[i][j] = 3;  
        }    
        }    
        for(i=0;i<rows;i++)    
        {    
        for(j=0;j<coulmns;j++)    
        {  
        //Generating random numbers from 1 to 100  
        b[i][j] = 2;    
        }    
        }    
        mul_time.Start();   
        int number_of_threads = 4;
        #pragma omp parallel private(i,j,k) shared(mul,a,b) num_threads(number_of_threads)
        {
        #pragma omp for  schedule(static)
        for(i=0;i<rows;i++)    
            {    
                   for(j=0;j<coulmns;j++)    
                    {    
                          mul[i][j]=0;    
                    for(k=0;k<coulmns;k++)    
                    {    
                         mul[i][j]+=a[i][k]*b[k][j]; 
                     }    
                }
            }

        }
        mul_time.Stop();
        mul_time.Print();    
        cout << "Matrix 1\n";   
        for(i=0;i<rows;i++)    
        {    
        for(j=0;j<coulmns;j++)    
        {
            cout<<a[i][j]<<" ";    

        }
            cout<<"\n"; 

        }    

        cout << "Matrix 2\n";   
        for(i=0;i<rows;i++)    
        {    
        for(j=0;j<coulmns;j++)    
        {
            cout<<b[i][j]<<" ";    

        }
            cout<<"\n"; 

        }  
        //for printing result 
        cout << "Final Result\n";   
        for(i=0;i<rows;i++)    
        {    
        for(j=0;j<coulmns;j++)    
        {
            cout<<mul[i][j]<<" ";    

        }
            cout<<"\n"; 

        }
        mul_time.Print();        
        return 0;   


    // deallocate memory using the delete operator
    for (int i = 0; i < rows; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] mul[i];

    }
    delete[] a;
    delete[] b;
    delete[] mul;
        
    }    
    else{
    cout << "We are multilying only square matrices\n";
    }

}