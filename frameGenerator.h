#include <string>
#include <SDL.h>

// Class to make a frame/screenshot of what is drawn to the screen
// the image will appear in a folder called frames

class FrameGenerator {
public:
  FrameGenerator(SDL_Renderer*, SDL_Window*, int, int, const std::string&);
  void makeFrame();
private:
  SDL_Renderer* const renderer;
  SDL_Window* const window;
  const int WIDTH;
  const int HEIGHT;
  const std::string USERNAME;
  FrameGenerator(const FrameGenerator&);
  FrameGenerator& operator=(const FrameGenerator&);
};

