package hust.cs.javacourse.search.index;

import hust.cs.javacourse.search.index.impl.Term;

/*
AbstractTermTuple是所有TermTuple对象的抽象父类.
 */
public abstract class AbstractTermTuple
        extends java.lang.Object
{
    // 字段
    public AbstractTerm term = new Term();
    public final int freq = 1;
    public int curPos;

    // 方法
    public abstract boolean equals(java.lang.Object obj);
    public abstract java.lang.String toString();

}
