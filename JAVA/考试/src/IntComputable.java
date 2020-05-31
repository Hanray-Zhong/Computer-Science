public class IntComputable implements Computable<IntComputable> {
    private int value;

    public IntComputable(int value) {
        this.value = value;
    }

    @Override
    public IntComputable add(IntComputable y) {
        return new IntComputable(value + y.value);
    }

    @Override
    public IntComputable subtract(IntComputable y) {
        return new IntComputable(value - y.value);
    }

    @Override
    public int compareTo(IntComputable o) {
        return value - o.value;
    }
}
