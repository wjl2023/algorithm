//整数二分
//有单调性，一定可以二分，但是没有单调性，也可能可以二分
//找到一个性质，把整个区间一分为二，那么二分就可以寻找这个性质的边界


#include <iostream>

using namespace std;
//check函数是用来检查该点是否满足某种性质
bool check(int mid) {
	return true;
}

//所以选择什么模板就看mid属于左边还是右边（mid是满足左边性质还是右边）
//区间[l,r]被划分为[l,mid]和[mid+1,r]使用
int bsearch_1(int l, int r) {
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid))r = mid;//判断是否满足性质
		else l = mid + 1;
	}
	return l;
}
//区间[l,r]被划分为[l,mid-1]和[mid,r]使用
//mid在右边的时候，算mid的时候要加上1（C++是xia取整 ）
int bsearch_2(int l, int r) {
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid))l = mid;
		else r = mid - 1;
	}
	return l;
}

int main() {

	return 0;
}