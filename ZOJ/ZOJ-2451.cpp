#include<stdio.h>
#define INF 1000000
const int maxn = 50000 + 5;
struct node
{
	int l, r;
	int key;
}tree[3 * maxn];
void buildtree(int i, int le, int ri)//
{
	tree[i].l = le;
	tree[i].r = ri;
	if (le == 1)
		tree[i].key = 0;
	else
		tree[i].key = INF;
	int mid = (le + ri) / 2;
	if (le < ri)
	{
		buildtree(2 * i, le, mid);
		buildtree(2 * i + 1, mid + 1, ri);
	}
}
void check(int i, int le, int ri, int &k)
{
	int mid = (tree[i].l + tree[i].r) / 2;
	if (le <= tree[i].l&&ri >= tree[i].r) {
		if (tree[i].key < k)
			k = tree[i].key;
	}
	if (le <= mid&&tree[i].l != tree[i].r)
		check(2 * i, le, ri, k);
	if (ri > mid&&tree[i].l != tree[i].r)
		check(2 * i + 1, le, ri, k);
}
void tab(int i, int le, int ri, int k)
{
	int mid = (tree[i].l + tree[i].r) / 2;
	if (le <= tree[i].l&&ri >= tree[i].r) {
		if (tree[i].key > k + 1)
			tree[i].key = k + 1;
		return;
	}
	if (le <= mid&&tree[i].l != tree[i].r)
		tab(2 * i, le, ri, k);
	if (ri > mid&&tree[i].l != tree[i].r)
		tab(2 * i + 1, le, ri, k);
}
void outputAns(int leng)
{
	int i = 1;
	while (tree[i].l != leng)
		i = i * 2 + 1;
	//if (tree[i].key < 1000000)
		printf("%d\n", tree[i].key);
	//else
		//printf("%d\n", 0);
}
int main()
{
	int len, kase, left, right;
	while (scanf("%d%d", &len, &kase) != EOF)
	{
		buildtree(1, 1, len);//init
		while (kase--)
		{
			scanf("%d%d", &left, &right);
			int kk = INF;
			check(1, left, right - 1, kk);
			if (kk < 1000000)
				tab(1, left + 1, right, kk);
		}
		outputAns(len);
	}//end while
}
