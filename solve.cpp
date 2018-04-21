#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;

int opredelitel(double **mas,int n);
void dp(double **mas,int n);
void transp(double **mas,int n);
void GetMatr(double **mas, double **p, int i, int j, int n);
void Print(double **mas, int n);
int main()
{
    int  i,j,n,d;
    setlocale(LC_ALL,"");
    cout << "Введите количество строк для квадратной матрицы" << endl;
    cin >> n ;
    cout << n<<endl;
    double **matriza;
    matriza=new double* [n];
    for(i=0;i<n;i++)
    {
        matriza[i]=new double [n];
    }
    for (i = 0; i<n; i++)
    {
      for (j = 0; j<n; j++)
      {
         cout << "mas[" << i << "][" << j << "]= ";
         cin >> matriza[i][j];
      }
    }
    d = opredelitel(matriza, n);
    cout<<"Определитель равен:  "<< d <<endl;
    dp(matriza,n);
    transp(matriza,n);

    for (i = 0; i<n; i++)
    {
      for (j = 0; j<n; j++)
      {
         matriza[i][j]/=d;
      }
    }
    Print(matriza,n);
    for (int i=0; i<n; i++)
    {
        delete matriza [i];
    }
    delete [] matriza;


    return 0;
}
int opredelitel(double **mas,int n)
{
   int i, j, d, k, m;
   double **p;
   p = new double*[n];
   for (i = 0; i<n; i++)
   {
       p[i] = new double[n];
   }
   i = 0; d = 0;
   k = 1;
   m = n - 1 ;
   if(n>2)
   {
      for (j = 0; j<n; j++)
      {
          GetMatr(mas, p, 0, j, m);
          d = d + k * mas[0][j] * opredelitel(p, m);
          k = -k;
      }
      return d;
   }
   else if(n==1)
   {
       d=mas[0][0];
       return d;
   }
   else
   {
       d=mas[0][0]*mas[1][1]-mas[1][0]*mas[0][1];
       return d;
   }

}
void GetMatr(double **mas, double **p, int i, int j, int m)
{
  int ki, kj, di, dj;
  di = 0;
  for (ki = 0; ki<m; ki++)
    {
        if (ki == i)
        {
            di = 1;
        }
        dj = 0;
        for (kj = 0; kj<m; kj++)
        {
            if (kj == j)
            {
                dj = 1;
            }
            p[ki][kj] = mas[ki + di][kj + dj];
        }
    }
}
void dp(double **mas,int n)
{
    int i,j,k;
    double **p,**mas2;
    p = new double*[n];
    mas2 = new double*[n];
    for (i = 0; i<n; i++)
    {
       p[i] = new double[n];
    }
    for (i = 0; i<n; i++)
    {
       mas2[i] = new double[n];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            mas2[i][j]=mas[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((j+i)%2==0)
            {
                k=1;
            }
            else
            {
                k=-1;
            }
            GetMatr(mas2,p,i,j,n-1);
            mas[i][j]=k*opredelitel(p,n-1);
        }

    }
}
void transp(double **mas,int n)
{
    int i,j;
    double mas2[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            mas2[i][j]=mas[i][j];
        }

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            mas[i][j]=mas2[j][i];
        }

    }
}

void Print(double **mas, int n)
{
  int i, j;
  for (i = 0; i<n; i++)
  {
      for (j = 0; j<n; j++)
      {
          cout << mas[i][j] <<"   ";

      }
      cout << endl;
  }
}

