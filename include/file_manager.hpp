#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

namespace fm
{
	enum pokekit_type {NPC = 0, PG, PROP, test,};
	static const char* pokekit_relPaths[] {
		"/pokekit/Graphics/Characters/",	// NPC
		"/pokekit/Graphics/Characters/",	// PG
        "/pokekit/Graphics/Autotiles/",     // PROP
		"/pokekit/Graphics/"				// test
	};
}

#endif
