datatype tree = Empty
                |Node of tree*int*tree ;

fun revT Empty = Empty
  | revT (Node(t1,r,t2)) = Node( revT t2, r, revT t1 );

fun split [] : (int list * int * int list) = raise Fail "list can not empty"
    | split(l: int list) =
      let
        val mid = (length l) div 2
        val L = (List.take (l,mid))
        val x :: R = (List.drop (l,mid))
      in
        (L, x, R)
end

fun listToTree ([]:int list) = Empty
| listToTree (L)=
let
      val (L, x, R) = split (L)
    in
      Node (listToTree(L), x , listToTree(R))
end

val l1 = [1,2,3,4,5,6,7,8,9];
val tree1 = listToTree(l1);
val test = revT(listToTree(l1));
