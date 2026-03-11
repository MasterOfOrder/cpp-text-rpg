#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef double dbl;

class Character {
protected:
    string name;
    dbl attack;
    dbl defense;
    dbl hp;
    dbl maxHp;
    int defenseModifier = 1;
    int healFactor = 0;

public:
    virtual void attackTarget(Character &target) = 0;
    Character(string n, dbl a, dbl d, dbl h, dbl mh) {
        name = n;
        attack = a;
        defense = d;
        hp = h;
        hp = maxHp = h;
    }
    dbl getHp() {return hp;}
    string getName() {return name;}
    dbl getMaxHp() {return maxHp;}
    dbl getAttack() {return attack;}
    dbl getDefense() {return defense;}
    dbl getDefenseModifier() {return defenseModifier;}
    dbl setDefenseModifier(int target) {
        defenseModifier = target;
        return defenseModifier;
    }
    int setHealFactor(int target) {
        healFactor = target;
        return healFactor;
    }
    void takeDamage(dbl dmg) {
        hp = hp - dmg + healFactor;
        if (hp <= 0) hp = 0;
    }
};
class Enemy : public Character {
public:
    Enemy(string n, dbl a, dbl d, dbl h, dbl mh):
    Character(n, a, d, h, mh) {}
    void attackTarget (Character &player) override {
        dbl randomFactor = rand() % 10 + 1;
        dbl damage = attack - (player.getDefense()/2 * player.getDefenseModifier()) + randomFactor;
        if (hp <= maxHp/2) {
            damage += 10;
        }
        if (damage<=0) damage = 0;
        player.takeDamage(damage);
        cout << name << " Dealt " << damage << " Damage To " << player.getName() << "\n";
        cout << player.getName() << " Has " << player.getHp() << " HP Left!\n";
    }
};
class Player : public Character {
public:
    Player(string n, dbl a, dbl d, dbl h, dbl mh):
    Character(n, a, d, h, mh) {}
    void attackTarget(Character &enemy) override {
        dbl randomFactor = rand() % 10 + 1;
        dbl damage = attack - (enemy.getDefense()/2 * enemy.getDefenseModifier()) + randomFactor;
        if (damage <= 0) damage = 0;
        enemy.takeDamage(damage);

        cout << name << " Dealt " << damage << " Damage To " << enemy.getName() << "\n";
        cout << enemy.getName() << " Has " << enemy.getHp() << " HP Left!\n";
    }
    void playerAttack(Character &enemy) {
        attackTarget(enemy);
        if (enemy.getHp() <=0) {
            cout << enemy.getName() << " Lost!\n";
            cout << name << " Wins!\n";
            return;
        }
        enemy.attackTarget(*this);
        if (getHp() <=0) {
            cout << name << " Lost!\n";
            cout << enemy.getName() << " Wins!\n";
            return;
        }
    }
    void playerDefend(Character &enemy) {
        cout << name << " Defends!\n";
        setDefenseModifier(2);
        enemy.attackTarget(*this);
        if (getHp() <=0) {
            cout << name << " Lost!\n";
            cout << enemy.getName() << " Wins!\n";
        }
        setDefenseModifier(1);
    }
    void playerHeal(Character &enemy) {
        if (hp + 20 >= maxHp) {
            setHealFactor(maxHp - hp);
        } else {
            setHealFactor(20);
        }
        takeDamage(0);
        cout << name << " Has " << hp << " HP Left!\n";
        enemy.attackTarget(*this);
        if (hp <=0) {
            cout << name << " Lost!\n";
            cout << enemy.getName() << " Wins!\n";
        }
        setHealFactor(0);
    }
};




int main() {
    srand (time(nullptr));
    string action;
    string answer;
    int round = 1;
    Player player("Conan", 45, 25, 160, 160);
    Enemy enemy("Herpo, The Terrible", 40, 20, 140, 140);
    do {
        cout << player.getName() << " VS " << enemy.getName() << "\n";
        cout << "Are You Ready?";
        cin >> answer;
    }while (answer != "yes");
    while (enemy.getHp() > 0 && player.getHp() > 0) {
        cout << "Get Ready For Round " << round << "!\n";
        cout << "ROUND " << round << " START!\n";
        do {
            cout << "1)Attack 2)Defend 3)Heal\n";
            cin >> action;
            if (action == "Attack") {
                player.playerAttack(enemy);
            }
            else if (action == "Defend") {
                player.playerDefend(enemy);
            }
            else if (action == "Heal") {
                player.playerHeal(enemy);
            }
        }while (action != "Attack" && action != "Defend" && action != "Heal");
        round ++;
    }
    return 0;
}
