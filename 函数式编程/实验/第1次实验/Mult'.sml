fun mult'([], a) = a
    | mult'(x::L, a) = mult'(L, x*a);


fun Mult'([], a) = a
    | Mult'(x::L, a) = Mult'(L, mult'(x,a));

val a = Mult'([[1,3],[2,5]],2); 