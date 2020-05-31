fun reverse' (L : int list) : int list =
    let
      fun help (L : int list, A : int list) : int list =
        case L of
             [ ] => A
           | x::R => help (R, x :: A)
    in
      help (L, [ ])
    end;

reverse'[1,2,3];