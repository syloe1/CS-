//ʹ��������������˫������
spinlock_Tt list;
spin_lock(&list) ;
item->forw->back = item->back;
item->back->forw = item->forw;
spin_unlock(&list) ;
