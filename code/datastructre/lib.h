#include <stdio.h> 
#include <stdlib.h> 
 
// Node structure for linked list representation of matrix 
typedef struct Node { 
    double data; 
    int row; 
    int col; 
    struct Node* right; 
    struct Node* down; 
} Node; 
 
// Function to create a new node 
Node* createNode(double data, int row, int col) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = data; 
    newNode->row = row; 
    newNode->col = col; 
    newNode->right = NULL; 
    newNode->down = NULL; 
    return newNode; 
} 
 
// Function to insert a node at the end of a linked list 
void insertNode(Node** head, double data, int row, int col) { 
    Node* newNode = createNode(data, row, col); 
    if (*head == NULL) { 
        *head = newNode; 
        return; 
    } 
    Node* temp = *head; 
    while (temp->right != NULL) 
        temp = temp->right; 
    temp->right = newNode; 
} 

//function to create matrix q1
Node* createMatrix(int rows, int cols) { 
    Node* head = NULL; 
    FILE* fp = fopen("matrix.dat", "r"); 
    if (fp == NULL) { 
        printf("Failed to open the file.\n"); 
        return head; 
    } 
 
    double data; 
    // Create an array of Node* pointers, one for each column
    Node** colHeads = (Node**)malloc(sizeof(Node*) * cols);
    // Initialize them to NULL
    for (int i = 0; i < cols; i++)
        colHeads[i] = NULL;
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            fscanf(fp, "%lf", &data); 
            if (data != 0) {
                // Insert the node as before
                insertNode(&head, data, i, j); 
                Node* temp = head;
                while (temp->right != NULL)
                    temp = temp->right;

                if (colHeads[j] != NULL)
                    colHeads[j]->down = temp;
                // Update the colHeads array with the current node
                colHeads[j] = temp;
            } 
        } 
    } 
    fclose(fp); 

    free(colHeads);
    return head; 
}
//end function for matrix q1

//function for creation of  matrix e1
Node* createMatrix1(int rows, int cols) { 
    Node* head = NULL; 
    FILE* fp = fopen("e1.dat", "r"); 
    if (fp == NULL) { 
        printf("Failed to open the file.\n"); 
        return head; 
    } 
 
    double data; 
    // Create an array of Node* pointers, one for each column
    Node** colHeads = (Node**)malloc(sizeof(Node*) * cols);
    // Initialize them to NULL
    for (int i = 0; i < cols; i++)
        colHeads[i] = NULL;
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            fscanf(fp, "%lf", &data); 
            if (data != 0) {
                // Insert the node as before
                insertNode(&head, data, i, j); 
                // Get the last inserted node
                Node* temp = head;
                while (temp->right != NULL)
                    temp = temp->right;
                // Update the down pointer of the previous node in the same column, if any
                if (colHeads[j] != NULL)
                    colHeads[j]->down = temp;
                // Update the colHeads array with the current node
                colHeads[j] = temp;
            } 
        } 
    } 
    fclose(fp); 
    // Free the colHeads array
    free(colHeads);
    return head; 
}
//end functon formatrix e1

// Function to print the matrix 
void printMatrix(Node* head, int rows, int cols) { 
    Node* temp = head; 
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            if (temp != NULL && temp->row == i && temp->col == j) { 
                printf("%lf ", temp->data); 
                temp = temp->right; 
            } else { 
                printf("0.0 "); 
            } 
        } 
        printf("\n"); 
    } 
} 
 
// Function to perform scalar multiplication on a matrix 
Node* scalarProduct(Node* head, double scalar) { 
    Node* temp = head; 
    while (temp != NULL) { 
        temp->data *= scalar; 
        temp = temp->right; 
    } 
    return head; 
} 
// Function to perform matrix multiplication
Node* matrixMultiply(Node* matrix1, Node* matrix2) {
    Node* result = NULL;
    Node* temp1 = matrix1;
    // Traverse the rows of matrix1
    for (int i = 0; i < 3; i++) {
        // Get the only element of matrix2 in the current column
        Node* temp2 = matrix2;
        while (temp2 != NULL && temp2->col != i)
            temp2 = temp2->down;
        // If the element exists
        if (temp2 != NULL) {
            double sum = 0;
            // Traverse the columns of matrix1 in the current row
            for (int j = 0; j < 3; j++) {
                // Get the element of matrix1 that matches with the row of temp2
                Node* temp3 = temp1;
                while (temp3 != NULL && temp3->col != temp2->row)
                    temp3 = temp3->right;
        
                if (temp3 != NULL) {
                    sum += (temp3->data * temp2->data);
                }
        }
            insertNode(&result, sum, i, 0);
        }
        // Move to the next row of matrix1
        temp1 = temp1->down;
    }
    // Return the result matrix
    return result;
} 
 //saving the resultant matrix in dat file
void createDatMat(char* filename, Node* head) {
    FILE *fp = fopen(filename, "w");
    Node *rp, *dp = head;
    
    while (dp) {
        rp = dp;       
        while (rp) {
            fprintf(fp, "%lf" ,rp->data);
            rp = rp->right;
        }
        fprintf(fp, "\n");
        dp = dp->down;
    }
}
