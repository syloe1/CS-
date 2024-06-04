//¶ÁÐ´ËøµÄÊµÏÖ
 struct rwlock {
    int nActive;           // number of active readers, or -1 if a writer is active
    int nPendingReads;
    int nPendingWrites;
    spinlock_t sl;         // protects the structure
    condition canRead;    // condition for readers
    condition canWrite;   // condition for writers
};

void lockShared(struct rwlock *r)
{
    spin_lock(&r->sl);
    r->nPendingReads++;
    if (r->nPendingWrites > 0)
        wait(&r->canRead, &r->sl); /* don't starve writers */
    while (r->nActive < 0)  /* someone has exclusive lock */
        wait(&r->canRead, &r->sl);
    r->nActive++;
    r->nPendingReads--;
    spin_unlock(&r->sl);
}

void unlockShared(struct rwlock *r)
{
    spin_lock(&r->sl);
    r->nActive--;
    if (r->nActive == 0)  /* no other readers */
    {
        spin_unlock(&r->sl);
        do_signal(&r->canWrite);
    }
    else
        spin_unlock(&r->sl);
}

void lockExclusive(struct rwlock *r)
{
    spin_lock(&r->sl);
    r->nPendingWrites++;
    while (r->nActive != 0) // while there are active readers or a writer
        wait(&r->canWrite, &r->sl);
    r->nPendingWrites--;
    r->nActive = -1; // mark as writer active
    spin_unlock(&r->sl);
}

void unlockExclusive(struct rwlock *r)
{
    boolean_t wakeReaders;
    spin_lock(&r->sl);
    r->nActive = 0; // no writer active
    wakeReaders = (r->nPendingReads != 0); // check if there are pending reads
    spin_unlock(&r->sl);
    if (wakeReaders)
        do_broadcast(&r->canRead); // wake all readers
    else
        do_signal(&r->canWrite); // wake a single writer
}

void downgrade(struct rwlock *r)
{
    boolean_t wakeReaders;
    spin_lock(&r->sl);
    r->nActive = 1; // allow one reader
    wakeReaders = (r->nPendingReads > 0); // check if there are pending reads
    spin_unlock(&r->sl);
    if (wakeReaders)
        do_broadcast(&r->canRead); // wake all readers
}

void upgrade(struct rwlock *r)
{
    spin_lock(&r->sl);
    if (r->nActive == 1) // if no other reader
    {
        r->nActive = -1; // mark as writer active
    }
    else
    {
        r->nPendingWrites++;
        r->nActive--; // release shared lock
        while (r->nActive != 0) // wait for no other readers or writers
            wait(&r->canWrite, &r->sl);
        r->nPendingWrites--;
        r->nActive = -1; // mark as writer active
    }
    spin_unlock(&r->sl);
}
