//
// Created by Vadik on 27.03.2021.
//

#ifndef CONSOLERPG_STATE_H
#define CONSOLERPG_STATE_H


class State
{
private:
    bool quit;


public:
    State();
    virtual ~State();

    //Accessors
    const bool& getQuit() const;

    // Modifiers
    void setQuit(const bool quit);
    // Functions
    virtual void update() = 0; //Virtual funk(Abstract class)
};


#endif //CONSOLERPG_STATE_H
