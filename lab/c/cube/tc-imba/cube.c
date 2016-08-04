#include <stdio.h>
#include <stdlib.h>

#define SIZE_X 3
#define SIZE_Y 3
#define SIZE_Z 3
#define EXTRA

char cube[7][12] = {'*', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '*', '/', ' ', ' ', ' ', ' ', ' ',
                    ' ', ' ', ' ', '|', '*', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '|', '/', '_', '_', '_',
                    '_', '_', '_', '_', ' ', '/', ' ', '|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '/',
                    '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '/', '*', '|', '_', '_', '_', '_', '_', '_', '_',
                    '|', '/', '*', '*'};
int pow2[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

int main()
{
    int A[SIZE_X][SIZE_Y] = {2, 0, 0, 1, 0, 0, 2, 0, 0}, i, j, k, m, n, min = 0, max = 0, z, *D[SIZE_X][SIZE_Y];
    FILE *fphzk = fopen("out.txt", "wt");
#ifndef EXTRA
    for (i = 0; i < SIZE_X; i++)
    {
        for (j = 0; j < SIZE_Y; j++)
        {
            A[i][j] > max ? max = A[i][j] : (A[i][j] < min ? min = A[i][j] : 1);
        }
    }
    for (i = 0, z = max - min; i < SIZE_X; i++)
    {
        for (j = 0; j < SIZE_Y; j++)
        {
            D[i][j] = (int *) malloc(sizeof(int) * (z));
            for (k = 0; k < z; k++)
            {
                D[i][j][k] = (k >= -min && k < A[i][j] - min && A[i][j] >= 0 ||
                              k >= -A[i][j] - 1 && k < -min && A[i][j] < 0 ? 1 : 0);
            }
        }
    }
#else
    int E[SIZE_X][SIZE_Z] = {0}, B[SIZE_Y][SIZE_Z] = {2, 1, 2, 0, 0, 0, 0, 0, 0};
    z = SIZE_Z;
    for (i = 0; i < SIZE_X; i++)
    {
        for (j = 0; j < SIZE_Y; j++)
        { D[i][j] = (int *) malloc(sizeof(int) * (z)); }
    }
    for (j = 0; j < SIZE_Y; j++)
    {
        int FLAG = 0;
        for (m = 0; m < pow2[SIZE_X * SIZE_Z]; m++)
        {
            int F[SIZE_X] = {0}, G[SIZE_Z] = {0}, flag = 1;
            for (n = 0, k = m; n < SIZE_X * SIZE_Z; n++)
            {
                E[n / SIZE_X][n % SIZE_X] = k / pow2[SIZE_X * SIZE_Z - 1 - n];
                k %= pow2[SIZE_X * SIZE_Z - 1 - n];
                F[n / SIZE_X] += E[n / SIZE_X][n % SIZE_X];
                G[n % SIZE_Z] += E[n / SIZE_X][n % SIZE_X];
            }
            for (i = 0; i < SIZE_X; i++)
            {
                if (A[i][j] != F[i])
                {
                    flag = 0;
                    break;
                }
            }
            for (k = 0; k < SIZE_Z && flag; k++)
            {
                if (B[j][k] != G[k])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                for (i = 0, FLAG = 1; i < SIZE_X; i++)
                {
                    for (k = 0; k < SIZE_Z; k++)
                    { D[i][j][k] = E[i][k]; }
                }
                break;
            }
        }
        if (FLAG == 0)
        {
            printf("failed");
            fclose(fphzk);
            return -1;
        }
    }
#endif
    char **C = (char **) malloc(sizeof(char *) * (3 * (SIZE_X + z) + 4));
    for (i = 0; i < 3 * (SIZE_X + z) + 4; i++)
    {
        C[i] = (char *) malloc(8 * SIZE_Y + 3 * (SIZE_X - 1) + 21);
        C[i][8 * SIZE_Y + 3 * (SIZE_X - 1) + 20] = '\0';
        for (j = 0; j < 8 * SIZE_Y + 3 * (SIZE_X - 1) + 20; j++)
        { C[i][j] = ' '; }
    }
    for (k = 0; k < z; k++)
    {
        for (j = 0; j < SIZE_Y; j++)
        {
            for (i = 0; i < SIZE_X; i++)
            {
                for (m = 0; m < 7 && D[i][j][k]; m++)
                {
                    for (n = 0; n < 12; n++)
                    {
                        char *c = &C[3 * i + 3 * (z - 1 - k) + m][3 * (SIZE_X - 1 - i) + 8 * j + n];
                        (m == 0 && n == 3 || m == 4 && n == 11) && *c != ' ' ||
                        m == 0 && cube[m][n] == '_' && (*c == '|' || *c == '/') ? 1 : (cube[m][n] == '*' ? 1
                                                                                                         : (*c = cube[m][n]));
                    }
                }
            }
        }
    }
    for (i = 0; i < 3 * (SIZE_X + z) + 4; i++)
    { fprintf(fphzk, "%s\n", C[i]); }
    fclose(fphzk);
    return 0;
}
