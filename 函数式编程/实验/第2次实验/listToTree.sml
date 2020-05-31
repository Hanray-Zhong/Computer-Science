datatype tree = Empty
                |Node of tree*int*tree ;

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

val l1 = [1,2,3,4,5,6,7,8,9,10];
val l2 = [7,8,9,10,11,12,13,14,15];
val tree1 = listToTree(l1);
val tree2 = listToTree(l2);