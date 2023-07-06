//Function declration
double **createMat(int m, int n);
double** matX(double v1, double v2);
double** mate1(double v1, double v2,double v3);
void print(double **p, int m,int n);
double** scalarProduct(double scalar, double **mat);
double** matq1(double v1, double v2,double v3,double v4,double v5,double v6,double v7,double v8,double v9);
double **linalg_inv(double **mat, int m, int n);
double **matmul(double **a, double **b, int m, int n, int p);
void save_X(double **a, int rows, int cols);
void save_e1(double **a, int rows, int cols);
void save_q1(double **a, int rows, int cols);
void save_q(double **a, int rows, int cols);
//End function declaration



//defining the function for matrix creation
double **createMat(int m, int n) { 
    int i, j; 
    double **a; 
     
    // Allocate memory to the pointer 
    a = (double **)malloc(m * sizeof(*a)); 
     
    for (i = 0; i < m; i++) { 
        a[i] = (double *)malloc(n * sizeof(*a[i])); 
        for (j = 0; j < n; j++) { 
            a[i][j] = 0.0; 
        } 
    } 
     
    return a; 
} 

//end function for the matrix creation


//Defining the function for creating matrix X 
double** matX(double v1, double v2) { 
    double **vector = (double **) malloc(2 * sizeof(*vector));  
    for(int i = 0; i < 2; i++){ 
     for(int j=0;j<1;j++){ 
        vector[i] = (double*) malloc(sizeof(vector)); 
     } 
    } 
    vector[0][0] = v1; 
    vector[1][0] = v2; 
     
 
    return vector; 
} 
//end function for matrix X


//Defining the function for creating matrix e1
double** mate1(double v1, double v2,double v3) { 
    double **vector = (double **) malloc(2 * sizeof(*vector));  
    for(int i = 0; i < 3; i++){ 
     for(int j=0;j<1;j++){ 
        vector[i] = (double*) malloc(sizeof(vector)); 
     } 
    } 
    vector[0][0] = v1; 
    vector[1][0] = v2; 
    vector[2][0] = v3; 
 
    return vector; 
} 
//end function for matrix X


//defining th funcion for printing of matrix 
void print(double **p, int m,int n)  
{  
 int i,j;  
  
 for(i=0;i<m;i++)  
 {  
  for(j=0;j<n;j++){ 
         printf("%lf ",p[i][j]); 
  } 
 printf("\n");  
 }  
}  
//end function for print matrix



//defining the function for multiplying a scalar value with the matrix
double** scalarProduct(double scalar, double **mat) { 
    double **product = (double**)malloc(2 * sizeof(*product)); 
    for(int i = 0; i < 3; i++) { 
     for(int j=0;j<1;j++){ 
        product[i] = (double*)malloc(sizeof(product)); 
             } 
    } 
 
    product[0][0] = mat[0][0] * scalar; 
    product[1][0] = mat[1][0] * scalar; 
    product[2][0] = mat[2][0] * scalar; 
 
    return product; 
} 

//end function for scalar multiplication


//definiing the function for crreating matrix q1
double** matq1(double v1, double v2,double v3,double v4,double v5,double v6,double v7,double v8,double v9) { 
    double **vector = (double**) malloc(2 * sizeof(*vector));  
 
    for(int i = 0; i < 3; i++){ 
     for(int j=0;j<3;j++){ 
               vector[i] = (double*) malloc(sizeof(vector)); 
     } 
    } 
    vector[0][0] = v1; 
    vector[0][1] = v2; 
    vector[0][2] = v3; 
    vector[1][0] = v4; 
    vector[1][1] = v5; 
    vector[1][2] = v6; 
    vector[2][0] = v7; 
    vector[2][1] = v8; 
    vector[2][2] = v9; 
return vector; 
} 
//end function for matrix q1


//defining the function for 3x3 inverse of a matrix
double **linalg_inv(double **mat, int m, int n) { 
    double **inv; 
    double det; 
 
    inv = createMat(m, n); 
     
    det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]) -  
          mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +  
          mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]); 
 
    // Calculate the adjoint matrix 
    inv[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) / det; 
    inv[0][1] = (mat[0][2] * mat[2][1] - mat[0][1] * mat[2][2]) / det; 
    inv[0][2] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) / det; 
    inv[1][0] = (mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2]) / det; 
    inv[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) / det; 
    inv[1][2] = (mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2]) / det; 
    inv[2][0] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) / det; 
    inv[2][1] = (mat[0][1] * mat[2][0] - mat[0][0] * mat[2][1]) / det; 
    inv[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) / det; 
 
    return inv; 
} 
//end function for inverse of matrix


//defining the function for multiplication of two matrices
double **matmul(double **a, double **b, int m, int n, int p) 
{ 
int i, j, k; 
double **c, temp =0; 
c = createMat(m,p); 
 
 for(i=0;i<m;i++) 
 { 
  for(k=0;k<p;k++) 
  { 
    for(j=0;j<n;j++) 
    { 
 temp= temp+a[i][j]*b[j][k]; 
    } 
 c[i][k]=temp; 
 temp = 0; 
  } 
 } 
return c; 
 
}
//end functon for martrix multiplication


//defining th function for saving the values of X in dat file
void save_X(double **a, int rows, int cols)
{ 
	FILE *fp;
        fp = fopen("X.dat", "w");  
  //fprintf(fp, "The result of the multiplication is:\n");
  int i, j;
  for (i = 0; i < rows; i++) {
    //fprintf(fp, "[");  
    for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);  
      if (j < cols - 1) {
        //fprintf(fp, ", ");    
	}
    }
    fprintf(fp, "\n");
  } 
  fclose(fp);
 }
//end function of X


//defiining the function for saving the values of e1
void save_e1(double **a, int rows, int cols) 
{
	FILE *fp;
  fp = fopen("e1.dat", "w");  
  //fprintf(fp, "The result of the multiplication is:\n");
  int i, j; 
  for (i = 0; i < rows; i++) {
    //fprintf(fp, "[");  
    for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);   
      if (j < cols - 1) {
        //fprintf(fp, ", ");     
	}
    }   
    fprintf(fp, "\n");
  } 
  fclose(fp);
}
//end function of e1


//defining the function for saving the values of q1
void save_q1(double **a, int rows, int cols) 
{
	FILE *fp;
  fp = fopen("q1.dat", "w");  
  //fprintf(fp, "The result of the multiplication is:\n");
  int i, j; 
  for (i = 0; i < rows; i++) {
    //fprintf(fp, "[");  
    for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);   
      if (j < cols - 1) {
        //fprintf(fp, ", ");     
	}
    }   
    fprintf(fp, "\n");
  } 
  fclose(fp);
}
//end function of q1 


//defining the function for saving the values of q(output values)
void save_q(double **a, int rows, int cols) 
{
	FILE *fp;
  fp = fopen("q.dat", "w");  
  //fprintf(fp, "The result of the multiplication is:\n");
  int i, j; 
  for (i = 0; i < rows; i++) {
    //fprintf(fp, "[");  
    for (j = 0; j < cols; j++) {
      fprintf(fp, "%lf", a[i][j]);   
      if (j < cols - 1) {
        //fprintf(fp, ", ");     
	}
    }   
    fprintf(fp, "\n");
  } 
  fclose(fp);
}
//end functiion of q
