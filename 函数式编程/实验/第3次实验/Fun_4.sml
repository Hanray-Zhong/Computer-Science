fun findOdd([] : int list): int option = NONE
  | findOdd(x::L) = 
  if (x mod 2)=1 then 
  SOME x else findOdd L

val l1 = [2,4,6,8,10];
val l2 = [2,4,7,8,10];
val t1 = findOdd(l1);
val t2 = findOdd(l2);