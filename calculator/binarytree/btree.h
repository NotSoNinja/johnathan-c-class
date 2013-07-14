#ifndef __btree_h__
#define __btree_h__

#include <stdlib.h>

typedef struct bt {
	struct bt *left;
	struct bt *right;
	struct bt *previous;
	void *data;
} Btree;

/* Args: node above the node to be deleted, node to be deleted
 * Returns: contents of deleted node
 */
void *removeNode(Btree *);

/* Args: node to delete
 * Returns: 0 - no error, else error
 */
int removeAll(Btree *);

/* Args: node to add new node on to (0 for root), L or R branch of said node, data for the new node
 * Returns: 0 - no error, else error
 */
int insertNode(Btree *, char, void *);

#endif