/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-cyril.grosjean
** File description:
** core_sdl
*/

#include "core_sdl.hpp"

core_sdl::core_sdl(/* args */)
{
	this->_isGameStarted = false;
	this->_username = "lol";
}

core_sdl::~core_sdl()
{
}

void core_sdl::display(IGameModule *g_data)
{
	input_management_game();
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
	updateGame(g_data);
	drawGame(g_data);
	SDL_RenderPresent(this->_renderer);
}

Vector2i core_sdl::getEventClick(void)
{
	Vector2i mousePosition = Vector2i(_mousePosition.x, _mousePosition.y);
	_mousePosition = Vector2i(-1, -1);
	return mousePosition;
}

char core_sdl::getEventKeyboard(void)
{
	char keyboardInput = _keyboardInput;
	_keyboardInput = 0;
	return keyboardInput;
}

void core_sdl::initGame(IGameModule *g_data)
{
	_game.initTiles(g_data->getTiles(), _renderer);
	_game.initObjects(g_data->getObjects(), _renderer);
}

void core_sdl::updateGame(IGameModule *g_data)
{
	this->_game.updateObjects(g_data->getObjects(), _renderer);
}

void core_sdl::drawGame(IGameModule *g_data)
{
	_game.drawTiles(_renderer, g_data->getTiles());
	_game.drawObjects(_renderer, g_data->getObjects());
	drawSetting(g_data->getSettings());
}
void core_sdl::drawSetting(Settings settings)
{
	std::string user = "User";
	putText({(50, 50, user + settings._playerName, false)});
	putText({(300, 50, "........MABITE", false)});
}

void core_sdl::destroyGame(IGameModule *g_data)
{
	SDL_RenderClear(_renderer);
	_game._tiles.clear();
	_game._objects.clear();
	_mainMenuInfo.clear();
	_isGameStarted = false;
}

void core_sdl::close()
{
	SDL_DestroyTexture(this->_background);
	this->_background = nullptr;
	SDL_DestroyRenderer(this->_renderer);
	this->_renderer = nullptr;
	SDL_DestroyWindow(this->_window);
	this->_window = nullptr;
	TTF_CloseFont(this->_font);
	this->_font = nullptr;
	TTF_Quit();
	SDL_Quit();
}
void core_sdl::input_management_game()
{
	while (SDL_PollEvent(&_input) > 0)
	{
		if (this->_input.type == SDL_KEYDOWN)
		{
			switch (this->_input.key.keysym.sym)
			{
			case SDLK_LEFT:
				this->_keyboardInput = 4;
				break;
			case SDLK_RIGHT:
				this->_keyboardInput = 3;
				break;
			case SDLK_UP:
				this->_keyboardInput = 1;
				break;
			case SDLK_DOWN:
				this->_keyboardInput = 2;
				break;
			case SDLK_SPACE:
				this->_keyboardInput = 13;
				break;
			case SDLK_RETURN:
				this->_keyboardInput = 32;
				break;
			case SDLK_ESCAPE:
				this->_keyboardInput = 27;
				break;
			case SDL_QUIT:
				this->_keyboardInput = 27;
				break;
			default:
				this->_keyboardInput = this->_input.key.keysym.sym;
				break;
			}
		}
	}
}

void core_sdl::input_management(std::vector<std::string> games, std::vector<std::string> graphicals)
{
	while (SDL_PollEvent(&_input) > 0)
	{
		if (this->_input.type == SDL_KEYDOWN)
		{
			switch (this->_input.key.keysym.sym)
			{
			case SDLK_LEFT:
				this->_keyboardInput = 4;
				break;
			case SDLK_RIGHT:
				this->_keyboardInput = 3;
				break;
			case SDLK_UP:
				this->_keyboardInput = 1;
				break;
			case SDLK_DOWN:
				this->_keyboardInput = 2;
				break;
			case SDLK_SPACE:
				this->_keyboardInput = 13;
				break;
			case SDLK_RETURN:
				this->_keyboardInput = 32;
				break;
			case SDLK_ESCAPE:
				this->_keyboardInput = 27;
				break;
			case SDL_QUIT:
				this->_keyboardInput = 27;
				break;
			default:
				this->_keyboardInput = this->_input.key.keysym.sym;
				break;
			}
		}
	}
}

void core_sdl::drawMainMenu()
{
	SDL_Rect rect;
	rect.h = 960;
	rect.w = 960;
	rect.x = 0;
	rect.y = 0;
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, _background, NULL, &rect);
	putText({300, 50, "Arcade SDL Graphics", false});
	// putText({300, 50, __LC_NAME, false});
	SDL_RenderPresent(_renderer);
}

void core_sdl::open()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "SDL initialization failed." << std::endl;
		exit(EXIT_FAILURE);
	}
	if (TTF_Init() != 0)
	{
		std::cerr << "SDL_ttf initialization failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	IMG_Init(IMG_INIT_PNG);
	this->_window = SDL_CreateWindow("Arcade SDL graphics", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 960, 0);
	if (this->_window == nullptr)
	{
		std::cerr << "SDL window creation failed." << std::endl;
		exit(EXIT_FAILURE);
	}
	this->_renderer = SDL_CreateRenderer(this->_window, -1,
										 SDL_RENDERER_ACCELERATED);
	if (this->_renderer == nullptr)
	{
		std::cerr << "SDL renderer creation failed." << std::endl;
		exit(EXIT_FAILURE);
	}
	this->_font = TTF_OpenFont("assets/sfml/arcade.ttf", 200);
	this->_background = IMG_LoadTexture(this->_renderer, "assets/sdl/menu.jpg");
}

std::unordered_map<std::string, std::string> *core_sdl::displayMainMenu(std::vector<std::string> games, std::vector<std::string> graphicals)
{
	if (_isGameStarted == true)
	{
		_mainMenuInfo.insert(std::make_pair("NAME", _username));
		_mainMenuInfo.insert(std::make_pair("GAME", (games.size() != 0) ? games[_mainMenu._gameIdx] : "UNDEFINED"));
		_mainMenuInfo.insert(std::make_pair("GRAPH", (graphicals.size() != 0) ? graphicals[_mainMenu._graphicalIdx] : "UNDEFINED"));
		close();
		return &_mainMenuInfo;
	}
	input_management(games, graphicals);
	drawMainMenu();
	return nullptr;
}

void core_sdl::putText(const core_sdl::Text &string)
{
	SDL_Color black = {0, 0, 0, 0};
	SDL_Surface *surfaceText = TTF_RenderText_Blended(_font,
													  string.text.c_str(), black);
	SDL_Texture *text = SDL_CreateTextureFromSurface(_renderer,
													 surfaceText);
	SDL_Rect rect;
	rect.x = string.x;
	rect.y = string.y;
	rect.w = string.text.length() * 15;
	rect.h = 24;
	SDL_RenderCopy(_renderer, text, NULL, &rect);
	SDL_DestroyTexture(text);
	SDL_FreeSurface(surfaceText);

	if (string.underline)
	{
		SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
		for (unsigned int i = 0; i < string.text.length() / 2 +
										 string.text.length() / 4;
			 ++i)
		{
			for (int j = 0; j < 21; ++j)
			{
				SDL_RenderDrawPoint(_renderer,
									(string.x + i) * 21 + j,
									(string.y + 1) * 21);
			}
		}
	}
}
