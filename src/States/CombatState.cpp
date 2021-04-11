//
// Created by Vadik on 07.04.2021.
//

#include "CombatState.h"
#include <stdio.h>

CombatState::CombatState(
        Character*& character,
        std::stack<State*>* states)
        : character(character), State()

{
    this->states = states;
}

CombatState::~CombatState()
{

}

//Functions

void CombatState::display(std::string atkStr, std::string defStr, int round, std::string encounterLog, float hitRating, float hitPercent, float defence, float defPercent, Enemy enemy)
{
    system("CLS");
    std::printf("+----------------------+\n");
    std::printf("| Attacker: %10s |\n", atkStr.c_str());
    std::printf("| Defender: %10s |\n", defStr.c_str());
    std::printf("| Round:    %10d |\n", round);
    std::printf("+----------------------+------------------------+\n");
    std::printf("| LOG: %-40s |\n", encounterLog.c_str());
    std::printf("+------------------------+----------------------+\n");
    std::printf("| Hit rating: %10.1f | Percent: %10.1f%% |\n", hitRating, hitPercent);
    std::printf("| Defence:    %10.1f | Percent: %10.1f%% |\n", defence, defPercent);
    std::printf("+------------------------+----------------------+\n");
    std::printf("| Player Damage: %7d - %-7d              |\n", this->character->getDamageMin(), this->character->getDamageMax());
    std::printf("| Enemy Damage:  %7d - %-7d              |\n", enemy.getDamageMin(), enemy.getDamageMax());
    std::printf("| Player HP:     %7d / %-7d              |\n", this->character->getHP(), this->character->getHPMax());
    std::printf("| Enemy HP:      %7d / %-7d              |\n", enemy.getHP(), enemy.getHPMax());
    std::printf("+-----------------------------------------------+\n");
}

void CombatState::beginCombat()
{
    Enemy enemy(this->character->getLevel());
    bool endCombat = false;
    int turn = rand() % 2;
    int round = 1;
    srand(time(nullptr));
    while (!endCombat)
    {
        std::string atkStr = "Player";
        std::string defStr = "Enemy";
        std::string encounterLog;
        float hitRating = static_cast<float>(this->character->getHitRating());
        float defence = static_cast<float>(enemy.getDefence());

        if (!turn)
        {
            atkStr = "Enemy";
            defStr = "Player";
            hitRating = static_cast<float>(enemy.getHitRating());
            defence = static_cast<float>(this->character->getDefence());
        }

        float totalHitDef = hitRating + defence;
        float hitPercent = 100.f * (hitRating / totalHitDef);
        float defPercent = 100.f * (defence / totalHitDef);

        int random = rand() % 100 + 1;

        //Hit
        if (random > 0 && random <= hitPercent)
        {
            int damage = 0;

            if (turn)
            {
                damage = character->getTotalDamage();
                enemy.takeDamage(damage);
            }
            else
            {
                damage = rand() % (enemy.getDamageMax() - enemy.getDamageMin()) + enemy.getDamageMin();
                this->character->takeDamage(damage);
            }

            encounterLog = atkStr + " HIT " + defStr + " FOR " + std::to_string(damage) + "!";
        }
        //Defend
        else
        {
            encounterLog = atkStr + " MISSED " + defStr;
        }

        //Data
        this->display(atkStr, defStr, round, encounterLog, hitRating, hitPercent, defence, defPercent, enemy);

        //Loss
        if (this->character->isDead())
        {
            endCombat = true;
            std::cout << "YOU ARE DEAD AND YOU LOST SOME EXP AND GOLD!" << "\n";
            this->setQuit(true);
        }
        //Win
        else if (enemy.isDead())
        {
            endCombat = true;
            int gainedExp = rand() % (enemy.getLevel() * 30);
            int gainedGold = rand() % (enemy.getLevel() * 75) ;
            this->character->addExp(gainedExp);
            this->character->addGold(gainedGold);
            std::cout << "YOU DEFEATED THE ENEMY AND GAINED " << gainedExp << " EXP" <<
            " AND" << gainedGold << " GOLD" << "\n";
            this->setQuit(true);
        }

        //Switch turn
        turn ^= 1;
        round++;
        system("pause");
    }
}

void CombatState::printMenu()
{
    std::cout << " --- Combat Menu ---" << "\n" << "\n";
    std::cout << this->character->getMenuBar() << "\n" << "\n";
    std::cout << " (1) Begin Combat" << "\n"
         << " (2) Flee" << "\n"
         << " (3) Heal" << "\n"
         << "\n";
}

void CombatState::updateMenu()
{
    switch (this->getChoice())
    {
        case 1:
            this->beginCombat();
            std::cout << "END OF COMBAT." << "\n";
            system("pause");
            this->setQuit(true);
            break;

        case 2:
            std::cout << "You fled and lost some valuables..." << "\n";
            std::cout << this->character->flee() << "\n";
            this->setQuit(true);
            system("pause");
            break;

        case 3:
            this->character->reset();
            std::cout << "You have rested..." << "\n";
            system("pause");
            break;

        default:
            std::cout << "Not a valid option! " << "\n";
            break;
    }
}

void CombatState::update()
{
    this->printMenu();
    this->updateMenu();
}