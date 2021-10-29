#include <stdio.h>
#include <math.h>

void sortComb (int *s, int N);
void sortAndFind(int *func, int size);

int main( )
{
    int x = 100;
    int n = 5;
    int q = 2;
    int counter = n-2;
    int positions[n-1];
    while (q < n){
        int temp = floor((double)x/q);
        printf("\n%d", temp);
        int val = x - (temp*q);
        printf("\n%d", val);
        positions[counter] = val;
        x = temp;
        ++q;
        counter--;
    }
    printf("\n%d", x);
    positions[counter] = x;
    printf("\n\nPOSITIONS VECTOR\n");
    for (int i = 0; i < n-1; ++i){
        printf("%d ",positions[i]);
    }
    printf("\n");
    //int fx [] = {1,2,3,4,5,6};
    //sortAndFind(fx,6);
    return 0;
}

void sortComb (int *s, int N)
{
    int i,j;
    int buf;

    for ( i=0;i<N;i++)
        for ( j=N-1;j>i;j--)
            if (s[j]<s[j-1])
            {
                buf=s[j];
                s[j]=s[j-1];
                s[j-1]=buf;
            }

}

void sortAndFind(int *func, int size){
    int buf;
    int i,j,N,k,q;
    N=size;
    int counter = 0;

    sortComb(func, N);

    while (1) {
        printf("\n");
        printf("\n%d\n",counter);
        for (int m = 0; m < size; ++m) {
            printf("%d, ", func[m]);
        }
        printf("\n");

        int one = 0,zer = 0;

        for (int t = 0; t < size; ++t) {
            if (func[t] == 1) {
                ++one;
            } else if (func[t] == 0) {
                ++zer;
            }
        }

        for (i = N-2; i >= 0  && func[i] >= func[i+1] ; i--);
        if (i<0) break;
        for(j=N-1; func[i] >= func[j]; j--) ;
        buf = func[j];
        func[j] = func[i];
        func[i] = buf;

        for ( k=i+1, q=N-1; k < q; k++ , q-- )
        {   buf=func[k];
            func[k]=func[q];
            func[q]=buf;
        }
        one = 0;
        zer = 0;
        ++counter;
    }
    printf("\n");
}
