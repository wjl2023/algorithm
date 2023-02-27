#include <iostream>
using namespace std;

//快排的主要思想：基于分治
//(1)确定分界点：直接确定左边界q[l];取中间值q[(l+r)/2];q[r];随机
//(2)根据分界点，重新调整区间。第一个区间所有数<=x，右边区间都>=。分界点上的数不一定是x
//(3)递归处理左右两段

//法一（暴力）：开两个额外数组，a[]和b[]，扫描整个数组，然后分别放到a[]和b[]，最后把a[]和b[]合到q[]里
//时间复杂度:O(n)

//法二：左右两个指针i,j，从左开始，i指的数小于等于x，就往右移动直到大于，就换j相反方向动
//i和j都停住的时候，两个所指的数交换位置，然后继续重复。直到i和j相遇后错位。
//i指针前面的数都是小于等于，j指针后面的数都是大于等于 

const int N = 1e6 + 10;
int n;
int q[N];

void quick_sort(int q[], int l, int r) {
	if (l >= r) return;//判断边界

	int x = q[l], i = l - 1, j = r + 1;
	while (i < j) {
		while (q[++i] < x);//只要小，就往后移
		while (q[--j] > x);
		if (i < j)
			swap(q[i], q[j]);//swap函数是交换两个数，没有这个函数可以用中间变量来实现
	}
	//下面重新划分边界进行迭代，下面用j来划分，上面int x=就不能是q[r]，否则会出现边界问题
	quick_sort(q, l, j);		//这里小心边界问题
	quick_sort(q, j + 1, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
	quick_sort(q, 0, n-1);
	for (int i = 0; i < n; i++) printf("%d", q[i]);
	return 0;

}