fun double(0:int):int = 0
    | double n = 2 + double(n-1);

fun square(x:int):int =
    if x = 0 then 0 else
    if x < 0 then square(~x)
    else square(x-1) + double(x) - 1;

val a = square(3);
square(0);
square(~4);
val a = square(a-4);

         