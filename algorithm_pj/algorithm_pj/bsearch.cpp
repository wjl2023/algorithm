//��������
//�е����ԣ�һ�����Զ��֣�����û�е����ԣ�Ҳ���ܿ��Զ���
//�ҵ�һ�����ʣ�����������һ��Ϊ������ô���־Ϳ���Ѱ��������ʵı߽�


#include <iostream>

using namespace std;
//check�������������õ��Ƿ�����ĳ������
bool check(int mid) {
	return true;
}

//����ѡ��ʲôģ��Ϳ�mid������߻����ұߣ�mid������������ʻ����ұߣ�
//����[l,r]������Ϊ[l,mid]��[mid+1,r]ʹ��
int bsearch_1(int l, int r) {
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid))r = mid;//�ж��Ƿ���������
		else l = mid + 1;
	}
	return l;
}
//����[l,r]������Ϊ[l,mid-1]��[mid,r]ʹ��
//mid���ұߵ�ʱ����mid��ʱ��Ҫ����1��C++��xiaȡ�� ��
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