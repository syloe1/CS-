//try_lock��ʵ��
 int try_lock(spinlock_t *s)
{
    if (test_and_set(s) != 0) /* already locked */
        return FAILURE;
    else
        return SUCCESS;
}
