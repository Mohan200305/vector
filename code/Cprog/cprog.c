#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "liv.h"

int main()
{
       double **e1,**e2,**q1,**q2,**q,**X;     
       double theta = 30.0,theta1=90.0;
    double radian = theta * (M_PI / 180.0);    //converting the values of degrees into radians
    double radian1 = theta1 *(M_PI / 180.0);
    X=matX(0,0);                               //matrix for the point vector X
    e1=mate1(1,0,0);                           //matrix for basic vector e1 
    print(e1,3,1);   
    e2=scalarProduct(11,e1);                   //multiplying the scalar value with the matrix e1
    print(e2,3,1);    
    q1=matq1(1,1,1,-1,cos(radian1),cos(radian),0,sin(radian1),-sin(radian));        //matrix q1 
    print(q1,3,3);   
    q2=linalg_inv(q1,3,3);                    //inverse of the matrix q1
    print(q2,3,3);   
    q=matmul(q2,e2,3,1,1);                    //matrix multiplication of q2 and e2 which produces the resultant matrix q
    print(q,3,1);
    save_X(X,2,1);                           //saving the values of X in dat file
    save_e1(e1,3,1);                         //saving the values of e1 in dat file
    save_q1(q1,3,3);                         //saving the values of q1 in dat file
    save_q(q,3,1);                           //saving the values of q in dat file which is the resultant matrix 
    return 0;
}

