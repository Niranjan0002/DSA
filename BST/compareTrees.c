  #include <stdio.h>
  #include <stdlib.h>
  #include"compareTrees.h"

  void main ()
  {
    struct tree *t1 = NULL;
    t1 = insert (t1,2); insert (t1,4); insert (t1,6); insert (t1,1);
    struct tree *t2 = NULL;
    t2 = insert (t2,2); insert (t2,1); insert (t2,4); insert (t2,6);
    int a1[4]; int a2[4];
    printf ("Inorder of tree 1: "); inorder (t1); printf ("\n");
    printf ("Inorder of tree 2: "); inorder (t2); printf ("\n");
    array (t1,a1,0);
    array (t2,a2,0);
    printf ("Tree 1 elements in array: "); print (a1,4);
    printf ("Tree 2 elements in array: "); print (a2,4);
    int i = check (a1,a2,4);
    if (i==0)
    printf ("Not same.");
    else
    printf ("Same elements.");
    printf ("\nNo. of nodes in the range 1-3: ");
    printf ("%d\n", count_nodes(t1,1,3,0));
    int a[4];
    printf ("Sum of 2 smallest elements: ");
    printf ("%d\n", sum(t1,2,a));
  }