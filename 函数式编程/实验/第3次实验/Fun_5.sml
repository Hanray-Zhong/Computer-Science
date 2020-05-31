fun subsetSumOption (l : int list, 0 : int) : int list option = SOME []
  | subsetSumOption ([], n) = NONE
  | subsetSumOption (x::L, sum) =
  if subsetSumOption(L, sum-x) =NONE 
  then subsetSumOption(L, sum)
  else
  SOME (x::(valOf(subsetSumOption(L, sum-x))))

val l1 = [1,2,3,4,5,6,7,8,9]
val t1 = subsetSumOption(l1,5);