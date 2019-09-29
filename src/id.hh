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

#ifndef ID_H
#define ID_H

//#include <tr1/cstdint>
#include <cstdint>

typedef uint32_t idType;

class Id {  
  
private:
  static idType uniqId;
  
protected:
  idType id; // uniq id
  
public:
  Id(void);
  virtual ~Id(void);
  
  const idType getId(void) const;
  
};

#endif // ID_H
