/*
1. 0이 입력될때까지 입력받는다. N은 1000자리 이하.

2. 해당 N의 자릿수들을 더해서 한자리일때 까지 반복한다.

3. 결과를 출력한다.
-----------------
N의 자릿수를 뽑아내서 배열[4]로 나타내는 기능.
이를 더해서 반복.
N이 1의 자리일 경우 종료.
-----------------
1000자리일 경우 처음 받을 때만 스트링처리를 하면 그 다음 계산할때는 int형을 초과하지는 않는다.

*/
#include <stdio.h>

void initialize(int *pSrc, int nSize);
void setData(int nNumber, int *pSrc, int nSize);
void sumData(const int *pSrc, int nSize, int *pRes);
void transformStr2Int(const char *pSrc, int *pRes, int *pResSize);

int main()
{
	char strData[1000 + 1]{};
	int nCount(0);

	int arData[1000 + 1]{};
	int nArraySize(1000);

	int nData(0);
	int nProcessNumber(0);
	int nTemp(0);
	//
	freopen("input.txt", "r", stdin);

	while (1)
	{
		scanf("%s", strData);
		transformStr2Int(strData, arData, &nArraySize);
		sumData(arData, nArraySize, &nTemp);
		if (nTemp == 0)
		{
			break;
		}

		nProcessNumber = nTemp;
		while (nProcessNumber != 0 && nProcessNumber >= 10)
		{
			initialize(arData, nArraySize);
			setData(nProcessNumber, arData, nArraySize);
			sumData(arData, nArraySize, &nTemp);
			nProcessNumber = nTemp;
		}
		printf("%d\n", nProcessNumber);
	}
	

	return 0;
}

void initialize(int * pSrc, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		pSrc[i] = 0;
	}
}

void setData(int nNumber, int * pSrc, int nSize)
{
	int nTempData(0);
	int nCount(0);

	nTempData = nNumber;
	nCount = 0;
	while (nTempData != 0 && nCount < nSize)
	{
		pSrc[nCount] = nTempData % 10;
		nTempData = nTempData / 10;
		++nCount;
	}
	//test
	//for (int i = 0; i < nSize; ++i)
	//{
	//	printf("[%d]", pSrc[nSize - i - 1]);
	//}
	//printf("\n");
	//test end
}

void sumData(const int * pSrc, int nSize, int * pRes)
{
	int nSum(0);

	nSum = 0;
	for (int i = 0; i < nSize; ++i)
	{
		nSum += pSrc[i];
	}
	*pRes = nSum;
}

void transformStr2Int(const char * pSrc, int * pRes, int * pResSize)
{
	int nCount(0);

	while (pSrc[nCount] != '\0')
	{
		if (pSrc[nCount] >= '0' && pSrc[nCount] <= '9')
		{
			pRes[nCount] = pSrc[nCount] - (int)'0';
			++nCount;
		}
		else
		{
			printf("transform func error\n");
		}
	}
	*pResSize = nCount;
}
