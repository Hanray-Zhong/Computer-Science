fun interleave ( A, [] ) = A
  | interleave ( [], B ) = B
  | interleave (x::A, y::B) = x::y::interleave(A,B);

val x=interleave([1,2,3,4],[5,6,7]);
val y=interleave([1,2,3],[4,5,6,7]);