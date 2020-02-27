#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000;
int main()
{
	int test_num, rock_num, arr[maxn], kase = 0, x;
	while (scanf_s("%d%d", &rock_num, &test_num) == 2 && rock_num) {
		printf("case# %d\n", ++kase);
		for (int i = 0; i < rock_num; i++) scanf_s("%d", &arr[i]);
		sort(arr, arr + rock_num);//
		while (test_num--) {
			scanf_s("%d", &x);
			int pos = lower_bound(arr, arr + rock_num, x) - arr;
			if (arr[pos] == x)	printf("%d found at %d\n", x, pos + 1);
			else
				printf("%d not found\n", x);
		}//while
	}//while
	return 0;
}