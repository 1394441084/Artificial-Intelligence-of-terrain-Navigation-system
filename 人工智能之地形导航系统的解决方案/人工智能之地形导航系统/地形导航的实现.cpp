#include <iostream>
#include <fstream>   //���ļ���������ͷ�ļ�
#include <Windows.h>
#include <string>
#include <assert.h>  //����ʽ���,���Ժ���void assert( ���ʽ );��ͷ�ļ�

#define M  64   //��Ϊ�ĵ���С,��ά������к���

using namespace std;

/*����ʽ���:

���Զ���:

#include <assert.h>
void assert( ���ʽ );

assert���������ȼ�����ʽexpression �������ֵΪ��(��Ϊ0)��
��ô������stderr��ӡһ��������Ϣ��Ȼ��ͨ������abort ����ֹ�������С�

*/

/*

���������Ҫ���޸�Ѱ�ҷ��ĳ���:
1.��ӡ�������з�����Ŀ��
2.��ӡ���ȵ��λ�á��ٶ��ȵ���-һ�����ڽӵ㺣�ζ�Ҫ�͵ĵ㡣��д-һ����ΪisValley �ĺ�������ĳ�����á�
3.�ҳ�����ӡ������������ߵ����͵��λ�ü��亣�Ρ���д-һ����Ϊextremes �ĺ�������ĳ�����á�
4.�޸ĺ���isPeakO,ʹ��8���ڽӵ����жϷ�㣬��������ֻʹ��4���ڽ����жϡ�

*/

//�����ֵ
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
	cout << "��߷���������:" << a << ". ��:" << s
		<< " ����:" << big << endl;
	cout << "��͹ȵ��������:" << d << ". ��:" << f
		<< " ����:" << smalla << endl;
	
}



//�Ƿ��ֵ(����[64][64],����,����),ʹ��8���ڽӵ����жϷ��
bool isPeak(int grid[M][M], int r, int c) {//��file1(����),i,j���˹���
	assert(0 < r && r < M - 1);//���Ϊfalse�򱨴�(����)
	assert(0 < c && c < M - 1);

	if ((grid[r][c] > grid[r - 1][c]) &&  //�ж��Ƿ������һ��(�ϱߵ�����)
		(grid[r][c] > grid[r + 1][c]) &&  //�ж��Ƿ������һ��(�±ߵ�����)
		(grid[r][c] > grid[r][c + 1]) &&  //�ж��Ƿ������һ��(��ߵ�����)
		(grid[r][c] > grid[r][c - 1]) &&  //�ж��Ƿ������һ��(�ұߵ�����)

		(grid[r][c] > grid[r-1][c-1]) &&  //�ж��Ƿ������һ�����һ��
		(grid[r][c] > grid[r-1][c+1]) &&  //�ж��Ƿ������һ���ұ�һ��
		(grid[r][c] > grid[r+1][c-1]) &&  //�ж��Ƿ������һ�����һ��
		(grid[r][c] > grid[r+1][c+1])) {  //�ж��Ƿ������һ���ұ�һ��
		return true;			 //������������ҵ�����Ҫ��Ļ��ͷ���true
	}else { 
		return false;			//������������ҵ�����ҪС�Ļ��ͷ���false
	}
}

//�Ƿ�ȵ�(����[64][64],����,����),ʹ��8���ڽӵ����жϷ��
bool isValley(int grid[M][M], int r, int c) {//��file1(����),i,j���˹���
	assert(0 < r && r < M - 1);//���Ϊfalse�򱨴�(����)
	assert(0 < c && c < M - 1);

	if ((grid[r][c] < grid[r - 1][c]) &&  //�ж��Ƿ�С����һ��(�ϱߵ�����)
		(grid[r][c] < grid[r + 1][c]) &&  //�ж��Ƿ�С����һ��(�±ߵ�����)
		(grid[r][c] < grid[r][c + 1]) &&  //�ж��Ƿ�С����һ��(��ߵ�����)
		(grid[r][c] < grid[r][c - 1]) &&  //�ж��Ƿ�С����һ��(�ұߵ�����)

		(grid[r][c] < grid[r-1][c-1]) &&  //�ж��Ƿ�С����һ�����һ��
		(grid[r][c] < grid[r-1][c+1]) &&  //�ж��Ƿ�С����һ���ұ�һ��
		(grid[r][c] < grid[r+1][c-1]) &&  //�ж��Ƿ�С����һ�����һ��
		(grid[r][c] < grid[r+1][c+1])) {  //�ж��Ƿ�С����һ���ұ�һ��
		return true;			 //������������ҵ�����ҪС�Ļ��ͷ���true
	}
	else {
		return false;			//������������ҵ�����ҪС�Ļ��ͷ���false
	}
}



int main(void) {
	int rows, columns;//����,����
	int file1[M][M];//�ļ�,�洢�ļ��������ݵĶ�ά����
	string file_name;//�ļ���
	ifstream file;//��ȡ�ļ��Ķ���

	cout << "�������ļ���:\n";
	//���Է��͹ȵ���ļ�.txt
	cin >> file_name;
	file.open(file_name.c_str());//��.txt�ļ�;.c_str()ת��Ϊc�����ַ���
	if (file.fail()) {
		cout << "�������ļ�����.\n";
		exit(1);//�쳣����д1,��������д0;
	}

	//�Ȱ��ĵ��ĵ�һ���������뵽������,��cinһ����
	file >> rows >> columns;

	if (rows > M || columns > M) {
		cout << "����������ά�����������,����Ǯ̫��,������.\n";
		exit(1);
	}

	//�������ļ���ȡ���ݵ���ά����
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			//file>>�ļ���ȡ��,��ѿո�ͻ��з����˵�,�������ݲ��������
			file >> file1[i][j];
		}
	}

	//���Բ���
	//isPeak(file1, -1, 0);//���������ʾAssertion failed: 0 < r && r < M - 1, file

	//�жϲ���ӡ����λ��
	for (int i= 1; i < rows-1; i++) {//���ĵ������Ե��������
		for (int j = 1; j < columns-1; j++) {//���������ڲ�������
			if (isPeak(file1, i, j)) {
				cout << "����������:" << i << ". ��:" << j 
					<<" ����:"<<file1[i][j]<< endl;
		    }
		}
	}

	//�жϲ���ӡ�ȵ��λ��
	for (int i = 1; i < rows - 1; i++) {//���ĵ������Ե��������
		for (int j = 1; j < columns - 1; j++) {//���������ڲ�������
			if (isValley(file1, i, j)) {
				cout << "�ȵ��������:" << i << ". ��:" << j
					<< " ����:" << file1[i][j] << endl;
			}
		}
	}

	extremes(file1,rows,columns);

	system("pause");
	//�ر��ļ�
	file.close();
	//��������
	return 0;
}