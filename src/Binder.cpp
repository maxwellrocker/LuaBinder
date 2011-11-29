#include "../include/Binder.h"

Binder::Binder(lua_State* _L)
{
    //ctor
    L = _L;
}

Binder::~Binder()
{
    //dtor
}

void Binder::init(const char* tname, const luaL_Reg* flist)
{
    luaL_register(L, tname, flist);
}

void Binder::pushnumber(double v)
{
    lua_pushnumber(L, v);
}

double Binder::checknumber(int index)
{
    return luaL_checknumber(L, index);
}

void Binder::pushstring(const char* s)
{
    lua_pushstring(L, s);
}

const char* Binder::checkstring(int index)
{
    return luaL_checkstring(L, index);
}

void Binder::pushusertype(void* udata, const char* tname)
{
    lua_pushlightuserdata(L, udata);
}

void* Binder::checkusertype(int index, const char* tname)
{
    void* udata = lua_touserdata(L, index);
    if(udata == 0)
        luaL_typerror(L, index, tname);

    return udata;
}
