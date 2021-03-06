/* **************************************************
 *
 * ELVEX
 *
 * Copyright 2019 LABRI, 
 * CNRS (UMR 5800), the University of Bordeaux,
 * and the Bordeaux INP
 *
 * Author: 
 * Lionel Clément
 * LaBRI -- Université Bordeaux 
 * 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 * 
 * This file is part of ELVEX.
 *
 ************************************************** */

#include "term.hh"
#include "vartable.hh"
#include "messages.hh"

/* **************************************************
 *
 ************************************************** */
Term::Term(unsigned int code) {
   this->code = code;
   NEW;
}

/* **************************************************
 *
 ************************************************** */
Term::~Term() {
   DELETE;
}

/* **************************************************
 *
 ************************************************** */
termPtr Term::create(unsigned int code) {
   return termPtr(new Term(code));
}

/* **************************************************
 *
 ************************************************** */
unsigned int Term::getCode(void) const {
   return code;
}

/* **************************************************
 *
 ************************************************** */
const bool Term::Less::operator()(const termPtr t1, const termPtr t2) const {
   if (t1->getCode() != t2->getCode())
      return (t1->getCode() < t2->getCode());
   return false;
}

/* **************************************************
 *
 ************************************************** */
void Term::print(std::ostream& outStream) const {
   outStream << Vartable::intToStr(code);
}

/* **************************************************
 *
 ************************************************** */
std::string Term::toString() const {
   return Vartable::intToStr(code);
}

/* **************************************************
 *
 ************************************************** */
termPtr Term::clone() const {
   return create(code);
}
