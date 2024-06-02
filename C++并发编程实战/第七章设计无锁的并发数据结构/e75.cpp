//引用计数的回收机制
template<typename T>
class lock_free_stack {
private:
    std::atomic<node*> to_be_deleted;

    static void delete_nodes(node* nodes) {
        while (nodes) {
            node* next = nodes->next;
            delete nodes;
            nodes = next;
        }
    }

    void try_reclaim(node* old_head) {
        if (threads_in_pop == 1) {
            node* nodes_to_delete = to_be_deleted.exchange(nullptr);
            if (nodes_to_delete) {
                delete_nodes(nodes_to_delete);
            }
            delete old_head;
        } else {
            chain_pending_nodes(old_head);
            --threads_in_pop;
        }
    }

    void chain_pending_nodes(node* nodes) {
        node* last = nodes;
        while (true) {
            node* const next = last->next;
            if (!next) {
                break;
            }
            last = next;
        }
        last->next = to_be_deleted;
        while (!to_be_deleted.compare_exchange_weak(last->next, nodes)) {}
    }

    void chain_pending_node(node* node) {
        chain_pending_nodes(node, node);
    }

    // Assume there are other members and methods not shown in the image.
}; 
