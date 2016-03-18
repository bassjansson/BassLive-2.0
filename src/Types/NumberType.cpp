//
//  NumberType.cpp
//  BassLive 2.0
//
//  Created by Bass Jansson on 17/02/16.
//
//

#include "Syntax.h"


//========================================================================
NumberType::NumberType() : Type(CHAR_TYPE_NUMBER), value(sample())
{
    typeType = NUMBER;
}

//========================================================================
void NumberType::keyPressed (int key)
{
    if ((key > 47 && key < 58) || key == 46)
        charSelected->add(new Character(key));
}

sig* NumberType::compile (Memory* memory, bool record)
{
    if (getTypeString() == "")
    {
                      add(new Character('0'));
        charSelected->add(new Character('.'));
        charSelected->add(new Character('0'));
        setTypeString("0.0");
    }
    
    char* err;
    value[0].L = value[0].R = strtof(getTypeString().c_str(), &err);
    
    if (*err == 0)
    {
        flash(COLOR_TYPE_NUMBER);
    }
    else
    {
        flash(COLOR_ERROR);
        value[0] = sample();
    }
    
    return &value;
}

//========================================================================
float NumberType::getValue()
{
    return value[0].L;
}