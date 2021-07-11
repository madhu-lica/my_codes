#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
int stsize;
int *frames;
int *refstr;
int fsize;
int pr[N];


void initialise();
void read_input();
void frprint();
int check(int f);
int min();
int max();
void FIFO();
void Optimal();
void LRU();
void LFU();


void main()
{

      printf("Page Replacement Algorithms\n");
      int choice;
      while(1)
      {
      printf("1.Read_Input\n2.FIFO\n3.Optimal\n4.LRU\n5.LFU\n6.Exit\nEnter your Option : ");
            scanf("%d",&choice);
            if(choice == 6)
                 exit(0);
            if(choice == 1)
               read_input();
            if(choice == 2)
                 FIFO();
            if(choice == 3)
                 Optimal();
            if(choice == 4)
                 LRU();
            if(choice == 5)
                 LFU();

      }


}


void initialise()
{
      for (int i = 0; i < fsize; ++i)
            frames[i] = -1;

      for (int i = 0; i < N; ++i)
           pr[i] = 0;
}

void read_input()
{
    printf("Enter size of reference string : ");
      scanf("%d",&stsize);

      refstr = (int*)malloc(stsize*sizeof(int));
    printf("Enter reference string : ");
      for (int i = 0; i < stsize; ++i)
      {
            scanf("%d",&refstr[i]);
      }
    printf("Enter number of frames : ");
      scanf("%d",&fsize);
      frames = (int*)malloc(fsize*sizeof(int));

}

void frprint()
{
     printf("|");
      for (int i = 0; i < fsize; ++i)
      {
           int x = frames[i];
            if(x==-1)
                 printf(" %2s ","-");
           else
                 printf(" %2d ", x);
      }
     printf("|");

}

int check(int f)
{
      for (int i = 0; i < fsize; ++i)
      {
      if(frames[i]==f)
                 return 1;
      }
      return 0;
}

int min()
{
      int min = 999;
      int amin = -1;

      for (int i = 0; i < fsize; ++i)
      {
        if(frames[i]!=-1 && min>pr[frames[i]]) {
                 min = pr[frames[i]];
                 amin = i;
           }
      }

      return amin;
}

int max()
{
      int max = 0;
      int amax = -1;

      for (int i = 0; i < fsize; ++i)
      {
        if(frames[i]!=-1 && max<pr[frames[i]]) {
                 max = pr[frames[i]];
                 amax = i;
           }
      }

      return amax;
}

void FIFO()
{
      printf("\t FIFO Page Replacement Algorithm\n\nPage ref-> memory           -> PF\n\n");
      int count = 0;
      int empty,flag;
    initialise();
      for (int i = 0; i < stsize; ++i)
      {
           empty = flag = 0;
           for (int j = 0; j < fsize; ++j)
           {
             if(frames[j]==-1) {
                      empty = 1;
                       frames[j] = refstr[i];
                     pr[refstr[i]] = i;
                       ++count;
                      flag = 1;
                       break;
                 }
           }

            if(!empty && !check(refstr[i])) {
                 int x = min();
                 frames[x] = refstr[i];
               pr[refstr[i]] = i;
                 ++count;
                 flag = 1;
           }

            printf("%2d -> ",refstr[i]);
            frprint();

            if(flag)
                 printf(" -> %3d\n", count);
           else
                 printf(" -> %3s\n","NO FAULT");

           
      }

  printf("\nTotal number of page faults : %d\n\n\n",count );
}

void Optimal()
{
      printf("\t Optimal Page Replacement Algorithm\n\nPage ref-> memory      -> PF\n\n");
      int count = 0;
      int empty,flag;
    initialise();

      for (int i = 0; i < stsize; ++i)
      ++pr[refstr[i]];

      for (int i = 0; i < stsize; ++i)
      {
           empty = flag = 0;
           for (int j = 0; j < fsize; ++j)
           {
             if(frames[j]==-1) {
                      empty = 1;
                       frames[j] = refstr[i];
                      --pr[refstr[i]];
                       ++count;
                      flag = 1;
                       break;
                 }
           }

            if(!empty && !check(refstr[i])) {
                 int x = min();
                 frames[x] = refstr[i];
                 --pr[refstr[i]];
                 ++count;
                 flag = 1;
           }
            printf("%2d -> ",refstr[i]);
            frprint();

            if(flag)
                 printf(" -> %3d\n", count);
           else
                 printf(" -> %3s\n","NO FAULT");

           
      }

  printf("\nTotal number of page faults : %d\n\n\n",count );
}


void LRU()
{
      printf("\t LRU Page Replacement Algorithm\n\nPage ref-> memory           -> PF\n\n");
      int count = 0;
      int empty,flag;
    initialise();
      for (int i = 0; i < stsize; ++i)
      {
           empty = flag = 0;
           for (int j = 0; j < fsize; ++j)
           {
             if(frames[j]==-1) {
                      empty = 1;
                       frames[j] = refstr[i];
                     pr[refstr[i]] = i;
                       ++count;
                      flag = 1;
                       break;
                 }
           }
            if(!empty && !check(refstr[i])) {
                 int x = min();
                 frames[x] = refstr[i];
               pr[refstr[i]] = i;
                 ++count;
                 flag = 1;
           }

          pr[refstr[i]] = i;
            printf("%2d -> ",refstr[i]);
            frprint();

            if(flag)
                 printf(" -> %3d\n", count);
           else
                 printf(" -> %3s\n","NO FAULT");

           
      }

  printf("\nTotal number of page faults : %d\n\n\n",count );
}

void LFU()
{
      printf("\t LFU Page Replacement Algorithm\n\nPage ref-> memory           -> PF\n\n");
      int count = 0;
      int empty,flag;
    initialise();
      for (int i = 0; i < stsize; ++i)
      {
           empty = flag = 0;
           for (int j = 0; j < fsize; ++j)
           {
             if(frames[j]==-1) {
                      empty = 1;
                       frames[j] = refstr[i];
                       ++count;
                      flag = 1;
                       break;
                 }
           }

            if(!empty && !check(refstr[i])) {
                 int x = min();
                 int old = frames[x];
                 frames[x] = refstr[i];

                 pr[old] = 0;
                 ++count;
                 flag = 1;
           }

          pr[refstr[i]] += 1;
            printf("%2d -> ",refstr[i]);
            frprint();

            if(flag)
                 printf(" -> %3d\n", count);
           else
                 printf(" -> %3s\n","NO FAULT");

           
      }

  printf("\nTotal number of page faults : %d\n\n\n",count );
}
