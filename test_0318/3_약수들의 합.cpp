/*
TC�� �־����� �������� -1�� �ԷµǸ� ����.

�ش� ���� ������� ������ �־�����

�� ����Ѵ�.
N = ��� + ��� + ���
N is NOT perfect.
----------
6 1 2 3 
12 1 2 3 4 6
28 1 2 4 7 14 
�ڽ��� ������ ����� ���� �� �ڽ��� �Ǿ���.

*/
#include <stdio.h>

void calculateDivisor(int nData, int *pResArray, int nMaxSize, int *pDivisorNum);
bool isPerfectNum(const int *pSrc, int nSize, int nTarget);
void printFormula(const int *pSrc, int nSize, int nTarget);

int main()
{
	int nData(0);
	int arDivisor[100];
	int nDivisorNum(0);

	//
	freopen("input.txt", "r", stdin);
	while (nData != -1)
	{
		nData = 0;
		nDivisorNum = 0;
		scanf("%d", &nData);
		if (nData > 0)
		{
			calculateDivisor(nData, arDivisor, 100, &nDivisorNum);
			if (isPerfectNum(arDivisor, nDivisorNum, nData))
			{
				printFormula(arDivisor, nDivisorNum, nData);
			}
			else
				printf("%d is NOT perfect.\n", nData);
		}
	}

	return 0;
}

void calculateDivisor(int nData, int * pResArray, int nMaxSize, int * pDivisorNum)
{
	int nCount(0);

	for (int i = 1; i < nData; ++i)
	{
		if (nData % i == 0)
		{
			pResArray[nCount] = i;
			++nCount;
		}
	}

	*pDivisorNum = nCount;
}

bool isPerfectNum(const int * pSrc, int nSize, int nTarget)
{
	int nSum(0);

	for (int i = 0; i < nSize; ++i)
	{
		nSum += pSrc[i];
	}

	if (nSum == nTarget)
		return true;
	else
		return false;
}

void printFormula(const int * pSrc, int nSize, int nTarget)
{
	printf("%d = ", nTarget);

	for (int i = 0; i < nSize - 1; ++i)
	{
		printf("%d + ", pSrc[i]);
	}
	printf("%d\n", pSrc[nSize - 1]);
}
