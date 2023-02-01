#include "_generated/performance_schemaBinds.h"

Binds<InputCType> accountsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_CONNECTIONS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TOTAL_CONNECTIONS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_TOTAL_MEMORY" ) ) );
}
Binds<OutputCType> accountsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_CONNECTIONS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TOTAL_CONNECTIONS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_TOTAL_MEMORY" ) ) );
}

Binds<InputCType> binary_log_transaction_compression_statsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "LOG_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "COMPRESSION_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "TRANSACTION_COUNTER" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COMPRESSED_BYTES_COUNTER" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "UNCOMPRESSED_BYTES_COUNTER" ),
        std::make_unique<TypeInputImpl<short, MYSQL_TYPE_SHORT>>( "COMPRESSION_PERCENTAGE" ),
        std::make_unique<TypeCharArrayInput>( "FIRST_TRANSACTION_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "FIRST_TRANSACTION_COMPRESSED_BYTES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "FIRST_TRANSACTION_UNCOMPRESSED_BYTES" ),
        std::make_unique<TypeMysqlTimeInput>( "FIRST_TRANSACTION_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayInput>( "LAST_TRANSACTION_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "LAST_TRANSACTION_COMPRESSED_BYTES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "LAST_TRANSACTION_UNCOMPRESSED_BYTES" ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_TRANSACTION_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> binary_log_transaction_compression_statsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "LOG_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "COMPRESSION_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "TRANSACTION_COUNTER" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COMPRESSED_BYTES_COUNTER" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "UNCOMPRESSED_BYTES_COUNTER" ),
        std::make_unique<TypeOutputImpl<short, MYSQL_TYPE_SHORT>>( "COMPRESSION_PERCENTAGE" ),
        std::make_unique<TypeCharArrayOutput>( "FIRST_TRANSACTION_ID", MYSQL_TYPE_BLOB, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "FIRST_TRANSACTION_COMPRESSED_BYTES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "FIRST_TRANSACTION_UNCOMPRESSED_BYTES" ),
        std::make_unique<TypeMysqlTimeOutput>( "FIRST_TRANSACTION_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayOutput>( "LAST_TRANSACTION_ID", MYSQL_TYPE_BLOB, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "LAST_TRANSACTION_COMPRESSED_BYTES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "LAST_TRANSACTION_UNCOMPRESSED_BYTES" ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_TRANSACTION_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> cond_instancesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ) ) );
}
Binds<OutputCType> cond_instancesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ) ) );
}

Binds<InputCType> data_lock_waitsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "ENGINE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "REQUESTING_ENGINE_LOCK_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "REQUESTING_ENGINE_TRANSACTION_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "REQUESTING_THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "REQUESTING_EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "REQUESTING_OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeCharArrayInput>( "BLOCKING_ENGINE_LOCK_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BLOCKING_ENGINE_TRANSACTION_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BLOCKING_THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BLOCKING_EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BLOCKING_OBJECT_INSTANCE_BEGIN" ) ) );
}
Binds<OutputCType> data_lock_waitsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "ENGINE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "REQUESTING_ENGINE_LOCK_ID", MYSQL_TYPE_VAR_STRING,
                                               100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "REQUESTING_ENGINE_TRANSACTION_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "REQUESTING_THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "REQUESTING_EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "REQUESTING_OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeCharArrayOutput>( "BLOCKING_ENGINE_LOCK_ID", MYSQL_TYPE_VAR_STRING,
                                               100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BLOCKING_ENGINE_TRANSACTION_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BLOCKING_THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BLOCKING_EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BLOCKING_OBJECT_INSTANCE_BEGIN" ) ) );
}

Binds<InputCType> data_locksInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "ENGINE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ENGINE_LOCK_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "ENGINE_TRANSACTION_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "PARTITION_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SUBPARTITION_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "INDEX_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeCharArrayInput>( "LOCK_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "LOCK_MODE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "LOCK_STATUS", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "LOCK_DATA", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> data_locksOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "ENGINE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ENGINE_LOCK_ID", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "ENGINE_TRANSACTION_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "PARTITION_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SUBPARTITION_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "INDEX_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeCharArrayOutput>( "LOCK_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "LOCK_MODE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "LOCK_STATUS", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "LOCK_DATA", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> error_logInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeMysqlTimeInput>( "LOGGED", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "PRIO", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ERROR_CODE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SUBSYSTEM", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DATA", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> error_logOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeMysqlTimeOutput>( "LOGGED", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "PRIO", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ERROR_CODE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SUBSYSTEM", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DATA", MYSQL_TYPE_BLOB, 100 ) ) );
}

Binds<InputCType> events_errors_summary_by_account_by_errorInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayInput>( "ERROR_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SQL_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_RAISED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_HANDLED" ),
        std::make_unique<TypeMysqlTimeInput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> events_errors_summary_by_account_by_errorOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayOutput>( "ERROR_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SQL_STATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_RAISED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_HANDLED" ),
        std::make_unique<TypeMysqlTimeOutput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> events_errors_summary_by_host_by_errorInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayInput>( "ERROR_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SQL_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_RAISED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_HANDLED" ),
        std::make_unique<TypeMysqlTimeInput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> events_errors_summary_by_host_by_errorOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayOutput>( "ERROR_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SQL_STATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_RAISED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_HANDLED" ),
        std::make_unique<TypeMysqlTimeOutput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> events_errors_summary_by_thread_by_errorInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayInput>( "ERROR_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SQL_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_RAISED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_HANDLED" ),
        std::make_unique<TypeMysqlTimeInput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> events_errors_summary_by_thread_by_errorOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayOutput>( "ERROR_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SQL_STATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_RAISED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_HANDLED" ),
        std::make_unique<TypeMysqlTimeOutput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> events_errors_summary_by_user_by_errorInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayInput>( "ERROR_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SQL_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_RAISED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_HANDLED" ),
        std::make_unique<TypeMysqlTimeInput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> events_errors_summary_by_user_by_errorOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayOutput>( "ERROR_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SQL_STATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_RAISED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_HANDLED" ),
        std::make_unique<TypeMysqlTimeOutput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> events_errors_summary_global_by_errorInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayInput>( "ERROR_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SQL_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_RAISED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_HANDLED" ),
        std::make_unique<TypeMysqlTimeInput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> events_errors_summary_global_by_errorOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayOutput>( "ERROR_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SQL_STATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_RAISED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ERROR_HANDLED" ),
        std::make_unique<TypeMysqlTimeOutput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> events_stages_currentInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_COMPLETED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_ESTIMATED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> events_stages_currentOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_COMPLETED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_ESTIMATED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> events_stages_historyInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_COMPLETED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_ESTIMATED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> events_stages_historyOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_COMPLETED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_ESTIMATED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> events_stages_history_longInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_COMPLETED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_ESTIMATED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> events_stages_history_longOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_COMPLETED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WORK_ESTIMATED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> events_stages_summary_by_account_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_stages_summary_by_account_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_stages_summary_by_host_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_stages_summary_by_host_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_stages_summary_by_thread_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_stages_summary_by_thread_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_stages_summary_by_user_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_stages_summary_by_user_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_stages_summary_global_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_stages_summary_global_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_statements_currentInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "LOCK_TIME" ),
        std::make_unique<TypeCharArrayInput>( "SQL_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DIGEST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DIGEST_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "CURRENT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "MYSQL_ERRNO" ),
        std::make_unique<TypeCharArrayInput>( "RETURNED_SQLSTATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MESSAGE_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "NESTING_EVENT_LEVEL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "STATEMENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeCharArrayInput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> events_statements_currentOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "LOCK_TIME" ),
        std::make_unique<TypeCharArrayOutput>( "SQL_TEXT", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DIGEST", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DIGEST_TEXT", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "CURRENT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "MYSQL_ERRNO" ),
        std::make_unique<TypeCharArrayOutput>( "RETURNED_SQLSTATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MESSAGE_TEXT", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "NESTING_EVENT_LEVEL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "STATEMENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeCharArrayOutput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> events_statements_histogram_by_digestInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "SCHEMA_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DIGEST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>( "BUCKET_NUMBER" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BUCKET_TIMER_LOW" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BUCKET_TIMER_HIGH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_BUCKET" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_BUCKET_AND_LOWER" ),
        std::make_unique<TypeInputImpl<double, MYSQL_TYPE_DOUBLE>>( "BUCKET_QUANTILE" ) ) );
}
Binds<OutputCType> events_statements_histogram_by_digestOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "SCHEMA_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DIGEST", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>( "BUCKET_NUMBER" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BUCKET_TIMER_LOW" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BUCKET_TIMER_HIGH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_BUCKET" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_BUCKET_AND_LOWER" ),
        std::make_unique<TypeOutputImpl<double, MYSQL_TYPE_DOUBLE>>( "BUCKET_QUANTILE" ) ) );
}

Binds<InputCType> events_statements_histogram_globalInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>( "BUCKET_NUMBER" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BUCKET_TIMER_LOW" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BUCKET_TIMER_HIGH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_BUCKET" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_BUCKET_AND_LOWER" ),
        std::make_unique<TypeInputImpl<double, MYSQL_TYPE_DOUBLE>>( "BUCKET_QUANTILE" ) ) );
}
Binds<OutputCType> events_statements_histogram_globalOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>( "BUCKET_NUMBER" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BUCKET_TIMER_LOW" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "BUCKET_TIMER_HIGH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_BUCKET" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_BUCKET_AND_LOWER" ),
        std::make_unique<TypeOutputImpl<double, MYSQL_TYPE_DOUBLE>>( "BUCKET_QUANTILE" ) ) );
}

Binds<InputCType> events_statements_historyInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "LOCK_TIME" ),
        std::make_unique<TypeCharArrayInput>( "SQL_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DIGEST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DIGEST_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "CURRENT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "MYSQL_ERRNO" ),
        std::make_unique<TypeCharArrayInput>( "RETURNED_SQLSTATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MESSAGE_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "NESTING_EVENT_LEVEL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "STATEMENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeCharArrayInput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> events_statements_historyOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "LOCK_TIME" ),
        std::make_unique<TypeCharArrayOutput>( "SQL_TEXT", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DIGEST", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DIGEST_TEXT", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "CURRENT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "MYSQL_ERRNO" ),
        std::make_unique<TypeCharArrayOutput>( "RETURNED_SQLSTATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MESSAGE_TEXT", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "NESTING_EVENT_LEVEL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "STATEMENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeCharArrayOutput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> events_statements_history_longInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "LOCK_TIME" ),
        std::make_unique<TypeCharArrayInput>( "SQL_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DIGEST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DIGEST_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "CURRENT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "MYSQL_ERRNO" ),
        std::make_unique<TypeCharArrayInput>( "RETURNED_SQLSTATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MESSAGE_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "NESTING_EVENT_LEVEL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "STATEMENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeCharArrayInput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> events_statements_history_longOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "LOCK_TIME" ),
        std::make_unique<TypeCharArrayOutput>( "SQL_TEXT", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DIGEST", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DIGEST_TEXT", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "CURRENT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "MYSQL_ERRNO" ),
        std::make_unique<TypeCharArrayOutput>( "RETURNED_SQLSTATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MESSAGE_TEXT", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "NESTING_EVENT_LEVEL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "STATEMENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeCharArrayOutput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> events_statements_summary_by_account_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_LOCK_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}
Binds<OutputCType> events_statements_summary_by_account_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_LOCK_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}

Binds<InputCType> events_statements_summary_by_digestInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "SCHEMA_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DIGEST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DIGEST_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_LOCK_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ),
        std::make_unique<TypeMysqlTimeInput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "QUANTILE_95" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "QUANTILE_99" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "QUANTILE_999" ),
        std::make_unique<TypeCharArrayInput>( "QUERY_SAMPLE_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "QUERY_SAMPLE_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "QUERY_SAMPLE_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_statements_summary_by_digestOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "SCHEMA_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DIGEST", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DIGEST_TEXT", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_LOCK_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ),
        std::make_unique<TypeMysqlTimeOutput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "QUANTILE_95" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "QUANTILE_99" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "QUANTILE_999" ),
        std::make_unique<TypeCharArrayOutput>( "QUERY_SAMPLE_TEXT", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "QUERY_SAMPLE_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "QUERY_SAMPLE_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_statements_summary_by_host_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_LOCK_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}
Binds<OutputCType> events_statements_summary_by_host_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_LOCK_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}

Binds<InputCType> events_statements_summary_by_programInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_STATEMENTS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_STATEMENTS_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_STATEMENTS_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_STATEMENTS_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_STATEMENTS_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_LOCK_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}
Binds<OutputCType> events_statements_summary_by_programOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_STATEMENTS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_STATEMENTS_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_STATEMENTS_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_STATEMENTS_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_STATEMENTS_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_LOCK_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}

Binds<InputCType> events_statements_summary_by_thread_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_LOCK_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}
Binds<OutputCType> events_statements_summary_by_thread_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_LOCK_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}

Binds<InputCType> events_statements_summary_by_user_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_LOCK_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}
Binds<OutputCType> events_statements_summary_by_user_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_LOCK_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}

Binds<InputCType> events_statements_summary_global_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_LOCK_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}
Binds<OutputCType> events_statements_summary_global_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_LOCK_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}

Binds<InputCType> events_transactions_currentInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TRX_ID" ),
        std::make_unique<TypeCharArrayInput>( "GTID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "XID_FORMAT_ID" ),
        std::make_unique<TypeCharArrayInput>( "XID_GTRID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "XID_BQUAL", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "XA_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeCharArrayInput>( "ACCESS_MODE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ISOLATION_LEVEL", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "AUTOCOMMIT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_SAVEPOINTS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_ROLLBACK_TO_SAVEPOINT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_RELEASE_SAVEPOINT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> events_transactions_currentOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TRX_ID" ),
        std::make_unique<TypeCharArrayOutput>( "GTID", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "XID_FORMAT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "XID_GTRID", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "XID_BQUAL", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "XA_STATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeCharArrayOutput>( "ACCESS_MODE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ISOLATION_LEVEL", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "AUTOCOMMIT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_SAVEPOINTS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_ROLLBACK_TO_SAVEPOINT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_RELEASE_SAVEPOINT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> events_transactions_historyInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TRX_ID" ),
        std::make_unique<TypeCharArrayInput>( "GTID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "XID_FORMAT_ID" ),
        std::make_unique<TypeCharArrayInput>( "XID_GTRID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "XID_BQUAL", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "XA_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeCharArrayInput>( "ACCESS_MODE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ISOLATION_LEVEL", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "AUTOCOMMIT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_SAVEPOINTS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_ROLLBACK_TO_SAVEPOINT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_RELEASE_SAVEPOINT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> events_transactions_historyOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TRX_ID" ),
        std::make_unique<TypeCharArrayOutput>( "GTID", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "XID_FORMAT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "XID_GTRID", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "XID_BQUAL", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "XA_STATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeCharArrayOutput>( "ACCESS_MODE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ISOLATION_LEVEL", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "AUTOCOMMIT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_SAVEPOINTS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_ROLLBACK_TO_SAVEPOINT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_RELEASE_SAVEPOINT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> events_transactions_history_longInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TRX_ID" ),
        std::make_unique<TypeCharArrayInput>( "GTID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "XID_FORMAT_ID" ),
        std::make_unique<TypeCharArrayInput>( "XID_GTRID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "XID_BQUAL", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "XA_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeCharArrayInput>( "ACCESS_MODE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ISOLATION_LEVEL", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "AUTOCOMMIT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_SAVEPOINTS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_ROLLBACK_TO_SAVEPOINT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_RELEASE_SAVEPOINT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> events_transactions_history_longOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TRX_ID" ),
        std::make_unique<TypeCharArrayOutput>( "GTID", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "XID_FORMAT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "XID_GTRID", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "XID_BQUAL", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "XA_STATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeCharArrayOutput>( "ACCESS_MODE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ISOLATION_LEVEL", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "AUTOCOMMIT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_SAVEPOINTS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_ROLLBACK_TO_SAVEPOINT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NUMBER_OF_RELEASE_SAVEPOINT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> events_transactions_summary_by_account_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_ONLY" ) ) );
}
Binds<OutputCType> events_transactions_summary_by_account_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_ONLY" ) ) );
}

Binds<InputCType> events_transactions_summary_by_host_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_ONLY" ) ) );
}
Binds<OutputCType> events_transactions_summary_by_host_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_ONLY" ) ) );
}

Binds<InputCType> events_transactions_summary_by_thread_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_ONLY" ) ) );
}
Binds<OutputCType> events_transactions_summary_by_thread_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_ONLY" ) ) );
}

Binds<InputCType> events_transactions_summary_by_user_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_ONLY" ) ) );
}
Binds<OutputCType> events_transactions_summary_by_user_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_ONLY" ) ) );
}

Binds<InputCType> events_transactions_summary_global_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_ONLY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_ONLY" ) ) );
}
Binds<OutputCType> events_transactions_summary_global_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_ONLY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_ONLY" ) ) );
}

Binds<InputCType> events_waits_currentInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>( "SPINS" ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "INDEX_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OPERATION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "NUMBER_OF_BYTES" ),
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>( "FLAGS" ) ) );
}
Binds<OutputCType> events_waits_currentOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>( "SPINS" ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "INDEX_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OPERATION", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "NUMBER_OF_BYTES" ),
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>( "FLAGS" ) ) );
}

Binds<InputCType> events_waits_historyInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>( "SPINS" ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "INDEX_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OPERATION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "NUMBER_OF_BYTES" ),
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>( "FLAGS" ) ) );
}
Binds<OutputCType> events_waits_historyOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>( "SPINS" ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "INDEX_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OPERATION", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "NUMBER_OF_BYTES" ),
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>( "FLAGS" ) ) );
}

Binds<InputCType> events_waits_history_longInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>( "SPINS" ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "INDEX_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OPERATION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "NUMBER_OF_BYTES" ),
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>( "FLAGS" ) ) );
}
Binds<OutputCType> events_waits_history_longOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "EVENT_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "END_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_START" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_END" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>( "SPINS" ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "INDEX_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "NESTING_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NESTING_EVENT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OPERATION", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "NUMBER_OF_BYTES" ),
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>( "FLAGS" ) ) );
}

Binds<InputCType> events_waits_summary_by_account_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_waits_summary_by_account_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_waits_summary_by_host_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_waits_summary_by_host_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_waits_summary_by_instanceInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_waits_summary_by_instanceOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_waits_summary_by_thread_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_waits_summary_by_thread_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_waits_summary_by_user_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_waits_summary_by_user_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> events_waits_summary_global_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> events_waits_summary_global_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> file_instancesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "FILE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>( "OPEN_COUNT" ) ) );
}
Binds<OutputCType> file_instancesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "FILE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>( "OPEN_COUNT" ) ) );
}

Binds<InputCType> file_summary_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_MISC" ) ) );
}
Binds<OutputCType> file_summary_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_MISC" ) ) );
}

Binds<InputCType> file_summary_by_instanceInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "FILE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_MISC" ) ) );
}
Binds<OutputCType> file_summary_by_instanceOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "FILE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_MISC" ) ) );
}

Binds<InputCType> global_statusInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> global_statusOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> global_variablesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> global_variablesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> host_cacheInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "IP", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST_VALIDATED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "SUM_CONNECT_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_HOST_BLOCKED_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_NAMEINFO_TRANSIENT_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_NAMEINFO_PERMANENT_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FORMAT_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_ADDRINFO_TRANSIENT_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_ADDRINFO_PERMANENT_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FCRDNS_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_HOST_ACL_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_NO_AUTH_PLUGIN_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_AUTH_PLUGIN_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_HANDSHAKE_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_PROXY_USER_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_PROXY_USER_ACL_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_AUTHENTICATION_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_SSL_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_MAX_USER_CONNECTIONS_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_MAX_USER_CONNECTIONS_PER_HOUR_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_DEFAULT_DATABASE_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_INIT_CONNECT_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_LOCAL_ERRORS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_UNKNOWN_ERRORS" ),
        std::make_unique<TypeMysqlTimeInput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "FIRST_ERROR_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_ERROR_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> host_cacheOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "IP", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST_VALIDATED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "SUM_CONNECT_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_HOST_BLOCKED_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_NAMEINFO_TRANSIENT_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_NAMEINFO_PERMANENT_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FORMAT_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_ADDRINFO_TRANSIENT_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_ADDRINFO_PERMANENT_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FCRDNS_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_HOST_ACL_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_NO_AUTH_PLUGIN_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_AUTH_PLUGIN_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_HANDSHAKE_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_PROXY_USER_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_PROXY_USER_ACL_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_AUTHENTICATION_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_SSL_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_MAX_USER_CONNECTIONS_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_MAX_USER_CONNECTIONS_PER_HOUR_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_DEFAULT_DATABASE_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_INIT_CONNECT_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_LOCAL_ERRORS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "COUNT_UNKNOWN_ERRORS" ),
        std::make_unique<TypeMysqlTimeOutput>( "FIRST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "FIRST_ERROR_SEEN", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_ERROR_SEEN", MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> hostsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_CONNECTIONS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TOTAL_CONNECTIONS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_TOTAL_MEMORY" ) ) );
}
Binds<OutputCType> hostsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_CONNECTIONS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TOTAL_CONNECTIONS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_TOTAL_MEMORY" ) ) );
}

Binds<InputCType> innodb_redo_log_filesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "FILE_ID" ),
        std::make_unique<TypeCharArrayInput>( "FILE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "START_LSN" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "END_LSN" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "SIZE_IN_BYTES" ),
        std::make_unique<TypeInputImpl<signed char, MYSQL_TYPE_TINY>>( "IS_FULL" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "CONSUMER_LEVEL" ) ) );
}
Binds<OutputCType> innodb_redo_log_filesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "FILE_ID" ),
        std::make_unique<TypeCharArrayOutput>( "FILE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "START_LSN" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "END_LSN" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "SIZE_IN_BYTES" ),
        std::make_unique<TypeOutputImpl<signed char, MYSQL_TYPE_TINY>>( "IS_FULL" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "CONSUMER_LEVEL" ) ) );
}

Binds<InputCType> keyring_component_statusInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "STATUS_KEY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "STATUS_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> keyring_component_statusOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "STATUS_KEY", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "STATUS_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> keyring_keysInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "KEY_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "KEY_OWNER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "BACKEND_KEY_ID", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> keyring_keysOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "KEY_ID", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "KEY_OWNER", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "BACKEND_KEY_ID", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> log_statusInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "SERVER_UUID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "LOCAL", MYSQL_TYPE_JSON, 100 ),
        std::make_unique<TypeCharArrayInput>( "REPLICATION", MYSQL_TYPE_JSON, 100 ),
        std::make_unique<TypeCharArrayInput>( "STORAGE_ENGINES", MYSQL_TYPE_JSON, 100 ) ) );
}
Binds<OutputCType> log_statusOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "SERVER_UUID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "LOCAL", MYSQL_TYPE_JSON, 100 ),
        std::make_unique<TypeCharArrayOutput>( "REPLICATION", MYSQL_TYPE_JSON, 100 ),
        std::make_unique<TypeCharArrayOutput>( "STORAGE_ENGINES", MYSQL_TYPE_JSON, 100 ) ) );
}

Binds<InputCType> memory_summary_by_account_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_ALLOC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FREE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_ALLOC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_FREE" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "LOW_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "HIGH_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "LOW_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "CURRENT_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "HIGH_NUMBER_OF_BYTES_USED" ) ) );
}
Binds<OutputCType> memory_summary_by_account_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_ALLOC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FREE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_ALLOC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_FREE" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "LOW_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "HIGH_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "LOW_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "CURRENT_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "HIGH_NUMBER_OF_BYTES_USED" ) ) );
}

Binds<InputCType> memory_summary_by_host_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_ALLOC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FREE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_ALLOC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_FREE" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "LOW_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "HIGH_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "LOW_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "CURRENT_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "HIGH_NUMBER_OF_BYTES_USED" ) ) );
}
Binds<OutputCType> memory_summary_by_host_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_ALLOC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FREE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_ALLOC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_FREE" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "LOW_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "HIGH_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "LOW_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "CURRENT_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "HIGH_NUMBER_OF_BYTES_USED" ) ) );
}

Binds<InputCType> memory_summary_by_thread_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_ALLOC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FREE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_ALLOC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_FREE" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "LOW_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "HIGH_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "LOW_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "CURRENT_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "HIGH_NUMBER_OF_BYTES_USED" ) ) );
}
Binds<OutputCType> memory_summary_by_thread_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_ALLOC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FREE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_ALLOC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_FREE" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "LOW_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "HIGH_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "LOW_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "CURRENT_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "HIGH_NUMBER_OF_BYTES_USED" ) ) );
}

Binds<InputCType> memory_summary_by_user_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_ALLOC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FREE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_ALLOC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_FREE" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "LOW_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "HIGH_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "LOW_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "CURRENT_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "HIGH_NUMBER_OF_BYTES_USED" ) ) );
}
Binds<OutputCType> memory_summary_by_user_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_ALLOC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FREE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_ALLOC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_FREE" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "LOW_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "HIGH_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "LOW_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "CURRENT_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "HIGH_NUMBER_OF_BYTES_USED" ) ) );
}

Binds<InputCType> memory_summary_global_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_ALLOC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FREE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_ALLOC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_FREE" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "LOW_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "HIGH_COUNT_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "LOW_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "CURRENT_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "HIGH_NUMBER_OF_BYTES_USED" ) ) );
}
Binds<OutputCType> memory_summary_global_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_ALLOC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FREE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_ALLOC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_FREE" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "LOW_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "HIGH_COUNT_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "LOW_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "CURRENT_NUMBER_OF_BYTES_USED" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>(
            "HIGH_NUMBER_OF_BYTES_USED" ) ) );
}

Binds<InputCType> metadata_locksInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "COLUMN_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeCharArrayInput>( "LOCK_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "LOCK_DURATION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "LOCK_STATUS", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_EVENT_ID" ) ) );
}
Binds<OutputCType> metadata_locksOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "COLUMN_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeCharArrayOutput>( "LOCK_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "LOCK_DURATION", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "LOCK_STATUS", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_EVENT_ID" ) ) );
}

Binds<InputCType> mutex_instancesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "LOCKED_BY_THREAD_ID" ) ) );
}
Binds<OutputCType> mutex_instancesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "LOCKED_BY_THREAD_ID" ) ) );
}

Binds<InputCType> objects_summary_global_by_typeInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}
Binds<OutputCType> objects_summary_global_by_typeOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ) ) );
}

Binds<InputCType> performance_timersInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "TIMER_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TIMER_FREQUENCY" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TIMER_RESOLUTION" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TIMER_OVERHEAD" ) ) );
}
Binds<OutputCType> performance_timersOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "TIMER_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TIMER_FREQUENCY" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TIMER_RESOLUTION" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TIMER_OVERHEAD" ) ) );
}

Binds<InputCType> persisted_variablesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> persisted_variablesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> prepared_statements_instancesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "STATEMENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "STATEMENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SQL_TEXT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "OWNER_OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OWNER_OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OWNER_OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TIMER_PREPARE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_REPREPARE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_EXECUTE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_EXECUTE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_EXECUTE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_EXECUTE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_EXECUTE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_LOCK_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ROWS_SENT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_ROWS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_SORT_SCAN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}
Binds<OutputCType> prepared_statements_instancesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "STATEMENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "STATEMENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SQL_TEXT", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "OWNER_OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OWNER_OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OWNER_OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "TIMER_PREPARE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_REPREPARE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_EXECUTE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_EXECUTE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_EXECUTE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_EXECUTE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_EXECUTE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_LOCK_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_ERRORS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_WARNINGS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_AFFECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_SENT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_ROWS_EXAMINED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_DISK_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_CREATED_TMP_TABLES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_FULL_RANGE_JOIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_RANGE_CHECK" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SELECT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_MERGE_PASSES" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_RANGE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_ROWS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_SORT_SCAN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NO_GOOD_INDEX_USED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "SUM_CPU_TIME" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_SECONDARY" ) ) );
}

Binds<InputCType> processlistInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ID" ),
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "DB", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "COMMAND", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TIME" ),
        std::make_unique<TypeCharArrayInput>( "STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "INFO", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> processlistOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "ID" ),
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "DB", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "COMMAND", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TIME" ),
        std::make_unique<TypeCharArrayOutput>( "STATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "INFO", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> replication_applier_configurationInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "DESIRED_DELAY" ),
        std::make_unique<TypeCharArrayInput>( "PRIVILEGE_CHECKS_USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "REQUIRE_ROW_FORMAT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "REQUIRE_TABLE_PRIMARY_KEY_CHECK", MYSQL_TYPE_STRING,
                                              100 ),
        std::make_unique<TypeCharArrayInput>( "ASSIGN_GTIDS_TO_ANONYMOUS_TRANSACTIONS_TYPE",
                                              MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ASSIGN_GTIDS_TO_ANONYMOUS_TRANSACTIONS_VALUE",
                                              MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> replication_applier_configurationOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "DESIRED_DELAY" ),
        std::make_unique<TypeCharArrayOutput>( "PRIVILEGE_CHECKS_USER", MYSQL_TYPE_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "REQUIRE_ROW_FORMAT", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "REQUIRE_TABLE_PRIMARY_KEY_CHECK", MYSQL_TYPE_STRING,
                                               100 ),
        std::make_unique<TypeCharArrayOutput>( "ASSIGN_GTIDS_TO_ANONYMOUS_TRANSACTIONS_TYPE",
                                               MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ASSIGN_GTIDS_TO_ANONYMOUS_TRANSACTIONS_VALUE",
                                               MYSQL_TYPE_BLOB, 100 ) ) );
}

Binds<InputCType> replication_applier_filtersInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "FILTER_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "FILTER_RULE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "CONFIGURED_BY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "ACTIVE_SINCE", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNTER" ) ) );
}
Binds<OutputCType> replication_applier_filtersOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "FILTER_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "FILTER_RULE", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "CONFIGURED_BY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "ACTIVE_SINCE", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNTER" ) ) );
}

Binds<InputCType> replication_applier_global_filtersInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "FILTER_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "FILTER_RULE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "CONFIGURED_BY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "ACTIVE_SINCE", MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> replication_applier_global_filtersOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "FILTER_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "FILTER_RULE", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "CONFIGURED_BY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "ACTIVE_SINCE", MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> replication_applier_statusInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SERVICE_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>( "REMAINING_DELAY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_RETRIES" ) ) );
}
Binds<OutputCType> replication_applier_statusOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SERVICE_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>( "REMAINING_DELAY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_RETRIES" ) ) );
}

Binds<InputCType> replication_applier_status_by_coordinatorInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "SERVICE_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "LAST_ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayInput>( "LAST_ERROR_MESSAGE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_ERROR_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayInput>( "LAST_PROCESSED_TRANSACTION", MYSQL_TYPE_STRING,
                                              100 ),
        std::make_unique<TypeMysqlTimeInput>(
            "LAST_PROCESSED_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>(
            "LAST_PROCESSED_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_PROCESSED_TRANSACTION_START_BUFFER_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_PROCESSED_TRANSACTION_END_BUFFER_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayInput>( "PROCESSING_TRANSACTION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "PROCESSING_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "PROCESSING_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "PROCESSING_TRANSACTION_START_BUFFER_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> replication_applier_status_by_coordinatorOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "SERVICE_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "LAST_ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayOutput>( "LAST_ERROR_MESSAGE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_ERROR_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayOutput>( "LAST_PROCESSED_TRANSACTION", MYSQL_TYPE_STRING,
                                               100 ),
        std::make_unique<TypeMysqlTimeOutput>(
            "LAST_PROCESSED_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>(
            "LAST_PROCESSED_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_PROCESSED_TRANSACTION_START_BUFFER_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_PROCESSED_TRANSACTION_END_BUFFER_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayOutput>( "PROCESSING_TRANSACTION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "PROCESSING_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "PROCESSING_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "PROCESSING_TRANSACTION_START_BUFFER_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> replication_applier_status_by_workerInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "WORKER_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "SERVICE_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "LAST_ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayInput>( "LAST_ERROR_MESSAGE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_ERROR_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayInput>( "LAST_APPLIED_TRANSACTION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_APPLIED_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_APPLIED_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_APPLIED_TRANSACTION_START_APPLY_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_APPLIED_TRANSACTION_END_APPLY_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayInput>( "APPLYING_TRANSACTION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "APPLYING_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "APPLYING_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "APPLYING_TRANSACTION_START_APPLY_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "LAST_APPLIED_TRANSACTION_RETRIES_COUNT" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>(
            "LAST_APPLIED_TRANSACTION_LAST_TRANSIENT_ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayInput>(
            "LAST_APPLIED_TRANSACTION_LAST_TRANSIENT_ERROR_MESSAGE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>(
            "LAST_APPLIED_TRANSACTION_LAST_TRANSIENT_ERROR_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "APPLYING_TRANSACTION_RETRIES_COUNT" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>(
            "APPLYING_TRANSACTION_LAST_TRANSIENT_ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayInput>( "APPLYING_TRANSACTION_LAST_TRANSIENT_ERROR_MESSAGE",
                                              MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "APPLYING_TRANSACTION_LAST_TRANSIENT_ERROR_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> replication_applier_status_by_workerOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "WORKER_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "SERVICE_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "LAST_ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayOutput>( "LAST_ERROR_MESSAGE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_ERROR_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayOutput>( "LAST_APPLIED_TRANSACTION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_APPLIED_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>(
            "LAST_APPLIED_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_APPLIED_TRANSACTION_START_APPLY_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_APPLIED_TRANSACTION_END_APPLY_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayOutput>( "APPLYING_TRANSACTION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "APPLYING_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "APPLYING_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "APPLYING_TRANSACTION_START_APPLY_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "LAST_APPLIED_TRANSACTION_RETRIES_COUNT" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>(
            "LAST_APPLIED_TRANSACTION_LAST_TRANSIENT_ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayOutput>(
            "LAST_APPLIED_TRANSACTION_LAST_TRANSIENT_ERROR_MESSAGE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>(
            "LAST_APPLIED_TRANSACTION_LAST_TRANSIENT_ERROR_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "APPLYING_TRANSACTION_RETRIES_COUNT" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>(
            "APPLYING_TRANSACTION_LAST_TRANSIENT_ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayOutput>( "APPLYING_TRANSACTION_LAST_TRANSIENT_ERROR_MESSAGE",
                                               MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>(
            "APPLYING_TRANSACTION_LAST_TRANSIENT_ERROR_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> replication_asynchronous_connection_failoverInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "PORT" ),
        std::make_unique<TypeCharArrayInput>( "NETWORK_NAMESPACE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned char, MYSQL_TYPE_TINY>>( "WEIGHT" ),
        std::make_unique<TypeCharArrayInput>( "MANAGED_NAME", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> replication_asynchronous_connection_failoverOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "PORT" ),
        std::make_unique<TypeCharArrayOutput>( "NETWORK_NAMESPACE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned char, MYSQL_TYPE_TINY>>( "WEIGHT" ),
        std::make_unique<TypeCharArrayOutput>( "MANAGED_NAME", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> replication_asynchronous_connection_failover_managedInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MANAGED_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MANAGED_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "CONFIGURATION", MYSQL_TYPE_JSON, 100 ) ) );
}
Binds<OutputCType> replication_asynchronous_connection_failover_managedOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MANAGED_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MANAGED_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "CONFIGURATION", MYSQL_TYPE_JSON, 100 ) ) );
}

Binds<InputCType> replication_connection_configurationInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "PORT" ),
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "NETWORK_INTERFACE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "AUTO_POSITION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SSL_ALLOWED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SSL_CA_FILE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SSL_CA_PATH", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SSL_CERTIFICATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SSL_CIPHER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SSL_KEY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SSL_VERIFY_SERVER_CERTIFICATE", MYSQL_TYPE_STRING,
                                              100 ),
        std::make_unique<TypeCharArrayInput>( "SSL_CRL_FILE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SSL_CRL_PATH", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "CONNECTION_RETRY_INTERVAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CONNECTION_RETRY_COUNT" ),
        std::make_unique<TypeInputImpl<double, MYSQL_TYPE_DOUBLE>>( "HEARTBEAT_INTERVAL" ),
        std::make_unique<TypeCharArrayInput>( "TLS_VERSION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "PUBLIC_KEY_PATH", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "GET_PUBLIC_KEY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "NETWORK_NAMESPACE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "COMPRESSION_ALGORITHM", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "ZSTD_COMPRESSION_LEVEL" ),
        std::make_unique<TypeCharArrayInput>( "TLS_CIPHERSUITES", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE_CONNECTION_AUTO_FAILOVER", MYSQL_TYPE_STRING,
                                              100 ),
        std::make_unique<TypeCharArrayInput>( "GTID_ONLY", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> replication_connection_configurationOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "PORT" ),
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "NETWORK_INTERFACE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "AUTO_POSITION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SSL_ALLOWED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SSL_CA_FILE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SSL_CA_PATH", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SSL_CERTIFICATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SSL_CIPHER", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SSL_KEY", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SSL_VERIFY_SERVER_CERTIFICATE", MYSQL_TYPE_STRING,
                                               100 ),
        std::make_unique<TypeCharArrayOutput>( "SSL_CRL_FILE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SSL_CRL_PATH", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "CONNECTION_RETRY_INTERVAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CONNECTION_RETRY_COUNT" ),
        std::make_unique<TypeOutputImpl<double, MYSQL_TYPE_DOUBLE>>( "HEARTBEAT_INTERVAL" ),
        std::make_unique<TypeCharArrayOutput>( "TLS_VERSION", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "PUBLIC_KEY_PATH", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "GET_PUBLIC_KEY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "NETWORK_NAMESPACE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "COMPRESSION_ALGORITHM", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "ZSTD_COMPRESSION_LEVEL" ),
        std::make_unique<TypeCharArrayOutput>( "TLS_CIPHERSUITES", MYSQL_TYPE_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE_CONNECTION_AUTO_FAILOVER", MYSQL_TYPE_STRING,
                                               100 ),
        std::make_unique<TypeCharArrayOutput>( "GTID_ONLY", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> replication_connection_statusInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "GROUP_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SOURCE_UUID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "SERVICE_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_RECEIVED_HEARTBEATS" ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_HEARTBEAT_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayInput>( "RECEIVED_TRANSACTION_SET", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "LAST_ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayInput>( "LAST_ERROR_MESSAGE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_ERROR_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayInput>( "LAST_QUEUED_TRANSACTION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_QUEUED_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_QUEUED_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_QUEUED_TRANSACTION_START_QUEUE_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "LAST_QUEUED_TRANSACTION_END_QUEUE_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayInput>( "QUEUEING_TRANSACTION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "QUEUEING_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "QUEUEING_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeInput>( "QUEUEING_TRANSACTION_START_QUEUE_TIMESTAMP",
                                              MYSQL_TYPE_TIMESTAMP ) ) );
}
Binds<OutputCType> replication_connection_statusOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "GROUP_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SOURCE_UUID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "SERVICE_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_RECEIVED_HEARTBEATS" ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_HEARTBEAT_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayOutput>( "RECEIVED_TRANSACTION_SET", MYSQL_TYPE_MEDIUM_BLOB,
                                               100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "LAST_ERROR_NUMBER" ),
        std::make_unique<TypeCharArrayOutput>( "LAST_ERROR_MESSAGE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_ERROR_TIMESTAMP", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayOutput>( "LAST_QUEUED_TRANSACTION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_QUEUED_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_QUEUED_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_QUEUED_TRANSACTION_START_QUEUE_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "LAST_QUEUED_TRANSACTION_END_QUEUE_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayOutput>( "QUEUEING_TRANSACTION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "QUEUEING_TRANSACTION_ORIGINAL_COMMIT_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "QUEUEING_TRANSACTION_IMMEDIATE_COMMIT_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeMysqlTimeOutput>( "QUEUEING_TRANSACTION_START_QUEUE_TIMESTAMP",
                                               MYSQL_TYPE_TIMESTAMP ) ) );
}

Binds<InputCType> replication_group_member_statsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VIEW_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MEMBER_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_IN_QUEUE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_CHECKED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_CONFLICTS_DETECTED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_ROWS_VALIDATING" ),
        std::make_unique<TypeCharArrayInput>( "TRANSACTIONS_COMMITTED_ALL_MEMBERS",
                                              MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "LAST_CONFLICT_FREE_TRANSACTION", MYSQL_TYPE_STRING,
                                              100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_REMOTE_APPLIED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_LOCAL_PROPOSED" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_LOCAL_ROLLBACK" ) ) );
}
Binds<OutputCType> replication_group_member_statsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VIEW_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MEMBER_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_IN_QUEUE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_CHECKED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_CONFLICTS_DETECTED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_ROWS_VALIDATING" ),
        std::make_unique<TypeCharArrayOutput>( "TRANSACTIONS_COMMITTED_ALL_MEMBERS",
                                               MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeCharArrayOutput>( "LAST_CONFLICT_FREE_TRANSACTION", MYSQL_TYPE_BLOB,
                                               100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_REMOTE_IN_APPLIER_QUEUE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_REMOTE_APPLIED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_LOCAL_PROPOSED" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_TRANSACTIONS_LOCAL_ROLLBACK" ) ) );
}

Binds<InputCType> replication_group_membersInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MEMBER_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MEMBER_HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "MEMBER_PORT" ),
        std::make_unique<TypeCharArrayInput>( "MEMBER_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MEMBER_ROLE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MEMBER_VERSION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MEMBER_COMMUNICATION_STACK", MYSQL_TYPE_STRING,
                                              100 ) ) );
}
Binds<OutputCType> replication_group_membersOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MEMBER_ID", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MEMBER_HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "MEMBER_PORT" ),
        std::make_unique<TypeCharArrayOutput>( "MEMBER_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MEMBER_ROLE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MEMBER_VERSION", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MEMBER_COMMUNICATION_STACK", MYSQL_TYPE_STRING,
                                               100 ) ) );
}

Binds<InputCType> rwlock_instancesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WRITE_LOCKED_BY_THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned int, MYSQL_TYPE_LONG>>(
            "READ_LOCKED_BY_COUNT" ) ) );
}
Binds<OutputCType> rwlock_instancesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "WRITE_LOCKED_BY_THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned int, MYSQL_TYPE_LONG>>(
            "READ_LOCKED_BY_COUNT" ) ) );
}

Binds<InputCType> session_account_connect_attrsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "PROCESSLIST_ID" ),
        std::make_unique<TypeCharArrayInput>( "ATTR_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ATTR_VALUE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "ORDINAL_POSITION" ) ) );
}
Binds<OutputCType> session_account_connect_attrsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "PROCESSLIST_ID" ),
        std::make_unique<TypeCharArrayOutput>( "ATTR_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ATTR_VALUE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "ORDINAL_POSITION" ) ) );
}

Binds<InputCType> session_connect_attrsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "PROCESSLIST_ID" ),
        std::make_unique<TypeCharArrayInput>( "ATTR_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ATTR_VALUE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "ORDINAL_POSITION" ) ) );
}
Binds<OutputCType> session_connect_attrsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "PROCESSLIST_ID" ),
        std::make_unique<TypeCharArrayOutput>( "ATTR_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ATTR_VALUE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "ORDINAL_POSITION" ) ) );
}

Binds<InputCType> session_statusInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> session_statusOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> session_variablesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> session_variablesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> setup_actorsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ROLE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ENABLED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HISTORY", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> setup_actorsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ROLE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ENABLED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HISTORY", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> setup_consumersInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ENABLED", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> setup_consumersOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ENABLED", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> setup_instrumentsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ENABLED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "TIMED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "PROPERTIES", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "FLAGS", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "VOLATILITY" ),
        std::make_unique<TypeCharArrayInput>( "DOCUMENTATION", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> setup_instrumentsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ENABLED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "TIMED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "PROPERTIES", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "FLAGS", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "VOLATILITY" ),
        std::make_unique<TypeCharArrayOutput>( "DOCUMENTATION", MYSQL_TYPE_MEDIUM_BLOB, 100 ) ) );
}

Binds<InputCType> setup_objectsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ENABLED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "TIMED", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> setup_objectsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ENABLED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "TIMED", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> setup_threadsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "ENABLED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HISTORY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "PROPERTIES", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "VOLATILITY" ),
        std::make_unique<TypeCharArrayInput>( "DOCUMENTATION", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> setup_threadsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "ENABLED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HISTORY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "PROPERTIES", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "VOLATILITY" ),
        std::make_unique<TypeCharArrayOutput>( "DOCUMENTATION", MYSQL_TYPE_MEDIUM_BLOB, 100 ) ) );
}

Binds<InputCType> socket_instancesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "SOCKET_ID" ),
        std::make_unique<TypeCharArrayInput>( "IP", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<int, MYSQL_TYPE_LONG>>( "PORT" ),
        std::make_unique<TypeCharArrayInput>( "STATE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> socket_instancesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "SOCKET_ID" ),
        std::make_unique<TypeCharArrayOutput>( "IP", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<int, MYSQL_TYPE_LONG>>( "PORT" ),
        std::make_unique<TypeCharArrayOutput>( "STATE", MYSQL_TYPE_STRING, 100 ) ) );
}

Binds<InputCType> socket_summary_by_event_nameInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_MISC" ) ) );
}
Binds<OutputCType> socket_summary_by_event_nameOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_MISC" ) ) );
}

Binds<InputCType> socket_summary_by_instanceInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "EVENT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_MISC" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_MISC" ) ) );
}
Binds<OutputCType> socket_summary_by_instanceOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "EVENT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_NUMBER_OF_BYTES_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_MISC" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_MISC" ) ) );
}

Binds<InputCType> status_by_accountInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> status_by_accountOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> status_by_hostInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> status_by_hostOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> status_by_threadInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> status_by_threadOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> status_by_userInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> status_by_userOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> table_handlesInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_THREAD_ID" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_EVENT_ID" ),
        std::make_unique<TypeCharArrayInput>( "INTERNAL_LOCK", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EXTERNAL_LOCK", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> table_handlesOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OBJECT_INSTANCE_BEGIN" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_THREAD_ID" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "OWNER_EVENT_ID" ),
        std::make_unique<TypeCharArrayOutput>( "INTERNAL_LOCK", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EXTERNAL_LOCK", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> table_io_waits_summary_by_index_usageInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "INDEX_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FETCH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_FETCH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_FETCH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_FETCH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_FETCH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_UPDATE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_UPDATE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_UPDATE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_UPDATE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_UPDATE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_DELETE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_DELETE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_DELETE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_DELETE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_DELETE" ) ) );
}
Binds<OutputCType> table_io_waits_summary_by_index_usageOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "INDEX_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FETCH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_FETCH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_FETCH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_FETCH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_FETCH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_UPDATE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_UPDATE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_UPDATE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_UPDATE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_UPDATE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_DELETE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_DELETE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_DELETE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_DELETE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_DELETE" ) ) );
}

Binds<InputCType> table_io_waits_summary_by_tableInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FETCH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_FETCH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_FETCH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_FETCH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_FETCH" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_UPDATE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_UPDATE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_UPDATE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_UPDATE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_UPDATE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_DELETE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_DELETE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_DELETE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_DELETE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_DELETE" ) ) );
}
Binds<OutputCType> table_io_waits_summary_by_tableOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_FETCH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_FETCH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_FETCH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_FETCH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_FETCH" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_UPDATE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_UPDATE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_UPDATE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_UPDATE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_UPDATE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_DELETE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_DELETE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_DELETE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_DELETE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_DELETE" ) ) );
}

Binds<InputCType> table_lock_waits_summary_by_tableInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "OBJECT_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_SCHEMA", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "OBJECT_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_NORMAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_NORMAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_NORMAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_NORMAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_NORMAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WITH_SHARED_LOCKS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WITH_SHARED_LOCKS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WITH_SHARED_LOCKS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WITH_SHARED_LOCKS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WITH_SHARED_LOCKS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_HIGH_PRIORITY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_HIGH_PRIORITY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_HIGH_PRIORITY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_HIGH_PRIORITY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_HIGH_PRIORITY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_NO_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_NO_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_NO_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_NO_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_NO_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_EXTERNAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_EXTERNAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_EXTERNAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_EXTERNAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_EXTERNAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_WRITE_ALLOW_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE_ALLOW_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE_ALLOW_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE_ALLOW_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE_ALLOW_WRITE" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_WRITE_CONCURRENT_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE_CONCURRENT_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE_CONCURRENT_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE_CONCURRENT_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE_CONCURRENT_INSERT" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_WRITE_LOW_PRIORITY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE_LOW_PRIORITY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE_LOW_PRIORITY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE_LOW_PRIORITY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE_LOW_PRIORITY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_WRITE_NORMAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE_NORMAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE_NORMAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE_NORMAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE_NORMAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_WRITE_EXTERNAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE_EXTERNAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE_EXTERNAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE_EXTERNAL" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE_EXTERNAL" ) ) );
}
Binds<OutputCType> table_lock_waits_summary_by_tableOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "OBJECT_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_SCHEMA", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "OBJECT_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_STAR" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WAIT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "COUNT_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_NORMAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_NORMAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_NORMAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_NORMAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_NORMAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_WITH_SHARED_LOCKS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_WITH_SHARED_LOCKS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_WITH_SHARED_LOCKS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_WITH_SHARED_LOCKS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_WITH_SHARED_LOCKS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_HIGH_PRIORITY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_HIGH_PRIORITY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_HIGH_PRIORITY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_HIGH_PRIORITY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_HIGH_PRIORITY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_NO_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_NO_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_NO_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_NO_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_NO_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_READ_EXTERNAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_READ_EXTERNAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_READ_EXTERNAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_READ_EXTERNAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_READ_EXTERNAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_WRITE_ALLOW_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE_ALLOW_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE_ALLOW_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE_ALLOW_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE_ALLOW_WRITE" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_WRITE_CONCURRENT_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE_CONCURRENT_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE_CONCURRENT_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE_CONCURRENT_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE_CONCURRENT_INSERT" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_WRITE_LOW_PRIORITY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE_LOW_PRIORITY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE_LOW_PRIORITY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE_LOW_PRIORITY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE_LOW_PRIORITY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_WRITE_NORMAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE_NORMAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE_NORMAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE_NORMAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE_NORMAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "COUNT_WRITE_EXTERNAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "SUM_TIMER_WRITE_EXTERNAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MIN_TIMER_WRITE_EXTERNAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "AVG_TIMER_WRITE_EXTERNAL" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TIMER_WRITE_EXTERNAL" ) ) );
}

Binds<InputCType> threadsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "PROCESSLIST_ID" ),
        std::make_unique<TypeCharArrayInput>( "PROCESSLIST_USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "PROCESSLIST_HOST", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "PROCESSLIST_DB", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "PROCESSLIST_COMMAND", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "PROCESSLIST_TIME" ),
        std::make_unique<TypeCharArrayInput>( "PROCESSLIST_STATE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "PROCESSLIST_INFO", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "PARENT_THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "ROLE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "INSTRUMENTED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "HISTORY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "CONNECTION_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_OS_ID" ),
        std::make_unique<TypeCharArrayInput>( "RESOURCE_GROUP", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TOTAL_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ) ) );
}
Binds<OutputCType> threadsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "PROCESSLIST_ID" ),
        std::make_unique<TypeCharArrayOutput>( "PROCESSLIST_USER", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "PROCESSLIST_HOST", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "PROCESSLIST_DB", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "PROCESSLIST_COMMAND", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "PROCESSLIST_TIME" ),
        std::make_unique<TypeCharArrayOutput>( "PROCESSLIST_STATE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "PROCESSLIST_INFO", MYSQL_TYPE_MEDIUM_BLOB, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "PARENT_THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "ROLE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "INSTRUMENTED", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "HISTORY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "CONNECTION_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_OS_ID" ),
        std::make_unique<TypeCharArrayOutput>( "RESOURCE_GROUP", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "EXECUTION_ENGINE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "TOTAL_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_TOTAL_MEMORY" ) ) );
}

Binds<InputCType> tls_channel_statusInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "CHANNEL", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "PROPERTY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> tls_channel_statusOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "CHANNEL", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "PROPERTY", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> user_defined_functionsInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "UDF_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "UDF_RETURN_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "UDF_TYPE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "UDF_LIBRARY", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "UDF_USAGE_COUNT" ) ) );
}
Binds<OutputCType> user_defined_functionsOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "UDF_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "UDF_RETURN_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "UDF_TYPE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "UDF_LIBRARY", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "UDF_USAGE_COUNT" ) ) );
}

Binds<InputCType> user_variables_by_threadInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_BLOB, 100 ) ) );
}
Binds<OutputCType> user_variables_by_threadOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_LONG_BLOB, 100 ) ) );
}

Binds<InputCType> usersInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_CONNECTIONS" ),
        std::make_unique<TypeInputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TOTAL_CONNECTIONS" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_CONTROLLED_MEMORY" ),
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_TOTAL_MEMORY" ) ) );
}
Binds<OutputCType> usersOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "CURRENT_CONNECTIONS" ),
        std::make_unique<TypeOutputImpl<long long, MYSQL_TYPE_LONGLONG>>( "TOTAL_CONNECTIONS" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_CONTROLLED_MEMORY" ),
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>(
            "MAX_SESSION_TOTAL_MEMORY" ) ) );
}

Binds<InputCType> variables_by_threadInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeInputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_VALUE", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> variables_by_threadOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeOutputImpl<unsigned long long, MYSQL_TYPE_LONGLONG>>( "THREAD_ID" ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_VALUE", MYSQL_TYPE_VAR_STRING, 100 ) ) );
}

Binds<InputCType> variables_infoInputBinds() {
    return Binds<InputCType>( make_vector<InputCType>(
        std::make_unique<TypeCharArrayInput>( "VARIABLE_NAME", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "VARIABLE_PATH", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MIN_VALUE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "MAX_VALUE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeMysqlTimeInput>( "SET_TIME", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayInput>( "SET_USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayInput>( "SET_HOST", MYSQL_TYPE_STRING, 100 ) ) );
}
Binds<OutputCType> variables_infoOutputBinds() {
    return Binds<OutputCType>( make_vector<OutputCType>(
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_NAME", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_SOURCE", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "VARIABLE_PATH", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MIN_VALUE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "MAX_VALUE", MYSQL_TYPE_VAR_STRING, 100 ),
        std::make_unique<TypeMysqlTimeOutput>( "SET_TIME", MYSQL_TYPE_TIMESTAMP ),
        std::make_unique<TypeCharArrayOutput>( "SET_USER", MYSQL_TYPE_STRING, 100 ),
        std::make_unique<TypeCharArrayOutput>( "SET_HOST", MYSQL_TYPE_STRING, 100 ) ) );
}
