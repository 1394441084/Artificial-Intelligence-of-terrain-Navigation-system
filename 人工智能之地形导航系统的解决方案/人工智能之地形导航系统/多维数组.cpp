#include <iostream>
#include <Windows.h>

using namespace std;

/*
һά����:ֻ��һ��
��ά����:���һά����
��ά����:�����ά����
*/

//��ά����ʾ��
void Multidimensional_array() {
	int i = 0, j = 0, k = 0;

	int a[3][3][4] = {
	{{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12} },//����a[0][][]��ֵ

	{{1,2,3,4},
	{5,6,7,8},
	{9,10,11,13} },//����a[1][][]��ֵ

	{{1,2,3,4},
	{5,6,7,8},
	{9,10,11,14} }//����a[2][][]��ֵ
	};//��һ�ֶ��帳ֵ

	int a1[3][3][4] = { 0 };//ȫ��ʼ��Ϊ0,��˳������

	//��ӡ��ά����
	for (k = 0; k < 3; k++) {
		printf("\n��%d����ά����\n", k+1);
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				printf("%d ", a[k][i][j]);
			}
			printf("\n");
		}
	}

}


int main(void) {

	Multidimensional_array();


	system("pause");
	return 0;
}