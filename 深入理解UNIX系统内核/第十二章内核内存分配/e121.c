//malloc´Ö²ÚÊµÏÖ
 void* malloc(size)
{
    int ndx = 0;
    /* freelist index */
    int bufsize = 1 << MINPOWER;
    /* size of smallest buffer */
    size += 4;  /* account for header */
    assert(size <= MAXBUFSIZE);
    while (bufsize < size)
    {
        ndx++;
        bufsize <<= 1;
        /* at this point, ndx is the index of the appropriate free list */
    }
}
