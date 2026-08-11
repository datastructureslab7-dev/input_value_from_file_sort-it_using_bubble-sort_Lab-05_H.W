#include <stdio.h>
int main(){
   int n=10, temp;
   int arr[10];

   FILE *myfile;
   myfile = fopen("unsorted_ value.txt", "r");

   for(int i=0; i<n; i++){
      fscanf(myfile, "%d", &arr[i]);
   }
   fclose(myfile);

   printf("Unsorte value from file :\n");
   for(int i=0; i<n; i++){
    printf("%d ",arr[i]);
   }

   for(int i=1; i<n; i++){
      for(int j=0; j<n-i; j++){
        
        if(arr[j] > arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
      }
   }

   printf("\nSorted value :\n");
   for(int i=0; i<n; i++){
    printf("%d ",arr[i]);
   }

    myfile = fopen("sorted_value.txt", "w");

    for(int i=0; i<n; i++){
        fprintf(myfile, "%d ", arr[i]);
    }


    return 0;
}
