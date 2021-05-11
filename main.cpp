#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <algorithm>
#include <ctype.h>
#include <time.h>

using namespace std;




const int SCREEN_WIDTH = 860;
const int SCREEN_HEIGHT = 580;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gXOut = SDL_LoadBMP( "mtr-lặn.bmp" );
	if( gXOut == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "mtr-lặn.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( gXOut );
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
    int m,n,x=0,row_1,column_1,row_2,column_2;
    char rand_1[16]={'a','g','h','j','k','a','s','d','f','g','s','d','f','h','j','k'};
    struct mem_char
    {
    char ch[5][5];
    };
        char re_play;
    mem_char char_1[2];


void output()
{
    //hien thi man hinnh chinh cua game
    for(int e=0 ; e<5 ; e++)
    {
	cout<<"       \t\t\t";
	for(int q=0 ; q<5 ; q++)
	{
        cout<<char_1[0].ch[e][q]<<"    ";
	}
	cout<<endl<<endl<<endl;
    }
}

void delay(long seconds){
    //tạo độ trễ trên màn hình
	clock_t time1 = clock(); //SD thời gian đồng hồ
   	clock_t time2 = time1 + seconds;
  	while(time1 < time2)
   	time1 = clock();
  	return;
    }

void sleep(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
    }


int main( ){
	//Start up SDL and create window

	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;

			SDL_Event e;

			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//Apply the image
				SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}

	//Free resources and close SDL
	close();

	srand(time(0));
	random_shuffle(rand_1,rand_1+16);
    for( m=1 ; m<5 ; m++)
        {
            for ( n=1 ; n<5 ; n++)
            {
                do
                {
                    char_1[1].ch[m][n]=*(rand_1+x);
                    x++;
                    break;
                }while(x<16);
            }
        }
    char_1[0].ch[0][0]=' ';
        for ( int u=1 ; u<5 ; u++)
        {
            char_1[0].ch[0][u]=48+u;
            char_1[0].ch[u][0]=48+u;
            for(int y=1 ; y<5 ; y++)
            {
                char_1[0].ch[u][y]='*';
            }
        }

    {
        cout<<"       \t"<<"     1    2    3    4"<<endl<<endl<<endl;
        for(int i=1 ; i<5 ; i++)
        {
            cout<<"       \t\t\t";
            for (int j=0 ; j<5 ; j++)
            {
                cout<<char_1[0].ch[i][j]<<"    ";
            }
            cout<<endl<<endl<<endl;
        }
    }


    if(char_1[1].ch[row_1][column_1]==char_1[1].ch[row_2][column_2]){
                    cout<<"Good "<<endl;
            char_1[0].ch[row_1][column_1]=' ';
            char_1[0].ch[row_2][column_2]=' ';

        }
        else{
        cout<<"Try Again";

        }


    if(char_1[1].ch[row_1][column_1]!=char_1[1].ch[row_2][column_2]){
        char_1[0].ch[row_1][column_1]='*','*';
        char_1[0].ch[row_2][column_2]='*','*';
    }
    sleep(1600);
    system("cls");

    for (int i=1 ; i<2 ; i++){
        for (int  j=1 ; j<2 ; j++){
            if (char_1[0].char[i][j]==' '&&char_1[0].char[i][j+1]==' '&&char_1[0].char[i][j+2]==' '&&char_1[0].char[i][j+3]==' '&&char_1[0].char[i+1][j]==' '
             &&char_1[0].char[i+1][j+1]==' '&&char_1[0].char[i+1][j+2]==' '&&char_1[0].char[i+1][j+3]==' '&&char_1[0].char[i+2][j]=='  '&&char_1[0].char[i+2][j+1]==' '
             &&char_1[0].char[i+2][j+2]==' '&&char_1[0].char[i+2][j+3]==' '&&char_1[0].char[i+3][j]==' '&&char_1[0].char[i+3][j+1]==' '&&char_1[0].char[i+3][j+2]==' '
             &&char_1[0].char[i+3][j+3]==' '){
                cout<<"\n\nYou win!!!"<<endl<<endl;
                cout<<"Do you want to play again?(y/n)";
                cin>>re_play;
                re_play=tolower(re_play);
            while(isdigit(re_play)){
                cout<<"Please enter a character";
                cin>>re_play;
                }
            if (re_play=='y'){

                x=0;
                system("cls");
                main();
                }
            if (re_play=='n'){
                cout<<"Thank you for playing memory";
                exit(0);
                }
            else{
                exit(0);
                }
            }
        }
    }


	return 0;

}
