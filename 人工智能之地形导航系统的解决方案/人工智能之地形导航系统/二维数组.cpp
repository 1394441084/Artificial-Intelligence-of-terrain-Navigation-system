#include <iostream>
#include <Windows.h>

using namespace std;

//int a[3][4];//全局变量,编译器默认初始化为0;局部变量不初始化是不确定值

//二数组的定义和初始化
void Two_dimensional(void) {
	
	//int a[25];//一维数组
	//二维数组,5行一维数组,每行25个元素,5行共125个元素,5行25列
	//int b[5][25];

	//二维数组初始化第一种方式:
	int a1[3][4]{//等效于:a1[][4]
		{1,2,3,4},//如果后面没初始化的,会默认为0,下面a3示例
		{5,6,7,8},//a[1(2行)][2(3列)] = { 7 };
		{9,10,11,12}
	};

	//二维数组初始化第二种方式:
	int a2[3][4]{ 1,2,3,4,5,6,7,8,9,10,11,12 };//等效于a1
	int a3[3][4]{ 3 };//只初始一个,后面全默认为0

}

//二维数组的访问
void Visit() {
	int a[3][4];//局部变量不初始化是不确定值,12个成员=48字节
	//给数组成员赋值,第一种方式
/*	for (int i=0; i < 12; i++) {
		//好好想想
		a[i/4][i%4] = i + 1;
	}//i=0=a[0][0],i=1=a[0][1],i=3=a[0][3],i=4=a[1][0]
*/

	//给数组成员赋值,第二种方式
	for (int i = 0; i < 3;i++) {
		for (int j = 0; j < 4; j++) {
			//好好想想
			a[i][j] = i * 4 + (j + 1);
		}
	}//a[0][0]=1;a[1][0]=5;a[2][0]=9


	//把二维数组成员打印出来
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}



int main(void) {
	Visit();

	system("pause");
	return 0;
}