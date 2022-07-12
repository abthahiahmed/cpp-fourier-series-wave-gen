#include <iostream>
#include <vector>

#include <math.h>
#include <SDL2/SDL.h>

using namespace std;

#define TWO_PI 2 * 3.1416
#define PI 3.1416

void print(string str){
    cout<<str;

}
void println(string str){
    cout<<str<<endl;

}

void drawCircle(SDL_Renderer *ren, int x, int y, int r){
    for(float i = 0; i < TWO_PI; i += 0.04){
       
        float cx = r * cos(i);
        float cy = r * sin(i);
        SDL_RenderDrawPoint(ren, x + cx, y + cy);
    }	
}

int main(int argc, char **argv){

    SDL_Window *win = SDL_CreateWindow("Mechanism", 100,100, 1000, 600, SDL_WINDOW_SHOWN);
    if(!win){
        cout<<"Error in creating Window"<<endl;
        exit(1);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 0);
    if(!ren){
        cout<<"Error in creating Renderer"<<endl;
        exit(1);
    }



    SDL_Event event;
	
	int x = 300, y = 300;
	float r = 100;
	bool running = true;
	float time = 0;
	
	vector<float> waves;
	
	
	while(running){
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		
		drawCircle(ren, x, y, r);
		
		float cx = r * cos(time);
		float cy = r * sin(time);
		
		time += 0.03;
		waves.insert(waves.begin(), cy);
		
		SDL_RenderDrawPoint(ren, x+ cx, y+cy);
		
		SDL_RenderDrawLine(ren, x + cx, y + cy,700 , y+cy);
		
		drawCircle(ren, x + cx, y + cy, 10);
		
		for (unsigned int i=0; i < waves.size(); i++){
			SDL_RenderDrawPoint(ren, 700 + i, y + waves[i]);
		}
		
		if(waves.size() > 400){
			waves.pop_back();
		}
		
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT){
            running = false;
        }
        SDL_RenderPresent(ren);

    }
    if(running == false){
        print("Program Terminated.");
    }
    return 0;
}

