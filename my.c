#include <linux/module.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/romfs_fs.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/file.h>
#include "my.h"

static struct file_system_type myfs_fs_type = {
         .name           = "myfs",
         .fs_flags       = FS_USERNS_MOUNT,
};

static int init_myfs_fs(void)
{
  ENTER
  return register_filesystem(&myfs_fs_type);
}

static void exit_myfs_fs(void)
{
 ENTER
 unregister_filesystem(&myfs_fs_type);
}

module_init(init_myfs_fs)
module_exit(exit_myfs_fs)
    
     
