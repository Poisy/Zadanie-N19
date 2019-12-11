#include <iostream>

struct Point		//�R�������{�������p �����y���r�p���p �������{�p �r ���p�r�~�y�~�p
{
	int x;		//�V - �V�����y�x���~���p�|�~�p���p �������z�~������
	int y;		//�T - �B�u�����y�{�p�|�~�p���p �������z�~������
};

struct Region		//�R�������{�������p �����y���r�p���p ���q�|�p���� �r ���p�r�~�y�~�p
{
	int x;		//�N�p���p�|�~�p���p �V
	int y;		//�N�p���p�|�~�p���p �T
	int w;		//�Q�p���������~�y�u���� �{���u���� �}�y�~�p�r�p ���� �V
	int h;		//�Q�p���������~�y�u���� �{���u���� �}�y�~�p�r�p ���� �T
};

//�P���t�p�r�p�}�u ���q�|�p�������p �{�p���� �����u�r�t���~�y�}
void SetTheRegion(Region& region, int x, int y, int w, int h)
{
	//�H�p�t�p�r�p�~�u �~�p �{�����t�y�~�p���y���u
	region.x = x;
	region.y = y;
	region.w = w;
	region.h = h;
}

//�U���~�{���y�����p �{�������� �����x�t�p�r�p �}�p�s�y�����p
//�I���{�p�}�u �}�p���y�r ���� ���q�|�p�����y, �~�p���p���p �������{�p �y ���p�x�}�u���p �~�p �}�p���y�r�p
void FoundInAnyRegion(Region* array, Point point, int sizeOfArray)
{
	//�P�����}�u�~�|�y�r�p �{�������� �����{�p�x�r�p �t�p�|�y �������{�p���p �u �r �~���{���� ���q�|�p����
	bool FoundAnywhere = false;
	//�M�y�~�p�r�p�}�u �����u�x �r�����{�p ���q�|�p���� ���� �}�p���y�r�p
	for (int i = 0; i < sizeOfArray; i++)
	{
		Region currentRegion = array[i];		//�R�u�s�p���~�p���p ���q�|�p����
		int pX = point.x;		//�K�����t�y�~�p���p���p �V �~�p �������{�p���p
		int pY = point.y;		//�K�����t�y�~�p���p���p �T �~�p �������{�p���p
		int regSX = currentRegion.x;		//�K�����t�y�~�p���p���p �V �~�p �~�p���p�|������ �~�p ���q�|�p�������p
		int regSY = currentRegion.y;		//�K�����t�y�~�p���p���p �T �~�p �~�p���p�{�y���y �~�p ���q�|�p�������p
		int regEX = currentRegion.w + regSX;		//�K�����t�y�~�p���p���p �V �~�p �{���p�� �~�p ���q�|�������p
		int regEY = regSY - currentRegion.h;		//�K�����t�y�~�p���p���p �T �~�p �{���p�� �~�p ���q�|�������p
		//�I�x���y���|���r�p�}�u �t�p�|�y �������z�~�������y���u ���� �{�����t�y�~�p���y���u �~�p �������{�p���p �~�y, ���p �}�u�w�t�� ���u�x�y �~�p ���q�|�p�������p
		if ((pX > regSX && pX < regEX) && (pY < regSY && pY > regEY))
		{
			//�@�{�� �����{���y�u�} ���p�{�p�r�p ���q�|�p����, �y�~�������}�y���p�}�u ���������u�q�y���u�|��
			printf("The point (%d, %d) is found in the %dst region (%d, %d, %d, %d)\n", 
				pX, pY, i+1, regSX, regSY, regEX, regEY);
			//�P�����}�u�~���}�u ���u�x���|���p���p
			FoundAnywhere = true;
		}
	}
	//�P�����r�u�����r�p�}�u �t�p�|�y �������{�p���p �u ���p�}�p :(
	if (!FoundAnywhere)
	{
		//�I�x�r�u�������r�p�}�u ���������u�q�y���u�|��
		printf("The point (%d, %d) isn't found anywhere :(\n", point.x, point.y);
	}
}


int main()
{
	//�S���y���u �~�y ���q�|�p�����y
	Region region1;	
	Region region2;
	Region region3;

	//�H�p�t�p�r�p�~�u �~�p �{�����t�y�~�p���y���u �y�}
	SetTheRegion(region1, -9, 6, 8, 9); 
	SetTheRegion(region2, -7, 7, 17, 5); 
	SetTheRegion(region3, 2, -2, 7, 5); 

	//�M�p���y�r�p �{���z���� �����t�����w�p �r���y���{�y ���q�|�p�����y
	Region array[3] = { region1, region2, region3 };

	//�S���r�p �u �~�p���p���p �������{�p
	Point point;

	//�I���{�p�}�u ���������u�q�y���u�|�� �t�p �r���r�u�t�u �~�u�y�~�y���u �{�����t�y�~�p���y
	printf("Give 2 integer numbers (x, y) for the point.\n");
	scanf_s("%d", &point.x);
	scanf_s("%d", &point.y);
	
	//�I�x�r�y�{�r�p�}�u �����~�{���y�����p �{������ �����{�p�x�r�p �~�p �{���~�x���|�p���p ���u�x���|���p���p
	FoundInAnyRegion(array, point, 3);
}

