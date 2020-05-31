fun mult [] = 1
    | mult(x::L) = x * (mult L);
val a = mult([1,2,3]);