fun reverse [] = []
	|reverse (a::L) =  (reverse L) @ [a];

reverse[1,2,3];