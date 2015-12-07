//
//  C++_prac.cpp
//  C_prac
//
//  Created by NAKHOE KIM on 11/28/15.
//  Copyright © 2015 NAKHOE KIM. All rights reserved.
//

#include "C++_prac.hpp"
class IntElement {
public:
    IntElement(int value): next(NULL), data(value) {}
    ~IntElement(){}
    
    IntElement *getNext() const { return next;}
    int value() const {return data;}
    
private:
    IntElement *next;
    int data;
    
    
};