#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};


struct colorPair
{
	int pairNo;
	char MajorColor[8];
	char MinorColor[8];
};

colorPair Pair[25];

int printColorMap() {
    
    int i = 0, j = 0, ArrayIndex = 1;
    for(i = 0; i < 5; i++) 
	{
        for(j = 0; j < 5; j++)
		{
			
			Pair[ArrayIndex].pairNo = ArrayIndex;
			strcpy(Pair[ArrayIndex].MajorColor , majorColor[i]);
			strcpy(Pair[ArrayIndex].MinorColor , minorColor[i]);
			printf("%d | %s | %s\n", ArrayIndex, majorColor[i], minorColor[i]);	
		        ArrayIndex++;				          
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
	assert(Pair[10].pairNo == 10);	
	assert(strcmp(Pair[10].MajorColor, "Red") == 0);
	assert(strcmp(Pair[10].MinorColor, "Slate") == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
