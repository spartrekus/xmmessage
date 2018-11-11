

// XCURSES LIBRARY 
// Vers. 0.1, Simple Library
// usage: apt-get install libx11-dev (linux)


/* here are our X variables */
Display *dis;
int screen;
Window win;
GC gc;

/* here are our X routines declared! */
//void init_x();
//void endwin();
void redraw();

XEvent event;		/* the XEvent declaration !!! */
KeySym key;		/* a dealie-bob to handle KeyPress Events */	

void initscr() 
{
        /* get the colors black and white (see section for details) */        
	unsigned long black,white;

	dis=XOpenDisplay((char *)0);
   	screen=DefaultScreen(dis);
	black=BlackPixel(dis, screen),
	white=WhitePixel(dis, screen);
        // xserver android
   	//win=XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0,	1260, 690, 5, black, white);
   	win=XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0,	640, 480, 5, black, white);
	XSetStandardProperties(dis,win,"X11 Window","Hi",None,NULL,0,NULL);
	XSelectInput(dis, win, ExposureMask|ButtonPressMask|KeyPressMask);
        gc=XCreateGC(dis, win, 0,0);        
	XSetBackground(dis,gc,white);
	XSetForeground(dis,gc,black);
	XClearWindow(dis, win);
	XMapRaised(dis, win);
};

void endwin() {
	XFreeGC(dis, gc);
	XDestroyWindow(dis,win);
	XCloseDisplay(dis);	
	exit(1);				
};


int getch()
{
     char text[255];
     int valuert = 0;
     if (event.type == KeyPress && XLookupString(&event.xkey, text, 255,&key,0)==1) 
       valuert = text[ 0 ];
     else 
       valuert = 0;

     return valuert;  
}

void erase() {
	XClearWindow(dis, win);
};

void redraw() {
	XClearWindow(dis, win);
};

void mvprintw( int yy , int xx , char *mystring) 
{
      int x = xx; int y= yy;  char text[255];			
      strcpy(text, mystring );
      XDrawString(dis,win,gc,x,y, text, strlen(text));  
};

void mvlinew( int y0, int x0, int y1, int x1)
{
    XPoint points[] = {
      {y0, x0},
      {y1, x1}
    };
    int npoints = sizeof(points)/sizeof(XPoint);
    XDrawLines( dis , win, gc, points, npoints, CoordModeOrigin);
}

void mvpointw( int y0, int x0 )
{
    XDrawPoint(dis, win, gc, x0 , y0 );
}

void mvrectanglew( int y0, int x0, int y1, int x1)
{
   XDrawRectangle(dis, win, gc, y0, x0, y1-y0, x1-x0);
}


