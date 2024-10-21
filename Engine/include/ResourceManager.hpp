#pragma once

#include <SDL3/SDL.h>
#include <unordered_map>
#include <memory>
#include <string>

/**
* Struct that handles deleting textures.
*/
struct TextureFunctorDeleter {
	void operator()(SDL_Texture* texture) const {
		SDL_DestroyTexture(texture);
	}
};


std::shared_ptr<SDL_Texture> make_shared_texture(SDL_Renderer* renderer, SDL_Surface* pixels);

/**
Class that handles loading and deleting textures.

The resource manager handles loading images from the file system into SDL efficiently, ensuring that once an image
has been loaded once, it will be reused rather than loaded again.
*/
struct ResourceManager {

    /**
    Returns an instance of the resource manager.

    Returns the current instance of the resource manager if one already exists,
    otherwise, creates a new one.
    */
	static ResourceManager& Instance() {
		if (nullptr == mInstance) {
			mInstance = new ResourceManager;
		}

		return *mInstance;
	}

	/**
	Loads an image from the filesystem into the resource manager.

	Loads the image at filepath as an SDL_Surface and saves it in the resource manager
	so that it can be reused in the future.

	\param renderer SDL_Renderer used to draw the image
	\param filepath Path to the image to be loaded
	*/
	std::shared_ptr<SDL_Texture> LoadTexture(SDL_Renderer* renderer, std::string filepath) {
		if (mTextureResources.find(filepath.c_str()) == mTextureResources.end()) {
			SDL_Surface* pixels = SDL_LoadBMP(filepath.c_str());
			SDL_SetSurfaceColorKey(pixels, SDL_TRUE,
				SDL_MapRGB(pixels->format, 0xFF, 0, 0xFF));

			std::shared_ptr<SDL_Texture> texture = make_shared_texture(renderer, pixels);

			mTextureResources.insert({ filepath.c_str(),texture});

			SDL_DestroySurface(pixels);
			SDL_Log("Created new resource %s", filepath.c_str());
		}
		else {
			SDL_Log("Reused resource %s", filepath.c_str());
		}

		return mTextureResources[filepath];

	}

private:
    /**
    Class declaration.
    */
	ResourceManager() {
	}

	/**
	Instance of the resource manager.
	*/
	inline static ResourceManager* mInstance{nullptr};

	/**
	Map of all currently loaded textures.

	Maps from a filepath to an SDL_Texture,
	so if the same image is passed in from multiple file paths, it will be duplicated.
	*/
	std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> mTextureResources;
};
