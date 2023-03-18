#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported
{

	DRAW_LINE,		
	DRAW_RECT,		
	DRAW_TRI,		
	DRAW_CIRC,		
	SEL,                  //Select a figure
	CHNG_DRAW_CLR_BLACK,  
	CHNG_DRAW_CLR_RED,	
	CHNG_DRAW_CLR_BLUE,	    
	CHNG_DRAW_CLR_GREEN,	

	CHNG_FILL_CLR_BLACK,
	CHNG_FILL_CLR_RED,
	CHNG_FILL_CLR_BLUE,
	CHNG_FILL_CLR_GREEN,
	CHNG_FILL_CLR_WHITE,

	COPY,           //Copy a figure
	CUT,            //Cut a figure
	PASTE,          //Paste a figure
	DEL,			//Delete a figure
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

//The following 2 enums are useful in case of Save and Load ations
//They are used to store information about the drawn figures in a text file as integers not strings
//in order to facilitate the save and load code

enum FigureType 
{
	LINE,
	RECTANGLE,
	TRIANGLE,
	CIRCLE,
};

enum ColorName 
{
	WHITE_CLR,
	BLACK_CLR,
	RED_CLR,
	BLUE_CLR,
	GREEN_CLR,
};


#endif