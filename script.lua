local h = Hero.Create("my hero")

local e = Hero.GetEnergy(h)
Hero.SetEnergy(h, e-1)

print(Hero.GetEnergy(h))

Hero.Destroy(h)