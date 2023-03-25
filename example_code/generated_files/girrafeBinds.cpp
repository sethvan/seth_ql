// This file was generated by createDBTableBinds() function
#include "makeBinds.hpp"
#include "girrafeBinds.h"

using namespace seth_ql;

BindsArray<InputCType> branchInputBindsArray(){
    return makeInputBindsArray( Bind<T_INT>("branch_id"), Bind<T_VARCHAR>("branch_name", 100), Bind<T_INT>("mgr_id"), Bind<T_DATE>("mgr_start_date") );
}
BindsArray<OutputCType> branchOutputBindsArray(){
    return makeOutputBindsArray( Bind<T_INT>("branch_id"), Bind<T_VARCHAR>("branch_name", 100), Bind<T_INT>("mgr_id"), Bind<T_DATE>("mgr_start_date") );
}

BindsArray<InputCType> branch_supplierInputBindsArray(){
    return makeInputBindsArray( Bind<T_INT>("branch_id"), Bind<T_VARCHAR>("supplier_name", 100), Bind<T_VARCHAR>("supply_type", 100) );
}
BindsArray<OutputCType> branch_supplierOutputBindsArray(){
    return makeOutputBindsArray( Bind<T_INT>("branch_id"), Bind<T_VARCHAR>("supplier_name", 100), Bind<T_VARCHAR>("supply_type", 100) );
}

BindsArray<InputCType> clientInputBindsArray(){
    return makeInputBindsArray( Bind<T_INT>("client_id"), Bind<T_VARCHAR>("client_name", 100), Bind<T_INT>("branch_id") );
}
BindsArray<OutputCType> clientOutputBindsArray(){
    return makeOutputBindsArray( Bind<T_INT>("client_id"), Bind<T_VARCHAR>("client_name", 100), Bind<T_INT>("branch_id") );
}

BindsArray<InputCType> employeeInputBindsArray(){
    return makeInputBindsArray( Bind<T_INT>("emp_id"), Bind<T_VARCHAR>("first_name", 100), Bind<T_VARCHAR>("last_name", 100), Bind<T_DATE>("birth_day"), Bind<T_VARCHAR>("sex", 100), Bind<T_INT>("salary"), Bind<T_INT>("super_id"), Bind<T_INT>("branch_id") );
}
BindsArray<OutputCType> employeeOutputBindsArray(){
    return makeOutputBindsArray( Bind<T_INT>("emp_id"), Bind<T_VARCHAR>("first_name", 100), Bind<T_VARCHAR>("last_name", 100), Bind<T_DATE>("birth_day"), Bind<T_VARCHAR>("sex", 100), Bind<T_INT>("salary"), Bind<T_INT>("super_id"), Bind<T_INT>("branch_id") );
}

BindsArray<InputCType> works_withInputBindsArray(){
    return makeInputBindsArray( Bind<T_INT>("emp_id"), Bind<T_INT>("client_id"), Bind<T_INT>("total_sales") );
}
BindsArray<OutputCType> works_withOutputBindsArray(){
    return makeOutputBindsArray( Bind<T_INT>("emp_id"), Bind<T_INT>("client_id"), Bind<T_INT>("total_sales") );
}
