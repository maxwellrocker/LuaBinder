#ifndef HERO_H
#define HERO_H

#include "../include/Binder.h"

class Hero
{
public:
    Hero(const char* name);
    virtual ~Hero();

    const char* GetName();
    void SetEnergy(double energy);
    double GetEnergy();

    static int bnd_Create(lua_State* L);
    static int bnd_Destroy(lua_State* L);
    static int bnd_GetEnergy(lua_State* L);
    static int bnd_SetEnergy(lua_State* L);

protected:

private:
    const char* HeroName;
    double      HeroEnergy;
};

#endif // HERO_H
