#include<stdio.h>
#include<stdlib.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int rows, int cols);
void make_picture(int **picture, int rows, int cols);
void reset_picture(int **picture, int rows, int cols);

void main()
{
   int picture[N][M];
   make_picture(picture, N, M);
}

void make_picture(int **picture, int n, int m)
{
   int frame_w[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   int frame_h[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
   int tree_trunk[] = { 7, 7, 7, 7 };
   int tree_foliage[] = { 3, 3, 3, 3 };
   int sun_data[6][5] = { { 0, 6, 6, 6, 6 }, 
                          { 0, 0, 6, 6, 6 }, 
                          { 0, 0, 6, 6, 6 },
                          { 0, 6, 0, 0, 6 },
                          { 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0 } };

   reset_picture(picture, n, m);



   int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
   
   for (int i = 0; i < length_frame_w; i++)
   {
      picture[0][i] = frame_w[i];
   }
}

void reset_picture(int **picture, int rows, int cols)
{
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         picture[i][j] = 0;
      }  
   }
}

void transform(int *buf, int **matr, int rows, int cols)
{  
   for(int i = 0; i < rows; i++)
   {
      matr[i] = buf + i * cols;
   }
}

