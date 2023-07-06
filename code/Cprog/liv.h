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
