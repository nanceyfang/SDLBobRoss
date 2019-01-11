#include <SDL.h>
#include <vector>

class Tree {
public:
	Tree(SDL_Renderer*, SDL_Point, const int);
	void drawTrunks();
	void drawTree();
	void makeLeaves();
	void moveTree(int);
	SDL_Point getPosition() const;
private:
	SDL_Renderer* const renderer;
	const SDL_Point POSITION;
	const int HEIGHT;
	std::vector<SDL_Rect> leaves;
};
