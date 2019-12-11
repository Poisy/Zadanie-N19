#include <iostream>

struct Point		//„R„„„‚„…„{„„„…„‚„p „€„„y„ƒ„r„p„‹„p „„„€„‰„{„p „r „‚„p„r„~„y„~„p
{
	int x;		//„V - „V„€„‚„y„x„€„~„„„p„|„~„p„„„p „ƒ„„„€„z„~„€„ƒ„„
	int y;		//„T - „B„u„‚„„„y„{„p„|„~„p„„„p „ƒ„„„€„z„~„€„ƒ„„
};

struct Region		//„R„„„‚„…„{„„„…„‚„p „€„„y„ƒ„r„p„‹„p „€„q„|„p„ƒ„„ „r „‚„p„r„~„y„~„p
{
	int x;		//„N„p„‰„p„|„~„p„„„p „V
	int y;		//„N„p„‰„p„|„~„p„„„p „T
	int w;		//„Q„p„ƒ„„„€„‘„~„y„u„„„€ „{„€„u„„„€ „}„y„~„p„r„p „„€ „V
	int h;		//„Q„p„ƒ„„„€„‘„~„y„u„„„€ „{„€„u„„„€ „}„y„~„p„r„p „„€ „T
};

//„P„€„t„p„r„p„}„u „€„q„|„p„ƒ„„„„„p „{„p„„„€ „„ƒ„u„r„t„€„~„y„}
void SetTheRegion(Region& region, int x, int y, int w, int h)
{
	//„H„p„t„p„r„p„~„u „~„p „{„€„‚„t„y„~„p„„„y„„„u
	region.x = x;
	region.y = y;
	region.w = w;
	region.h = h;
}

//„U„…„~„{„ˆ„y„‘„„„p „{„€„‘„„„€ „ƒ„Œ„x„t„p„r„p „}„p„s„y„‘„„„p
//„I„ƒ„{„p„}„u „}„p„ƒ„y„r „€„„ „€„q„|„p„ƒ„„„y, „~„p„Š„p„„„p „„„€„‰„{„p „y „‚„p„x„}„u„‚„p „~„p „}„p„ƒ„y„r„p
void FoundInAnyRegion(Region* array, Point point, int sizeOfArray)
{
	//„P„‚„€„}„u„~„|„y„r„p „{„€„‘„„„€ „„€„{„p„x„r„p „t„p„|„y „„„€„‰„{„p„„„p „u „r „~„‘„{„€„‘ „€„q„|„p„ƒ„„
	bool FoundAnywhere = false;
	//„M„y„~„p„r„p„}„u „„‚„u„x „r„ƒ„‘„{„p „€„q„|„p„ƒ„„ „€„„ „}„p„ƒ„y„r„p
	for (int i = 0; i < sizeOfArray; i++)
	{
		Region currentRegion = array[i];		//„R„u„s„p„Š„~„p„„„p „€„q„|„p„ƒ„„
		int pX = point.x;		//„K„€„‚„t„y„~„p„„„p„„„p „V „~„p „„„€„‰„{„p„„„p
		int pY = point.y;		//„K„€„‚„t„y„~„p„„„p„„„p „T „~„p „„„€„‰„{„p„„„p
		int regSX = currentRegion.x;		//„K„€„‚„t„y„~„p„„„p„„„p „V „~„p „~„p„‰„p„|„€„„„€ „~„p „€„q„|„p„ƒ„„„„„p
		int regSY = currentRegion.y;		//„K„€„‚„t„y„~„p„„„p„„„p „T „~„p „~„p„‰„p„{„y„„„y „~„p „€„q„|„p„ƒ„„„„„p
		int regEX = currentRegion.w + regSX;		//„K„€„‚„t„y„~„p„„„p„„„p „V „~„p „{„‚„p„‘ „~„p „€„q„|„ƒ„„„„„p
		int regEY = regSY - currentRegion.h;		//„K„€„‚„t„y„~„p„„„p„„„p „T „~„p „{„‚„p„‘ „~„p „€„q„|„ƒ„„„„„p
		//„I„x„‰„y„ƒ„|„‘„r„p„}„u „t„p„|„y „ƒ„„„€„z„~„€„ƒ„„„y„„„u „€„„ „{„€„‚„t„y„~„p„„„y„„„u „~„p „„„€„‰„{„p„„„p „~„y, „ƒ„p „}„u„w„t„… „„„u„x„y „~„p „€„q„|„p„ƒ„„„„„p
		if ((pX > regSX && pX < regEX) && (pY < regSY && pY > regEY))
		{
			//„@„{„€ „€„„„{„‚„y„u„} „„„p„{„p„r„p „€„q„|„p„ƒ„„, „y„~„†„€„‚„}„y„‚„p„}„u „„€„„„‚„u„q„y„„„u„|„‘
			printf("The point (%d, %d) is found in the %dst region (%d, %d, %d, %d)\n", 
				pX, pY, i+1, regSX, regSY, regEX, regEY);
			//„P„‚„€„}„u„~„‘„}„u „‚„u„x„…„|„„„p„„„p
			FoundAnywhere = true;
		}
	}
	//„P„‚„€„r„u„‚„‘„r„p„}„u „t„p„|„y „„„€„‰„{„p„„„p „u „ƒ„p„}„p :(
	if (!FoundAnywhere)
	{
		//„I„x„r„u„ƒ„„„‘„r„p„}„u „„€„„„‚„u„q„y„„„u„|„‘
		printf("The point (%d, %d) isn't found anywhere :(\n", point.x, point.y);
	}
}


int main()
{
	//„S„‚„y„„„u „~„y „€„q„|„p„ƒ„„„y
	Region region1;	
	Region region2;
	Region region3;

	//„H„p„t„p„r„p„~„u „~„p „{„€„‚„t„y„~„p„„„y„„„u „y„}
	SetTheRegion(region1, -9, 6, 8, 9); 
	SetTheRegion(region2, -7, 7, 17, 5); 
	SetTheRegion(region3, 2, -2, 7, 5); 

	//„M„p„ƒ„y„r„p „{„€„z„„„€ „ƒ„Œ„t„Œ„‚„w„p „r„ƒ„y„‰„{„y „€„q„|„p„ƒ„„„y
	Region array[3] = { region1, region2, region3 };

	//„S„€„r„p „u „~„p„Š„p„„„p „„„€„‰„{„p
	Point point;

	//„I„ƒ„{„p„}„u „„€„„„‚„u„q„y„„„u„|„‘ „t„p „r„Œ„r„u„t„u „~„u„y„~„y„„„u „{„€„‚„t„y„~„p„„„y
	printf("Give 2 integer numbers (x, y) for the point.\n");
	scanf_s("%d", &point.x);
	scanf_s("%d", &point.y);
	
	//„I„x„r„y„{„r„p„}„u „†„…„~„{„ˆ„y„‘„„„p „{„€„‘„„ „„€„{„p„x„r„p „~„p „{„€„~„x„€„|„p„„„p „‚„u„x„…„|„„„p„„„p
	FoundInAnyRegion(array, point, 3);
}

