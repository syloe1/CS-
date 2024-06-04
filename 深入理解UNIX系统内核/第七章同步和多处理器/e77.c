//使用自旋锁来访问双向链表
spinlock_Tt list;
spin_lock(&list) ;
item->forw->back = item->back;
item->back->forw = item->forw;
spin_unlock(&list) ;
