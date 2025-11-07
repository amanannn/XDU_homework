#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1;i >= 0;i--){
        if (digits[i] != 9){
            digits[i]++;
            *returnSize = digitsSize;
            int *result = (int *)malloc(digitsSize * sizeof(int));
            for (int j = 0;j < digitsSize;j++){
                result[j] = digits[j];
            }
            return result;
        }else{
            digits[i] = 0;
        }
    }

    *returnSize = digitsSize + 1;
    int *result = (int *)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;
    for (int i = 1;i < digitsSize+1;i++){
        result[i] = 0;
    }
    return result;
}

int main()
{
	int n;
	scanf("%d",&n);
	int digits[n];
	int returnSize;
	for (int i = 0;i < n;i++){
		scanf("%d",&digits[i]);
	}
	int *result = plusOne(digits,n,&returnSize);
	for (int i = 0;i < returnSize;i++){
		printf("%d",result[i]);
	}
	return 0;
}