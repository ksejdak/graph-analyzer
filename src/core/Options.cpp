/*
 * Filename		: Options.cpp
 * Author		: Kuba Sejdak
 * Created on	: 16-09-2012
 */

#include <core/Options.h>

/* ===== EmulationSystem ===== */

/* how many steps should EmulationUnit go */
int EMULATION_STEPS;

/* where to put graphs and samples */
QString GRAPHS_DIR;

/* delete sample's code after analysis (memory management issue) */
bool DELETE_CODE_INSTANTLY;

/* ===== Input Modules ===== */

/* protection against too big files */
bool PROTECT_AGAINST_BIG_FILES;
int MAX_INPUT_FILE_SIZE;

/* ===== DatabaseOutput ===== */

/* info to connect with database */
QString DB_QT_DRIVER;
QString DB_HOST;
QString DB_NAME;
QString DB_USER;
QString DB_PASS;
QString ANA_TABLE_PREFIX;
QString OPT_TABLE_PREFIX;
QString ID_SEQ_POSTFIX;

/* should system skip output for non-explit samples */
bool SKIP_NONEXPLOIT_OUTPUT;
