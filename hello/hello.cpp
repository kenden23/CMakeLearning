#include <stdio.h>
#include <stdlib.h>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "utils.h"
#endif

int main(int argc, char *argv[])
{
   printf("hello, world.\n");

   fprintf(stdout, "%s Version %d.%d\n",
	   argv[0],
	   Tutorial_VERSION_MAJOR,
	   Tutorial_VERSION_MINOR);
   fprintf(stdout, "Usage: %s number\n", argv[0]);

   int a = 6, b = 2, c = 6;
#ifdef USE_MYMATH
   c = add(a, b);
   printf("using USE_MYMATH.\n");
#else
   c = a + b;
#endif

   printf("a + b  = %d\n", c);

   system("pause");

   return 0;
}