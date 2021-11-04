#include <stdio.h>
#include <math.h>
#include <malloc.h>

void sortComb (int *s, int N);
void sortAndFind(int *func, int size);
void factorialCS (int x, int n);
int *numberToFactorial(int x, int n);
int *numberToSubstitution(int *number, int size);

int main(){

    int n = 5;
    int *arr = numberToFactorial(114,n);
    //int mass [] = {0,1,0,0};
    int *sub = numberToSubstitution(arr,n);
    printf("\n\nRESULT\n");
    for (int i = 0; i < n; ++i){
        printf("%d, ",sub[i]);
    }
    printf("\n");
}

int *numberToSubstitution(int *number, int size){
    int *S = calloc (size,sizeof(int));
    int *result = calloc (size,sizeof(int));
    int newSize = size;
    int counter = 0;
    int coeffNum = 0;
    int innerCounter = 0;
    while(counter < size){
        int *emptyPos = calloc (newSize,sizeof(int));
        for (int i = 0; i < size; ++i){
            if (S[i]==0){
                emptyPos[innerCounter] = i;
                innerCounter++;
            }
        }
        for (int k =0; k <newSize; ++k){
            printf("%d, ",emptyPos[k]);
        }
        for (int q = 0; q < newSize; ++q){
            if (q==number[newSize-1]){
                printf("q = %d ",q);
                printf("MT pos = %d ",emptyPos[q]);
                S[emptyPos[q]] = 1;
                result[coeffNum] = emptyPos[q];
                ++coeffNum;
            }
        }
        innerCounter = 0;
        printf("\n");
        for (int k =0; k <size; ++k){
            printf("%d, ",S[k]);
        }
        printf("\n");
        ++counter;
        newSize--;
        free(emptyPos);
    }
    int numberInArr = size;
    int *sub = calloc (size,sizeof(int));
    for (int u = 0; u < size; ++u){
        sub[result[u]] = numberInArr;
        numberInArr--;
    }
    free(result);
    int *subRev = calloc (size,sizeof(int));
    for (int r = 0,t = size-1; r < size, t>=0; ++r, t--){
        subRev[t] = sub[r];
    }
    free(sub);
    return subRev;
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
void factorialCS (int x, int n){
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
    int substitution [] = {0,0,0,0,0};
    int arrVal = n;
    int newN = n;
    for (int i = 0; i < n; ++i){
        printf("\nposi = %d ",newN-positions[i]);
        printf("\narrval = %d ",arrVal);
        if(substitution[newN-positions[i]-1]==0) {
            substitution[newN - positions[i] - 1] = arrVal;
        }
            /*else if (substitution[newN-positions[i]-1]==0&&positions[i]==0){
                substitution[newN - positions[i]] = arrVal;
            }*/
        else if (substitution[newN-positions[i]-1]!=0&&positions[i]==0){
            int newnewN = newN;
            while(substitution[newnewN-positions[i]-1]>arrVal){
                newnewN++;
            }
            printf("newnewN %d ", newnewN);
            substitution[newnewN - positions[i]] = arrVal;
            printf("arrval = %d",arrVal);
        }
        else if (substitution[newN-positions[i]-1]!=0&&positions[i]!=0){
            substitution[newN - positions[i]+1] = arrVal;
        }
        arrVal--;
        newN--;
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < n; ++i){
        printf("%d ", substitution[i]);
    }
}

int *numberToFactorial(int x, int n){
    int q = 1;
    int counter = n-1;
    int *positions = calloc (n,sizeof(int));
    while (counter > 0){
        int temp = floor(x/q);
        printf("\nq = %d ",q);
        printf("\n%d", temp);
        int val = x - (temp*q);
        printf("\n%d", val);
        positions[counter] = val;
        x = temp;
        ++q;
        counter--;
    }
    positions[counter] = x;
    int *positionsRev = calloc (n,sizeof(int));
    for (int r = 0,t = n-1; r < n, t>=0; ++r, t--){
        positionsRev[t] = positions[r];
    }
    printf("\n\nPOSITIONS VECTOR\n");
    for (int i = 0; i < n ; ++i){
        printf("%d ",positionsRev[i]);
    }
    printf("\n");
    free(positions);
    return positionsRev;
}