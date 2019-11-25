#include <iostream>
#include <Windows.h>

using namespace std;

//二维数组作为函数的参数调用的版本一
void Call_one(int a1[3][4]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", a1[i][j]);
		}
		printf("\n");
	}
}

//二维数组作为函数的参数调用的版本二
void Call_two(int a2[][4],int hang_shu) {
	//为解决兼容性,多定义一个参数行数,作为a2[hang_shu][4]使用
	for (int i = 0; i < hang_shu; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", a2[i][j]);
		}
		printf("\n");
	}
}

/*
数组传递的不是值,而是数组本身,也就是说,把数组作为函数参数调用时
函数数组形参会替换成传递过来的那个数组,成为实参进行函数调用,如参数的值改变那么
返回的值会成为传递过来的数组的值(main函数的值也会同步改变)
跟指针一样,传输的是地址,形参和实参是同一地址,操作也是对地址操作
*/
//修改数组中的元素
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

	//给数组成员赋值
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = i * 4 + j + 1;
		}
	}
	Call_two(a, 3);
	printf("------我是华丽的分割线-------\n");
	Modification(a,3);
	printf("------我是华丽的分割线-------\n");
	Call_two(b,4);
	printf("------我是华丽的分割线-------\n");
	Call_two(a,3);

	system("pause");
	return 0;
}