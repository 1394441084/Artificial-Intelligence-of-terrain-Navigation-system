#include <iostream>
#include <fstream>   //对文件流操作的头文件
#include <Windows.h>
#include <string>
#include <assert.h>  //防御式编程,断言函数void assert( 表达式 );的头文件

#define M  64   //作为文档大小,二维数组的行和列

using namespace std;

/*防御式编程:

断言定义:

#include <assert.h>
void assert( 表达式 );

assert的作用是先计算表达式expression ，如果其值为假(即为0)，
那么它先向stderr打印一条出错信息，然后通过调用abort 来终止程序运行。

*/

/*

按照下面的要求修改寻找峰点的程序:
1.打印出网格中峰点的数目。
2.打印出谷点的位置。假定谷点是-一个比邻接点海拔都要低的点。编写-一个名为isValley 的函数供你的程序调用。
3.找出并打印海拔数据中最高点和最低点的位置及其海拔。编写-一个名为extremes 的函数供你的程序调用。
4.修改函数isPeakO,使用8个邻接点来判断峰点，而不再是只使用4个邻近点判断。

*/

//找最大值
void extremes(int grid[M][M],int r,int c) {
	int smalla = grid[0][0];
	int big = grid[0][0];
	int a,s,d,f;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j]>big) {
				big = grid[i][j];
				a = i; s = j;
			}
			else if (grid[i][j]<=smalla) {
				smalla = grid[i][j];
				d = i; f = j;
			}
		}
	}
	cout << "最高峰点出现在行:" << a << ". 列:" << s
		<< " 数据:" << big << endl;
	cout << "最低谷点出现在行:" << d << ". 列:" << f
		<< " 数据:" << smalla << endl;
	
}



//是否峰值(网格[64][64],行数,列数),使用8个邻接点来判断峰点
bool isPeak(int grid[M][M], int r, int c) {//把file1(数组),i,j传了过来
	assert(0 < r && r < M - 1);//如果为false则报错(断言)
	assert(0 < c && c < M - 1);

	if ((grid[r][c] > grid[r - 1][c]) &&  //判断是否大于上一格(上边的数据)
		(grid[r][c] > grid[r + 1][c]) &&  //判断是否大于下一格(下边的数据)
		(grid[r][c] > grid[r][c + 1]) &&  //判断是否大于左一格(左边的数据)
		(grid[r][c] > grid[r][c - 1]) &&  //判断是否大于右一格(右边的数据)

		(grid[r][c] > grid[r-1][c-1]) &&  //判断是否大于上一格左边一格
		(grid[r][c] > grid[r-1][c+1]) &&  //判断是否大于上一格右边一格
		(grid[r][c] > grid[r+1][c-1]) &&  //判断是否大于下一格左边一格
		(grid[r][c] > grid[r+1][c+1])) {  //判断是否大于下一格右边一格
		return true;			 //如果比上下左右的数据要大的话就返回true
	}else { 
		return false;			//如果比上下左右的数据要小的话就返回false
	}
}

//是否谷点(网格[64][64],行数,列数),使用8个邻接点来判断峰点
bool isValley(int grid[M][M], int r, int c) {//把file1(数组),i,j传了过来
	assert(0 < r && r < M - 1);//如果为false则报错(断言)
	assert(0 < c && c < M - 1);

	if ((grid[r][c] < grid[r - 1][c]) &&  //判断是否小于上一格(上边的数据)
		(grid[r][c] < grid[r + 1][c]) &&  //判断是否小于下一格(下边的数据)
		(grid[r][c] < grid[r][c + 1]) &&  //判断是否小于左一格(左边的数据)
		(grid[r][c] < grid[r][c - 1]) &&  //判断是否小于右一格(右边的数据)

		(grid[r][c] < grid[r-1][c-1]) &&  //判断是否小于上一格左边一格
		(grid[r][c] < grid[r-1][c+1]) &&  //判断是否小于上一格右边一格
		(grid[r][c] < grid[r+1][c-1]) &&  //判断是否小于下一格左边一格
		(grid[r][c] < grid[r+1][c+1])) {  //判断是否小于下一格右边一格
		return true;			 //如果比上下左右的数据要小的话就返回true
	}
	else {
		return false;			//如果比上下左右的数据要小的话就返回false
	}
}



int main(void) {
	int rows, columns;//行数,列数
	int file1[M][M];//文件,存储文件里面内容的二维数组
	string file_name;//文件名
	ifstream file;//读取文件的对象

	cout << "请输入文件名:\n";
	//测试峰点和谷点的文件.txt
	cin >> file_name;
	file.open(file_name.c_str());//打开.txt文件;.c_str()转换为c语言字符串
	if (file.fail()) {
		cout << "打开输入文件出错.\n";
		exit(1);//异常结束写1,正常结束写0;
	}

	//先把文档的第一行数据输入到变量中,和cin一样的
	file >> rows >> columns;

	if (rows > M || columns > M) {
		cout << "超过所定二维数组的行与列,给的钱太少,不干了.\n";
		exit(1);
	}

	//从数据文件读取数据到二维数组
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			//file>>文件读取流,会把空格和换行符过滤掉,所以数据不会乱输的
			file >> file1[i][j];
		}
	}

	//断言测试
	//isPeak(file1, -1, 0);//出现这个提示Assertion failed: 0 < r && r < M - 1, file

	//判断并打印峰点的位置
	for (int i= 1; i < rows-1; i++) {//对文档网格边缘数据无视
		for (int j = 1; j < columns-1; j++) {//遍历网格内部的数据
			if (isPeak(file1, i, j)) {
				cout << "峰点出现在行:" << i << ". 列:" << j 
					<<" 数据:"<<file1[i][j]<< endl;
		    }
		}
	}

	//判断并打印谷点的位置
	for (int i = 1; i < rows - 1; i++) {//对文档网格边缘数据无视
		for (int j = 1; j < columns - 1; j++) {//遍历网格内部的数据
			if (isValley(file1, i, j)) {
				cout << "谷点出现在行:" << i << ". 列:" << j
					<< " 数据:" << file1[i][j] << endl;
			}
		}
	}

	extremes(file1,rows,columns);

	system("pause");
	//关闭文件
	file.close();
	//结束程序
	return 0;
}