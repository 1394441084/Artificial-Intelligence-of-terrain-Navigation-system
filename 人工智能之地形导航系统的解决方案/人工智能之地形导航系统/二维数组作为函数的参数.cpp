#include <iostream>
#include <Windows.h>

using namespace std;

//��ά������Ϊ�����Ĳ������õİ汾һ
void Call_one(int a1[3][4]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", a1[i][j]);
		}
		printf("\n");
	}
}

//��ά������Ϊ�����Ĳ������õİ汾��
void Call_two(int a2[][4],int hang_shu) {
	//Ϊ���������,�ඨ��һ����������,��Ϊa2[hang_shu][4]ʹ��
	for (int i = 0; i < hang_shu; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", a2[i][j]);
		}
		printf("\n");
	}
}

/*
���鴫�ݵĲ���ֵ,�������鱾��,Ҳ����˵,��������Ϊ������������ʱ
���������βλ��滻�ɴ��ݹ������Ǹ�����,��Ϊʵ�ν��к�������,�������ֵ�ı���ô
���ص�ֵ���Ϊ���ݹ����������ֵ(main������ֵҲ��ͬ���ı�)
��ָ��һ��,������ǵ�ַ,�βκ�ʵ����ͬһ��ַ,����Ҳ�ǶԵ�ַ����
*/
//�޸������е�Ԫ��
void Modification(int a3[][4], int hang) {
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < 4; j++) {
			a3[i][j]=666;
		}
		printf("\n");
	}
}



int main(void) {
	int a[3][4] = { 0 };
	int b[4][4] = { 0 };
	int i = 0, j = 0;

	//�������Ա��ֵ
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = i * 4 + j + 1;
		}
	}
	Call_two(a, 3);
	printf("------���ǻ����ķָ���-------\n");
	Modification(a,3);
	printf("------���ǻ����ķָ���-------\n");
	Call_two(b,4);
	printf("------���ǻ����ķָ���-------\n");
	Call_two(a,3);

	system("pause");
	return 0;
}