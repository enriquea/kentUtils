/* eapDb.h was originally generated by the autoSql program, which also 
 * generated eapDb.c and eapDb.sql.  This header links the database and
 * the RAM representation of objects. */

/* Copyright (C) 2014 The Regents of the University of California 
 * See README in this or parent directory for licensing information. */

#ifndef EAPDB_H
#define EAPDB_H

#include "jksql.h"
#define EAPJOB_NUM_COLS 8

extern char *eapJobCommaSepFieldNames;

struct eapJob
/* An analysis pipeline job to be run asynchronously and not too many all at once. */
    {
    struct eapJob *next;  /* Next in singly linked list. */
    unsigned id;	/* Job id */
    char *commandLine;	/* Command line of job */
    long long startTime;	/* Start time in seconds since 1970 */
    long long endTime;	/* End time in seconds since 1970 */
    char *stderr;	/* The output to stderr of the run - may be nonempty even with success */
    int returnCode;	/* The return code from system command - 0 for success */
    int cpusRequested;	/* Number of CPUs to request from job control system */
    char *parasolId;	/* Parasol job id for process. */
    };

void eapJobStaticLoad(char **row, struct eapJob *ret);
/* Load a row from eapJob table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct eapJob *eapJobLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapJob from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapJobFreeList(). */

void eapJobSaveToDb(struct sqlConnection *conn, struct eapJob *el, char *tableName, int updateSize);
/* Save eapJob as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapJob *eapJobLoad(char **row);
/* Load a eapJob from row fetched with select * from eapJob
 * from database.  Dispose of this with eapJobFree(). */

struct eapJob *eapJobLoadAll(char *fileName);
/* Load all eapJob from whitespace-separated file.
 * Dispose of this with eapJobFreeList(). */

struct eapJob *eapJobLoadAllByChar(char *fileName, char chopper);
/* Load all eapJob from chopper separated file.
 * Dispose of this with eapJobFreeList(). */

#define eapJobLoadAllByTab(a) eapJobLoadAllByChar(a, '\t');
/* Load all eapJob from tab separated file.
 * Dispose of this with eapJobFreeList(). */

struct eapJob *eapJobCommaIn(char **pS, struct eapJob *ret);
/* Create a eapJob out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapJob */

void eapJobFree(struct eapJob **pEl);
/* Free a single dynamically allocated eapJob such as created
 * with eapJobLoad(). */

void eapJobFreeList(struct eapJob **pList);
/* Free a list of dynamically allocated eapJob's */

void eapJobOutput(struct eapJob *el, FILE *f, char sep, char lastSep);
/* Print out eapJob.  Separate fields with sep. Follow last field with lastSep. */

#define eapJobTabOut(el,f) eapJobOutput(el,f,'\t','\n');
/* Print out eapJob as a line in a tab-separated file. */

#define eapJobCommaOut(el,f) eapJobOutput(el,f,',',',');
/* Print out eapJob as a comma separated list including final comma. */

#define EAPSOFTWARE_NUM_COLS 5

extern char *eapSoftwareCommaSepFieldNames;

struct eapSoftware
/* Software that is tracked by the analysis pipeline. */
    {
    struct eapSoftware *next;  /* Next in singly linked list. */
    unsigned id;	/* Software id */
    char *name;	/* Command line name */
    char *url;	/* Suggested reference URL */
    char *email;	/* Suggested contact email */
    char metaUuid[37];	/* UUID into Stanford metadata system if synced */
    };

void eapSoftwareStaticLoad(char **row, struct eapSoftware *ret);
/* Load a row from eapSoftware table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct eapSoftware *eapSoftwareLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapSoftware from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapSoftwareFreeList(). */

void eapSoftwareSaveToDb(struct sqlConnection *conn, struct eapSoftware *el, char *tableName, int updateSize);
/* Save eapSoftware as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapSoftware *eapSoftwareLoad(char **row);
/* Load a eapSoftware from row fetched with select * from eapSoftware
 * from database.  Dispose of this with eapSoftwareFree(). */

struct eapSoftware *eapSoftwareLoadAll(char *fileName);
/* Load all eapSoftware from whitespace-separated file.
 * Dispose of this with eapSoftwareFreeList(). */

struct eapSoftware *eapSoftwareLoadAllByChar(char *fileName, char chopper);
/* Load all eapSoftware from chopper separated file.
 * Dispose of this with eapSoftwareFreeList(). */

#define eapSoftwareLoadAllByTab(a) eapSoftwareLoadAllByChar(a, '\t');
/* Load all eapSoftware from tab separated file.
 * Dispose of this with eapSoftwareFreeList(). */

struct eapSoftware *eapSoftwareCommaIn(char **pS, struct eapSoftware *ret);
/* Create a eapSoftware out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapSoftware */

void eapSoftwareFree(struct eapSoftware **pEl);
/* Free a single dynamically allocated eapSoftware such as created
 * with eapSoftwareLoad(). */

void eapSoftwareFreeList(struct eapSoftware **pList);
/* Free a list of dynamically allocated eapSoftware's */

void eapSoftwareOutput(struct eapSoftware *el, FILE *f, char sep, char lastSep);
/* Print out eapSoftware.  Separate fields with sep. Follow last field with lastSep. */

#define eapSoftwareTabOut(el,f) eapSoftwareOutput(el,f,'\t','\n');
/* Print out eapSoftware as a line in a tab-separated file. */

#define eapSoftwareCommaOut(el,f) eapSoftwareOutput(el,f,',',',');
/* Print out eapSoftware as a comma separated list including final comma. */

#define EAPSWVERSION_NUM_COLS 7

extern char *eapSwVersionCommaSepFieldNames;

struct eapSwVersion
/* A version of a particular piece of software */
    {
    struct eapSwVersion *next;  /* Next in singly linked list. */
    unsigned id;	/* Version id */
    char *software;	/* Name field of software this is associated with */
    char *version;	/* Version as carved out of program run with --version or the like */
    char md5[33];	/* md5 sum of executable file */
    signed char redoPriority;	/* -1 for routine recompile, 0 for unknown, 1 for recommended, 2 for required. */
    char *notes;	/* Any notes on the version */
    char metaUuid[37];	/* UUID into Stanford metadata system if synced */
    };

void eapSwVersionStaticLoad(char **row, struct eapSwVersion *ret);
/* Load a row from eapSwVersion table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct eapSwVersion *eapSwVersionLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapSwVersion from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapSwVersionFreeList(). */

void eapSwVersionSaveToDb(struct sqlConnection *conn, struct eapSwVersion *el, char *tableName, int updateSize);
/* Save eapSwVersion as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapSwVersion *eapSwVersionLoad(char **row);
/* Load a eapSwVersion from row fetched with select * from eapSwVersion
 * from database.  Dispose of this with eapSwVersionFree(). */

struct eapSwVersion *eapSwVersionLoadAll(char *fileName);
/* Load all eapSwVersion from whitespace-separated file.
 * Dispose of this with eapSwVersionFreeList(). */

struct eapSwVersion *eapSwVersionLoadAllByChar(char *fileName, char chopper);
/* Load all eapSwVersion from chopper separated file.
 * Dispose of this with eapSwVersionFreeList(). */

#define eapSwVersionLoadAllByTab(a) eapSwVersionLoadAllByChar(a, '\t');
/* Load all eapSwVersion from tab separated file.
 * Dispose of this with eapSwVersionFreeList(). */

struct eapSwVersion *eapSwVersionCommaIn(char **pS, struct eapSwVersion *ret);
/* Create a eapSwVersion out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapSwVersion */

void eapSwVersionFree(struct eapSwVersion **pEl);
/* Free a single dynamically allocated eapSwVersion such as created
 * with eapSwVersionLoad(). */

void eapSwVersionFreeList(struct eapSwVersion **pList);
/* Free a list of dynamically allocated eapSwVersion's */

void eapSwVersionOutput(struct eapSwVersion *el, FILE *f, char sep, char lastSep);
/* Print out eapSwVersion.  Separate fields with sep. Follow last field with lastSep. */

#define eapSwVersionTabOut(el,f) eapSwVersionOutput(el,f,'\t','\n');
/* Print out eapSwVersion as a line in a tab-separated file. */

#define eapSwVersionCommaOut(el,f) eapSwVersionOutput(el,f,',',',');
/* Print out eapSwVersion as a comma separated list including final comma. */

#define EAPSTEP_NUM_COLS 14

extern char *eapStepCommaSepFieldNames;

struct eapStep
/* A step in an analysis pipeline - something that takes one set of files to another */
    {
    struct eapStep *next;  /* Next in singly linked list. */
    unsigned id;	/* Step id */
    char *name;	/* Name of this analysis step */
    int cpusRequested;	/* Number of CPUs to request from job control system */
    char *description;	/* Description of step, about a sentence. */
    unsigned inCount;	/* Total number of inputs */
    char **inputTypes;	/* List of types to go with input files */
    char **inputFormats;	/* List of formats of input files */
    char **inputDescriptions;	/* List of descriptions of input files */
    unsigned outCount;	/* Total number of outputs */
    char **outputNamesInTempDir;	/* list of all output file names in output dir */
    char **outputFormats;	/* list of formats of output files */
    char **outputTypes;	/* list of outputType of output files */
    char **outputDescriptions;	/* list of descriptions of outputs */
    char metaUuid[37];	/* UUID into Stanford metadata system if synced */
    };

struct eapStep *eapStepLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapStep from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapStepFreeList(). */

void eapStepSaveToDb(struct sqlConnection *conn, struct eapStep *el, char *tableName, int updateSize);
/* Save eapStep as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapStep *eapStepLoad(char **row);
/* Load a eapStep from row fetched with select * from eapStep
 * from database.  Dispose of this with eapStepFree(). */

struct eapStep *eapStepLoadAll(char *fileName);
/* Load all eapStep from whitespace-separated file.
 * Dispose of this with eapStepFreeList(). */

struct eapStep *eapStepLoadAllByChar(char *fileName, char chopper);
/* Load all eapStep from chopper separated file.
 * Dispose of this with eapStepFreeList(). */

#define eapStepLoadAllByTab(a) eapStepLoadAllByChar(a, '\t');
/* Load all eapStep from tab separated file.
 * Dispose of this with eapStepFreeList(). */

struct eapStep *eapStepCommaIn(char **pS, struct eapStep *ret);
/* Create a eapStep out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapStep */

void eapStepFree(struct eapStep **pEl);
/* Free a single dynamically allocated eapStep such as created
 * with eapStepLoad(). */

void eapStepFreeList(struct eapStep **pList);
/* Free a list of dynamically allocated eapStep's */

void eapStepOutput(struct eapStep *el, FILE *f, char sep, char lastSep);
/* Print out eapStep.  Separate fields with sep. Follow last field with lastSep. */

#define eapStepTabOut(el,f) eapStepOutput(el,f,'\t','\n');
/* Print out eapStep as a line in a tab-separated file. */

#define eapStepCommaOut(el,f) eapStepOutput(el,f,',',',');
/* Print out eapStep as a comma separated list including final comma. */

#define EAPSTEPSOFTWARE_NUM_COLS 3

extern char *eapStepSoftwareCommaSepFieldNames;

struct eapStepSoftware
/* Relates steps to the software they use */
    {
    struct eapStepSoftware *next;  /* Next in singly linked list. */
    unsigned id;	/* Link id - helps give order to software within step among other things */
    char *step;	/* name of associated step */
    char *software;	/* name of associated software */
    };

void eapStepSoftwareStaticLoad(char **row, struct eapStepSoftware *ret);
/* Load a row from eapStepSoftware table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct eapStepSoftware *eapStepSoftwareLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapStepSoftware from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapStepSoftwareFreeList(). */

void eapStepSoftwareSaveToDb(struct sqlConnection *conn, struct eapStepSoftware *el, char *tableName, int updateSize);
/* Save eapStepSoftware as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapStepSoftware *eapStepSoftwareLoad(char **row);
/* Load a eapStepSoftware from row fetched with select * from eapStepSoftware
 * from database.  Dispose of this with eapStepSoftwareFree(). */

struct eapStepSoftware *eapStepSoftwareLoadAll(char *fileName);
/* Load all eapStepSoftware from whitespace-separated file.
 * Dispose of this with eapStepSoftwareFreeList(). */

struct eapStepSoftware *eapStepSoftwareLoadAllByChar(char *fileName, char chopper);
/* Load all eapStepSoftware from chopper separated file.
 * Dispose of this with eapStepSoftwareFreeList(). */

#define eapStepSoftwareLoadAllByTab(a) eapStepSoftwareLoadAllByChar(a, '\t');
/* Load all eapStepSoftware from tab separated file.
 * Dispose of this with eapStepSoftwareFreeList(). */

struct eapStepSoftware *eapStepSoftwareCommaIn(char **pS, struct eapStepSoftware *ret);
/* Create a eapStepSoftware out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapStepSoftware */

void eapStepSoftwareFree(struct eapStepSoftware **pEl);
/* Free a single dynamically allocated eapStepSoftware such as created
 * with eapStepSoftwareLoad(). */

void eapStepSoftwareFreeList(struct eapStepSoftware **pList);
/* Free a list of dynamically allocated eapStepSoftware's */

void eapStepSoftwareOutput(struct eapStepSoftware *el, FILE *f, char sep, char lastSep);
/* Print out eapStepSoftware.  Separate fields with sep. Follow last field with lastSep. */

#define eapStepSoftwareTabOut(el,f) eapStepSoftwareOutput(el,f,'\t','\n');
/* Print out eapStepSoftware as a line in a tab-separated file. */

#define eapStepSoftwareCommaOut(el,f) eapStepSoftwareOutput(el,f,',',',');
/* Print out eapStepSoftware as a comma separated list including final comma. */

#define EAPSTEPVERSION_NUM_COLS 3

extern char *eapStepVersionCommaSepFieldNames;

struct eapStepVersion
/* All the versions of a step - a new row if any subcomponent is versioned too. */
    {
    struct eapStepVersion *next;  /* Next in singly linked list. */
    unsigned id;	/* ID of step version -used to tie together rows in edwAnalysisStepVector */
    char *step;	/* name of associated step */
    unsigned version;	/* Version of given step - just increases by 1 with each change */
    };

void eapStepVersionStaticLoad(char **row, struct eapStepVersion *ret);
/* Load a row from eapStepVersion table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct eapStepVersion *eapStepVersionLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapStepVersion from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapStepVersionFreeList(). */

void eapStepVersionSaveToDb(struct sqlConnection *conn, struct eapStepVersion *el, char *tableName, int updateSize);
/* Save eapStepVersion as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapStepVersion *eapStepVersionLoad(char **row);
/* Load a eapStepVersion from row fetched with select * from eapStepVersion
 * from database.  Dispose of this with eapStepVersionFree(). */

struct eapStepVersion *eapStepVersionLoadAll(char *fileName);
/* Load all eapStepVersion from whitespace-separated file.
 * Dispose of this with eapStepVersionFreeList(). */

struct eapStepVersion *eapStepVersionLoadAllByChar(char *fileName, char chopper);
/* Load all eapStepVersion from chopper separated file.
 * Dispose of this with eapStepVersionFreeList(). */

#define eapStepVersionLoadAllByTab(a) eapStepVersionLoadAllByChar(a, '\t');
/* Load all eapStepVersion from tab separated file.
 * Dispose of this with eapStepVersionFreeList(). */

struct eapStepVersion *eapStepVersionCommaIn(char **pS, struct eapStepVersion *ret);
/* Create a eapStepVersion out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapStepVersion */

void eapStepVersionFree(struct eapStepVersion **pEl);
/* Free a single dynamically allocated eapStepVersion such as created
 * with eapStepVersionLoad(). */

void eapStepVersionFreeList(struct eapStepVersion **pList);
/* Free a list of dynamically allocated eapStepVersion's */

void eapStepVersionOutput(struct eapStepVersion *el, FILE *f, char sep, char lastSep);
/* Print out eapStepVersion.  Separate fields with sep. Follow last field with lastSep. */

#define eapStepVersionTabOut(el,f) eapStepVersionOutput(el,f,'\t','\n');
/* Print out eapStepVersion as a line in a tab-separated file. */

#define eapStepVersionCommaOut(el,f) eapStepVersionOutput(el,f,',',',');
/* Print out eapStepVersion as a comma separated list including final comma. */

#define EAPSTEPSWVERSION_NUM_COLS 3

extern char *eapStepSwVersionCommaSepFieldNames;

struct eapStepSwVersion
/* A table that is queried for list of all software versions used in a step */
    {
    struct eapStepSwVersion *next;  /* Next in singly linked list. */
    unsigned id;	/* Link id - helps give order to steps in a given version */
    unsigned stepVersionId;	/* Key in edwAnalysisStepVersion table */
    unsigned swVersionId;	/* Key in edwAnalysisSwVersion table */
    };

void eapStepSwVersionStaticLoad(char **row, struct eapStepSwVersion *ret);
/* Load a row from eapStepSwVersion table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct eapStepSwVersion *eapStepSwVersionLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapStepSwVersion from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapStepSwVersionFreeList(). */

void eapStepSwVersionSaveToDb(struct sqlConnection *conn, struct eapStepSwVersion *el, char *tableName, int updateSize);
/* Save eapStepSwVersion as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapStepSwVersion *eapStepSwVersionLoad(char **row);
/* Load a eapStepSwVersion from row fetched with select * from eapStepSwVersion
 * from database.  Dispose of this with eapStepSwVersionFree(). */

struct eapStepSwVersion *eapStepSwVersionLoadAll(char *fileName);
/* Load all eapStepSwVersion from whitespace-separated file.
 * Dispose of this with eapStepSwVersionFreeList(). */

struct eapStepSwVersion *eapStepSwVersionLoadAllByChar(char *fileName, char chopper);
/* Load all eapStepSwVersion from chopper separated file.
 * Dispose of this with eapStepSwVersionFreeList(). */

#define eapStepSwVersionLoadAllByTab(a) eapStepSwVersionLoadAllByChar(a, '\t');
/* Load all eapStepSwVersion from tab separated file.
 * Dispose of this with eapStepSwVersionFreeList(). */

struct eapStepSwVersion *eapStepSwVersionCommaIn(char **pS, struct eapStepSwVersion *ret);
/* Create a eapStepSwVersion out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapStepSwVersion */

void eapStepSwVersionFree(struct eapStepSwVersion **pEl);
/* Free a single dynamically allocated eapStepSwVersion such as created
 * with eapStepSwVersionLoad(). */

void eapStepSwVersionFreeList(struct eapStepSwVersion **pList);
/* Free a list of dynamically allocated eapStepSwVersion's */

void eapStepSwVersionOutput(struct eapStepSwVersion *el, FILE *f, char sep, char lastSep);
/* Print out eapStepSwVersion.  Separate fields with sep. Follow last field with lastSep. */

#define eapStepSwVersionTabOut(el,f) eapStepSwVersionOutput(el,f,'\t','\n');
/* Print out eapStepSwVersion as a line in a tab-separated file. */

#define eapStepSwVersionCommaOut(el,f) eapStepSwVersionOutput(el,f,',',',');
/* Print out eapStepSwVersion as a comma separated list including final comma. */

#define EAPRUN_NUM_COLS 10

extern char *eapRunCommaSepFieldNames;

struct eapRun
/* Information on an compute job that produces files by running a step. */
    {
    struct eapRun *next;  /* Next in singly linked list. */
    unsigned id;	/* Analysis run ID */
    unsigned jobId;	/* ID in edwAnalysisJob table */
    char experiment[17];	/* Something like ENCSR000CFA. */
    char *analysisStep;	/* Name of analysis step.  Different data can be analysed with same step */
    unsigned stepVersionId;	/* Keep track of versions of everything */
    char *tempDir;	/* Where analysis is to be computed */
    unsigned assemblyId;	/* Id of assembly we are working with if analysis is all on one assembly */
    char *jsonResult;	/* JSON formatted object with result for Stanford metaDatabase */
    signed char createStatus;	/* 1 if output files made 0 if not made, -1 if make tried and failed */
    char metaUuid[37];	/* UUID into Stanford metadata system if synced */
    };

void eapRunStaticLoad(char **row, struct eapRun *ret);
/* Load a row from eapRun table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct eapRun *eapRunLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapRun from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapRunFreeList(). */

void eapRunSaveToDb(struct sqlConnection *conn, struct eapRun *el, char *tableName, int updateSize);
/* Save eapRun as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapRun *eapRunLoad(char **row);
/* Load a eapRun from row fetched with select * from eapRun
 * from database.  Dispose of this with eapRunFree(). */

struct eapRun *eapRunLoadAll(char *fileName);
/* Load all eapRun from whitespace-separated file.
 * Dispose of this with eapRunFreeList(). */

struct eapRun *eapRunLoadAllByChar(char *fileName, char chopper);
/* Load all eapRun from chopper separated file.
 * Dispose of this with eapRunFreeList(). */

#define eapRunLoadAllByTab(a) eapRunLoadAllByChar(a, '\t');
/* Load all eapRun from tab separated file.
 * Dispose of this with eapRunFreeList(). */

struct eapRun *eapRunCommaIn(char **pS, struct eapRun *ret);
/* Create a eapRun out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapRun */

void eapRunFree(struct eapRun **pEl);
/* Free a single dynamically allocated eapRun such as created
 * with eapRunLoad(). */

void eapRunFreeList(struct eapRun **pList);
/* Free a list of dynamically allocated eapRun's */

void eapRunOutput(struct eapRun *el, FILE *f, char sep, char lastSep);
/* Print out eapRun.  Separate fields with sep. Follow last field with lastSep. */

#define eapRunTabOut(el,f) eapRunOutput(el,f,'\t','\n');
/* Print out eapRun as a line in a tab-separated file. */

#define eapRunCommaOut(el,f) eapRunOutput(el,f,',',',');
/* Print out eapRun as a comma separated list including final comma. */

#define EAPINPUT_NUM_COLS 6

extern char *eapInputCommaSepFieldNames;

struct eapInput
/* Inputs to an eapAnalysis */
    {
    struct eapInput *next;  /* Next in singly linked list. */
    unsigned id;	/* Input table ID */
    unsigned runId;	/* Which eapAnalysis this is associated with */
    char *name;	/* Input name within step */
    unsigned ix;	/* Inputs always potentially vectors.  Have single one with zero ix for scalar input */
    unsigned fileId;	/* Associated file - 0 for no file, look perhaps to val below instead. */
    char *val;	/* Non-file data */
    };

void eapInputStaticLoad(char **row, struct eapInput *ret);
/* Load a row from eapInput table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct eapInput *eapInputLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapInput from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapInputFreeList(). */

void eapInputSaveToDb(struct sqlConnection *conn, struct eapInput *el, char *tableName, int updateSize);
/* Save eapInput as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapInput *eapInputLoad(char **row);
/* Load a eapInput from row fetched with select * from eapInput
 * from database.  Dispose of this with eapInputFree(). */

struct eapInput *eapInputLoadAll(char *fileName);
/* Load all eapInput from whitespace-separated file.
 * Dispose of this with eapInputFreeList(). */

struct eapInput *eapInputLoadAllByChar(char *fileName, char chopper);
/* Load all eapInput from chopper separated file.
 * Dispose of this with eapInputFreeList(). */

#define eapInputLoadAllByTab(a) eapInputLoadAllByChar(a, '\t');
/* Load all eapInput from tab separated file.
 * Dispose of this with eapInputFreeList(). */

struct eapInput *eapInputCommaIn(char **pS, struct eapInput *ret);
/* Create a eapInput out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapInput */

void eapInputFree(struct eapInput **pEl);
/* Free a single dynamically allocated eapInput such as created
 * with eapInputLoad(). */

void eapInputFreeList(struct eapInput **pList);
/* Free a list of dynamically allocated eapInput's */

void eapInputOutput(struct eapInput *el, FILE *f, char sep, char lastSep);
/* Print out eapInput.  Separate fields with sep. Follow last field with lastSep. */

#define eapInputTabOut(el,f) eapInputOutput(el,f,'\t','\n');
/* Print out eapInput as a line in a tab-separated file. */

#define eapInputCommaOut(el,f) eapInputOutput(el,f,',',',');
/* Print out eapInput as a comma separated list including final comma. */

#define EAPOUTPUT_NUM_COLS 6

extern char *eapOutputCommaSepFieldNames;

struct eapOutput
/* Outputs to an eapAnalysis */
    {
    struct eapOutput *next;  /* Next in singly linked list. */
    unsigned id;	/* Output table ID */
    unsigned runId;	/* Which eapAnalysis this is associated with */
    char *name;	/* Output name within step */
    unsigned ix;	/* Outputs always potentially vectors. Have single one with zero ix for scalar output */
    unsigned fileId;	/* Associated file - 0 for no file, look perhaps to val below instead. */
    char *val;	/* Non-file data */
    };

void eapOutputStaticLoad(char **row, struct eapOutput *ret);
/* Load a row from eapOutput table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct eapOutput *eapOutputLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapOutput from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapOutputFreeList(). */

void eapOutputSaveToDb(struct sqlConnection *conn, struct eapOutput *el, char *tableName, int updateSize);
/* Save eapOutput as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapOutput *eapOutputLoad(char **row);
/* Load a eapOutput from row fetched with select * from eapOutput
 * from database.  Dispose of this with eapOutputFree(). */

struct eapOutput *eapOutputLoadAll(char *fileName);
/* Load all eapOutput from whitespace-separated file.
 * Dispose of this with eapOutputFreeList(). */

struct eapOutput *eapOutputLoadAllByChar(char *fileName, char chopper);
/* Load all eapOutput from chopper separated file.
 * Dispose of this with eapOutputFreeList(). */

#define eapOutputLoadAllByTab(a) eapOutputLoadAllByChar(a, '\t');
/* Load all eapOutput from tab separated file.
 * Dispose of this with eapOutputFreeList(). */

struct eapOutput *eapOutputCommaIn(char **pS, struct eapOutput *ret);
/* Create a eapOutput out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapOutput */

void eapOutputFree(struct eapOutput **pEl);
/* Free a single dynamically allocated eapOutput such as created
 * with eapOutputLoad(). */

void eapOutputFreeList(struct eapOutput **pList);
/* Free a list of dynamically allocated eapOutput's */

void eapOutputOutput(struct eapOutput *el, FILE *f, char sep, char lastSep);
/* Print out eapOutput.  Separate fields with sep. Follow last field with lastSep. */

#define eapOutputTabOut(el,f) eapOutputOutput(el,f,'\t','\n');
/* Print out eapOutput as a line in a tab-separated file. */

#define eapOutputCommaOut(el,f) eapOutputOutput(el,f,',',',');
/* Print out eapOutput as a comma separated list including final comma. */

#define EAPPHANTOMPEAKSTATS_NUM_COLS 11

extern char *eapPhantomPeakStatsCommaSepFieldNames;

struct eapPhantomPeakStats
/* Statistics on a BAM file that contains reads that will align in a peaky fashion - deprecated */
    {
    struct eapPhantomPeakStats *next;  /* Next in singly linked list. */
    unsigned fileId;	/* ID of BAM file this is taken from */
    unsigned numReads;	/* Number of mapped reads in that file */
    char *estFragLength;	/* Up to three comma separated strand cross-correlation peaks */
    char *corrEstFragLen;	/* Up to three cross strand correlations at the given peaks */
    int phantomPeak;	/* Read length/phantom peak strand shift */
    double corrPhantomPeak;	/* Correlation value at phantom peak */
    int argMinCorr;	/* strand shift at which cross-correlation is lowest */
    double minCorr;	/* minimum value of cross-correlation */
    double nsc;	/* Normalized strand cross-correlation coefficient (NSC) = COL4 / COL8 */
    double rsc;	/* Relative strand cross-correlation coefficient (RSC) = (COL4 - COL8) / (COL6 - COL8)A */
    int qualityTag;	/* based on thresholded RSC (codes: -2:veryLow,-1:Low,0:Medium,1:High,2:veryHigh) */
    };

void eapPhantomPeakStatsStaticLoad(char **row, struct eapPhantomPeakStats *ret);
/* Load a row from eapPhantomPeakStats table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct eapPhantomPeakStats *eapPhantomPeakStatsLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all eapPhantomPeakStats from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with eapPhantomPeakStatsFreeList(). */

void eapPhantomPeakStatsSaveToDb(struct sqlConnection *conn, struct eapPhantomPeakStats *el, char *tableName, int updateSize);
/* Save eapPhantomPeakStats as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct eapPhantomPeakStats *eapPhantomPeakStatsLoad(char **row);
/* Load a eapPhantomPeakStats from row fetched with select * from eapPhantomPeakStats
 * from database.  Dispose of this with eapPhantomPeakStatsFree(). */

struct eapPhantomPeakStats *eapPhantomPeakStatsLoadAll(char *fileName);
/* Load all eapPhantomPeakStats from whitespace-separated file.
 * Dispose of this with eapPhantomPeakStatsFreeList(). */

struct eapPhantomPeakStats *eapPhantomPeakStatsLoadAllByChar(char *fileName, char chopper);
/* Load all eapPhantomPeakStats from chopper separated file.
 * Dispose of this with eapPhantomPeakStatsFreeList(). */

#define eapPhantomPeakStatsLoadAllByTab(a) eapPhantomPeakStatsLoadAllByChar(a, '\t');
/* Load all eapPhantomPeakStats from tab separated file.
 * Dispose of this with eapPhantomPeakStatsFreeList(). */

struct eapPhantomPeakStats *eapPhantomPeakStatsCommaIn(char **pS, struct eapPhantomPeakStats *ret);
/* Create a eapPhantomPeakStats out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new eapPhantomPeakStats */

void eapPhantomPeakStatsFree(struct eapPhantomPeakStats **pEl);
/* Free a single dynamically allocated eapPhantomPeakStats such as created
 * with eapPhantomPeakStatsLoad(). */

void eapPhantomPeakStatsFreeList(struct eapPhantomPeakStats **pList);
/* Free a list of dynamically allocated eapPhantomPeakStats's */

void eapPhantomPeakStatsOutput(struct eapPhantomPeakStats *el, FILE *f, char sep, char lastSep);
/* Print out eapPhantomPeakStats.  Separate fields with sep. Follow last field with lastSep. */

#define eapPhantomPeakStatsTabOut(el,f) eapPhantomPeakStatsOutput(el,f,'\t','\n');
/* Print out eapPhantomPeakStats as a line in a tab-separated file. */

#define eapPhantomPeakStatsCommaOut(el,f) eapPhantomPeakStatsOutput(el,f,',',',');
/* Print out eapPhantomPeakStats as a comma separated list including final comma. */

/* -------------------------------- End autoSql Generated Code -------------------------------- */

#endif /* EAPDB_H */
