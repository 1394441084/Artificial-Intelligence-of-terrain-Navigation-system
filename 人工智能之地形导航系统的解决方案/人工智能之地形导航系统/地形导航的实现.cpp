#include <iostream>
#include <fstream>   //对文件流操作的头文件
#include <Windows.h>
#include <string>

#define M  64   //作为文档大小,二维数组的行和列

using namespace std;

//是否峰值(网格[64][64],行数,列数)
bool isPeak(int grid[M][M], int r, int c) {
	if ((grid[r][c] > grid[r + 1][c]) &&
		(grid[r][c] > grid[r - 1][c]) &&
		(grid[r][c] > grid[r][c - 1]) &&
		(grid[r][c] > grid[r][c + 1])) {
		return true;
	}else { 
		return false; 
	}
}



int main(void) {
	int rows, columns;//行数,列数
	int file1[M][M];//文件,存储文件里面内容的二维数组
	string file_name;//文件名
	ifstream file;//读取文件的对象
	cout << "请输入文件名:\n";
	cin >> file_name;
	file.open(file_name.c_str());//打开.txt文件;.c_str()转换为c语言字符串
	if (file.fail()) {
		cout << "打开输入文件出错.\n";
		exit(1);//异常结束写1,正常结束写0;
	}

	//先把文档的第一行数据输入到变量中,和cin一样的
	file >> rows >> columns;

	if (rows > M || columns > M) {
		cout << "超过我们所定二维数组的行与列,给的钱太少,不干了.\n";
		exit(1);
	}

	//从数据文件读取数据到二维数组
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			//file>>文件读取流,会把空格和换行符过滤掉,所以数据不会乱输的
			file >> file1[i][j];
		}
	}

	//判断并打印峰值的位置
	for (int i= 1; i < rows-1; i++) {//对文档网格边缘数据无视
		for (int j = 1; j < columns-1; j++) {//遍历网格内部的数据
			if (isPeak(file1, i, j)) {
				cout << "峰值峰点出现在行:" << i << ". 列:" << j << endl;
		    }
		}
	}

	system("pause");
	//关闭文件
	file.close();
	//结束程序
	return 0;
}