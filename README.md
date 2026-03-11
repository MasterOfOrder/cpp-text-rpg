# C++ Text RPG

A turn-based combat RPG playable in the terminal. Built in C++ using object-oriented programming.

## Gameplay

You play as **Conan**, a warrior who must defeat **Herpo, The Terrible** in turn-based combat. Each round you choose one of three actions:

- **Attack** — Deal damage to the enemy
- **Defend** — Double your defense for the turn while the enemy attacks
- **Heal** — Recover HP before the enemy strikes back

The enemy gets stronger when it drops below half HP, so don't let the fight drag on too long!

## How To Compile & Run

Make sure you have a C++ compiler installed (g++ recommended).

```bash
g++ -o rpg main.cpp
./rpg
```

On Windows:
```bash
g++ -o rpg main.cpp
rpg.exe
```

## Features

- Turn-based combat system
- Three player actions: Attack, Defend, Heal
- Random damage factor each turn to keep fights unpredictable
- Enemy enrages at 50% HP, dealing bonus damage
- Heal is capped at max HP so you can't overheal

## Built With

- C++
- OOP (inheritance, polymorphism, encapsulation, abstraction)

## Author

**masteroforder** — [github.com/masteroforder](https://github.com/masteroforder)
