#include<cstdio>
const int maxn = 100000 + 5;
int right[maxn], left[maxn];
void link(int x, int y)//x is int the lest
{
	right[x] = y;
	left[y] = x;
}
void swap(int x, int y)
{
	int lx = left[x], rx = right[x], ly = left[y], ry = right[y];
	link(lx, y);
	link(y, rx);
	link(ly, x);
	link(x, ry);
}
void test(int n)
{
	int count = 0;
	for (int i = right[0]; count < n; count++) {
		printf("%d ", i);
		i = right[i];
	}
}
int main()
{
	int n, kase = 0 , m, op;
	while (scanf("%d%d", &n, &m) == 2) {
		int X, Y, Inturnflag = 0;//
		for (int i = 1; i <= n; i++) {
			left[i] = i - 1;
			right[i] = (i + 1) % (n + 1);
		}
		right[0] = 1; left[0] = n;
		while(m--)
		{
			scanf("%d", &op);
			if (op != 4) {//op == 1 or 2 or 3
				scanf("%d%d", &X, &Y);
				int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
				if (op != 3 && Inturnflag)
					op = 3 - op;
				switch (op) {
				case 1:
				{
					if (right[X] == Y&&left[Y] == X)//X has already been left of Y
						continue;//continue to while
					else {
						link(LX, RX);
						link(LY, X);
						link(X, Y);
					}
				}break;
				case 2:
				{
					if (right[Y] == X&&left[X] == Y)//X has already been right of Y
						continue;
					else {
						link(LX, RX);
						link(X, RY);
						link(Y, X);
					}
				}break;
				case 3:
				{
					swap(X, Y);
				}break;
				default:break;
				}//4switch
			}//3if
			else
				Inturnflag = 1;
			//test(n);
		}//2while
		//print
		int pos = 0;
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			pos = right[pos];
			if (i % 2 == 1)
			{
				//printf("%d ", pos);
				ans += pos;
			}
		}
		if (Inturnflag&&n % 2 == 0)
			ans = (long long)n*(n + 1) / 2 - ans;//if turnover and the size is even
		printf("Case %d: %lld\n", ++kase, ans);
	}//1while

}