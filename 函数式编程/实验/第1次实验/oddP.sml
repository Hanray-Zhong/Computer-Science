fun oddP(x:int):bool =
    if x = 1 then true else
    if x = 0 then false else
    oddP(x-2);

oddP 3;
oddP 4;
oddP 0;
oddP 1;