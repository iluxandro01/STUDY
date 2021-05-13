
/****************************************************************
* Project Type : Win32 Console Application *
* Project Name : lab3*
* File Name : lab3333.CPP *
* Programmer(s) : �������� �.�. *
* Modifyed By : *
* Created : 16/04/20 *
* Last Revision : 28/05/20 *
* Comment(s) : ������������ ����������� �������� *
*****************************************************************/
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const char* FILENAME_1 = "src.txt"; //���� � �������� ������ ��� 1 �������
const char* FILENAME_2 = "../tests_1/src12.txt"; //���� � �������� ������ ��� 2 �������

//	* ----------------------------------------------------------------------------------------- *
//								� � � � � � � � � � � �  � � � � �
//			src0.txt  - ���� �� ���������� �����
//			src1.txt  - ���� �� ������ ����
//			src2.txt  - ���� �� ������������ ������� ��� ����� (�����)
//			src3.txt  - ���� �� ���������� ������� ��������� > ������� �������
//			src4.txt  - ���� �� ���������� ������� ��������� < ������� �������
//			src13.txt - ���� �� ������������� ������� ������� (N<0)
//			src14.txt - ���� �� ������������� ������� ������� (M<0)
//
//								    � � � � � � � � � �  � � � � � 
//			src5.txt  - ���� �� ������ ������� = ���������� ������� ���������
//
//			src6.txt  - ���� ��� ������������� ��������� � �������
//			src7.txt  - ���� � ����� ������������� ��������� � �������
//			src8.txt  - ���� � ����������� ����������� �����������
//
//			src9.txt  - ���� ��� �������� ������������ � �������� ����������� ��������
//			src10.txt - ���� ��� �������� ������������ � ������ ����������� ��������
//
//			src11.txt - ���� � ��������� ���������: ARRAY1 - 5 8; ARRAY2 - 4 7
//			src12.txt - ���� � ��������� ���������: ARRAY1 - 6 9; ARRAY2 - 3 6
//
//	* ----------------------------------------------------------------------------------------- *	

void CleanMemory(double** ARRAY, int N) { //����������� ������
	for (int i = 0; i < N; i++) {
		delete[] ARRAY[i];
	}

	delete[] ARRAY;
}
void PrintArray(double** ARRAY, int *VecX, int N, int M) { //������ �������
	cout << endl;
	for (int i = 0; i < M-1; i++) {
		cout << setw(6) << "x" << VecX[i];
	}
	cout << setw(6) << "b";
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M; j++) {
			if (j == M-1) {
				cout << "  |" << setw(7) << ARRAY[i][j];
			}
			else {
				cout << setw(7) << ARRAY[i][j];
			}
			
		}
	}
	cout << endl;
}
void GetCode(int CodeError) {
	switch (CodeError)
	{
	case -1:
		cout << "������! ���� �� ������" << endl << endl;
		break;
	case -2:
		cout << "������! ���� ����!" << endl << endl;
		break;
	case -3:
		cout << "������! �������� ���� ������ ����!" << endl << endl;
		break;
	case -4:
		cout << "������! ���������� ������� ��������� ������ ������� �������!" << endl << endl;
		break;
	case -5:
		cout << "������! ���������� ������� ��������� ������ ������� �������!" << endl << endl;
		break;
	}
}
void IntMatrix(double*** ARRAY, int* N, int* M, int* CodeError, const char* FILENAME) {
	ifstream fin; //������� ������ ������ ifstream
	fin.open(FILENAME); //��������� ����
	int CntVec = 0; //������� ��������� ������� �������
	int CntLine = 0; //������� ��� �����
	int CntColumn = 0; //������� ��� �����
	double buff; // ������ ��� �������� ������������ �������� ������

	if (!fin) // ���� ���� �� ������
	{
		*CodeError = -1;
		return;
	}

	if (fin.peek() == EOF)  //���� ��������� ���� ����
	{
		*CodeError = -2;
		return;
	}

	while (!fin.eof()) { //�������� �� ���� ����
		fin >> buff;
		if (!fin) {
			*CodeError = -3;
			return;
		}
	}
	fin.seekg(0); //������� ������ ����� �� ����� ������

	fin >> *N; //��������� ���������� �����
	fin >> *M; //��������� ���������� ��������

	*ARRAY = new double* [*N];
	for (int i = 0; i < *N; i++) {
		*(*ARRAY + i) = new double[*M];
	}

	while (!fin.eof()) { //������ ��������� �������, ���� �������� �� ����������
		fin >> buff;
		CntVec++; //������� ���������� ��������� ������
	}
	if (CntVec > * N * *M) { //�������� �� ����� �� ������� �������
		*CodeError = -4;
		return;
	}
	if (CntVec < *N * *M) { //�������� �� ���������� ��������� 
		*CodeError = -5;
		return;
	}
	fin.seekg(0); //������� ������ ����� �� ����� ������

	fin >> buff >> buff; //��� ��� ��������� �� ����� ������, ���������� � ������ �������
	while (!fin.eof()) {
		fin >> *(*(*ARRAY + CntLine) + CntColumn); //������ ������� �� �����
		CntColumn++;
		if (CntColumn == *M) {
			CntLine++;
			CntColumn = 0;
		}
	}

	fin.close(); // ��������� ����

}

/*
������� ��� ������������ ������
������� ���������:
	ARRAY - ������� � ������� ��������
	M - ������ ������
	row - ������ ������ � ������� ���� �����
����������� ���������:
	����� ������ ��� ������� row, ��� ��������� ������ 
*/
double SumLine(double** ARRAY, int M, int row) {
	double sum = 0; 
	for (int i = 0; i < M-1; i++) { //���� �� ������� ������� ��������� ��������� �����
		sum += fabs(ARRAY[row][i]); //�������� � row �������, ������� |�����| ���� ������
	}
	return sum;
}
//++

/*
������� ��� �������� ����� �������
������� ���������:
	ARRAY - ������� � ������� ����������
	N - ������ �������� 
	M - ������ ������
����������� ���������:
	����� ������� - ������������ ����� ����� ����� �������� �� ������
*/
double NormMatrix(double **ARRAY, int N, int M) {
	double max = 0; //�.�. �� ������� ������ �������� � ������, 
					//�� max ����� ������� �� 0, �.� ����� ����� >=0
	for (int i = 0; i < N; i++) { //���� �� ������� �������
		if (SumLine(ARRAY, M, i) > max) {
			max = SumLine(ARRAY, M, i);
		}
	}
	return max;
}
//++

/*
������� ��������� �������� ����� �������� ��������� ������ �� ������
������� ���������:
	ARRAY - ������� � ������� ��������
	N - ������ ��������
������������ ���������:
	�������� ����� �������� ��������� ������ �� ������
*/
double MaxFreeTerm(double **ARRAY, int N, int M) {
	double max = 0; //�.�. �������� � ������� �������� ����� ������ >=0
	for (int i = 0; i < N; i++) {
		if (fabs(ARRAY[i][M-1]) > max) { //�������� � i-�� ������ � ���� �� ��. ����
			max = fabs(ARRAY[i][M-1]);
		}
	}
	return max;
}
//++

/*
template <typename T>
T MatrixB(T** ARRAY) {
	T temp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			if (i == j) {
				continue;
			}
			*(*(ARRAY + i) + j) -= *(*(ARRAY + i) + j) / temp;
		}
	}
}
*/


void Res(double** ARRAY, double* res, int N, int M) {
	for (int i = 0; i < N; i++) {
		res[i] == ARRAY[i][M-1] / ARRAY[i][i];
		cout << ARRAY[i][M-1] << "  " << ARRAY[i][i];
		cout << endl;
	}
}

 /*
������� ��� ������������ ��������
������� ���������:
   ARRAY - ������� � ������� ��������
   indexmax - ��������� ������� � ����. ���������
   num - ������� � ������� ����� ������
   N - ������ ��������
�������� ���������:
	������������, �������� � ������
 */
 void SwapCols(double** ARRAY, int *VecX, int indexmax, int num, int M) {
	 double temp;
	 for (int i = num; i < M; i++) {
		 temp = ARRAY[i][indexmax];
		 ARRAY[i][indexmax] = ARRAY[i][num];
		 ARRAY[i][num] = temp;	

		 temp = VecX[indexmax];
		 VecX[indexmax] = VecX[num];
		 VecX[num] = temp;
	 }
 }
 //++

 /*
������� ��� ������������ �����
������� ���������:
   ARRAY - ������� � ������� ��������
   indexmax - ��������� ������� � ����. ���������
   num - ������� � ������� ����� ������
   N - ������ ������
�������� ���������:
	������������, �������� � ������
 */
 void SwapRows(double** ARRAY, int *VecX, int indexmax, int num, int N) {
	 double temp;
	 for (int i = num; i < N; i++) {
		 temp = ARRAY[indexmax][i];
		 ARRAY[indexmax][i] = ARRAY[num][i];
		 ARRAY[num][i] = temp;

		
		
	 }
 }
 //++

/*
������� ��� ������ ��������� �� ����������� ����� � �������� (i==j)
������� ���������:
	ARRAY - ������� � ������� ��������
	NUM - ����� ��������� �� ������� ��������
	N - ������ ��������
	M - ������ �����
����������� ���������:
	������� - ������ ������/�������
*/
 void SwapMaxRowsCols(double** ARRAY, int *VecX, int num, int N, int M) {
	 double max = 0;
	 int indexmax = 0;
	 for (int i = 0; i < M - 1; i++) {		//-1 �.�. �� �������� ��� ��������� �����
		 if (ARRAY[num][i] > max) {		//�������� � ������� num � ���� �� ������
			 max = ARRAY[num][i];
			 indexmax = i;
		 }
	 }
		 bool flag = false;						//������ ���� ����� ����� ������/�������

	 for (int i = 0; i < N; i++) {
		if (ARRAY[i][num] > max) {		//���� �� ���� �������� 
			max = ARRAY[i][num];		//������� � num ������
			indexmax = i;						//���� ��������
			flag = true;						//� ������� ������� �������
		}
	 }
		 if (flag == false) {					//�������� � ������
			 SwapCols(ARRAY, VecX, indexmax, num, N);	//������ num ������� � ������������ �������� 
		 }
		 else {									//�������� � �������
			 SwapRows(ARRAY, VecX, indexmax, num, M);	//������ num ������ � ������������ ������� 
		 }
	 }
 //++

 /*
������� ������������� ������������ ��������� �������
������� ���������:
	ARRAY - ������ � ������� ��������
	N - ������ ��������
	M - ������ �����
�������� ���������:
	������� - �������� ������� ������
*/
 void DominateDiagonal(double** ARRAY, int *VecX, int N, int M) {
	 for (int i = 0; i < N; i++) {
		 if (fabs(SumLine(ARRAY, M, i) - *(*(ARRAY + i) + i)) > fabs(*(*(ARRAY + i) + i))) {
			 SwapMaxRowsCols(ARRAY, VecX, i, N, M);
		 }
	 }

 }

 //++
 void MinMaxRows(double** ARRAY, int N, int M) {
	 for (int i = 0; i < N; i++) {
		 if (fabs(SumLine(ARRAY, M, i) - *(*(ARRAY + i) + i)) > fabs(*(*(ARRAY + i) + i))) {

		 }
	 }
 }
 void CheckDominate(double** ARRAY, int N, int M) {
	 for (int i = 0; i < N; i++) {
		 if (fabs(SumLine(ARRAY, M, i) - *(*(ARRAY + i) + i)) < fabs(*(*(ARRAY + i) + i))) { //���� �� ������������ ��...
			 cout << "true" << i << " ";
		 }
		 else {
			 cout << "false" << i << " ";
		 }
	 }
 }


 int main() {
	 system("color F0"); //������ ���� �������
	 setlocale(LC_ALL, "Russian"); //������ ����
	 int N; //���-�� ��������
	 int M = 1; //���-�� �����
	 int CodeError = 0; //��� ������
	 double** ARRAY_1; //���������� ������ �������
	 IntMatrix(&ARRAY_1, &N, &M, &CodeError, FILENAME_1);
	 int* VecX = new int[M - 1];
	 for (int i = 0; i < M - 1; i++) {
		 VecX[i] = i;
	 }
	 double* res = new double[N];
	 if (CodeError == 0) {
		 cout << "�������� ������ ������� �������: ";
		 PrintArray(ARRAY_1, VecX, N, M);
		 cout << endl << "-------------------------------------------------" << endl << endl;
		 cout << NormMatrix(ARRAY_1, N, M);
		 cout << endl;
		 cout << MaxFreeTerm(ARRAY_1, N, M);
		 DominateDiagonal(ARRAY_1, VecX, N, M);
		 //SwapMaxRowsCols(ARRAY_1, 0, N, M);
		 PrintArray(ARRAY_1, VecX, N, M);
		 Res(ARRAY_1, res, N, M);
		 CheckDominate(ARRAY_1, N, M);
		 CleanMemory(ARRAY_1, N);
		 
	 }
	 else {
		 GetCode(CodeError);
	 }
 }
