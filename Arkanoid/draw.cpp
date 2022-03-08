#include <draw.h>

void prepareScene(void)
{
	SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
	SDL_RenderClear(renderer);
}

void presentScene(void)
{
	SDL_RenderPresent(renderer);
}

SDL_Texture *loadTexture(const char *filename)
{
	SDL_Texture* texture;

	//SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(renderer, filename);

	return texture;
}

void blit(SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture, NULL, &dest);
}