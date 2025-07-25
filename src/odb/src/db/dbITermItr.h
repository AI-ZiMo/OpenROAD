// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2019-2025, The OpenROAD Authors

#pragma once

#include "dbCore.h"
#include "odb/dbIterator.h"
#include "odb/odb.h"

namespace odb {

class _dbITerm;

class dbNetITermItr : public dbIterator
{
  dbTable<_dbITerm, 1024>* _iterm_tbl;

 public:
  dbNetITermItr(dbTable<_dbITerm, 1024>* iterm_tbl) { _iterm_tbl = iterm_tbl; }

  bool reversible() override;
  bool orderReversed() override;
  void reverse(dbObject* parent) override;
  uint sequential() override;
  uint size(dbObject* parent) override;
  uint begin(dbObject* parent) override;
  uint end(dbObject* parent) override;
  uint next(uint id, ...) override;
  dbObject* getObject(uint id, ...) override;
};

class dbInstITermItr : public dbIterator
{
  dbTable<_dbITerm, 1024>* _iterm_tbl;

 public:
  dbInstITermItr(dbTable<_dbITerm, 1024>* iterm_tbl) { _iterm_tbl = iterm_tbl; }

  bool reversible() override;
  bool orderReversed() override;
  void reverse(dbObject* parent) override;
  uint sequential() override;
  uint size(dbObject* parent) override;
  uint begin(dbObject* parent) override;
  uint end(dbObject* parent) override;
  uint next(uint id, ...) override;
  dbObject* getObject(uint id, ...) override;
};

}  // namespace odb
