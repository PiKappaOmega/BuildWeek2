/********** LIBRARIES START **********/
#include <stdio.h>
#include <stdlib.h>//used for "exit(0)"
#include <unistd.h>//used for "sleep"
/*********** LIBRARIES END ***********/
/********** BLOCK BLOCKS START **********/
int main ();
int menu ();
int vector ();
int faulty ();
int end ();
/*********** BLOCK BLOCKS END ***********/
/********** BLOCK MAIN START **********/
int main()
{
	printf("\a==============================================================================\n");
	printf("                         *** GRUPPO I - CS01-23 *** \n");
	printf("                              ==(W{==========-      /===-\n");
	printf("          IANNELLA Pasquale     ||  (.--.)         /===-_---~~~~~~~----__\n");
	printf("                                | \\_,|\\/|,__      |===-~___            _,-'`\n");
	printf(" CHIEPPA Marco     -==\\         `\\ ' `--'   ),    `//~\\    ~~~~`--._.-~\n");
	printf("               ______-==|        /`\\_. .__/\\ \\    | |  \\           _-~`\n");
	printf("         __--~~~  ,-/-==\\       (   | .  |~~~~|   | |   `\\       ,'\n");
	printf("      _-~       /'    |  \\      )__/==0==-\\<>/   / /      \\     /\n");
	printf("    .'      CIULLA Marco  \\       /~\\___/~~\\/  /' /        \\   /\n");
	printf("   /  ____  /         |    \\`\\.__/-~~   \\  |_/'  /          \\/'\n");
	printf("  /-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~`\n");
	printf("                    \\_|      /        _) | ;  ),   __--~~\n");
	printf("                      '~~--_/      _-~/- |/ \\   '-~ \\ \n");
	printf("                     {\\__--_/}    / \\ _>-|)<__\\      \\      DI SALVO Gabriele\n");
	printf("   KENYON Alessio    /'   (_/  _-~  | |__>--<__|      |\n");
	printf("                    |   _/) )-~     | |__>--<__|      |\n");
	printf("                    / /~ ,_/       / /__>---<__/      |  POSER Paola\n");
	printf("                   o-o _//        /-~_>---<__-~      /\n");
	printf("                   (^(~          /~_>---<__-      _-~\n");
	printf("                  ,/|           /__>--<__/     _-~\n");
	printf("       RESTANI Davide          |__>--<__|     /                  .--_\n");
	printf("              ( ( '))          |__>--<__|    |                 /' _-_~\\ \n");
	printf("           `-)) )) (           |ROVELLA Andrea              /'  /   ~\\`\\ \n");
	printf("    ._-~//( )/ )) `                    ~~-'_/_/ /~~~~~__--~     -Tua Xiong mod\n");
	printf("==============================================================================\n");
	menu();//launches "menu()"
}
/*********** BLOCK MAIN END ***********/
/********** BLOCK MENU START **********/
int menu()
{
	int menuPick = 0;
	printf("\nWelcome to Array Arranger\n");
    printf("This program will receive an input of 10 integer numbers\n");
   	printf("And arrange them in ascending order.\n");
    printf("How do you want to run this program?\n");
    printf("1. Regular\n");
    printf("2. Faulty\n");
   	printf("3. QUIT\n");
    printf("Your pick: ");
	while (1)
	{
    	if (scanf("%d", &menuPick) != 1)//Checks for input not being INT
	    {
    	    printf("Invalid input. Please, enter a valid parameter.\nYour pick: ");
    	    while (getchar() != '\n') {}//Empties input buffer to avoid looping
	        continue;
    	}
	    getchar();//Empties surplus chars
    	if (menuPick == 1) { vector(); }
	    else if (menuPick == 2) { faulty(); }
    	else if (menuPick == 3) { end(); }
    	else { printf("Invalid input. Please, enter a valid parameter.\nYour pick: "); }
	}
}
/********** BLOCK MENU END **********/
/********** BLOCK VECTOR START **********/
int vector ()
{
	// VAR DEF START
	long vector [10], i, j, k;//supports -2.147.483.648 to 2.147.483.647 (2bn 147m 483k 648)
	long swap_var;
	// VAR DEF END
	// PROG OPEN START
	printf ("\nType in 10 integer entries:\n");
	// PROG OPEN END
	// NUMBER OF VECTORS START
	for (long i = 0; i < 10; i++)//enumerates single entries assigning an incremental number to each
	{
		long c = i + 1;
		printf("[%ld]: ", c);
		while (scanf("%ld", &vector[i]) != 1)
		{
			printf("Wrong parameter - only Integer Numbers allowed!\nPlease, re-enter your INT: ");
		    while (getchar() != '\n') {} // clear input buffer
		}
	}
	// NUMBER OF VECTORS END
	// LISTS VECTORS IN A SINGLE ROW, SEPARATED BY COMMAS START
	printf("Inserted vectors are: ");
	for (i = 0; i < 10; i++)
	{
		if (i == 0) { printf("%ld", vector[i]);}//prints the first INT
		else { printf(", %ld", vector[i]); }// prints the other INTs with a ", "
	}
	printf("\n");
	sleep(3);//program waits 3 seconds to allow to check the sequence
	// LISTS VECTORS IN A SINGLE ROW, SEPARATED BY COMMAS END
	// ARRANGES VECTORS START //
	for (j = 0 ; j < 10 - 1; j++)// creates a J list
	{
		for (k = 0 ; k < 10 - j - 1; k++)// creates a temporary K list to compare values
		{
			if (vector[k] > vector[k+1])//checks INT size, in pairs (k and k+1)
			{
				//if first vector is greater than second, swaps pairs
				swap_var=vector[k];
				vector[k]=vector[k+1];
				vector[k+1]=swap_var;//swap command
			}
		}
	}
	// ARRANGES VECTORS END
	// LISTS ARRANGED VECTORS START
	printf("Here are thy vectors, in ascending order:\n");
	for (j = 0; j < 10; j++)//retrieves J
	{
		long g = j+1;//creates G, assigning J+1
		printf("[%ld]:", g);//prints [G]
		printf("%ld\n", vector[j]);//retrieves J, assigns to G
	}
	// LISTS ARRANGED VECTORS END
	menu();// runs "menu()"
}
/*********** BLOCK VECTOR END ***********/
/********** BLOCK FAULTY VECTOR START **********/
int faulty ()
{
	// VAR DEF START
	long vector [10], i, j, k;
	long* g = NULL;//Indicizes G as pointer (*) to an empty address (NULL)
	long swap_var;
	// VAR DEF END
	// PROG OPEN START
	printf ("\nThis cycle will perform a 'Segmentation fault (core dumped)' error.\n");
	printf ("Type in 10 integer entries:\n");
	// PROG OPEN END
	// NUMBER OF VECTORS START
	for (long i = 0; i < 10; i++)
	{
		long c = i + 1;
		printf("[%ld]: ", c);
		while (scanf("%ld", &vector[i]) != 1)
		{
			printf("Wrong parameter - only Integer Numbers allowed!\nPlease, re-enter your INT: ");
		    while (getchar() != '\n') {}
		}
	}
	// NUMBER OF VECTORS END
	// LISTS VECTORS IN A SINGLE ROW, SEPARATED BY COMMAS START
	printf("Inserted vectors are: ");
	for (i = 0; i < 10; i++)
	{
		if (i == 0) { printf("%ld", vector[i]);}//prints the first INT
		else { printf(", %ld", vector[i]); }//prints the other INTs with a ", "
	}
	printf("\n");
	sleep(3);//program waits 3 seconds to allow to check the sequence
	// LISTS VECTORS IN A SINGLE ROW, SEPARATED BY COMMAS END
	// ARRANGES VECTORS START
	for (j = 0 ; j < 10 - 1; j++)
	{
		for (k = 0 ; k < 10 - j - 1; k++)
		{
			if (vector[k] > vector[k+1])
			{
				swap_var=vector[k];
				vector[k]=vector[k+1];
				vector[k+1]=swap_var;
			}
		}
	}
	// ARRANGES VECTORS END
	// LISTS ARRANGED VECTORS START
	printf("Here are thy vectors, in ascending order:\n");
	for (j = 0; j < 10; j++)
	{
		*g = j+1;// MODIFIED: "int g = j+1" | THIS CAUSES THE SEGMENTATION FAULT
		/* "*g" causes a "segmentation fault" 'cause' g points to no variable.
		g has a wrong value and attempts to access a memory sectionit has no access to*/
		printf("[%ld]:", g);//prints [G]	
		printf("%ld\n", vector[j]);
	}
	// LISTS ARRANGED VECTORS END
	menu();// launches "menu()"
}
/*********** BLOCK FAULTY VECTOR END ***********/
/*********** BLOCK END START ***********/
int end()
{
	printf("\n======================================\n");
	printf("        _________   _ ____       *\n");
	printf("  *     | ____|  \\ | |  _ \\ \n");
	printf("        | |__ |   \\| | | \\ \\ * \n");
	printf("     *  |  __|| |\\   | |  \\ \\ \n");
	printf("   *    | |___| | \\  | |__| |      *\n");
	printf("        |_____|_|  \\_|______|\n");
	printf("\n");
	printf("======================================\n\n"); 
	exit(0);// ends the program
}
/*********** BLOCK END END ***********/
//======================================================================
//========================== END OF FILE ===============================
//======================================================================

/* REPOSITORY
OLD ENTRY LOGO
 printf("\a==============================================================================\n");
 printf("                              *** GRUPPO I *** \n");
 printf("                              ==(W{==========-      /===-\n");
 printf("          IANNELLA Pasquale     ||  (.--.)         /===-_---~~~~~~~----__\n");
 printf("                                | \\_,|\\/|,__      |===-~___            _,-'`\n");
 printf(" CHIEPPA Marco     -==\\         `\\ ' `--'   ),    `//~\\    ~~~~`--._.-~\n");
 printf("               ______-==|        /`\\_. .__/\\ \\    | |  \\           _-~`\n");
 printf("         __--~~~  ,-/-==\\       (   | .  |~~~~|   | |   `\\       ,'\n");
 printf("      _-~       /'    |  \\      )__/==0==-\\<>/   / /      \\     /\n");
 printf("    .'      CIULLA Marco  \\       /~\\___/~~\\/  /' /        \\   /\n");
 printf("   /  ____  /         |    \\`\\.__/-~~   \\  |_/'  /          \\/'\n");
 printf("  /-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~`\n");
 printf("                    \\_|      /        _) | ;  ),   __--~~\n");
 printf("                      '~~--_/      _-~/- |/ \\   '-~ \\ \n");
 printf("                     {\\__--_/}    / \\ _>-|)<__\\      \\      DI SALVO Gabriele\n");
 printf(" KENYON Alessio      /'   (_/  _-~  | |__>--<__|      |\n");
 printf("                    |   _/) )-~     | |__>--<__|      |\n");
 printf("                    / /~ ,_/       / /__>---<__/      |  POSER Paola\n");
 printf("                   o-o _//        /-~_>---<__-~      /\n");
 printf("                   (^(~          /~_>---<__-      _-~\n");
 printf("                  ,/|           /__>--<__/     _-~\n");
 printf("               ,//('(          |__>--<__|     /                  .--_\n");
 printf("              ( ( '))          |__>--<__|    |                 /' _-_~\\ \n");
 printf("           `-)) )) (           |__>--<__|    |               /'  /   ~\\`\\ \n");
 printf("       RESTANI Davide           \\__>--<__\\    \\            /'  //      ||\n");
 printf("        ,( ( ((, ))              ~-__>--<_~-_  ~--__---~'/'/  /'       VV\n");
 printf("      `~/  )` ) ,/|                 ~-_~>--<_/-__      __-~ _/\n");
 printf("    ._-~//( )/ )) `                    ~~-'_/_/ /~~~~~__--~\n");
 printf("     ;'( ')/ ,)(      ROVELLA Andrea         ~~~~~~~~\n");
 printf("    ' ') '( (/                                                  -Tua Xiong mod\n");
 printf("==============================================================================\n");
 */
