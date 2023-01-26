#ifndef INCLUDED_TABLEROW_H
#define INCLUDED_TABLEROW_H

#include <algorithm>
#include <exception>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>

#include "sqlTypes.hpp"
#include "utilities.h"

/*
    Was thinking something like this class could be used to set up a prepared statement
   for a row in a table for creating, modifying or reading. Statement will be prepared in
   another class. Once it is constructed, It's MYSQL_BIND array parameter can be bound
   with a prepared statement that could be executed. If it is a write/modify statement
   then the values of each field could be updated between statement executions. If it is a
   read statement, then updated values could be read between executions if they have
   changed.

   May decide to make separate classes for rows that are meant to read or write.
*/

class TableRow {
   private:
    std::vector<std::unique_ptr<SqlCType>> columns;
    std::vector<MYSQL_BIND> selection;

   public:
    // Points to columns' elements. After object instantiated, do not want column elements
    // added or deleted, just access for selecting ad modifying.
    std::vector<SqlCType*> fields;

    TableRow() = delete;
    TableRow(
        std::vector<std::unique_ptr<SqlCType>> _columns );  // to set once the correct
                                                            // order of columns
    void displayFields();
    void setBinds( const std::optional<std::initializer_list<bool>>& selectedColumns =
                       std::nullopt );
    MYSQL_BIND* getBinds() {
        return selection.data();
    }
    size_t getBindsSize() {
        return selection.size();
    }
};

#endif  // INCLUDED_TABLEROW_H