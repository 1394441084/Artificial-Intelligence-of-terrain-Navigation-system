#include <iostream>
#include <fstream>   //���ļ���������ͷ�ļ�
#include <Windows.h>
#include <string>

#define M  64   //��Ϊ�ĵ���С,��ά������к���

using namespace std;

//�Ƿ��ֵ(����[64][64],����,����)
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
	int rows, columns;//����,����
	int file1[M][M];//�ļ�,�洢�ļ��������ݵĶ�ά����
	string file_name;//�ļ���
	ifstream file;//��ȡ�ļ��Ķ���
	cout << "�������ļ���:\n";
	cin >> file_name;
	file.open(file_name.c_str());//��.txt�ļ�;.c_str()ת��Ϊc�����ַ���
	if (file.fail()) {
		cout << "�������ļ�����.\n";
		exit(1);//�쳣����д1,��������д0;
	}

	//�Ȱ��ĵ��ĵ�һ���������뵽������,��cinһ����
	file >> rows >> columns;

	if (rows > M || columns > M) {
		cout << "��������������ά�����������,����Ǯ̫��,������.\n";
		exit(1);
	}

	//�������ļ���ȡ���ݵ���ά����
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			//file>>�ļ���ȡ��,��ѿո�ͻ��з����˵�,�������ݲ��������
			file >> file1[i][j];
		}
	}

	//�жϲ���ӡ��ֵ��λ��
	for (int i= 1; i < rows-1; i++) {//���ĵ������Ե��������
		for (int j = 1; j < columns-1; j++) {//���������ڲ�������
			if (isPeak(file1, i, j)) {
				cout << "��ֵ����������:" << i << ". ��:" << j << endl;
		    }
		}
	}

	system("pause");
	//�ر��ļ�
	file.close();
	//��������
	return 0;
}