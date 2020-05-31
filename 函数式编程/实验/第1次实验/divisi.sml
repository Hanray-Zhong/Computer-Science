fun divisibleByThree (x:int):bool =
    if      x=0 then true
    else if x=1 then false
    else if x=2 then false
    else divisibleByThree(x-3);
divisibleByThree 2;
divisibleByThree 3;
divisibleByThree 0;