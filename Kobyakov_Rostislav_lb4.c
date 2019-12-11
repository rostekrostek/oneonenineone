#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int funccmp(const void * k, const void * m)                            
{
      int* k1 = (int*)k;
      int* m1 = (int*)m;
      if (*k1 > *m1)
        return 1;
      else if (*k1 == *m1)
        return 0;
      else
        return -1;                                           
}


int main() {
    int arr[1000];
    for (int i=0;i<1000;i++){
        scanf("%d",arr+i);
    }
    qsort(arr,1000,sizeof(int),funccmp);
    clock_t start=clock();
    int key=0;
      int* find=bsearch(&key,arr,1000,sizeof(int),funccmp);
      clock_t finish=clock();
    if(find==NULL)
        printf("doesn't exist\n");
    else
        printf("exists\n");
      printf("%ld \n",(finish-start)/CLOCKS_PER_SEC);
    find=NULL;
    start=clock();
    for (int i=0;i<1000;i++){
      if (arr[i]==0){
        find=arr+i;
        break;
        }
    } 
    finish=clock();

	if (find == NULL) 
		printf("doesn't exist\n");
	else 
		printf("exists\n");
	printf("%ld\n", (finish - start) / CLOCKS_PER_SEC);
  return 0;
}
