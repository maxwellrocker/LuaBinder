#include <iostream>
#include "include/Hero.h"

using namespace std;

static const luaL_Reg herolib[] = {
    {"Create",      Hero::bnd_Create},
    {"Destroy",     Hero::bnd_Destroy},
    //{"GetName",     Hero::bnd_GetName},
    {"GetEnergy",   Hero::bnd_GetEnergy},
    {"SetEnergy",   Hero::bnd_SetEnergy},
    {NULL, NULL}
};

int luaopen_hero(lua_State* L){
    Binder binder(L);
    binder.init("Hero", herolib);
    return 1;
}

int main()
{
    cout << "Hello world!" << endl;

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
	luaopen_hero(L);
    luaL_dofile(L, "script.lua");

    return 0;
}
