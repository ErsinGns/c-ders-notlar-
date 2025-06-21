#include <stdio.h>
typedef enum { white, gray, blue, magenta, brown, red, black,NoOfColors }Color;

int main()
{
	for (Color c = white; c < NoOfColors; ++c)
		printf("%d", c);
}