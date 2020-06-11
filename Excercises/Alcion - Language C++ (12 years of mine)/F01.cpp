# include <iostream.h>
# include <stdio.h>
# include <conio.h>

main()

{
	clrscr();
	FILE* f1 = fopen("b:\install.txt","wt+");
	if (!f1) { cout << "Error create file"; }
	fputs("Hello, File!",f1);

return 0;
}