#ifndef __FILE_IO_DEMO_H
#define __FILE_IO_DEMO_H

extern char * file_io_str[];
extern DEMO_SHOW file_io_demo_list[];

void open_demo(void);

void creat_demo(void);
void close_demo(void);
void lseek_demo(void);

void read_demo(void);
void write_demo(void);
void dup_demo(void);

void sync_demo(void);
void fcntl_demo(void);
void ioctl_demo(void);

#endif
