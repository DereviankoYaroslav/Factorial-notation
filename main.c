#include <stdio.h>
#include <math.h>

void sortComb (int *s, int N);
void sortAndFind(int *func, int size);

int main( )
{
    int x = 100;
    int n = 5;
    int q = 1;
    int counter = n-1;
    int positions[n];
    while (counter > 0){
        int temp = floor(x/q);
        printf("\n%d", temp);
        int val = x - (temp*q);
        printf("\n%d", val);
        positions[counter] = val;
        x = temp;
        ++q;
        counter--;
    }
    positions[counter] = x;
    printf("\n\nPOSITIONS VECTOR\n");
    for (int i = 0; i <n ; ++i){
        printf("%d ",positions[i]);
    }
    printf("\n");
    int result[n];
    int fx [] = {1,2,3,4};
    int fx2 [] = {3,2,1,0};
    int tempArr [n];
    int flags [] = {3,2,1,0};
    for (int c = 0; c < n; ++c){
        tempArr[c] = fx2[c];
    }
    int flag = 0;
    int innerCounter = n;
    for (int q = 0; q < n; ++q){
        for (int m = 0; m < n; ++m){
            printf("%d ", tempArr[m]);
            if (tempArr[m] == innerCounter) {
                int y = m;
                for (int t = y; t < n; ++t) {
                    if (tempArr[y] > tempArr[t]) {
                        ++flag;
                    }
                }
            }
        }
        printf("\nflag %d, \n",flag);
        printf("\nposition %d, \n",positions[q]);
        //int k = 0;
        if (flag > positions[q]) {
            int temp = tempArr[flag-positions[q]];
            tempArr[flag-positions[q]] = tempArr[q];
            tempArr[q] = temp;
        }
        flag = 0;
        innerCounter--;
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < n; ++i){
        printf("%d ",tempArr[i]);
    }
    printf("\n");
    /*for (int i = 0; i < n; ++i){
        for (int j = 0; j  < n; ++j) {
            if (positions[i] < fx[j]) {
                result[i] = fx[j];
                fx[j] = 0;
                break;
            }
        }
    }
    printf("\n");
    printf("\n");*/
    /*for (int i = 0; i < n; ++i){
        //result[i] = result[i]-1;
        printf("%d ",result[i]);
    }*/
    printf("\n");
    //int fx3 [] = {1,2,3,4};
    //sortAndFind(fx3,4);
    /*while (q < n){
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
    positions[counter] = x;*/
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
