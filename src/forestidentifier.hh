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

#ifndef FORESTIDENTIFIER_H
#define FORESTIDENTIFIER_H

#include "serializable.hh"
#include "shared_ptr.hh"

class ForestIdentifier:
      public Serializable, public std::enable_shared_from_this<ForestIdentifier> {

private:

   unsigned int code;
   std::string featuresSerialString;
   unsigned int from;
   unsigned int to;

   ForestIdentifier(unsigned int, const std::string, unsigned int, unsigned int);

public:
   ~ForestIdentifier();
   static forestIdentifierPtr create(unsigned int, const std::string, unsigned int, unsigned int);

   void makeSerialString(void);
   unsigned int getFrom(void) const {
      return from;
   }
   ;
   unsigned int getTo(void) const {
      return to;
   }
   ;
   unsigned int getCode(void) const {
      return code;
   }
   ;
   void print(std::ostream &) const;

   bool operator <(ForestIdentifier const &) const;
   bool operator !=(ForestIdentifier const &) const;

   struct hash {
      size_t operator()(const forestIdentifierPtr) const;
   };

   struct equal_to {
      bool operator()(const forestIdentifierPtr, const forestIdentifierPtr) const;
   };

};

#endif // FORESTIDENTIFIER_H
