#include <iostream>
#include <Windows.h>

using namespace std;

/*
一维数组:只有一行
二维数组:多个一维数组
多维数组:多个二维数组
*/

//多维数组示例
void Multidimensional_array() {
	int i = 0, j = 0, k = 0;

	int a[3][3][4] = {
	{{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12} },//这是a[0][][]的值

	{{1,2,3,4},
	{5,6,7,8},
	{9,10,11,13} },//这是a[1][][]的值

	{{1,2,3,4},
	{5,6,7,8},
	{9,10,11,14} }//这是a[2][][]的值
	};//第一种定义赋值

	int a1[3][3][4] = { 0 };//全初始化为0,按顺序排列

	//打印多维数组
	for (k = 0; k < 3; k++) {
		printf("\n第%d个二维数组\n", k+1);
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