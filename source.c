asmlinkage long sys_mycopy(const char *src,const char *dst)
{
    int infd,outfd,count;
    char buf[256];
    mm_segment_t fs;
    fs=get_fs();
    set_fs(get_ds());
    infd=sys_open(src,O_RDONLY,0);
    outfd=sys_open(dst,O_WRONLY|O_CREAT|O_TRUNC,0600);
    if((infd>0)&&(outfd>0))
    {
        do
	{
	    count=sys_read(infd,buf,256);
            sys_write(outfd,buf,count);
	}
        while(count);
    }
    else
    {
    	printk("ERROR!");
        return 0;
    }
    sys_close(infd);
    sys_close(outfd);
    set_fs(fs);
    return 1;
}