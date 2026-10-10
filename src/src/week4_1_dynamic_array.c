   #include <stdio.h>
    #include <stdlib.h>

      int main(void)
{
    int n;
      printf("Enter number of element");
       if (scanf("%d", &n) !=1 || n<=0)
{
         printf("Invalid size.\n");
           return 1;}

     int *arr=malloc(n * sizeof(int));
        if (arr==NULL) {
        printf("Memory allocation failed.\n");
          return 1;}
         printf("Enter %d integers",n);
           long sum=0;
            for (int i=0;i<n;i++) 
    {
         if(scanf("%d", &arr[i]) !=1) {
             free(arr);
              printf("Invalid input.\n");
               return 1;}
              sum += arr[i];}
            double average =(double)sum / n;
           printf("Sum= %ld\n", sum);
            printf("Average= %.2f\n", average);
              free(arr);
             return 0; }