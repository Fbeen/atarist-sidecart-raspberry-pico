#ifndef VFS_H
#define VFS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ff.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define vfs_load_plugin(x)
#define bcopy(src, dest, len) memmove(dest, src, len)

#ifndef __time_t_defined
typedef struct {
	short date;
	short time;
} time_t;

struct tm {
  int tm_year;
  int tm_mon;
  int tm_mday;
  int tm_hour;
  int tm_min;
  int tm_sec;
};
#endif // __time_t_defined
typedef DIR vfs_dir_t;
typedef FIL vfs_file_t;
typedef struct {
	long st_size;
	char st_mode;
	time_t st_mtime;
} vfs_stat_t;
typedef struct {
	char name[13];
} vfs_dirent_t;
typedef FIL vfs_t;

#define time(x)
#define vfs_eof f_eof
#define VFS_ISDIR(st_mode) ((st_mode) & AM_DIR)
#define VFS_ISREG(st_mode) !((st_mode) & AM_DIR)
#define vfs_rename(vfs, from, to) f_rename(from, to)
#define VFS_IRWXU 0
#define VFS_IRWXG 0
#define VFS_IRWXO 0
#define vfs_mkdir(vfs, name, mode) f_mkdir(name)
#define vfs_rmdir(vfs, name) f_unlink(name)
#define vfs_remove(vfs, name) f_unlink(name)
#define vfs_chdir(vfs, dir) f_chdir(dir)
char* vfs_getcwd(vfs_t* vfs, void*, int dummy);
int vfs_read (void* buffer, int dummy, int len, vfs_file_t* file);
int vfs_write (void* buffer, int dummy, int len, vfs_file_t* file);
vfs_dirent_t* vfs_readdir(vfs_dir_t* dir);
vfs_file_t* vfs_open(vfs_t* vfs, const char* filename, const char* mode);
vfs_t* vfs_openfs();
void vfs_close(vfs_t* vfs);
int vfs_stat(vfs_t* vfs, const char* filename, vfs_stat_t* st);
void vfs_closedir(vfs_dir_t* dir);
vfs_dir_t* vfs_opendir(vfs_t* vfs, const char* path);
struct tm* gmtime(const time_t *c_t);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* VFS_H */
