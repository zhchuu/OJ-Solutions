#include<cstdio>
#include<cstring>
const int maxn = 100005;
char s[maxn];
int next[maxn];
int main()
{
	while (scanf("%s", s + 1) == 1) {
		int n = strlen(s + 1);
		int cur = 0, last = 0;
		next[0] = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '[')cur = 0;
			else if (s[i] == ']')cur = last;
			else {
				next[i] = next[cur];
				next[cur] = i;
				if (cur == last)last = i;//current is the last,update last
				cur = i;//update current
			}
		}
		for (int i = next[0]; i != 0; i = next[i])
			printf("%c", s[i]);
		printf("\n");
	}
}