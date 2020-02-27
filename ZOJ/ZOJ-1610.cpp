/*
 *zoj1610
 *Print a blank line after every dataset
*/

#include<stdio.h>
#include<memory.h>
//using namespace std;
const int maxn = 8000+5;
struct Node
{
	int l, r;
	int key;//-2 has branches,-1 no color and no branches
}tree[5*maxn];
int color[maxn];
void initTree(int i, int a, int b)
{
	tree[i].l = a;
	tree[i].r = b;
	if (b - a > 1) {
		initTree(2 * i, a, (a + b) / 2);//leftchild
		initTree(2 * i + 1, (a + b) / 2, b);//rightchild
	}
}
void paint(int i, int a, int b, int c)
{//
	int mid = (tree[i].l + tree[i].r) / 2;
	if (a <= tree[i].l&&b >= tree[i].r) {//paint this segment
		tree[i].key = c;//no branches any more
		return;
	}
	if (tree[i].key != -2) {//
		paint(2 * i, tree[i].l, mid, tree[i].key);
		paint(2 * i + 1, mid, tree[i].r, tree[i].key);
	}
	if (a < mid)
	{
		tree[i].key = -2;//has branches
		paint(2 * i, a, b, c);
	}
	if (b > mid)
	{
		tree[i].key = -2;//
		paint(2 * i + 1, a, b, c);
	}
}
//preorder
void preorder(int i,int &c)//i means index, c means previous color
{
	if (tree[i].key == -1){
		if (c == -1)//the previous color
			return;
		else{
			color[c]++;
			c = -1;//c = tree[i].key
			return;
		}//end else
	}//endif
	else if (tree[i].key == -2){//has branches
		preorder(2 * i, c);
		preorder(2 * i + 1, c);
	}//end else if
	else {//has color
		if (c == tree[i].key)//same
			return;
		else {//different color
			if(c!=-1)
				color[c]++;
			c = tree[i].key;
		}
	}//end else
	return;
}
void init()
{
	memset(color, 0, sizeof(color));
	/*for (int i = 0; i <= 2*maxn; i++) {
		tree[i].key = -1;
	}*/
	initTree(1, 0, maxn);
	tree[1].key = -1;
}
int main()
{
	int kase, le, ri, col;	
	initTree(1, 0, maxn);//
	while (scanf("%d", &kase) != EOF&&kase) {
		//init();
		memset(color, 0, sizeof(color));//
		tree[1].key = -1;
		while (kase--) {
			scanf("%d%d%d", &le, &ri, &col);
			paint(1, le, ri, col);
		}//end while
		int cc = -1;
		preorder(1, cc);
		for (int i = 0; i < maxn; i++)
		{
			if(color[i])
				printf("%d %d\n", i, color[i]);
		}
		printf("\n");
	}//end while
}
