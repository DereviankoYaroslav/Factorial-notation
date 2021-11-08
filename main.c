#include <stdio.h>
#include <math.h>
#include <malloc.h>

int *numberToFactorial(int x, int n);
int *numberToSubstitution(int *number, int size);
int *substitutionToFactorial(int *sub, int size);
int factorialCounting(int x);
int factorialNumberToNumber(int *number, int size);

int main(){

    int n = 5;
    int x = 100;
    printf("START NUMBER\n");
    printf("%d\n ",x);
    int *arr = numberToFactorial(x,n);
    int *sub = numberToSubstitution(arr,n);
    printf("\n\nSUBSTITUTION\n");
    for (int i = 0; i < n; ++i){
        printf("%d ",sub[i]);
    }
    int *factNum = substitutionToFactorial(sub,n);
    printf("\n\nFACTORIAL NUMBER\n");
    for (int j = 0; j < n; ++j){
        printf("%d ",factNum[j]);
    }
    printf("\n");
    int number = factorialNumberToNumber(factNum,n);
    printf("\nFINAL NUMBER\n");
    printf("%d\n ",number);
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
            //printf("%d, ",emptyPos[k]);
        }
        for (int q = 0; q < newSize; ++q){
            if (q==number[newSize-1]){
                //printf("q = %d ",q);
                //printf("MT pos = %d ",emptyPos[q]);
                S[emptyPos[q]] = 1;
                result[coeffNum] = emptyPos[q];
                ++coeffNum;
            }
        }
        innerCounter = 0;
        //printf("\n");
        for (int k =0; k <size; ++k){
            //printf("%d, ",S[k]);
        }
        //printf("\n");
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
    free(S);
    return subRev;
}

int *numberToFactorial(int x, int n){
    int q = 2;
    int counter = n-2;
    int *positions = calloc (n,sizeof(int));
    positions[n-1] = 0;
    while (counter > 0){
        int temp = floor(x/q);
        //printf("\nq = %d ",q);
        //printf("\n%d", temp);
        int val = x - (temp*q);
        //printf("\n%d", val);
        positions[counter] = val;
        x = temp;
        ++q;
        counter--;
    }
    positions[counter] = x;
    printf("\nPOSITIONS VECTOR\n");
    for (int i = 0; i < n ; ++i){
        printf("%d ",positions[i]);
    }
    int *positionsRev = calloc (n,sizeof(int));
    for (int r = 0,t = n-1; r < n, t>=0; ++r, t--){
        positionsRev[t] = positions[r];
    }
    //printf("\n\nPOSITIONS VECTOR\n");
    for (int i = 0; i < n ; ++i){
        //printf("%d ",positionsRev[i]);
    }
    //printf("\n");
    free(positions);
    return positionsRev;
}

int *substitutionToFactorial(int *sub, int size) {
    int *result = calloc(size,sizeof(int));
    int value = size;
    int flag = 0;
    int innerCounter = 0;
    int counter = 0;
    while (counter<size) {
        for (int i = 0; i < size; ++i) {
            if (flag == 1 && sub[i] < value) {
                ++innerCounter;
            }
            if (sub[i] == value) {
                flag = 1;
            }
        }
        //printf("IC = %d ",innerCounter);
        result[counter] = innerCounter;
        innerCounter = 0;
        flag = 0;
        ++counter;
        value--;
    }
    return result;
}

int factorialCounting(int x){
    return (x==0) || (x==1) ? 1 : x* factorialCounting(x-1);
}

int factorialNumberToNumber(int *number, int size){
    int *numberRev = calloc (size,sizeof(int));
    int result = 0;
    for (int r = 0,t = size-1; r < size, t>=0; ++r, t--){
        numberRev[t] = number[r];
    }
    for (int i = 0; i < size; ++i){
        result += numberRev[i]*factorialCounting(numberRev[i]);
        //printf("\n%d ",result);
    }
    free(numberRev);
    return result;
}
