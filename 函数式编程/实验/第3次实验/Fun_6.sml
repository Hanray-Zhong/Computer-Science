fun exists (p : 'a -> bool) (l : 'a list) : bool =
    foldr (fn (a,b) => p a orelse b) false l
	
fun forall (p : 'a -> bool) (l : 'a list) : bool =
    foldr (fn (a,b) => p a andalso b) true l

fun test1(x) = x<5;
fun test2(x) = x>5;
val l1 = [1,2,3,4,5,6,7,8,9];
val l2 = [6,7,8,9];
val l3 = [1,2,3,4];
val e1 = exists(test1)(l1);
val e2 = exists(test2)(l1);
val e3 = exists(test1)(l2);
val e4 = exists(test2)(l2);
val f1 = forall(test1)(l2);
val f2 = forall(test2)(l2);
val f3 = forall(test1)(l3);
val f4 = forall(test2)(l3);