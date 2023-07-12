#include "lib.h"
#include<math.h>
 
int main() { 
 
    Node* q2 = createMatrix(3, 3); 
    Node* X = createMatrix(2,1);

    printMatrix(q2, 3, 3); 
 
    double k = 11; 
    Node* e1 =createMatrix1(3, 1); 
    Node* e2 = scalarProduct(e1, k); 
    printf("Scalar Product Matrix:\n"); 
    printMatrix(e2, 3, 1); 
 
    Node* multipliedMatrix = matrixMultiply(q2,e2); 
    printf("Multiplied Matrix:\n"); 
    printMatrix(multipliedMatrix, 3, 1); 
    createDatMat("q.dat",multipliedMatrix);
    createDatMat("X.dat",X);
 
    return 0; 
}
