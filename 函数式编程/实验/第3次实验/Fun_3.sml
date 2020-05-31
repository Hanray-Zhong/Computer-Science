fun f2(x:int):int = x*x;

fun mapList' (f : 'a -> 'b) ([] : 'a list) : 'b list = []
|mapList'(f)(x::L)=(f x)::(mapList' f L);

val l = [1,2,3,4,5,6,7,8,9];
val y = mapList'(f2)(l);