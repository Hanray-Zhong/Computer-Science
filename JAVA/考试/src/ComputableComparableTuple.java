public class ComputableComparableTuple<T1 extends Computable<T1>, T2 extends Computable<T2>>
    implements Computable<ComputableComparableTuple<T1, T2>>
{
    private T1 first;
    private T2 second;

    public ComputableComparableTuple(T1 first, T2 second){
        this.first = first;
        this.second = second;
    }

    @Override
    public ComputableComparableTuple<T1, T2> add(ComputableComparableTuple<T1, T2> y) {
        ComputableComparableTuple result = new ComputableComparableTuple(first.add(y.first), second.add(y.second));
        return result;
    }

    @Override
    public ComputableComparableTuple<T1, T2> subtract(ComputableComparableTuple<T1, T2> y) {
        ComputableComparableTuple result = new ComputableComparableTuple(first.subtract(y.first), second.subtract(y.second));
        return result;
    }


    @Override
    public int compareTo(ComputableComparableTuple<T1, T2> o) {
        if (first.compareTo(o.first) != 0)
            return first.compareTo(o.first);
        else
            return second.compareTo(o.second);
    }
}
