#ifndef BINDER_H
#define BINDER_H

extern "C"{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

class Binder
{
public:
    Binder(lua_State* _L);
    virtual ~Binder();

    //Module(library) initializer
    void init(const char* tname, const luaL_Reg* flist);

    //Mapping methods for basic types
    void pushnumber(double v);
    double checknumber(int index);
    void pushstring(const char* s);
    const char* checkstring(int index);

    //Mapping methods for typed host objects
    void pushusertype(void* udata, const char* tname);
    void* checkusertype(int index, const char* tname);

protected:

private:
    lua_State* L;
};

#endif // BINDER_H
