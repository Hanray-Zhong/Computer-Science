import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class test {
    public static void main(String[] args) {
        ComputableComparableTuple<IntComputable, IntComputable> tuple1 =
                new ComputableComparableTuple(new IntComputable(2),new IntComputable(3));
        ComputableComparableTuple<IntComputable, IntComputable> tuple2=
                new ComputableComparableTuple(new IntComputable(4),new IntComputable(5));

        ComputableComparableTuple<IntComputable, IntComputable> tuple3 = tuple1.add(tuple2);
        ComputableComparableTuple<IntComputable, IntComputable> tuple4 = tuple1.subtract(tuple2);
        System.out.println(tuple1.compareTo(tuple2));
        System.out.println();
    }
}
