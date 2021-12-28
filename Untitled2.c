#include <stdio.h>
//#include<stdlib.h>
#include<time.h>
int countDistinct(int arr[], int n)
{
    int res = 1;

    // Pick all elements one by one
    for (int i = 1; i < n; i++) {
        int j = 0;
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j])
                break;

        // If not printed earlier, then print it
        if (i == j)
            res++;
    }
    return res;
}




int matric_type(int SIZE){

int row, col, isSymmetric,s,i=0 ;

    s=SIZE*SIZE;
    int A[SIZE][SIZE],a[s];  // Original matrix
    int B[SIZE][SIZE];  // Transpose matrix

    /* Input elements in matrix A from user */
    printf("Enter elements in matrix of size %dx%d: \n",SIZE,SIZE);
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            scanf("%d",&A[row][col]);
            a[i]=A[row][col];
            i++;
        }
    }


            printf("\n");
        for(row=0; row<SIZE; row++)
    {
        printf("| ");
        for(col=0; col<SIZE; col++)
        {
            printf(" %d ",A[row][col]);
        }
        printf("| \n");
    }



   srand(time(NULL));
   double t, start=clock();

    s=countDistinct(a,i);

    printf("Total distinct number: %d\n",s);



    /*
     * Find transpose of matrix A
     */
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            // Store each row of matrix A to each column of matrix B
            B[row][col] = A[col][row];
        }
    }



    // Check whether matrix A is equal to its transpose or not

    isSymmetric = 1;
    for(row=0; row<SIZE && isSymmetric; row++)
    {
        for(col=0; col<SIZE; col++)
        {
          //   If matrix A is not equal to its transpose
            if(A[row][col] != B[row][col])
            {
                isSymmetric = 0;
                break;
            }
        }
    }




    int j,x,y;

    for (i = 0; i <SIZE; i++) {
      for( j = 0; j <SIZE; j++) {
         if (A[i][j] != A[j][i])
            x = 1;
         else if (A[i][j] == -A[j][i])
            y = 1;
      }
   }
   if (x == 0){
      printf("The matrix is symmetric.\n ");
   t=(clock()-start);
   printf("\n\nTime  taken by this function is %.3f seconds\n\t\t or %11.0f nanoseconds\n",t/1000, t*1000000);
           for(row=0; row<SIZE; row++)
        {
            for(col=0; col<SIZE; col++)
            {
                printf("%d ", A[row][col]);
            }

            printf("\n");
        }
   }

   else if (y == 1){
       printf("The matrix is Anti symmetric.\n");
        t=(clock()-start);
   printf("\n\nTime  taken by this function is %.3f seconds\n\t\t or %11.0f nanoseconds\n",t/1000, t*1000000);
   }
      else if(x==0&&y==1)
   {
       printf("The matrix is Transitive");
       t=(clock()-start);
    printf("\n\nTime  taken by this function is %.3f seconds\n\t\t or %11.0f nanoseconds\n",t/1000, t*1000000);
//       return t;
   }
   else{
       printf("The matrix is Equivalence.\n ");
      t=(clock()-start);
  printf("\n\nTime  taken by this function is %.3f seconds\n\t\t or %11.0f nanoseconds\n",t/1000, t*1000000);
  // return t;
   }

   for (i = 0; i < SIZE; i++) {
      for (j = 0; j <SIZE; j++)
         printf(A[i][j]);
      printf( "\n ");
   }



}



int main()
{

int SIZE;
    printf("Enter Size of matrix : ");
    scanf("%d",&SIZE);
    matric_type(SIZE);


 return 0;
}
