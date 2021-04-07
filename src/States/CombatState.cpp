//
// Created by Vadik on 07.04.2021.
//

#include "CombatState.h"

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
void CombatState::beginCombat()
{
    Enemy enemy(this->character->getLevel());
    bool endCombat = false;

    int turn = rand() % 2;
    int round = 0;

    srand(time(nullptr));

    while (!endCombat)
    {
        //Test for player attacking and enemy defending
        std::string atkStr = "Player";
        std::string defStr = "Enemy";
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

        std::cout << "-------------------------------------------------" << "\n";
        std::cout << " Attacker: " << atkStr << "\n";
        std::cout << " Defender: " << defStr << "\n";
        std::cout << " Round: " << ++round << "\n";
        std::cout << "-------------------------------------------------" << "\n";

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

            std::cout << atkStr << " HIT " << defStr << " FOR " << damage << "!" << "\n";
        }
        //Defend
        else
        {
            std::cout << atkStr << " MISSED " << defStr << "\n";
        }

        //Data
        std::cout << "-------------------------------------------------" << "\n";
        std::cout << " Hit rating: " << hitRating << " Percent: " << hitPercent << "\n";
        std::cout << " Defence: " << defence << " Percent: " << defPercent << "\n";
        std::cout << " Player Damage: " << this->character->getDamageMin() << " - " << this->character->getDamageMax() << "\n";
        std::cout << " Enemy Damage: " << enemy.getDamageMin() << " - " << enemy.getDamageMax() << "\n";
        std::cout << " Player HP: " << this->character->getHP() << " / " << this->character->getHPMax() << "\n";
        std::cout << " Enemy HP: " << enemy.getHP() << " / " << enemy.getHPMax() << "\n";
        std::cout << "-------------------------------------------------" << "\n";

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
            int gainedExp = rand() % (enemy.getLevel() * 20) + (enemy.getLevel() * 10);
            this->character->addExp(gainedExp);
            std::cout << "YOU DEFEATED THE ENEMY AND GAINED " << gainedExp << " EXP!" << "\n";
            this->setQuit(true);
        }

        //Switch turn
        turn = turn ? 0 : 1;

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
            //this->setQuit(true);
            break;

        case 2:
            std::cout << "You fled and lost some valuables..." << "\n";
            std::cout << this->character->flee() << "\n";

            this->setQuit(true);
            break;

        case 3:
            this->character->reset();
            std::cout << "You have rested..." << "\n";

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