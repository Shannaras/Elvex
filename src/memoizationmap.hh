/* **************************************************
 *
 * ELVEX
 *
 * Copyright 2018 LABRI, 
 * CNRS (UMR 5800), the University of Bordeaux,
 * and the Bordeaux INP
 *
 * Author: Lionel Clément,
 * Labri -- 351, cours de la Libération
 * 33405 Talence Cedex - France
 * lionel.clement@labri.fr
 * 
 * This file is part of ELVEX.
 *
 ************************************************** */

#ifndef MEMOIZATIONMAP_H
#define MEMOIZATIONMAP_H

#include "memoizationvalue.hh"
#include "ipointer.hh"
#include <list>
#include <map>
#include <string>

class MemoizationMap:
  public enable_shared_from_this< class MemoizationMap > {
  
private:
  std::map<std::string, std::list< memoizationValuePtr > > map;

public:
  //std::map<std::string, std::list< MemoizationValue* > >::iterator begin(void) ;
  std::map<std::string, std::list< memoizationValuePtr > >::iterator end(void) ;
  std::map<std::string, std::list< memoizationValuePtr > >::iterator find(const std::string);
  void insert(std::string, std::list< memoizationValuePtr > &);
  //void push_back(MemoizationValue*);
  //void print(std::ostream &) const;
  
};  
#endif // MEMOIZATIONMAP_H
