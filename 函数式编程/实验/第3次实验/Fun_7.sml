datatype 'a tree = Empty
    | Node of 'a tree * 'a * 'a tree

fun treeFilter (p : 'a -> bool ) (Empty) : 'a option tree = Empty
  | treeFilter (p) (Node (l, x, r)) =
    let
      val y = if p x then SOME x else NONE
    in
      Node (treeFilter p l, y, treeFilter p r)
    end

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

fun f3(x:int):bool = (x mod 2 = 0)
val test = treeFilter(f3)(listToTree([2,3,4,5]));