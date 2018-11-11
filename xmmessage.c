
/* include the X library headers */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdio.h>
#include <stdlib.h>


#include <dirent.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 
#include <time.h>

#include "xcurses.c"


int main( int argc, char *argv[])
//int main()
{

        int ch ; int gameover = 0;
        char text[255];
        char content[PATH_MAX];
	initscr();
        //int posy = 10; int i; 
        int posy ; 

	while( gameover == 0 ) 
        {		
		XNextEvent(dis, &event);
                
                posy = 10; int i;
                //erase();
                //for( i = 1; i <= 15 ; i++)
                for( i = 1 ; i <= 30 ; i++)
                {
                    strncpy( content, argv[ 1 ], PATH_MAX );
                    //mvprintw( posy , 15 , content );   
                  //  //strcpy(text, mystring );
                    XDrawString(dis,win,gc, 10 , posy , content, strlen(content));
                    XDrawString(dis,win,gc, 300 , posy , content, strlen(content));
                    posy = posy + 15;
                }

                ch = getch(); 

                if      ( ch =='L') {    mvprintw( 250, 250, "line" );   } 
                else if ( ch =='l') {    mvlinew( 20, 30, 100, 120 ); }
                else if ( ch =='r') {    mvrectanglew( 10, 20, 100, 200); }
                else if ( ch =='q') {  gameover = 1 ; }
                else if ( ch =='p') {  mvpointw( 75, 50 ); }

		if (event.type==ButtonPress) 
                {
			int x=event.xbutton.x, y=event.xbutton.y;
                        XSetForeground(dis, gc, 0 );
			mvprintw( y, x , "Mouse ");
			printf( "Y=%d X=%d\n", y, x );
		}

	}

   	endwin();
	return 0;
}



