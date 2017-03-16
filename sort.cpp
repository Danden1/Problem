#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Arr {
	char arr[51];
};
int compare(const void *a, const void *b) {
	Arr *aptr = (Arr *)a;
	Arr *bptr = (Arr *)b;
	return (strcmp(aptr->arr, bptr->arr));
}
Arr arr[50][20000];
int count[50]={ 0, };
int main() {
	int n,len;
	char tmp[51];
	scanf("%d", &n);
	bool check;
	for (int i = 0; i < n; i++) {
		check = false;
		scanf("%s", tmp);
		len = strlen(tmp)-1;
		for (int j = 0; j < count[len]; j++) {
			if (!strcmp(arr[len][j].arr, tmp)) {
				check = true; break;
			}
		}
		if (check)
			continue;
		strcpy(arr[len][count[len]].arr, tmp);
		count[len] += 1;
	}

	for (int i = 0; i < 50; i++) {
		qsort(&arr[i][0], count[i], sizeof(arr[i][0].arr), compare);
		for (int j = 0; j < count[i]; j++) {
			printf("%s\n", arr[i][j].arr);

		}
	}
	

}