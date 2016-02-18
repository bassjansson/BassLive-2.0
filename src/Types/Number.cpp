//
//  Number.cpp
//  BassLive 2.0
//
//  Created by Bass Jansson on 17/02/16.
//
//

#include "Function.hpp"


//========================================================================
Number::Number() : Signal('#')
{
    typeColor = ofColor(120, 109, 196);
}

//========================================================================
void Number::keyPressed (int key)
{
    if ((key > 47 && key < 58) || key == 46)
    {
        new Character(key);
    }
    else if ((key > 64 && key < 91) ||
             (key > 96 && key < 123))
    {
        getFunction(RIGHT)->removeSelectedType(false);
        new Identifier('$');
        new Character(key);
    }
}
