//条件变量的实现

struct condition {
    proc *next;
    /* doubly linked list */
    proc *prev;
    /* of blocked threads */
    spinlock listLock; 
    /* protects this list */
};

void wait(condition *c, Spinlock_t *s)
{
    spin_lock(&c->listLock);
    add self to the linked list;
    spin_unlock(&c->listLock);
    spin_unlock(s);
    /* release spinlock before blocking */
    Swtch();
    /* perform context switch */
    /* when we return from swtch, the event has occurred */
    spin_lock(s);
    /* acquire the spin lock again */
    return;
}

void do_signal(condition *c)
/* Wake up one thread waiting on this condition */
{
    spin_lock(&c->listLock);
    remove one thread from linked list, if it is nonempty;
    spin_unlock(&c->listLock);
    if a thread was removed from the list, make it runnable;
    return;
}

void do_broadcast(condition *c)
/* Wake up all threads waiting on this condition */
{
    spin_lock(&c->listLock);
    while (linked list is nonempty)
        remove a thread from linked list;
    make it runnable;
    spin_unlock(&c->listLock);
}
``
