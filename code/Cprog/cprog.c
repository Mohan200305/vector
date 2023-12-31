#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include "liv.h"   //include user defined library that contains required functions

int main()
{
    double **e1,**e2,**q1,**q2,**q,**X;  
     double k=11;
     X=loadtxt("X.dat",2,1);                     //matrix for the point vector X
     e1=loadtxt("e1.dat",3,1);                  //reading the values of matrix e1 from the dat file
    print(e1,3,1);   
    e2=scalarProduct(k,e1);                   //multiplying the scalar value with the matrix e1
    print(e2,3,1);    
    q1=loadtxt("q1.dat",3,3);                  //reading the values of matrix q1 from the dat file
    print(q1,3,3);   
    q2=linalg_inv(q1,3,3);                    //inverse of the matrix q1
    print(q2,3,3);   
    q=matmul(q2,e2,3,1,1);                    //matrix multiplication of q2 and e2 which produces the resultant matrix q
    print(q,3,1);
    save_q(q,3,1);                           //saving the values of q in dat file which is the resultant matrix 
    return 0;
}

