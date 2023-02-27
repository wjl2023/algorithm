#include <iostream>
using namespace std;

//归并排序（稳定）
//也是基于分治的思想
//快排通过数来分治，而归并以数组的中间部分来分

//(1)确定分界点:mid=(l+r)/2
//(2)递归排序左边和右边。（左边和右边变成有序的）
//(3)归并：合二为一（两个序列都是有序的，从左到右再比较合起来，最后的那个总和也是有序的）

//排序算法稳定：原数列值相同，排序后位置不发生变化

const int N = 1e6 + 10;
int n;
int q[N],tmp[N];

void merge_sort(int q[], int l,int r) {
	if (l >= r)return;
	int mid = (l + r) >> 1;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);	//递归排序左边和右边

	//归并
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (q[i] <= q[j])tmp[k++] = q[i++];
		else tmp[k++] = q[j++];
	}
	while (i <= mid)tmp[k++] = q[i++];
	while (j <= r)tmp[k++] = q[j++];

	for (int i = l, j = 0; i <= r; i++, j++)q[i] = tmp[j];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);
	merge_sort(q, 0, n - 1);
	for (int i = 0; i < n; i++)printf("%d", q[i]);
	return 0;
}
