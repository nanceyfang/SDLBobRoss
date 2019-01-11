#include<SDL.h>
#include <vector>

class Mountain {
public: 
	Mountain(SDL_Renderer*, SDL_Color, std::vector<SDL_Point>, const int);
	void drawMountain();
private:
	SDL_Renderer* const renderer;
	const SDL_Color COLOR;
	std::vector<SDL_Point> border;
	const int bottom;
};

