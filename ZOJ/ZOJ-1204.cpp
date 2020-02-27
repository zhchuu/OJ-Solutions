#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;
int N;
int a[35];
bool isvis[35], flag;
void DFS(int start, int len, int sum)
{
	if (len != 0) {
		for (int i = start; i < N; i++) {
			if (sum + a[i] <= a[N - 1]) {
				sum += a[i];
				isvis[i] = true;
				len--;
				DFS(i + 1, len, sum);
				sum -= a[i];
				isvis[i] = false;
				len++;
			}//if
		}//for
	}//if
	else {
		for (int i = start; i < N&&sum >= a[i]; i++) {
			if (sum == a[i]) {
				flag = true;
				for (int j = 0; j <= i; j++) {
					if (isvis[j])
					{
						if (sum == a[j])
							printf("%d=%d\n", a[j], a[i]);
						else
							printf("%d+", a[j]);
						sum -= a[j];
					}//if
				}//for
			}//if
		}//for
	}//else
}
int main()
{
	int kase;
	scanf_s("%d", &kase);
	while (kase--) {
		scanf_s("%d", &N);
		for (int i = 0; i < N; i++)
			scanf_s("%d", &a[i]);
		flag = false;
		memset(isvis, false, sizeof(isvis));
		sort(a, a + N);
		for (int i = 2; i < N; i++) {
			DFS(0, i, 0);
		}//for
		if (!flag)
			printf("Can't find any equations.\n\n");
		else
			printf("\n");
	}//while
}
