#include <stdlib.h>

#ifndef NXSH_H
#define NXSH_H

/* Useful constants */
#define NXSH_WELCOME "Welcome to nxsh! Type 'help' for a list of available commands.\r\n"
#define NXSH_SEPARATOR "-------------------------------------------------------------\r\n"
#define NXSH_HELP "List of available commands:\r\n" \
                    "\tls - get a directory listing\r\n" \
                    "\tcd - change directory\r\n" \
                    "\tmkdir - make directory\r\n" \
                    "\trm - remove file or directory\r\n" \
                    "\tcp - copy file or directory\r\n" \
                    "\tcat - print file on standard output\r\n" \
                    "\tlog - enable/disablel logging\r\n" \
                    "\tversion - display NXSH version\r\n" \
                    "\thelp - print this message\r\n"

#define NXSH_LOG_DIR "/logs"
#define NXSH_VERSION "0.1.4 alpha"

int NXSH_LOGGING_ENABLED;

/* Functions in main.c */
void nxsh_session(int connfd);
char *nxsh_command(char *command, int argc, char **argv);

/* Basic shell commands */
char *nxsh_ls(int argc, char **argv);
char *nxsh_cd(int argc, char **argv);
char *nxsh_mkdir(int argc, char **argv);
char *nxsh_rm(int argc, char **argv);
char *nxsh_cp(int argc, char **argv);
char *nxsh_mv(int argc, char **argv);
char *nxsh_cat(int argc, char **argv);
char *nxsh_log(int argc, char **argv);

/* Behind the scenes */
char *nxsh_cwd();
char *nxsh_prompt();

/* Logging functions */
int logging_enabled();
void write_log(char *input);
void write_log_raw(char *input);

/* Utility functions */
void trim(char *input);
void delete_end(char *input);
char *error(char *msg);
int is_file(char *name);
int is_dir_empty(char *dir);
int exists(char *name);
char *filename(char *fullpath);
char *strip_prefix(char *inpath);

#endif