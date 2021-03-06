/* -------------------------------------------------------------------------
 *
 * barrier.h
 *
 *	  Definitions for the PITR barrier handling
 *
 *
 * Portions Copyright (c) 1996-2011, PostgreSQL Global Development Group
 * Portions Copyright (c) 2010-2012 Postgres-XC Development Group
 *
 * src/include/pgxc/barrier.h
 *
 * -------------------------------------------------------------------------
 */

#ifndef XC_BARRIER_H
#define XC_BARRIER_H

#include "access/xlogreader.h"
#include "lib/stringinfo.h"

#define CREATE_BARRIER_PREPARE 'P'
#define CREATE_BARRIER_EXECUTE 'X'
#define CREATE_BARRIER_END 'E'

#define CREATE_BARRIER_PREPARE_DONE 'p'
#define CREATE_BARRIER_EXECUTE_DONE 'x'

#define BARRIER_LSN_FILE "barrier_lsn"
#define BARRIER_LSN_FILE_LENGTH 17

#define XLOG_BARRIER_CREATE 0x00

extern void ProcessCreateBarrierPrepare(const char* id);
extern void ProcessCreateBarrierEnd(const char* id);
extern void ProcessCreateBarrierExecute(const char* id);

extern void RequestBarrier(const char* id, char* completionTag);
extern void barrier_redo(XLogReaderState* record);
extern void barrier_desc(StringInfo buf, XLogReaderState* record);
#endif
