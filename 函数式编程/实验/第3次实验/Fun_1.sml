fun f1(x:int):int = x*2;


fun thenAddOne ((f1:int -> int), (x:int)) : int =
    f1 x + 1;

val x=5;
val y=thenAddOne (f1,x);