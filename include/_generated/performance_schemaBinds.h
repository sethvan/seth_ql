#ifndef INCLUDED_PERFORMANCE_SCHEMABINDS_H
#define INCLUDED_PERFORMANCE_SCHEMABINDS_H

#include "binds.hpp"

Binds<InputCType> accountsInputBinds();
Binds<OutputCType> accountsOutputBinds();

Binds<InputCType> binary_log_transaction_compression_statsInputBinds();
Binds<OutputCType> binary_log_transaction_compression_statsOutputBinds();

Binds<InputCType> cond_instancesInputBinds();
Binds<OutputCType> cond_instancesOutputBinds();

Binds<InputCType> data_lock_waitsInputBinds();
Binds<OutputCType> data_lock_waitsOutputBinds();

Binds<InputCType> data_locksInputBinds();
Binds<OutputCType> data_locksOutputBinds();

Binds<InputCType> error_logInputBinds();
Binds<OutputCType> error_logOutputBinds();

Binds<InputCType> events_errors_summary_by_account_by_errorInputBinds();
Binds<OutputCType> events_errors_summary_by_account_by_errorOutputBinds();

Binds<InputCType> events_errors_summary_by_host_by_errorInputBinds();
Binds<OutputCType> events_errors_summary_by_host_by_errorOutputBinds();

Binds<InputCType> events_errors_summary_by_thread_by_errorInputBinds();
Binds<OutputCType> events_errors_summary_by_thread_by_errorOutputBinds();

Binds<InputCType> events_errors_summary_by_user_by_errorInputBinds();
Binds<OutputCType> events_errors_summary_by_user_by_errorOutputBinds();

Binds<InputCType> events_errors_summary_global_by_errorInputBinds();
Binds<OutputCType> events_errors_summary_global_by_errorOutputBinds();

Binds<InputCType> events_stages_currentInputBinds();
Binds<OutputCType> events_stages_currentOutputBinds();

Binds<InputCType> events_stages_historyInputBinds();
Binds<OutputCType> events_stages_historyOutputBinds();

Binds<InputCType> events_stages_history_longInputBinds();
Binds<OutputCType> events_stages_history_longOutputBinds();

Binds<InputCType> events_stages_summary_by_account_by_event_nameInputBinds();
Binds<OutputCType> events_stages_summary_by_account_by_event_nameOutputBinds();

Binds<InputCType> events_stages_summary_by_host_by_event_nameInputBinds();
Binds<OutputCType> events_stages_summary_by_host_by_event_nameOutputBinds();

Binds<InputCType> events_stages_summary_by_thread_by_event_nameInputBinds();
Binds<OutputCType> events_stages_summary_by_thread_by_event_nameOutputBinds();

Binds<InputCType> events_stages_summary_by_user_by_event_nameInputBinds();
Binds<OutputCType> events_stages_summary_by_user_by_event_nameOutputBinds();

Binds<InputCType> events_stages_summary_global_by_event_nameInputBinds();
Binds<OutputCType> events_stages_summary_global_by_event_nameOutputBinds();

Binds<InputCType> events_statements_currentInputBinds();
Binds<OutputCType> events_statements_currentOutputBinds();

Binds<InputCType> events_statements_histogram_by_digestInputBinds();
Binds<OutputCType> events_statements_histogram_by_digestOutputBinds();

Binds<InputCType> events_statements_histogram_globalInputBinds();
Binds<OutputCType> events_statements_histogram_globalOutputBinds();

Binds<InputCType> events_statements_historyInputBinds();
Binds<OutputCType> events_statements_historyOutputBinds();

Binds<InputCType> events_statements_history_longInputBinds();
Binds<OutputCType> events_statements_history_longOutputBinds();

Binds<InputCType> events_statements_summary_by_account_by_event_nameInputBinds();
Binds<OutputCType> events_statements_summary_by_account_by_event_nameOutputBinds();

Binds<InputCType> events_statements_summary_by_digestInputBinds();
Binds<OutputCType> events_statements_summary_by_digestOutputBinds();

Binds<InputCType> events_statements_summary_by_host_by_event_nameInputBinds();
Binds<OutputCType> events_statements_summary_by_host_by_event_nameOutputBinds();

Binds<InputCType> events_statements_summary_by_programInputBinds();
Binds<OutputCType> events_statements_summary_by_programOutputBinds();

Binds<InputCType> events_statements_summary_by_thread_by_event_nameInputBinds();
Binds<OutputCType> events_statements_summary_by_thread_by_event_nameOutputBinds();

Binds<InputCType> events_statements_summary_by_user_by_event_nameInputBinds();
Binds<OutputCType> events_statements_summary_by_user_by_event_nameOutputBinds();

Binds<InputCType> events_statements_summary_global_by_event_nameInputBinds();
Binds<OutputCType> events_statements_summary_global_by_event_nameOutputBinds();

Binds<InputCType> events_transactions_currentInputBinds();
Binds<OutputCType> events_transactions_currentOutputBinds();

Binds<InputCType> events_transactions_historyInputBinds();
Binds<OutputCType> events_transactions_historyOutputBinds();

Binds<InputCType> events_transactions_history_longInputBinds();
Binds<OutputCType> events_transactions_history_longOutputBinds();

Binds<InputCType> events_transactions_summary_by_account_by_event_nameInputBinds();
Binds<OutputCType> events_transactions_summary_by_account_by_event_nameOutputBinds();

Binds<InputCType> events_transactions_summary_by_host_by_event_nameInputBinds();
Binds<OutputCType> events_transactions_summary_by_host_by_event_nameOutputBinds();

Binds<InputCType> events_transactions_summary_by_thread_by_event_nameInputBinds();
Binds<OutputCType> events_transactions_summary_by_thread_by_event_nameOutputBinds();

Binds<InputCType> events_transactions_summary_by_user_by_event_nameInputBinds();
Binds<OutputCType> events_transactions_summary_by_user_by_event_nameOutputBinds();

Binds<InputCType> events_transactions_summary_global_by_event_nameInputBinds();
Binds<OutputCType> events_transactions_summary_global_by_event_nameOutputBinds();

Binds<InputCType> events_waits_currentInputBinds();
Binds<OutputCType> events_waits_currentOutputBinds();

Binds<InputCType> events_waits_historyInputBinds();
Binds<OutputCType> events_waits_historyOutputBinds();

Binds<InputCType> events_waits_history_longInputBinds();
Binds<OutputCType> events_waits_history_longOutputBinds();

Binds<InputCType> events_waits_summary_by_account_by_event_nameInputBinds();
Binds<OutputCType> events_waits_summary_by_account_by_event_nameOutputBinds();

Binds<InputCType> events_waits_summary_by_host_by_event_nameInputBinds();
Binds<OutputCType> events_waits_summary_by_host_by_event_nameOutputBinds();

Binds<InputCType> events_waits_summary_by_instanceInputBinds();
Binds<OutputCType> events_waits_summary_by_instanceOutputBinds();

Binds<InputCType> events_waits_summary_by_thread_by_event_nameInputBinds();
Binds<OutputCType> events_waits_summary_by_thread_by_event_nameOutputBinds();

Binds<InputCType> events_waits_summary_by_user_by_event_nameInputBinds();
Binds<OutputCType> events_waits_summary_by_user_by_event_nameOutputBinds();

Binds<InputCType> events_waits_summary_global_by_event_nameInputBinds();
Binds<OutputCType> events_waits_summary_global_by_event_nameOutputBinds();

Binds<InputCType> file_instancesInputBinds();
Binds<OutputCType> file_instancesOutputBinds();

Binds<InputCType> file_summary_by_event_nameInputBinds();
Binds<OutputCType> file_summary_by_event_nameOutputBinds();

Binds<InputCType> file_summary_by_instanceInputBinds();
Binds<OutputCType> file_summary_by_instanceOutputBinds();

Binds<InputCType> global_statusInputBinds();
Binds<OutputCType> global_statusOutputBinds();

Binds<InputCType> global_variablesInputBinds();
Binds<OutputCType> global_variablesOutputBinds();

Binds<InputCType> host_cacheInputBinds();
Binds<OutputCType> host_cacheOutputBinds();

Binds<InputCType> hostsInputBinds();
Binds<OutputCType> hostsOutputBinds();

Binds<InputCType> innodb_redo_log_filesInputBinds();
Binds<OutputCType> innodb_redo_log_filesOutputBinds();

Binds<InputCType> keyring_component_statusInputBinds();
Binds<OutputCType> keyring_component_statusOutputBinds();

Binds<InputCType> keyring_keysInputBinds();
Binds<OutputCType> keyring_keysOutputBinds();

Binds<InputCType> log_statusInputBinds();
Binds<OutputCType> log_statusOutputBinds();

Binds<InputCType> memory_summary_by_account_by_event_nameInputBinds();
Binds<OutputCType> memory_summary_by_account_by_event_nameOutputBinds();

Binds<InputCType> memory_summary_by_host_by_event_nameInputBinds();
Binds<OutputCType> memory_summary_by_host_by_event_nameOutputBinds();

Binds<InputCType> memory_summary_by_thread_by_event_nameInputBinds();
Binds<OutputCType> memory_summary_by_thread_by_event_nameOutputBinds();

Binds<InputCType> memory_summary_by_user_by_event_nameInputBinds();
Binds<OutputCType> memory_summary_by_user_by_event_nameOutputBinds();

Binds<InputCType> memory_summary_global_by_event_nameInputBinds();
Binds<OutputCType> memory_summary_global_by_event_nameOutputBinds();

Binds<InputCType> metadata_locksInputBinds();
Binds<OutputCType> metadata_locksOutputBinds();

Binds<InputCType> mutex_instancesInputBinds();
Binds<OutputCType> mutex_instancesOutputBinds();

Binds<InputCType> objects_summary_global_by_typeInputBinds();
Binds<OutputCType> objects_summary_global_by_typeOutputBinds();

Binds<InputCType> performance_timersInputBinds();
Binds<OutputCType> performance_timersOutputBinds();

Binds<InputCType> persisted_variablesInputBinds();
Binds<OutputCType> persisted_variablesOutputBinds();

Binds<InputCType> prepared_statements_instancesInputBinds();
Binds<OutputCType> prepared_statements_instancesOutputBinds();

Binds<InputCType> processlistInputBinds();
Binds<OutputCType> processlistOutputBinds();

Binds<InputCType> replication_applier_configurationInputBinds();
Binds<OutputCType> replication_applier_configurationOutputBinds();

Binds<InputCType> replication_applier_filtersInputBinds();
Binds<OutputCType> replication_applier_filtersOutputBinds();

Binds<InputCType> replication_applier_global_filtersInputBinds();
Binds<OutputCType> replication_applier_global_filtersOutputBinds();

Binds<InputCType> replication_applier_statusInputBinds();
Binds<OutputCType> replication_applier_statusOutputBinds();

Binds<InputCType> replication_applier_status_by_coordinatorInputBinds();
Binds<OutputCType> replication_applier_status_by_coordinatorOutputBinds();

Binds<InputCType> replication_applier_status_by_workerInputBinds();
Binds<OutputCType> replication_applier_status_by_workerOutputBinds();

Binds<InputCType> replication_asynchronous_connection_failoverInputBinds();
Binds<OutputCType> replication_asynchronous_connection_failoverOutputBinds();

Binds<InputCType> replication_asynchronous_connection_failover_managedInputBinds();
Binds<OutputCType> replication_asynchronous_connection_failover_managedOutputBinds();

Binds<InputCType> replication_connection_configurationInputBinds();
Binds<OutputCType> replication_connection_configurationOutputBinds();

Binds<InputCType> replication_connection_statusInputBinds();
Binds<OutputCType> replication_connection_statusOutputBinds();

Binds<InputCType> replication_group_member_statsInputBinds();
Binds<OutputCType> replication_group_member_statsOutputBinds();

Binds<InputCType> replication_group_membersInputBinds();
Binds<OutputCType> replication_group_membersOutputBinds();

Binds<InputCType> rwlock_instancesInputBinds();
Binds<OutputCType> rwlock_instancesOutputBinds();

Binds<InputCType> session_account_connect_attrsInputBinds();
Binds<OutputCType> session_account_connect_attrsOutputBinds();

Binds<InputCType> session_connect_attrsInputBinds();
Binds<OutputCType> session_connect_attrsOutputBinds();

Binds<InputCType> session_statusInputBinds();
Binds<OutputCType> session_statusOutputBinds();

Binds<InputCType> session_variablesInputBinds();
Binds<OutputCType> session_variablesOutputBinds();

Binds<InputCType> setup_actorsInputBinds();
Binds<OutputCType> setup_actorsOutputBinds();

Binds<InputCType> setup_consumersInputBinds();
Binds<OutputCType> setup_consumersOutputBinds();

Binds<InputCType> setup_instrumentsInputBinds();
Binds<OutputCType> setup_instrumentsOutputBinds();

Binds<InputCType> setup_objectsInputBinds();
Binds<OutputCType> setup_objectsOutputBinds();

Binds<InputCType> setup_threadsInputBinds();
Binds<OutputCType> setup_threadsOutputBinds();

Binds<InputCType> socket_instancesInputBinds();
Binds<OutputCType> socket_instancesOutputBinds();

Binds<InputCType> socket_summary_by_event_nameInputBinds();
Binds<OutputCType> socket_summary_by_event_nameOutputBinds();

Binds<InputCType> socket_summary_by_instanceInputBinds();
Binds<OutputCType> socket_summary_by_instanceOutputBinds();

Binds<InputCType> status_by_accountInputBinds();
Binds<OutputCType> status_by_accountOutputBinds();

Binds<InputCType> status_by_hostInputBinds();
Binds<OutputCType> status_by_hostOutputBinds();

Binds<InputCType> status_by_threadInputBinds();
Binds<OutputCType> status_by_threadOutputBinds();

Binds<InputCType> status_by_userInputBinds();
Binds<OutputCType> status_by_userOutputBinds();

Binds<InputCType> table_handlesInputBinds();
Binds<OutputCType> table_handlesOutputBinds();

Binds<InputCType> table_io_waits_summary_by_index_usageInputBinds();
Binds<OutputCType> table_io_waits_summary_by_index_usageOutputBinds();

Binds<InputCType> table_io_waits_summary_by_tableInputBinds();
Binds<OutputCType> table_io_waits_summary_by_tableOutputBinds();

Binds<InputCType> table_lock_waits_summary_by_tableInputBinds();
Binds<OutputCType> table_lock_waits_summary_by_tableOutputBinds();

Binds<InputCType> threadsInputBinds();
Binds<OutputCType> threadsOutputBinds();

Binds<InputCType> tls_channel_statusInputBinds();
Binds<OutputCType> tls_channel_statusOutputBinds();

Binds<InputCType> user_defined_functionsInputBinds();
Binds<OutputCType> user_defined_functionsOutputBinds();

Binds<InputCType> user_variables_by_threadInputBinds();
Binds<OutputCType> user_variables_by_threadOutputBinds();

Binds<InputCType> usersInputBinds();
Binds<OutputCType> usersOutputBinds();

Binds<InputCType> variables_by_threadInputBinds();
Binds<OutputCType> variables_by_threadOutputBinds();

Binds<InputCType> variables_infoInputBinds();
Binds<OutputCType> variables_infoOutputBinds();

#endif  // INCLUDED_PERFORMANCE_SCHEMABINDS_H
