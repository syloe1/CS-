//ÐÅºÅÁ¿²Ù×÷
 void initsem (semaphore* sem, int val)
{
    *sem = val;
}

void P(semaphore *sem) /* acquire the semaphore */
{
    *sem -= 1;
    while (*sem < 0)
        sleep;
}

void V(semaphore *sem) /* release the semaphore */
{
    *sem += 1;
    if (*sem <= 0)
        wakeup a thread blocked on sem;
}

boolean tryP(semaphore* sem)
/* try to acquire semaphore without blocking */
{
    if (*sem > 0)
    {
        *sem -= 1;
        return TRUE;
    }
    else
        return FALSE;
}
