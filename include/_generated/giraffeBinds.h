// Generated by createDBTableBinds() function
// giraffe database taken from freecodecamp YT SQL tutorial
// https://www.youtube.com/watch?v=HXV3zeQKqGY

#ifndef INCLUDED_GIRAFFEBINDS_H
#define INCLUDED_GIRAFFEBINDS_H

#include "binds.hpp"

Binds<InputCType> branchInputBinds();
Binds<OutputCType> branchOutputBinds();

Binds<InputCType> branch_supplierInputBinds();
Binds<OutputCType> branch_supplierOutputBinds();

Binds<InputCType> clientInputBinds();
Binds<OutputCType> clientOutputBinds();

Binds<InputCType> employeeInputBinds();
Binds<OutputCType> employeeOutputBinds();

Binds<InputCType> works_withInputBinds();
Binds<OutputCType> works_withOutputBinds();

#endif  // INCLUDED_GIRAFFEBINDS_H
