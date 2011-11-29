#include "../include/Hero.h"

Hero::Hero(const char* name)
{
    //ctor
    HeroName    = name;
    HeroEnergy  = 0;
}

Hero::~Hero()
{
    //dtor
}

void Hero::SetEnergy(double energy)
{
    HeroEnergy = energy;
}

double Hero::GetEnergy()
{
    return HeroEnergy;
}

int Hero::bnd_Create(lua_State* L)
{
    Binder binder(L);
    Hero* h = new Hero(binder.checkstring(1));
    binder.pushusertype(h, "Hero");
    return 1;
}

int Hero::bnd_Destroy(lua_State* L)
{
    Binder binder(L);
    Hero* h = (Hero*)binder.checkusertype(1, "Hero");
    delete h;
    return 0;
}

int Hero::bnd_GetEnergy(lua_State* L)
{
    Binder binder(L);
    Hero* hero = (Hero*)binder.checkusertype(1, "Hero");
    binder.pushnumber(hero->GetEnergy());
    return 1;
}

int Hero::bnd_SetEnergy(lua_State* L)
{
    Binder binder(L);
    Hero* hero = (Hero*)binder.checkusertype(1, "Hero");
    hero->SetEnergy(binder.checknumber(2));
    return 0;
}
